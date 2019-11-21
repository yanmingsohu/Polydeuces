// generate by 'generate-lexer.js'
#include "parser.h"
#include "parser_gen.h"

namespace PolydeucesEngine {

int parser_operator(CharSequence str, int len, JSLexer& t) {
  switch (str[0]) {
    case '[':
      t = JSLexer::OpenBracket;
      return 1;

    case ']':
      t = JSLexer::CloseBracket;
      return 1;

    case '(':
      t = JSLexer::OpenParen;
      return 1;

    case ')':
      t = JSLexer::CloseParen;
      return 1;

    case '{':
      t = JSLexer::OpenBrace;
      return 1;

    case '}':
      t = JSLexer::CloseBrace;
      return 1;

    case ';':
      t = JSLexer::SemiColon;
      return 1;

    case ',':
      t = JSLexer::Comma;
      return 1;

    case '=':
      if (len >= 3 && str[1] == '=' && str[2] == '=') {
        t = JSLexer::IdentityEquals;
        return 3;
      }
      if (len >= 2 && str[1] == '>') {
        t = JSLexer::ARROW;
        return 2;
      }
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::Equals_;
        return 2;
      }
      t = JSLexer::Assign;
      return 1;

    case '?':
      if (len >= 2 && str[1] == '?') {
        t = JSLexer::NullCoalesce;
        return 2;
      }
      t = JSLexer::QuestionMark;
      return 1;

    case ':':
      t = JSLexer::Colon;
      return 1;

    case '.':
      if (len >= 3 && str[1] == '.' && str[2] == '.') {
        t = JSLexer::Ellipsis;
        return 3;
      }
      t = JSLexer::Dot;
      return 1;

    case '+':
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::PlusAssign;
        return 2;
      }
      if (len >= 2 && str[1] == '+') {
        t = JSLexer::PlusPlus;
        return 2;
      }
      t = JSLexer::Plus;
      return 1;

    case '-':
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::MinusAssign;
        return 2;
      }
      if (len >= 2 && str[1] == '-') {
        t = JSLexer::MinusMinus;
        return 2;
      }
      t = JSLexer::Minus;
      return 1;

    case '~':
      t = JSLexer::BitNot;
      return 1;

    case '!':
      if (len >= 3 && str[1] == '=' && str[2] == '=') {
        t = JSLexer::IdentityNotEquals;
        return 3;
      }
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::NotEquals;
        return 2;
      }
      t = JSLexer::Not;
      return 1;

    case '*':
      if (len >= 3 && str[1] == '*' && str[2] == '=') {
        t = JSLexer::PowerAssign;
        return 3;
      }
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::MultiplyAssign;
        return 2;
      }
      if (len >= 2 && str[1] == '*') {
        t = JSLexer::Power;
        return 2;
      }
      t = JSLexer::Multiply;
      return 1;

    case '/':
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::DivideAssign;
        return 2;
      }
      t = JSLexer::Divide;
      return 1;

    case '%':
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::ModulusAssign;
        return 2;
      }
      t = JSLexer::Modulus;
      return 1;

    case '#':
      t = JSLexer::Hashtag;
      return 1;

    case '>':
      if (len >= 4 && str[1] == '>' && str[2] == '>' && str[3] == '=') {
        t = JSLexer::RightShiftLogicalAssign;
        return 4;
      }
      if (len >= 3 && str[1] == '>' && str[2] == '=') {
        t = JSLexer::RightShiftArithmeticAssign;
        return 3;
      }
      if (len >= 3 && str[1] == '>' && str[2] == '>') {
        t = JSLexer::RightShiftLogical;
        return 3;
      }
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::GreaterThanEquals;
        return 2;
      }
      if (len >= 2 && str[1] == '>') {
        t = JSLexer::RightShiftArithmetic;
        return 2;
      }
      t = JSLexer::MoreThan;
      return 1;

    case '<':
      if (len >= 3 && str[1] == '<' && str[2] == '=') {
        t = JSLexer::LeftShiftArithmeticAssign;
        return 3;
      }
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::LessThanEquals;
        return 2;
      }
      if (len >= 2 && str[1] == '<') {
        t = JSLexer::LeftShiftArithmetic;
        return 2;
      }
      t = JSLexer::LessThan;
      return 1;

    case '&':
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::BitAndAssign;
        return 2;
      }
      if (len >= 2 && str[1] == '&') {
        t = JSLexer::And;
        return 2;
      }
      t = JSLexer::BitAnd;
      return 1;

    case '^':
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::BitXorAssign;
        return 2;
      }
      t = JSLexer::BitXOr;
      return 1;

    case '|':
      if (len >= 2 && str[1] == '=') {
        t = JSLexer::BitOrAssign;
        return 2;
      }
      if (len >= 2 && str[1] == '|') {
        t = JSLexer::Or;
        return 2;
      }
      t = JSLexer::BitOr;
      return 1;

  };
  return 0;
}

int parser_key_word(CharSequence str, int length, JSLexer& ret) {
  int state = 2;
  JSLexer t;
  for (int i=0; i<length; ++i) {
    switch (state) {
      case 0: // break word
        return 0;
      case 1: // end word but not end
        return 0;
      case 2:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 3;
            break;
          case 't':state = 7;
            break;
          case 'f':state = 11;
            break;
          case 'b':state = 16;
            break;
          case 'd':state = 21;
            break;
          case 'i':state = 23;
            break;
          case 'c':state = 38;
            break;
          case 'e':state = 42;
            break;
          case 'v':state = 48;
            break;
          case 'r':state = 60;
            break;
          case 's':state = 78;
            break;
          case 'w':state = 84;
            break;
          case 'a':state = 123;
            break;
          case 'l':state = 170;
            break;
          case 'p':state = 173;
            break;
          case 'y':state = 210;
            break;
        }
        break;
      case 3:
        switch (str[i]) {
          default: state = 0; break;
          case 'u':state = 4;
            break;
          case 'e':state = 46;
            break;
        }
        break;
      case 4:
        switch (str[i]) {
          default: state = 0; break;
          case 'l':state = 5;
            break;
        }
        break;
      case 5:
        switch (str[i]) {
          default: state = 0; break;
          case 'l':state = 1; t = JSLexer::NullLiteral;
            break;
        }
        break;
      case 6:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 46:
        switch (str[i]) {
          default: state = 0; break;
          case 'w':state = 1; t = JSLexer::New;
            break;
        }
        break;
      case 47:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 7:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 8;
            break;
          case 'y':state = 33;
            break;
          case 'h':state = 103;
            break;
        }
        break;
      case 8:
        switch (str[i]) {
          default: state = 0; break;
          case 'u':state = 9;
            break;
          case 'y':state = 1; t = JSLexer::Try;
            break;
        }
        break;
      case 9:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 1; t = JSLexer::True;
            break;
        }
        break;
      case 10:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 122:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 33:
        switch (str[i]) {
          default: state = 0; break;
          case 'p':state = 34;
            break;
        }
        break;
      case 34:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 35;
            break;
        }
        break;
      case 35:
        switch (str[i]) {
          default: state = 0; break;
          case 'o':state = 36;
            break;
        }
        break;
      case 36:
        switch (str[i]) {
          default: state = 0; break;
          case 'f':state = 1; t = JSLexer::Typeof;
            break;
        }
        break;
      case 37:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 103:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 104;
            break;
          case 'r':state = 115;
            break;
        }
        break;
      case 104:
        switch (str[i]) {
          default: state = 0; break;
          case 's':state = 1; t = JSLexer::This;
            break;
        }
        break;
      case 105:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 115:
        switch (str[i]) {
          default: state = 0; break;
          case 'o':state = 116;
            break;
        }
        break;
      case 116:
        switch (str[i]) {
          default: state = 0; break;
          case 'w':state = 1; t = JSLexer::Throw;
            break;
        }
        break;
      case 117:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 11:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 12;
            break;
          case 'i':state = 54;
            break;
          case 'o':state = 76;
            break;
          case 'u':state = 96;
            break;
          case 'r':state = 125;
            break;
        }
        break;
      case 12:
        switch (str[i]) {
          default: state = 0; break;
          case 'l':state = 13;
            break;
        }
        break;
      case 13:
        switch (str[i]) {
          default: state = 0; break;
          case 's':state = 14;
            break;
        }
        break;
      case 14:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 1; t = JSLexer::False;
            break;
        }
        break;
      case 15:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 54:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 55;
            break;
        }
        break;
      case 55:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 56;
            break;
        }
        break;
      case 56:
        switch (str[i]) {
          default: state = 0; break;
          case 'l':state = 57;
            break;
        }
        break;
      case 57:
        switch (str[i]) {
          default: state = 0; break;
          case 'l':state = 58;
            break;
        }
        break;
      case 58:
        switch (str[i]) {
          default: state = 0; break;
          case 'y':state = 1; t = JSLexer::Finally;
            break;
        }
        break;
      case 59:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 76:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 1; t = JSLexer::For;
            break;
        }
        break;
      case 77:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 96:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 97;
            break;
        }
        break;
      case 97:
        switch (str[i]) {
          default: state = 0; break;
          case 'c':state = 98;
            break;
        }
        break;
      case 98:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 99;
            break;
        }
        break;
      case 99:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 100;
            break;
        }
        break;
      case 100:
        switch (str[i]) {
          default: state = 0; break;
          case 'o':state = 101;
            break;
        }
        break;
      case 101:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 1; t = JSLexer::Function;
            break;
        }
        break;
      case 102:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 125:
        switch (str[i]) {
          default: state = 0; break;
          case 'o':state = 126;
            break;
        }
        break;
      case 126:
        switch (str[i]) {
          default: state = 0; break;
          case 'm':state = 1; t = JSLexer::From;
            break;
        }
        break;
      case 127:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 16:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 17;
            break;
        }
        break;
      case 17:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 18;
            break;
        }
        break;
      case 18:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 19;
            break;
        }
        break;
      case 19:
        switch (str[i]) {
          default: state = 0; break;
          case 'k':state = 1; t = JSLexer::Break;
            break;
        }
        break;
      case 20:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 21:
        switch (str[i]) {
          default: state = 0; break;
          case 'o':state = 1; t = JSLexer::Do;
            break;
          case 'e':state = 89;
            break;
        }
        break;
      case 22:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 89:
        switch (str[i]) {
          default: state = 0; break;
          case 'b':state = 90;
            break;
          case 'f':state = 109;
            break;
          case 'l':state = 118;
            break;
        }
        break;
      case 90:
        switch (str[i]) {
          default: state = 0; break;
          case 'u':state = 91;
            break;
        }
        break;
      case 91:
        switch (str[i]) {
          default: state = 0; break;
          case 'g':state = 92;
            break;
        }
        break;
      case 92:
        switch (str[i]) {
          default: state = 0; break;
          case 'g':state = 93;
            break;
        }
        break;
      case 93:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 94;
            break;
        }
        break;
      case 94:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 1; t = JSLexer::Debugger;
            break;
        }
        break;
      case 95:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 109:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 110;
            break;
        }
        break;
      case 110:
        switch (str[i]) {
          default: state = 0; break;
          case 'u':state = 111;
            break;
        }
        break;
      case 111:
        switch (str[i]) {
          default: state = 0; break;
          case 'l':state = 112;
            break;
        }
        break;
      case 112:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 1; t = JSLexer::Default;
            break;
        }
        break;
      case 113:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 118:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 119;
            break;
        }
        break;
      case 119:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 120;
            break;
        }
        break;
      case 120:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 1; t = JSLexer::Delete;
            break;
        }
        break;
      case 121:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 23:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 1; t = JSLexer::In;
            break;
          case 'f':state = 1; t = JSLexer::If;
            break;
          case 'm':state = 151;
            break;
        }
        break;
      case 24:
        switch (str[i]) {
          default: state = 0; break;
          case 's':state = 25;
            break;
          case 't':state = 185;
            break;
        }
        break;
      case 25:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 26;
            break;
        }
        break;
      case 26:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 27;
            break;
        }
        break;
      case 27:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 28;
            break;
        }
        break;
      case 28:
        switch (str[i]) {
          default: state = 0; break;
          case 'c':state = 29;
            break;
        }
        break;
      case 29:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 30;
            break;
        }
        break;
      case 30:
        switch (str[i]) {
          default: state = 0; break;
          case 'o':state = 31;
            break;
        }
        break;
      case 31:
        switch (str[i]) {
          default: state = 0; break;
          case 'f':state = 1; t = JSLexer::Instanceof;
            break;
        }
        break;
      case 32:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 185:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 186;
            break;
        }
        break;
      case 186:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 187;
            break;
        }
        break;
      case 187:
        switch (str[i]) {
          default: state = 0; break;
          case 'f':state = 188;
            break;
        }
        break;
      case 188:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 189;
            break;
        }
        break;
      case 189:
        switch (str[i]) {
          default: state = 0; break;
          case 'c':state = 190;
            break;
        }
        break;
      case 190:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 1; t = JSLexer::Interface;
            break;
        }
        break;
      case 191:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 114:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 151:
        switch (str[i]) {
          default: state = 0; break;
          case 'p':state = 152;
            break;
        }
        break;
      case 152:
        switch (str[i]) {
          default: state = 0; break;
          case 'o':state = 153;
            break;
          case 'l':state = 163;
            break;
        }
        break;
      case 153:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 154;
            break;
        }
        break;
      case 154:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 1; t = JSLexer::Import;
            break;
        }
        break;
      case 155:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 163:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 164;
            break;
        }
        break;
      case 164:
        switch (str[i]) {
          default: state = 0; break;
          case 'm':state = 165;
            break;
        }
        break;
      case 165:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 166;
            break;
        }
        break;
      case 166:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 167;
            break;
        }
        break;
      case 167:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 168;
            break;
        }
        break;
      case 168:
        switch (str[i]) {
          default: state = 0; break;
          case 's':state = 1; t = JSLexer::Implements;
            break;
        }
        break;
      case 169:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 38:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 39;
            break;
          case 'o':state = 69;
            break;
          case 'l':state = 128;
            break;
        }
        break;
      case 39:
        switch (str[i]) {
          default: state = 0; break;
          case 's':state = 40;
            break;
          case 't':state = 51;
            break;
        }
        break;
      case 40:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 1; t = JSLexer::Case;
            break;
        }
        break;
      case 41:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 51:
        switch (str[i]) {
          default: state = 0; break;
          case 'c':state = 52;
            break;
        }
        break;
      case 52:
        switch (str[i]) {
          default: state = 0; break;
          case 'h':state = 1; t = JSLexer::Catch;
            break;
        }
        break;
      case 53:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 69:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 70;
            break;
        }
        break;
      case 70:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 71;
            break;
          case 's':state = 145;
            break;
        }
        break;
      case 71:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 72;
            break;
        }
        break;
      case 72:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 73;
            break;
        }
        break;
      case 73:
        switch (str[i]) {
          default: state = 0; break;
          case 'u':state = 74;
            break;
        }
        break;
      case 74:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 1; t = JSLexer::Continue;
            break;
        }
        break;
      case 75:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 145:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 1; t = JSLexer::Const;
            break;
        }
        break;
      case 146:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 128:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 129;
            break;
        }
        break;
      case 129:
        switch (str[i]) {
          default: state = 0; break;
          case 's':state = 130;
            break;
        }
        break;
      case 130:
        switch (str[i]) {
          default: state = 0; break;
          case 's':state = 1; t = JSLexer::Class;
            break;
        }
        break;
      case 131:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 42:
        switch (str[i]) {
          default: state = 0; break;
          case 'l':state = 43;
            break;
          case 'n':state = 132;
            break;
          case 'x':state = 135;
            break;
        }
        break;
      case 43:
        switch (str[i]) {
          default: state = 0; break;
          case 's':state = 44;
            break;
        }
        break;
      case 44:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 1; t = JSLexer::Else;
            break;
        }
        break;
      case 45:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 132:
        switch (str[i]) {
          default: state = 0; break;
          case 'u':state = 133;
            break;
        }
        break;
      case 133:
        switch (str[i]) {
          default: state = 0; break;
          case 'm':state = 1; t = JSLexer::Enum;
            break;
        }
        break;
      case 134:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 135:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 136;
            break;
          case 'p':state = 147;
            break;
        }
        break;
      case 136:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 137;
            break;
        }
        break;
      case 137:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 138;
            break;
        }
        break;
      case 138:
        switch (str[i]) {
          default: state = 0; break;
          case 'd':state = 139;
            break;
        }
        break;
      case 139:
        switch (str[i]) {
          default: state = 0; break;
          case 's':state = 1; t = JSLexer::Extends;
            break;
        }
        break;
      case 140:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 147:
        switch (str[i]) {
          default: state = 0; break;
          case 'o':state = 148;
            break;
        }
        break;
      case 148:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 149;
            break;
        }
        break;
      case 149:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 1; t = JSLexer::Export;
            break;
        }
        break;
      case 150:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 48:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 49;
            break;
          case 'o':state = 66;
            break;
        }
        break;
      case 49:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 1; t = JSLexer::Var;
            break;
        }
        break;
      case 50:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 66:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 67;
            break;
        }
        break;
      case 67:
        switch (str[i]) {
          default: state = 0; break;
          case 'd':state = 1; t = JSLexer::Void;
            break;
        }
        break;
      case 68:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 60:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 61;
            break;
        }
        break;
      case 61:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 62;
            break;
        }
        break;
      case 62:
        switch (str[i]) {
          default: state = 0; break;
          case 'u':state = 63;
            break;
        }
        break;
      case 63:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 64;
            break;
        }
        break;
      case 64:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 1; t = JSLexer::Return;
            break;
        }
        break;
      case 65:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 78:
        switch (str[i]) {
          default: state = 0; break;
          case 'w':state = 79;
            break;
          case 'u':state = 141;
            break;
          case 't':state = 205;
            break;
        }
        break;
      case 79:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 80;
            break;
        }
        break;
      case 80:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 81;
            break;
        }
        break;
      case 81:
        switch (str[i]) {
          default: state = 0; break;
          case 'c':state = 82;
            break;
        }
        break;
      case 82:
        switch (str[i]) {
          default: state = 0; break;
          case 'h':state = 1; t = JSLexer::Switch;
            break;
        }
        break;
      case 83:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 141:
        switch (str[i]) {
          default: state = 0; break;
          case 'p':state = 142;
            break;
        }
        break;
      case 142:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 143;
            break;
        }
        break;
      case 143:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 1; t = JSLexer::Super;
            break;
        }
        break;
      case 144:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 205:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 206;
            break;
        }
        break;
      case 206:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 207;
            break;
        }
        break;
      case 207:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 208;
            break;
        }
        break;
      case 208:
        switch (str[i]) {
          default: state = 0; break;
          case 'c':state = 1; t = JSLexer::Static;
            break;
        }
        break;
      case 209:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 84:
        switch (str[i]) {
          default: state = 0; break;
          case 'h':state = 85;
            break;
          case 'i':state = 106;
            break;
        }
        break;
      case 85:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 86;
            break;
        }
        break;
      case 86:
        switch (str[i]) {
          default: state = 0; break;
          case 'l':state = 87;
            break;
        }
        break;
      case 87:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 1; t = JSLexer::While;
            break;
        }
        break;
      case 88:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 106:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 107;
            break;
        }
        break;
      case 107:
        switch (str[i]) {
          default: state = 0; break;
          case 'h':state = 1; t = JSLexer::With;
            break;
        }
        break;
      case 108:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 123:
        switch (str[i]) {
          default: state = 0; break;
          case 's':state = 1; t = JSLexer::As;
            break;
          case 'w':state = 159;
            break;
        }
        break;
      case 124:
        switch (str[i]) {
          default: state = 0; break;
          case 'y':state = 156;
            break;
        }
        break;
      case 156:
        switch (str[i]) {
          default: state = 0; break;
          case 'n':state = 157;
            break;
        }
        break;
      case 157:
        switch (str[i]) {
          default: state = 0; break;
          case 'c':state = 1; t = JSLexer::Async;
            break;
        }
        break;
      case 158:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 159:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 160;
            break;
        }
        break;
      case 160:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 161;
            break;
        }
        break;
      case 161:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 1; t = JSLexer::Await;
            break;
        }
        break;
      case 162:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 170:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 171;
            break;
        }
        break;
      case 171:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 1; t = JSLexer::Let;
            break;
        }
        break;
      case 172:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 173:
        switch (str[i]) {
          default: state = 0; break;
          case 'r':state = 174;
            break;
          case 'u':state = 180;
            break;
          case 'a':state = 192;
            break;
        }
        break;
      case 174:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 175;
            break;
          case 'o':state = 198;
            break;
        }
        break;
      case 175:
        switch (str[i]) {
          default: state = 0; break;
          case 'v':state = 176;
            break;
        }
        break;
      case 176:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 177;
            break;
        }
        break;
      case 177:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 178;
            break;
        }
        break;
      case 178:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 1; t = JSLexer::Private;
            break;
        }
        break;
      case 179:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 198:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 199;
            break;
        }
        break;
      case 199:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 200;
            break;
        }
        break;
      case 200:
        switch (str[i]) {
          default: state = 0; break;
          case 'c':state = 201;
            break;
        }
        break;
      case 201:
        switch (str[i]) {
          default: state = 0; break;
          case 't':state = 202;
            break;
        }
        break;
      case 202:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 203;
            break;
        }
        break;
      case 203:
        switch (str[i]) {
          default: state = 0; break;
          case 'd':state = 1; t = JSLexer::Protected;
            break;
        }
        break;
      case 204:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 180:
        switch (str[i]) {
          default: state = 0; break;
          case 'b':state = 181;
            break;
        }
        break;
      case 181:
        switch (str[i]) {
          default: state = 0; break;
          case 'l':state = 182;
            break;
        }
        break;
      case 182:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 183;
            break;
        }
        break;
      case 183:
        switch (str[i]) {
          default: state = 0; break;
          case 'c':state = 1; t = JSLexer::Public;
            break;
        }
        break;
      case 184:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 192:
        switch (str[i]) {
          default: state = 0; break;
          case 'c':state = 193;
            break;
        }
        break;
      case 193:
        switch (str[i]) {
          default: state = 0; break;
          case 'k':state = 194;
            break;
        }
        break;
      case 194:
        switch (str[i]) {
          default: state = 0; break;
          case 'a':state = 195;
            break;
        }
        break;
      case 195:
        switch (str[i]) {
          default: state = 0; break;
          case 'g':state = 196;
            break;
        }
        break;
      case 196:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 1; t = JSLexer::Package;
            break;
        }
        break;
      case 197:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
      case 210:
        switch (str[i]) {
          default: state = 0; break;
          case 'i':state = 211;
            break;
        }
        break;
      case 211:
        switch (str[i]) {
          default: state = 0; break;
          case 'e':state = 212;
            break;
        }
        break;
      case 212:
        switch (str[i]) {
          default: state = 0; break;
          case 'l':state = 213;
            break;
        }
        break;
      case 213:
        switch (str[i]) {
          default: state = 0; break;
          case 'd':state = 1; t = JSLexer::Yield;
            break;
        }
        break;
      case 214:
        switch (str[i]) {
          default: state = 0; break;
        }
        break;
    }
  }
  if (state == 1) {
    ret = t;
    return 1;
  }
  return 0;
}


}