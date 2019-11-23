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


// i ʼ��ָ���������������������ֶε���һ����
// ������һ���µ������������ʱ, ����������������ǰ�Ĵ�
struct GrammarData {
public:
  WordIter i;
  WordIter end;
  WordIter beg;
  IGrammarListener* listener;

  GrammarData(WordList& wl, IGrammarListener* gl)
    : i(wl.begin()), end(wl.end()), listener(gl), beg(wl.begin()) {
  }

  // ����һ�������, ��Ϊ����鴴�� GrammarData, o ��ָ��Ҳ�����
  GrammarData(GrammarData& o, WordIter& _end)
    : i(o.i), end(_end), listener(o.listener), beg(o.i) {
    o.i = _end;
  }

  // ��ǰָ��ָ��� word ������
  JSLexer lexer() { return i->lexer; }
  WordType type() { return i->type; }
  Word& word() { return *i; }
  // �����ǰָ�����һ�� word ��Ч���� true, ����ע�͵������� word
  bool has();
  // ʹָ��ָ����һ����Ч����, ����ע�͵������� word
  bool back();
  // ��ָ��ָ����һ����Ч����� word, ����ע�͵������� word
  bool next();
  // ʹָ������ƶ������������� word, �ҵ��ĵ�һ�� word �� what
  // �򷵻� true, ��� move Ϊ true, ���д��ǰָ��Ϊ what ����һ��λ��.
  bool find(const JSLexer what, bool move);
  // ָ��ƫ��(Ĭ��Ϊ��ǰָ�����һ��)�� word ��һ������������ true
  bool eos(int offset =1);
};


// *{0,}  +{1,}  ?{0,1}
enum GramState {
  g_not=0,// û��ƥ��, û�д���
  g_one,  // ƥ��һ��
  g_more, // ƥ����
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