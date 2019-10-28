
    #include "JavaScriptBaseLexer.h"


// Generated from D:\Polydeuces\deps\javascript-grammars\javascript\JavaScriptLexer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"


namespace PolydeucesEngine {


class  JavaScriptLexer : public JavaScriptBaseLexer {
public:
  enum {
    MultiLineComment = 1, SingleLineComment = 2, RegularExpressionLiteral = 3, 
    OpenBracket = 4, CloseBracket = 5, OpenParen = 6, CloseParen = 7, OpenBrace = 8, 
    CloseBrace = 9, SemiColon = 10, Comma = 11, Assign = 12, QuestionMark = 13, 
    Colon = 14, Ellipsis = 15, Dot = 16, PlusPlus = 17, MinusMinus = 18, 
    Plus = 19, Minus = 20, BitNot = 21, Not = 22, Multiply = 23, Divide = 24, 
    Modulus = 25, RightShiftArithmetic = 26, LeftShiftArithmetic = 27, RightShiftLogical = 28, 
    LessThan = 29, MoreThan = 30, LessThanEquals = 31, GreaterThanEquals = 32, 
    Equals_ = 33, NotEquals = 34, IdentityEquals = 35, IdentityNotEquals = 36, 
    BitAnd = 37, BitXOr = 38, BitOr = 39, And = 40, Or = 41, MultiplyAssign = 42, 
    DivideAssign = 43, ModulusAssign = 44, PlusAssign = 45, MinusAssign = 46, 
    LeftShiftArithmeticAssign = 47, RightShiftArithmeticAssign = 48, RightShiftLogicalAssign = 49, 
    BitAndAssign = 50, BitXorAssign = 51, BitOrAssign = 52, ARROW = 53, 
    NullLiteral = 54, BooleanLiteral = 55, DecimalLiteral = 56, HexIntegerLiteral = 57, 
    OctalIntegerLiteral = 58, OctalIntegerLiteral2 = 59, BinaryIntegerLiteral = 60, 
    Break = 61, Do = 62, Instanceof = 63, Typeof = 64, Case = 65, Else = 66, 
    New = 67, Var = 68, Catch = 69, Finally = 70, Return = 71, Void = 72, 
    Continue = 73, For = 74, Switch = 75, While = 76, Debugger = 77, Function = 78, 
    This = 79, With = 80, Default = 81, If = 82, Throw = 83, Delete = 84, 
    In = 85, Try = 86, As = 87, From = 88, Class = 89, Enum = 90, Extends = 91, 
    Super = 92, Const = 93, Export = 94, Import = 95, Implements = 96, Let = 97, 
    Private = 98, Public = 99, Interface = 100, Package = 101, Protected = 102, 
    Static = 103, Yield = 104, Identifier = 105, StringLiteral = 106, TemplateStringLiteral = 107, 
    WhiteSpaces = 108, LineTerminator = 109, HtmlComment = 110, CDataComment = 111, 
    UnexpectedCharacter = 112
  };

  enum {
    ERROR = 2
  };

  JavaScriptLexer(antlr4::CharStream *input);
  ~JavaScriptLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.
  void OpenBraceAction(antlr4::RuleContext *context, size_t actionIndex);
  void CloseBraceAction(antlr4::RuleContext *context, size_t actionIndex);
  void StringLiteralAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool RegularExpressionLiteralSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool OctalIntegerLiteralSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool ImplementsSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool LetSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool PrivateSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool PublicSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool InterfaceSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool PackageSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool ProtectedSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool StaticSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);
  bool YieldSempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace PolydeucesEngine
