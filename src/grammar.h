#pragma once
#include "parser.h"


namespace PolydeucesEngine {

#define ThrowIf(    exp, g, msg) if ((exp)) throw GrammarError(g, msg)
#define ThrowIfNot( exp, g, msg) if (!(exp)) throw GrammarError(g, msg)
#define ReturnIf(   exp, retVal) if ((exp)) return retVal
#define ReturnIfNot(exp, retVal) if (!(exp)) return retVal
#define ReturnNotIf(        exp) ReturnIf(exp, g_not)
#define ReturnNotIfNot(     exp) ReturnIfNot(exp, g_not)

typedef WordList::iterator WordIter;


class Expression {
private:
  IGrammarListener* listener;
};


// i 始终指向最后处理过的完整的语义字段的下一个词
// 当进入一个新的语义解析函数时, 函数可以立即处理当前的词
struct GrammarData {
public:
  WordIter i;
  WordIter end;
  WordIter beg;
  IGrammarListener* listener;

  GrammarData(WordList& wl, IGrammarListener* gl)
    : i(wl.begin()), end(wl.end()), listener(gl), beg(wl.begin()) {
  }

  // 进入一个代码块, 并为代码块创建 GrammarData, o 的指针也会更新
  GrammarData(GrammarData& o, WordIter& _end)
    : i(o.i), end(_end), listener(o.listener), beg(o.i) {
    o.i = _end;
  }

  // 当前指针指向的 word 的语义
  JSLexer lexer() { return i->lexer; }
  WordType type() { return i->type; }
  Word& word() { return *i; }
  // 如果当前指针的下一个 word 有效返回 true, 跳过注释等无意义 word
  bool has();
  // 使指针指向上一个有效语义, 跳过注释等无意义 word
  bool back();
  // 将指针指向下一个有效语义的 word, 跳过注释等无意义 word
  bool next();
  // 使指针向后移动并跳过无意义 word, 找到的第一个 word 是 what
  // 则返回 true, 如果 move 为 true, 则改写当前指针为 what 的下一个位置.
  bool find(const JSLexer what, bool move);
  // 指定偏移(默认为当前指针的下一个)的 word 是一个结束符返回 true
  bool eos(int offset =1);
};


// *{0,}  +{1,}  ?{0,1}
enum GramState {
  g_not=0,// 没有匹配, 没有错误
  g_one,  // 匹配一次
  g_more, // 匹配多次
};


class GrammarError {
public:
  const std::string msg;
  Word where;
  GrammarError(GrammarData& gd, const char* _msg) : msg(_msg), where(*gd.i) {}
};


GramState g_block(GrammarData& g);
GramState g_statement(GrammarData& g);
GramState g_statement_list(GrammarData& g);
GramState g_source_element(GrammarData& g);
GramState g_source_elements(GrammarData& g);
GramState g_variable_statement(GrammarData& g);
GramState g_variable_declaration_list(GrammarData& g, JSLexer& modifier);
GramState g_variable_declaration(GrammarData& g, JSLexer& modifier);
GramState g_single_expression(GrammarData& g);
GramState g_assignable(GrammarData& g);
GramState g_identifier(GrammarData& g);
GramState g_object_literal(GrammarData& g);
GramState g_array_literal(GrammarData& g);
GramState g_array_element(GrammarData& g);
GramState g_property_assignment(GrammarData& g);
GramState g_numeric_literal(GrammarData&);
GramState g_keyword(GrammarData& g);
GramState g_reserved_word(GrammarData& g);
GramState g_identifier_name(GrammarData& g);
GramState g_string_literal(GrammarData& g);
GramState g_template_string_literal(GrammarData& g);
GramState g_property_name(GrammarData& g);
GramState g_assignment_operator(GrammarData& g);
GramState g_bigint_literal(GrammarData& g);
GramState g_literal(GrammarData& g);
GramState g_getter(GrammarData& g);


}