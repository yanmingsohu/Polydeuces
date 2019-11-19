// generate by 'generate-lexer.js'
#pragma once

namespace PolydeucesEngine {


enum JSLexer {
  Unknow=0, OpenBracket, CloseBracket, OpenParen, 
  CloseParen, OpenBrace, CloseBrace, SemiColon, 
  Comma, Assign, QuestionMark, Colon, 
  Ellipsis, Dot, PlusPlus, MinusMinus, 
  Plus, Minus, BitNot, Not, 
  Multiply, Divide, Modulus, Power, 
  NullCoalesce, Hashtag, RightShiftArithmetic, LeftShiftArithmetic, 
  RightShiftLogical, LessThan, MoreThan, LessThanEquals, 
  GreaterThanEquals, Equals_, NotEquals, IdentityEquals, 
  IdentityNotEquals, BitAnd, BitXOr, BitOr, 
  And, Or, MultiplyAssign, DivideAssign, 
  ModulusAssign, PlusAssign, MinusAssign, LeftShiftArithmeticAssign, 
  RightShiftArithmeticAssign, RightShiftLogicalAssign, BitAndAssign, BitXorAssign, 
  BitOrAssign, PowerAssign, ARROW, NullLiteral, 
  True, False, Break, Do, 
  Instanceof, Typeof, Case, Else, 
  New, Var, Catch, Finally, 
  Return, Void, Continue, For, 
  Switch, While, Debugger, Function, 
  This, With, Default, If, 
  Throw, Delete, In, Try, 
  As, From, Class, Enum, 
  Extends, Super, Const, Export, 
  Import, Async, Await, Implements, 
  Let, Private, Public, Interface, 
  Package, Protected, Static, Yield, 
  
};

template<class Out> void print_lexer(JSLexer t, Out& out) {
  switch(t) {
    default: return;
    case OpenBracket:
      out << "OpenBracket"; return;
    case CloseBracket:
      out << "CloseBracket"; return;
    case OpenParen:
      out << "OpenParen"; return;
    case CloseParen:
      out << "CloseParen"; return;
    case OpenBrace:
      out << "OpenBrace"; return;
    case CloseBrace:
      out << "CloseBrace"; return;
    case SemiColon:
      out << "SemiColon"; return;
    case Comma:
      out << "Comma"; return;
    case Assign:
      out << "Assign"; return;
    case QuestionMark:
      out << "QuestionMark"; return;
    case Colon:
      out << "Colon"; return;
    case Ellipsis:
      out << "Ellipsis"; return;
    case Dot:
      out << "Dot"; return;
    case PlusPlus:
      out << "PlusPlus"; return;
    case MinusMinus:
      out << "MinusMinus"; return;
    case Plus:
      out << "Plus"; return;
    case Minus:
      out << "Minus"; return;
    case BitNot:
      out << "BitNot"; return;
    case Not:
      out << "Not"; return;
    case Multiply:
      out << "Multiply"; return;
    case Divide:
      out << "Divide"; return;
    case Modulus:
      out << "Modulus"; return;
    case Power:
      out << "Power"; return;
    case NullCoalesce:
      out << "NullCoalesce"; return;
    case Hashtag:
      out << "Hashtag"; return;
    case RightShiftArithmetic:
      out << "RightShiftArithmetic"; return;
    case LeftShiftArithmetic:
      out << "LeftShiftArithmetic"; return;
    case RightShiftLogical:
      out << "RightShiftLogical"; return;
    case LessThan:
      out << "LessThan"; return;
    case MoreThan:
      out << "MoreThan"; return;
    case LessThanEquals:
      out << "LessThanEquals"; return;
    case GreaterThanEquals:
      out << "GreaterThanEquals"; return;
    case Equals_:
      out << "Equals_"; return;
    case NotEquals:
      out << "NotEquals"; return;
    case IdentityEquals:
      out << "IdentityEquals"; return;
    case IdentityNotEquals:
      out << "IdentityNotEquals"; return;
    case BitAnd:
      out << "BitAnd"; return;
    case BitXOr:
      out << "BitXOr"; return;
    case BitOr:
      out << "BitOr"; return;
    case And:
      out << "And"; return;
    case Or:
      out << "Or"; return;
    case MultiplyAssign:
      out << "MultiplyAssign"; return;
    case DivideAssign:
      out << "DivideAssign"; return;
    case ModulusAssign:
      out << "ModulusAssign"; return;
    case PlusAssign:
      out << "PlusAssign"; return;
    case MinusAssign:
      out << "MinusAssign"; return;
    case LeftShiftArithmeticAssign:
      out << "LeftShiftArithmeticAssign"; return;
    case RightShiftArithmeticAssign:
      out << "RightShiftArithmeticAssign"; return;
    case RightShiftLogicalAssign:
      out << "RightShiftLogicalAssign"; return;
    case BitAndAssign:
      out << "BitAndAssign"; return;
    case BitXorAssign:
      out << "BitXorAssign"; return;
    case BitOrAssign:
      out << "BitOrAssign"; return;
    case PowerAssign:
      out << "PowerAssign"; return;
    case ARROW:
      out << "ARROW"; return;
    case NullLiteral:
      out << "NullLiteral"; return;
    case True:
      out << "True"; return;
    case False:
      out << "False"; return;
    case Break:
      out << "Break"; return;
    case Do:
      out << "Do"; return;
    case Instanceof:
      out << "Instanceof"; return;
    case Typeof:
      out << "Typeof"; return;
    case Case:
      out << "Case"; return;
    case Else:
      out << "Else"; return;
    case New:
      out << "New"; return;
    case Var:
      out << "Var"; return;
    case Catch:
      out << "Catch"; return;
    case Finally:
      out << "Finally"; return;
    case Return:
      out << "Return"; return;
    case Void:
      out << "Void"; return;
    case Continue:
      out << "Continue"; return;
    case For:
      out << "For"; return;
    case Switch:
      out << "Switch"; return;
    case While:
      out << "While"; return;
    case Debugger:
      out << "Debugger"; return;
    case Function:
      out << "Function"; return;
    case This:
      out << "This"; return;
    case With:
      out << "With"; return;
    case Default:
      out << "Default"; return;
    case If:
      out << "If"; return;
    case Throw:
      out << "Throw"; return;
    case Delete:
      out << "Delete"; return;
    case In:
      out << "In"; return;
    case Try:
      out << "Try"; return;
    case As:
      out << "As"; return;
    case From:
      out << "From"; return;
    case Class:
      out << "Class"; return;
    case Enum:
      out << "Enum"; return;
    case Extends:
      out << "Extends"; return;
    case Super:
      out << "Super"; return;
    case Const:
      out << "Const"; return;
    case Export:
      out << "Export"; return;
    case Import:
      out << "Import"; return;
    case Async:
      out << "Async"; return;
    case Await:
      out << "Await"; return;
    case Implements:
      out << "Implements"; return;
    case Let:
      out << "Let"; return;
    case Private:
      out << "Private"; return;
    case Public:
      out << "Public"; return;
    case Interface:
      out << "Interface"; return;
    case Package:
      out << "Package"; return;
    case Protected:
      out << "Protected"; return;
    case Static:
      out << "Static"; return;
    case Yield:
      out << "Yield"; return;
  }
}


}