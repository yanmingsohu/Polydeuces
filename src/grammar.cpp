#include "grammar.h"
#include "debug.h"
#include <iostream>
#include <cstdarg>

namespace PolydeucesEngine {


GramState g_or(GrammarData&) { return g_not; }


template<class A, class ...T>
GramState g_or(GrammarData& g, A func, T ... fnX) {
  GramState r = func(g);
  if (r == g_not) {
    return g_or(g, fnX...);
  }
  return r;
}


inline bool skip(Word& w) {
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


// ! p 会在迭代时改变
inline bool move_itr(int increment, WordIter& p, WordIter& end) {
  for (; p != end; ++p) {
    if (!skip(*p)) {
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
  if (move_itr(1, p, end)) {
     i = p;
     return true;
  }
  return false;
}


bool GrammarData::back() {
  WordIter p = i - 1;
  if (move_itr(-1, p, beg)) {
    i = p;
    return true;
  }
  return false;
}


bool GrammarData::has() { 
  WordIter p = i + 1;
  return move_itr(1, p, end);
}


bool GrammarData::find(const JSLexer what, bool move) {
  WordIter p = i;
  if (move_itr(1, p, end)) {
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
  ReturnNotIf(g.lexer() != JSLexer::OpenBrace);
  g.listener->enterBlock(g.word());
  ThrowIfNot(g.next(), g, "Missing block body");

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
  ReturnNotIf(g.lexer() != JSLexer::OpenBrace);
  ThrowIfNot(g.next(), g, "Missing object body");

  if (g.lexer() != JSLexer::CloseBrace) {
    GrammarData scg = scopeDataWithBlock(g, JSLexer::OpenBrace, JSLexer::CloseBrace);
    if (g_property_assignment(scg)) {
      for (;;) {
        if (!scg.find(JSLexer::Comma, true)) break;
        if (!scg.has()) break;
        ThrowIfNot(g_property_assignment(scg), g, 
                   "Missing object property assignment");
      }
    }
    while (scg.find(JSLexer::Comma, true));
    ThrowIfNot(g.lexer() != JSLexer::CloseBrace, g, "Missing object end");
  }
  return g_more;
}


GramState g_array_element(GrammarData& g) {
  g.find(JSLexer::Ellipsis, true);
  ThrowIfNot(g_single_expression(g), g, "Missing array element");
  return g_one;
}


GramState g_array_literal(GrammarData& g) {
  ReturnNotIf(g.lexer() != JSLexer::OpenBracket);
  
  while (g.find(JSLexer::Comma, true));

  while (g.has()) {
    if (g.find(JSLexer::CloseBracket, false)) break;
    ThrowIfNot(g_array_element(g), g, "Missing more array element");
    while (g.find(JSLexer::Comma, true));
  }

  ThrowIfNot(g.find(JSLexer::CloseBracket, true), g, "Missing array end");
  return g_more;
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


GramState g_formal_parameter_list(GrammarData& g) {
  return g_not;
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
    ThrowIf(g.find(JSLexer::Async, true), g, "Unsupport Async");
    ThrowIf(g.find(JSLexer::Multiply, true), g, "Unsupport Generators");
    ThrowIfNot(g_property_name(g), g, "Missing property name");

    ThrowIfNot(g.find(JSLexer::OpenParen, true), g,
               "Missing OpenParen in function property assignment");
    g_formal_parameter_list(g);
    ThrowIfNot(g.find(JSLexer::CloseParen, true), g,
               "Missing CloseParen in function property assignment");

    ThrowIfNot(g.find(JSLexer::OpenBrace, true), g,
               "Missing OpenBrace in function property assignment");
    ThrowIfNot(g_function_body(g), g,
               "Missing function body in function property assignment");
    ThrowIfNot(g.find(JSLexer::CloseBrace, true), g,
               "Missing CloseBrace in function property assignment");
  }
  return g_one;
}


GramState g_identifier(GrammarData& g) {
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


GramState g_anoymous_function(GrammarData& g) {
  return g_not;
}


GramState g_single_expression(GrammarData& g) {
  return g_or(g
    , g_anoymous_function);
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
    , g_variable_statement);
}


GramState g_source_element(GrammarData& g) {
  return g_statement(g);
}


GramState g_source_elements(GrammarData& g) {
  ThrowIfNot(g_source_element(g), g, "Missing source element");
  while (g_source_element(g));
  return g_more;
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