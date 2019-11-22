#include "grammar.h"
#include "debug.h"
#include <iostream>
#include <cstdarg>

namespace PolydeucesEngine {


template<class T>
GramState g_or(int count, GrammarData& g, T fn0, ...) {
  GramState r = fn0(g);
  if (r == g_not) {
    va_list arg;
    va_start(arg, fn0);
    for (int i = 0; i < count-1; ++i) {
      T fn = va_arg(arg, T);
      r = fn(g);
      if (r != g_not) break;
    }
    va_end(arg);
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


GrammarData scopeDataWithBlock(GrammarData& g) {
  int brace = 0;
  WordIter i = g.i;
  for (; i != g.end; ++i) {
    if (i->lexer == JSLexer::OpenBrace) {
      ++brace;
    } 
    else if (i->lexer == JSLexer::CloseBrace) {
      if (brace > 0) --brace;
      else break;
    }
  }
  return GrammarData(g, i);
}


GramState g_statement_list(GrammarData& g) {
  g_statement(g);
  if (!g.has()) return g_one;

  do {
    g_statement(g);
  } while (g.has());
  return g_more;
}


GramState g_block(GrammarData& g) {
  if (g.lexer() != JSLexer::OpenBrace) {
    return g_not;
  }
  g.listener->enterBlock(g.word());

  if (!g.next()) {
    throw GrammarError(g, "Missing block body");
  }

  if (g.lexer() != JSLexer::CloseBrace) {
    GrammarData scg = scopeDataWithBlock(g);

    g_statement_list(scg);

    if (g.lexer() != JSLexer::CloseBrace) {
      throw GrammarError(g, "Missing block end");
    }
  }
  
  g.listener->exitBlock(g.word());
  g.next();
  return g_one;
}


GramState g_array_element(GrammarData& g) {
  g.find(JSLexer::Ellipsis, true);
  return g_single_expression(g);
}


GramState g_array_literal(GrammarData& g) {
  ReturnIf(g.lexer() != JSLexer::OpenBracket, g_not);
  
  while (g.find(JSLexer::Comma, true));
  if (g_not == g_array_element(g)) {
    throw GrammarError(g, "Missing array element");
  }

  for (;;) {
    if (!g.find(JSLexer::Comma, true)) {
      break;
    }
    while (g.find(JSLexer::Comma, true));
    if (g_not == g_array_element(g)) {
      throw GrammarError(g, "Missing array element");
    }
  }
  
  while (g.find(JSLexer::Comma, true));

  ThrowIfNot(g.find(JSLexer::CloseBracket, true), g, "Missing array end");
  return g_more;
}


GramState g_object_literal(GrammarData& g) {
  return g_not;
}


GramState g_identifier(GrammarData& g) {
  ReturnIfNot(g.type() == WordType::Symbol, g_not);
  g.next();
  return g_one;
}


GramState g_assignable(GrammarData& g) {
  return g_or(3, g, g_identifier, g_array_literal, g_object_literal);
}


GramState g_single_expression(GrammarData& g) {
  throw GrammarError(g, "Unsupport single expression");
}


GramState g_variable_declaration(GrammarData& g, JSLexer& modifier) {
  Word& who = *g.i;
  ReturnIf(g_not == g_assignable(g), g_not);
  g.listener->declaration_var(who, modifier);
  ReturnIfNot(g.find(JSLexer::Assign, true), g_one);
  ThrowIf(g_not == g_single_expression(g), g, "Missing expression");
  return g_more;
}


GramState g_variable_declaration_list(GrammarData& g, JSLexer& modifier) {
  ReturnIf(g_not == g_variable_declaration(g, modifier), g_not);
  ReturnIfNot(g.find(JSLexer::Comma, true), g_one);
  do {
    ThrowIf(g_not == g_variable_declaration(g, modifier),
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
  ThrowIf(g_not == g_variable_declaration_list(g, modifier), 
          g, "Missing declaration list");
  ThrowIfNot(g.eos(), g, "Missing declaration end");
  return g_one;
}


//TODO: GrammarData 增加一个标记, 当进入一个语义函数时, 
// 不符合第一个语义标记时抛出异常/返回 g_not
GramState g_statement(GrammarData& g) {
  return g_or(2, g
    , g_block
    , g_variable_statement
  );
}


int begin_parse_grammar(ParseData& pd) {
  DebugGrammar dg;
  GrammarData g(pd.getWords(), &dg);
  IncrementCounter ic(pd);

  try {
    return g_statement(g);
  } catch (GrammarError & e) {
    std::cout << "GrammarError: " << e.msg << std::endl;
    print_error_line(ic, e.where);
    return g_fail;
  }
}


}