#include "grammar.h"
#include "debug.h"
#include <iostream>
#include <cstdarg>

namespace PolydeucesEngine {


GrammarError::GrammarError(GrammarData& gd, const char* _msg, int code)
  : msg(_msg), where(*gd.i) 
{
  if (code) {
    msg += " [" + std::to_string(code) + "]";
  }
}


GramState g_or(GrammarData&) { return g_not; }
GramState g_placeholder(GrammarData&) { return g_not; }


template<class A, class ...T>
GramState g_or(GrammarData& g, A func, T ... fnX) {
  GramState r = func(g);
  if (r == g_not) {
    return g_or(g, fnX...);
  }
  return r;
}


inline bool all_lexical_separator(Word& w) {
  if (w.lexer == JSLexer::SemiColon)
    return true;

  switch (w.type) {
  case WordType::Non:
  case WordType::NewLine:
  case WordType::Comment:
    return true;
  }
  return false;
}


inline bool lexical_separator_without_line(Word& w) {
  if (w.lexer == JSLexer::SemiColon)
    return true;

  switch (w.type) {
  case WordType::Non:
  case WordType::Comment:
    return true;
  }
  return false;
}


template<bool needFunctionKey, bool needIdentifier, class Identifier>
GramState g_function_define(GrammarData& g,
                            Identifier fn) 
{
  bool async = g.find(JSLexer::Async, true);
  if (async) { //TODO: remove
    throw GrammarError(g, "Unsupport Async");
  }
  if (needFunctionKey) {
    if (async) {
      ThrowIfNot(g.find(JSLexer::Function, true), g, "Mission Function");
    } else {
      ReturnNotIfNot(g.find(JSLexer::Function, true));
    }
  }
  if (g.find(JSLexer::Multiply, true)) {  //TODO: remove
    throw GrammarError(g, "Unsupport Generators");
  }
  if (needIdentifier) {
    ThrowIfNot(fn(g), g, "Missing Identifier");
  }

  ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing OpenParen");
  g_formal_parameter_list(g);
  ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing CloseParen");

  ThrowIfNot(g.find(JSLexer::OpenBrace, true), g, "Missing OpenBrace");
  g_function_body(g);
  ThrowIfNot(g.find(JSLexer::CloseBrace, true), g, "Missing CloseBrace");
  return g_one;
}


// ! p 会在迭代时改变
template<class CheckCh>
inline bool move_itr(int increment, WordIter& p, WordIter& end, CheckCh fn) {
  for (; p != end; p += increment) {
    if (!fn(*p)) {
      return true;
    }
  }
  return false;
}


bool GrammarData::eos(int offset) {
  if (i + offset != end) return true;
  if ((i + offset)->lexer == JSLexer::SemiColon) return true;
  if ((i + offset)->type == WordType::NewLine) return true;
  return false;
}


bool GrammarData::next() {
  WordIter p = i+1;
  if (move_itr(1, p, end, all_lexical_separator)) {
     i = p;
     return true;
  }
  return false;
}


bool GrammarData::back() {
  WordIter p = i - 1;
  if (move_itr(-1, p, beg, all_lexical_separator)) {
    i = p;
    return true;
  }
  return false;
}


bool GrammarData::has(bool withoutNewLine) {
  WordIter p = i + 1;
  return move_itr(1, p, end, withoutNewLine
      ? lexical_separator_without_line : all_lexical_separator);
}


bool GrammarData::find(const JSLexer what, bool move, bool withoutNewLine) {
  WordIter p = i;
  const auto filter = withoutNewLine 
                    ? lexical_separator_without_line 
                    : all_lexical_separator;
  if (move_itr(1, p, end, filter)) {
    if (p->lexer == what) {
      if (move) {
        if (p + 1 < end) {
          i = p + 1;
        } else {
          return false;
        }
      }
      return true;
    }
  }
  return false;
}


GrammarData scopeDataWithBlock(GrammarData& g, JSLexer begin, JSLexer end) {
  int brace = 0;
  WordIter i = g.i;
  for (; i != g.end; ++i) {
    if (i->lexer == begin) {
      ++brace;
    } 
    else if (i->lexer == end) {
      if (brace > 0) --brace;
      else break;
    }
  }
  return GrammarData(g, i);
}


GramState g_statement_list(GrammarData& g) {
  ReturnNotIfNot(g_statement(g));
  ReturnIfNot(g.has(), g_one);
  do {
    ThrowIfNot(g_statement(g), g, "Missing statement");
  } while (g.has());
  return g_more;
}


GramState g_block(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::OpenBrace, true));
  ThrowIfNot(g.next(), g, "Missing block body");
  g.listener->enterBlock(g.word());

  if (g.lexer() != JSLexer::CloseBrace) {
    GrammarData scg = scopeDataWithBlock(g, JSLexer::OpenBrace, JSLexer::CloseBrace);
    ThrowIfNot(g_statement_list(scg), g, "Missing statement");
    ThrowIf(g.lexer() != JSLexer::CloseBrace, g, "Missing block end");
  }
  
  g.listener->exitBlock(g.word());
  g.next();
  return g_one;
}


GramState g_object_literal(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::OpenBrace, true));
  debug(object literal);
  if (g_property_assignment(g)) {
    for (;;) {
      if (g.find(JSLexer::Comma, true)) {
        if (g_property_assignment(g)) {
          continue;
        }
      }
      break;
    }
  }
  ThrowIfNot(g.lexer() != JSLexer::CloseBrace, g, "Missing object end");
  return g_more;
}


GramState g_element_list(GrammarData& g) {
  if (!g.find(JSLexer::Comma, true) && !g_array_element(g)) {
    return g_not;
  }

  while (g.find(JSLexer::Comma, true));

  while (g.has()) {
    if (g.find(JSLexer::CloseBracket, false)) break;
    ThrowIfNot(g_array_element(g), g, "Missing more array element");
    while (g.find(JSLexer::Comma, true));
  }
  return g_more;
}


GramState g_array_element(GrammarData& g) {
  if (g.find(JSLexer::Ellipsis, true)) {
    ThrowIfNot(g_single_expression(g), g, "Missing array element");
    return g_one;
  }
  return g_single_expression(g);
}


GramState g_array_literal(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::OpenBracket, true));
  debug(array literal);
  ThrowIfNot(g_element_list(g), g, "Missing array element list");
  ThrowIfNot(g.find(JSLexer::CloseBracket, true), g, "Missing array end");
  debug(array literal end);
  return g_one;
}


GramState g_keyword(GrammarData& g) {
  switch (g.lexer()) {
    case JSLexer::Break:
    case JSLexer::Do:
    case JSLexer::Instanceof:
    case JSLexer::Typeof:
    case JSLexer::Case:
    case JSLexer::Else:
    case JSLexer::New:
    case JSLexer::Var:
    case JSLexer::Catch:
    case JSLexer::Finally:
    case JSLexer::Return:
    case JSLexer::Void:
    case JSLexer::Continue:
    case JSLexer::For:
    case JSLexer::Switch:
    case JSLexer::While:
    case JSLexer::Debugger:
    case JSLexer::Function:
    case JSLexer::This:
    case JSLexer::With:
    case JSLexer::Default:
    case JSLexer::If:
    case JSLexer::Throw:
    case JSLexer::Delete:
    case JSLexer::In:
    case JSLexer::Try:
    case JSLexer::Class: // new keyword
    case JSLexer::Enum:
    case JSLexer::Extends:
    case JSLexer::Super:
    case JSLexer::Const:
    case JSLexer::Export:
    case JSLexer::Import:
    case JSLexer::Implements:
    case JSLexer::Let:
    case JSLexer::Private:
    case JSLexer::Public:
    case JSLexer::Interface:
    case JSLexer::Package:
    case JSLexer::Protected:
    case JSLexer::Static:
    case JSLexer::Yield:
    case JSLexer::Async:
    case JSLexer::Await:
    case JSLexer::From:
    case JSLexer::As:
      g.next();
      return g_one;
  }
  return g_not;
}


GramState g_reserved_word(GrammarData& g) {
  switch (g.lexer()) {
    case JSLexer::NullLiteral:
    case JSLexer::True:
    case JSLexer::False:
      g.next();
      return g_one;
  }
  ReturnIf(g_keyword(g), g_one);
  return g_not;
}


GramState g_identifier_name(GrammarData& g) {
  return g_or(g, g_identifier, g_reserved_word);
}


GramState g_string_literal(GrammarData& g) {
  if (g.type() == WordType::String) {
    g.next();
    return g_one;
  }
  return g_not;
}


GramState g_template_string_literal(GrammarData& g) {
  if (g.type() == WordType::TemplateString) {
    g.next();
    return g_one;
  }
  return g_not;
}


GramState g_property_name(GrammarData& g) {
  if (g_not != g_or(g
    , g_identifier_name
    , g_string_literal
    , g_numeric_literal)
  ) return g_one;

  ReturnNotIf(g.lexer() != JSLexer::OpenBracket);
  ThrowIfNot(g_single_expression(g), g, "Missing expression");
  ThrowIfNot(g.find(JSLexer::CloseBracket, true), g, "Missing array end");
  return g_one;
}


GramState g_assignment_operator(GrammarData& g) {
  switch (g.lexer()) {
    case JSLexer::MultiplyAssign:
    case JSLexer::DivideAssign:
    case JSLexer::ModulusAssign:
    case JSLexer::PlusAssign:
    case JSLexer::MinusAssign:
    case JSLexer::LeftShiftArithmeticAssign:
    case JSLexer::RightShiftArithmeticAssign:
    case JSLexer::RightShiftLogicalAssign:
    case JSLexer::BitAndAssign:
    case JSLexer::BitXorAssign:
    case JSLexer::BitOrAssign:
    case JSLexer::PowerAssign:
      g.next();
      return g_one;
  }
  return g_not;
}


GramState g_numeric_literal(GrammarData& g) {
  switch (g.type()) {
    case WordType::Decimal:
    case WordType::HexInt:
    case WordType::OctalInt1:
    case WordType::OctalInt2:
    case WordType::BinaryInt:
      g.next();
      return g_one;
  }
  return g_not;
}


GramState g_bigint_literal(GrammarData& g) {
  switch (g.type()) {
    case WordType::BigDecimal:
    case WordType::BigHexInt:
    case WordType::BigOctalInt:
    case WordType::BigBinaryInt:
      g.next();
      return g_one;
  }
  return g_not;
}


GramState g_literal(GrammarData& g) {
  debug(literal);
  switch (g.lexer()) {
    case JSLexer::NullLiteral:
    case JSLexer::True:
    case JSLexer::False:
      g.next();
      return g_one;
  }

  switch (g.type()) {
    case WordType::String:
    case WordType::RegularExpression:
    case WordType::TemplateString:
      g.next();
      return g_one;
  }

  ReturnIf(g_numeric_literal(g), g_one);
  ReturnIf(g_bigint_literal(g), g_one);
  return g_not;
}


GramState g_getter(GrammarData& g) {
  ReturnNotIf(g.type() != WordType::Symbol);
  ReturnNotIf(g.i->toString() != "get");
  ThrowIfNot(g.next(), g, "Missing getter property name");
  ThrowIfNot(g_property_name(g), g, "Missing getter property name");
  return g_not;
}


GramState g_setter(GrammarData& g) {
  ReturnNotIf(g.type() != WordType::Symbol);
  ReturnNotIf(g.i->toString() != "set");
  ThrowIfNot(g.next(), g, "Missing setter property name");
  ThrowIfNot(g_property_name(g), g, "Missing setter property name");
  return g_not;
  return g_not;
}


GramState g_function_body(GrammarData& g) {
  int i = 0;
  while (g_source_element(g)) ++i;
  return  i==0 ? g_not : (i>1 ? g_more: g_one);
}


GramState g_formal_parameter_arg(GrammarData& g) {
  ReturnNotIfNot(g_assignable(g));
  if (g.find(JSLexer::Assign, true)) {
    ThrowIfNot(g_single_expression(g), g, "Missing assign value");
  }
  return g_one;
}


GramState g_property_assignment(GrammarData& g) {
  if (g_property_name(g)) {
    ThrowIfNot(g.find(JSLexer::Colon, true), g, 
               "Missing Colon in in property assignment");
    ThrowIfNot(g_single_expression(g), g, 
               "Missing expression in property assignment");
  }
  else if (g.find(JSLexer::OpenBracket, true)) {
    ThrowIfNot(g_single_expression(g), g, 
               "Missing expression in property assignment");
    ThrowIfNot(g.find(JSLexer::CloseBracket, true), g, 
               "Missing CloseBracket in property assignment");
    ThrowIfNot(g.find(JSLexer::SemiColon, true), g, 
               "Missing SemiColon in property assignment");
    ThrowIfNot(g_single_expression(g), g, 
               "Missing expression in property assignment");
  }
  else if (g_getter(g)) {
    ThrowIfNot(g.find(JSLexer::OpenParen, true), g,
               "Missing OpenParen in getter property assignment");
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g,
               "Missing CloseParen in getter property assignment");
    ThrowIfNot(g.find(JSLexer::OpenBrace, true), g,
               "Missing OpenBrace in getter property assignment");
    ThrowIfNot(g_function_body(g), g,
               "Missing function body in getter property assignment");
    ThrowIfNot(g.find(JSLexer::CloseBrace, true), g,
               "Missing CloseBrace in getter property assignment");
  }
  else if (g_setter(g)) {
    ThrowIfNot(g.find(JSLexer::OpenParen, true), g,
               "Missing OpenParen in setter property assignment");
    ThrowIfNot(g_formal_parameter_arg(g), g, 
               "Missing parameter in setter property assignment");
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g,
               "Missing CloseParen in setter property assignment");
    ThrowIfNot(g.find(JSLexer::OpenBrace, true), g,
               "Missing OpenBrace in setter property assignment");
    ThrowIfNot(g_function_body(g), g,
               "Missing function body in setter property assignment");
    ThrowIfNot(g.find(JSLexer::CloseBrace, true), g,
               "Missing CloseBrace in setter property assignment");
  }
  else if (g.find(JSLexer::Ellipsis, true)) {
    ThrowIfNot(g_single_expression(g), g, 
               "Missing expression in property assignment");
  }
  else if (g_single_expression(g)) {
    // do nothing
  }
  else {
     return g_function_define<false, true>(g, g_property_name);
  }
  return g_one;
}


GramState g_identifier(GrammarData& g) {
  debug(!identtifier);
  ReturnNotIf(g.type() != WordType::Symbol);
  g.next();
  return g_one;
}


GramState g_assignable(GrammarData& g) {
  return g_or(g
    , g_identifier
    , g_array_literal
    , g_object_literal);
}


GramState g_variable_declaration(GrammarData& g, JSLexer& modifier) {
  Word& who = *g.i;
  ReturnNotIfNot(g_assignable(g));
  g.listener->declaration_var(who, modifier);
  ReturnIfNot(g.find(JSLexer::Assign, true), g_one);
  ThrowIfNot(g_single_expression(g), g, "Missing expression");
  return g_more;
}


GramState g_variable_declaration_list(GrammarData& g, JSLexer& modifier) {
  ReturnNotIfNot(g_variable_declaration(g, modifier));
  ReturnIfNot(g.find(JSLexer::Comma, true), g_one);
  do {
    ThrowIfNot(g_variable_declaration(g, modifier),
               g, "Missing declaration");
  } while(g.find(JSLexer::Comma, true));
  return g_more;
}


GramState g_variable_statement(GrammarData& g) {
  JSLexer modifier = g.lexer();
  switch (modifier) {
    case JSLexer::Var:
    case JSLexer::Let:
    case JSLexer::Const:
      break;

    default:
      return g_not;
  }

  ThrowIfNot(g.next(), g, "Missing declaration name");
  ThrowIfNot(g_variable_declaration_list(g, modifier),
             g, "Missing declaration list");
  ThrowIfNot(g.eos(), g, "Missing declaration end");
  return g_one;
}


GramState g_statement(GrammarData& g) {
  return g_or(g
    , g_block
    , g_variable_statement
    , g_import_statement
    , g_export_statement
    , g_empty_statement
    , g_class_declaration
    , g_expression_statement
    , g_if_statement
    , g_iteration_statement
    , g_continue_statement
    , g_break_statement
    , g_return_statement
    , g_yield_statement
    , g_with_statement
    , g_labelled_statement
    , g_switch_statement
    , g_throw_statement
    , g_debug_statement
    , g_function_declaration);
}


GramState g_source_element(GrammarData& g) {
  auto r = g_statement(g);
  ThrowIfNot(r, g, "Missing source");
  return r;
}


GramState g_source_elements(GrammarData& g) {
  ThrowIfNot(g_source_element(g), g, "Missing source element");
  if (g_source_element(g)) {
    while (g_source_element(g));
    return g_more;
  }
  return g_one;
}


GramState g_arrow_function_declaration(GrammarData& g) {
  const auto back = g.i;
  const bool async = g.find(JSLexer::Async, true);
  if (async) { //TODO: remove
    throw GrammarError(g, "Unsupport async");
  }
  const auto param = g_arrow_function_parameters(g);
  if (g.find(JSLexer::ARROW, true)) {
    ThrowIfNot(param, g, "Missing parameters");
  } else {
    g.i = back;
    return g_not;
  }
  ThrowIfNot(g_arrow_function_body(g), g, "Missing arrow function body");
  return g_one;
}


GramState g_non_name_function(GrammarData& g) {
  return g_function_define<true, false>(g, g_placeholder);
}


GramState g_anoymous_function(GrammarData& g) {
  return g_or(g
    , g_function_declaration
    , g_non_name_function
    , g_arrow_function_declaration);
}


GramState g_formal_parameter_list(GrammarData& g) {
  return g_not;
}


GramState g_import_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Import, true));
  ThrowIfNot(g_import_from_block(g), g, "Missing from block");
  return g_one;
}


GramState g_import_from_block(GrammarData& g) {
  if (g_string_literal(g)) {
    ThrowIfNot(g.eos(), g, "Missing 'import' end");
    return g_one;
  }

  g_import_default(g);
  if (g_import_namespace(g) || g_module_items(g)) {
    ThrowIfNot(g_import_from(g), g, "Missing 'From'");
    ThrowIfNot(g.eos(), g, "Missing 'import' end");
  } else {
    /*throw GrammarError(g, "Missing module name");*/
    return g_not;
  }
  return g_one;
}


GramState g_module_items(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::OpenBrace, true));
  ThrowIfNot(g_alias_name(g), g, "Missing alias name");
  while (g.has()) {
    ThrowIfNot(g.find(JSLexer::Comma, true), g, "Missing 'Comma'");
    if (!g.has()) break;
    ThrowIfNot(g_alias_name(g), g, "Missing alias name");
  }
  ThrowIfNot(g.find(JSLexer::CloseBrace, true), g, "Missing close brace");
  return g_one;
}


GramState g_import_default(GrammarData& g) {
  ReturnNotIfNot(g_alias_name(g));
  ThrowIfNot(g.find(JSLexer::Comma, true), g, "Missing 'Comma'");
  return g_one;
}


GramState g_import_namespace(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Multiply, true));
  if (g.find(JSLexer::As, true)) {
    ThrowIfNot(g_identifier_name(g), g, "Missing identifier name");
  }
  return g_one;
}


GramState g_import_from(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::From, true));
  ThrowIfNot(g_string_literal(g), g, "Missing string literal");
  return g_one;
}


GramState g_alias_name(GrammarData& g) {
  ReturnNotIfNot(g_identifier_name(g));
  if (g.find(JSLexer::As, true)) {
    ThrowIfNot(g_identifier_name(g), g, "Missing 'AS' identifier name");
  }
  return g_one;
}


GramState g_export_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Export, true));
  if (g.find(JSLexer::Default, true)) {
    ThrowIfNot(g_single_expression(g), g, "Missing 'Default' expression");
    ThrowIfNot(g.eos(), g, "Missing 'Export' end");
  }
  else if (g_export_from_block(g) || g_declaration(g)) {
    ThrowIfNot(g.eos(), g, "Missing 'Export' end");
  }
  else {
    throw GrammarError(g, "Missing export statement");
  }
  return g_one;
}


GramState g_export_from_block(GrammarData& g) {
  if (g_import_namespace(g)) {
    ThrowIfNot(g_import_from(g), g, "Missing 'From'");
    ThrowIfNot(g.eos(), g, "Missing 'From' end");
  } 
  else if (g_module_items(g)) {
    ThrowIfNot(g.eos(), g, "Missing 'From' end"); 
    while (!g.eos()) {
      ThrowIfNot(g_import_from(g), g, "Missing 'From'");
    }
    ThrowIfNot(g.eos(), g, "Missing 'From' end");
  }
  else {
    return g_not;
  }
  return g_one;
}


GramState g_declaration(GrammarData& g) {
  return g_or(g
    , g_variable_statement
    , g_class_declaration
    , g_function_declaration);
}


GramState g_empty_statement(GrammarData& g) {
  return g.find(JSLexer::SemiColon, true) ? g_one : g_not;
}


GramState g_expression_statement(GrammarData& g) {
  ReturnNotIf(g.find(JSLexer::OpenBrace, false));
  ReturnNotIf(g.find(JSLexer::Function, false));
  ThrowIfNot(g_expression_sequence(g), g, "Miss expression seq");
  ThrowIfNot(g.eos(), g, "Missing end");
  return g_one;
}


GramState g_if_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::If, true));
  ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing open 'paren'");
  ThrowIfNot(g_expression_sequence(g), g, "Missing if expression");
  ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
  ThrowIfNot(g_statement(g), g, "Missing if statement");
  if (g.find(JSLexer::Else, true)) {
    ThrowIfNot(g_statement(g), g, "Missing else statement");
  }
  return g_one;
}


GramState g_iteration_statement(GrammarData& g) {
  if (g.find(JSLexer::Do, true)) {
    ThrowIfNot(g_statement(g), g, "Missing 'Do' statement");
    ThrowIfNot(g.find(JSLexer::While, true), g, "Missing 'While'");
    ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing open 'paren'");
    ThrowIfNot(g_expression_sequence(g), g, "Missing expression in 'While'");
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
  }
  else if (g.find(JSLexer::While, true)) {
    ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing open 'paren'");
    ThrowIfNot(g_expression_sequence(g), g, "Missing expression in 'While'");
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
    ThrowIfNot(g_statement(g), g, "Missing 'While' statement");
  }
  else if (g.find(JSLexer::For, true)) {
    ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing open 'paren'");
    const auto _var = g_variable_statement(g);
    const auto _exp = g_expression_sequence(g);
    ThrowIfNot(_var != g_not || _exp != g_not, g, "Missing 'for' expression");

    if (g.find(JSLexer::SemiColon, true)) {
      if (!g.find(JSLexer::SemiColon, true)) {
        ThrowIfNot(g_expression_sequence(g), g, "Missing 'for' expression");
        ThrowIfNot(g.find(JSLexer::SemiColon, true), g, "Missing 'for' expression");
      }
      g_expression_sequence(g);
    }
    else if (g.find(JSLexer::In, true)) {
      ThrowIf(_exp == g_more, g, "Missing left-value");
      ThrowIfNot(g_expression_sequence(g), g, "Missing 'in' expression");
    }
    else {
      throw GrammarError(g, "Missing 'for' expression");
    }
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
    ThrowIfNot(g_statement(g), g, "Missing 'For' statement");
  }
  else {
    return g_not;
  }
  return g_one;
}


GramState g_continue_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Continue, true));
  if (!g.eos()) {
    ThrowIfNot(g_identifier(g), g, "Missing identifier");
    ThrowIfNot(g.eos(), g, "Missing EOS");
  }
  return g_one;
}


GramState g_break_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Break, true));
  if (!g.eos()) {
    ThrowIfNot(g_identifier(g), g, "Missing identifier");
    ThrowIfNot(g.eos(), g, "Missing EOS");
  }
  return g_one;
}


GramState g_return_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Return, true));
  if (!g.eos()) {
    ThrowIfNot(g_expression_sequence(g), g, "Missing expression");
    ThrowIfNot(g.eos(), g, "Missing EOS");
  }
  return g_one;
}


GramState g_yield_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Yield, true));
  if (!g.eos()) {
    ThrowIfNot(g_expression_sequence(g), g, "Missing expression");
    ThrowIfNot(g.eos(), g, "Missing EOS");
  }
  return g_one;
}


GramState g_with_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::With, true));
  ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing open 'paren'");
  ThrowIfNot(g_expression_sequence(g), g, "Missing expression in 'With'");
  ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
  ThrowIfNot(g_statement(g), g, "Missing 'With' statement");
  return g_one;
}


GramState g_switch_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Switch, true));
  ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing open 'paren'");
  ThrowIfNot(g_expression_sequence(g), g, "Missing expression in 'Switch'");
  ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
  ThrowIfNot(g_case_block(g), g, "Missing case in 'Switch'");
  return g_one;
}


GramState g_case_block(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::OpenBrace, true));
  g_case_clauses(g);
  g_default_clause(g);
  while (g_case_clauses(g));
  ThrowIfNot(g.find(JSLexer::CloseBrace, true), g, "Missing close 'brace'");
  return g_one;
}


GramState g_case_clauses(GrammarData& g) {
  if (!g_case_clause(g)) return g_not;
  if (g_case_clause(g)) {
    while (g_case_clause(g));
    return g_more;
  }
  return g_one;
}


GramState g_case_clause(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Case, true));
  ThrowIfNot(g_expression_sequence(g), g, "Missing expression in 'Case'");
  ThrowIfNot(g.find(JSLexer::Colon, true), g, "Missing ':' in Case");
  g_statement_list(g);
  return g_one;
}


GramState g_default_clause(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Default, true));
  ThrowIfNot(g.find(JSLexer::Colon, true), g, "Missing ':' in Default case");
  g_statement_list(g);
  return g_one;
}


GramState g_labelled_statement(GrammarData& g) {
  ReturnNotIfNot(g_identifier(g));
  ThrowIfNot(g.find(JSLexer::Colon, true), g, "Missing ':' in label");
  ThrowIfNot(g_statement(g), g, "Missing statement");
  return g_one;
}


GramState g_throw_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Throw, true));
  if (!g.eos()) {
    ThrowIfNot(g_expression_sequence(g), g, "Missing expression");
    ThrowIfNot(g.eos(), g, "Missing EOS");
  }
  return g_one;
}


GramState g_try_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Try, true));
  ThrowIfNot(g_block(g), g, "Missing try block");
  auto ca = g_catch_production(g);
  auto fi = g_finally_production(g);
  ThrowIfNot(ca && fi, g, "Missing 'catch' or 'finally' block");
  return g_one;
}


GramState g_catch_production(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Catch, true));
  ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing open 'paren'");
  ThrowIfNot(g_assignable(g), g, "Missing assignable in 'catch'");
  ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
  ThrowIfNot(g_block(g), g, "Missing 'catch' block");
  return g_one;
}


GramState g_finally_production(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Finally, true));
  ThrowIfNot(g_block(g), g, "Missing 'finally' block");
  return g_one;
}


GramState g_debug_statement(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Debugger, true));
  ThrowIfNot(g.eos(), g, "Missing EOS");
  return g_one;
}


GramState g_function_declaration(GrammarData& g) {
  return g_function_define<true, true>(g, g_identifier);
}


GramState g_class_declaration(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Class, true));
  ThrowIfNot(g_identifier(g), g, "Missing class identifier");
  ThrowIfNot(g_class_tail(g), g, "Missing class declaration");
  return g_one;
}


GramState g_class_tail(GrammarData& g) {
  if (g.find(JSLexer::Extends, true)) {
    ThrowIfNot(g_single_expression(g), g, "Missing expression in 'Extends'");
    ThrowIfNot(g.find(JSLexer::OpenBrace, true), g, "Missing open 'brace'");
  } else {
    ReturnNotIfNot(g.find(JSLexer::OpenBrace, true));
  }
  while (g_class_element(g));
  ThrowIfNot(g.find(JSLexer::CloseBrace, true), g, "Missing close 'brace'");
  return g_one;
}


GramState g_class_element(GrammarData& g) {
  if (g_empty_statement(g)) 
    return g_one;

  if (g.find(JSLexer::Hashtag, true)) {
    ThrowIfNot(g_property_name(g), g, "Mission property name");
    ThrowIfNot(g.find(JSLexer::Assign, true), g, "Mission assign");
    ThrowIfNot(g_single_expression(g), g, "Mission expression");
    return g_one;
  }

  if (g.find(JSLexer::Static, true) || g.find(JSLexer::Async, true)) {
    ThrowIfNot(g_method_definition(g), g, "Mission method definition in class");
    return g_one;
  }

  if (g_property_name(g)) {
    ThrowIfNot(g.find(JSLexer::Assign, true), g, "Mission assign");
    ThrowIfNot(g_single_expression(g), g, "Mission expression");
    return g_one;
  }
  return g_not;
}


GramState g_method_definition(GrammarData& g) {
  const auto m = g.find(JSLexer::Multiply, true);
  const auto h = g.find(JSLexer::Hashtag, true);
  if (g_property_name(g)) {
    ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing open 'paren'");
    g_formal_parameter_list(g);
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
    ThrowIfNot(g.find(JSLexer::OpenBrace, true), g, "Missing open 'brace'");
    g_function_body(g);
    ThrowIfNot(g.find(JSLexer::CloseBrace, true), g, "Missing close 'brace'");
  } 
  else if (g_getter(g)) {
    ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing open 'paren'");
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
    ThrowIfNot(g.find(JSLexer::OpenBrace, true), g, "Missing open 'brace'");
    g_function_body(g);
    ThrowIfNot(g.find(JSLexer::CloseBrace, true), g, "Missing close 'brace'");
  }
  else if (g_setter(g)) {
    ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing open 'paren'");
    g_formal_parameter_list(g);
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
    ThrowIfNot(g.find(JSLexer::OpenBrace, true), g, "Missing open 'brace'");
    g_function_body(g);
    ThrowIfNot(g.find(JSLexer::CloseBrace, true), g, "Missing close 'brace'");
  } 
  else {
    if (m || h) throw GrammarError(g, "Missing method definition");
    return g_not;
  }
  return g_one;
}


GramState g_last_formal_parameter_list(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::Ellipsis, true));
  ThrowIfNot(g_single_expression(g), g, "Missing expression");
  return g_one;
}


GramState g_argument(GrammarData& g) {
  if (g.find(JSLexer::Ellipsis, true)) {
    if (g_single_expression(g)) {
      return g_one;
    } else if (g_identifier(g)) {
      return g_one;
    } else {
      throw GrammarError(g, "Missing expression");
    }
  } 
  else if (g_single_expression(g)) {
    return g_one;
  }
  else if (g_identifier(g)) {
    return g_one;
  }
  return g_not;
}


GramState g_arguments(GrammarData& g) {
  ReturnNotIfNot(g.find(JSLexer::OpenParen, true));
  for (;;) {
    if (g_argument(g)) {
      if (g.find(JSLexer::Comma, true)) 
        continue;
    }
    break;
  }
  ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
  return g_one;
}


GramState g_expression_sequence(GrammarData& g) {
  ReturnNotIfNot(g_single_expression(g));
  if (!g.find(JSLexer::Comma, true)) {
    return g_one;
  }
  do {
    ThrowIfNot(g_single_expression(g), g, "Missing expression");
  } while (g.find(JSLexer::Comma, true));
  return g_more;
}


GramState g_arrow_function_parameters(GrammarData& g) {
  if (g_identifier(g)) {
    //todo
  } else if (g.find(JSLexer::OpenParen, true)) {
    g_formal_parameter_list(g);
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing close 'paren'");
  } else {
    return g_not;
  }
  return g_one;
}


GramState g_arrow_function_body(GrammarData& g) {
  if (g_single_expression(g)) {
    //todo
  } else if (g.find(JSLexer::OpenBrace, true)) {
    ThrowIfNot(g_function_body(g), g, "Missing arrow body");
    ThrowIfNot(g.find(JSLexer::CloseBrace, true), g, "Missing close 'brace'");
  } else {
    return g_not;
  }
  return g_one;
}


GramState g_single_expression(GrammarData& g, Expression& e) {
  debug(single expression);

  if (g_anoymous_function(g)) {
    //TODO
    debug(anoymous function);
  }
  else if (g.find(JSLexer::Class, true)) {
    debug(Class);
    g_identifier(g);
    ThrowIfNot(g_class_tail(g), g, "Missing class expression");
  }
  else if (g.find(JSLexer::New, true)) {
    debug(New);
    if (g.find(JSLexer::Dot, true)) {
      ThrowIfNot(g_identifier(g), g, "Missing identifier");
    }
    else if (g_single_expression(g, e)) {
      g_arguments(g);
    }
    else {
      throw GrammarError(g, "Missing 'new' expression");
    }
  }
  else if (g.find(JSLexer::Delete, true)) {
    debug(Delete);
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'delete' expression");
  }
  else if (g.find(JSLexer::Void, true)) {
    debug(Void);
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'void' expression");
  }
  else if (g.find(JSLexer::Typeof, true)) {
    debug(Type of);
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'typeof' expression");
  }
  else if (g.find(JSLexer::PlusPlus, true)) {
    debug(++);
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'Pre Increment' expression");
  }
  else if (g.find(JSLexer::MinusMinus, true)) {
    debug(--);
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'Pre Decrease' expression");
  }
  else if (g.find(JSLexer::Plus, true)) {
    debug(+);
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'unary plus' expression");
  }
  else if (g.find(JSLexer::Minus, true)) {
    debug(-);
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'unary minus' expression");
  }
  else if (g.find(JSLexer::BitNot, true)) {
    debug(~);
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'Bit Not' expression");
  }
  else if (g.find(JSLexer::Not, true)) {
    debug(!);
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'Not' expression");
  }
  else if (g.find(JSLexer::Await, true)) {
    debug(Await);
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'await' expression");
  }
  else if (g.find(JSLexer::Import, true)) {
    debug(Import);
    ThrowIfNot(g.find(JSLexer::OpenParen, true), g, "Missing '('");
    ThrowIfNot(g_single_expression(g, e), g, "Missing 'delete' expression");
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing ')'");
  }
  else if (g_yield_statement(g)) {
    //TODO
    debug(yeild);
  }
  else if (g.find(JSLexer::This, true)) {
    //TODO
    debug(this);
  } 
  else if (g_identifier(g)) {
    //TODO
  }
  else if (g.find(JSLexer::Super, true)) {
    //TODO
    debug(super);
  }
  else if (g_literal(g)) {
    //TODO
  }
  else if (g_array_literal(g)) {
    //TODO
  }
  else if (g_object_literal(g)) {
    //TODO
  }
  else if (g.find(JSLexer::OpenParen, true)) {
    debug('(');
    ThrowIfNot(g_expression_sequence(g), g, "Missing expression seq");
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g, "Missing ')'");
    //TODO
  }
  else {
    return g_not;
  }
  return g_one;
}


GramState g_single_expression(GrammarData& g) {
  Expression exp;
  g.listener->enterExp(*g.i);
  auto r = g_single_expression(g, exp);
  g.listener->exitExp(*g.i);
  return r;
}


int begin_parse_grammar(ParseData& pd) {
  DebugGrammar dg;
  GrammarData g(pd.getWords(), &dg);
  IncrementCounter ic(pd);

  try {
    return g_source_element(g);
  } catch (GrammarError & e) {
    std::cout << "GrammarError: " << e.msg << std::endl;
    print_error_line(ic, e.where);
    return FailCode;
  }
}


}