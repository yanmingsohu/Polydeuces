
    #include "JavaScriptBaseParser.h"


// Generated from D:\Polydeuces\deps\javascript-grammars\javascript\JavaScriptParser.g4 by ANTLR 4.7.2


#include "JavaScriptParserListener.h"
#include "JavaScriptParserVisitor.h"

#include "JavaScriptParser.h"


using namespace antlrcpp;
using namespace PolydeucesEngine;
using namespace antlr4;

JavaScriptParser::JavaScriptParser(TokenStream *input) : JavaScriptBaseParser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

JavaScriptParser::~JavaScriptParser() {
  delete _interpreter;
}

std::string JavaScriptParser::getGrammarFileName() const {
  return "JavaScriptParser.g4";
}

const std::vector<std::string>& JavaScriptParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& JavaScriptParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

JavaScriptParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ProgramContext::EOF() {
  return getToken(JavaScriptParser::EOF, 0);
}

JavaScriptParser::SourceElementsContext* JavaScriptParser::ProgramContext::sourceElements() {
  return getRuleContext<JavaScriptParser::SourceElementsContext>(0);
}


size_t JavaScriptParser::ProgramContext::getRuleIndex() const {
  return JavaScriptParser::RuleProgram;
}

void JavaScriptParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void JavaScriptParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any JavaScriptParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ProgramContext* JavaScriptParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, JavaScriptParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(140);
      sourceElements();
      break;
    }

    }
    setState(143);
    match(JavaScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SourceElementContext ------------------------------------------------------------------

JavaScriptParser::SourceElementContext::SourceElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaScriptParser::StatementContext* JavaScriptParser::SourceElementContext::statement() {
  return getRuleContext<JavaScriptParser::StatementContext>(0);
}

tree::TerminalNode* JavaScriptParser::SourceElementContext::Export() {
  return getToken(JavaScriptParser::Export, 0);
}


size_t JavaScriptParser::SourceElementContext::getRuleIndex() const {
  return JavaScriptParser::RuleSourceElement;
}

void JavaScriptParser::SourceElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSourceElement(this);
}

void JavaScriptParser::SourceElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSourceElement(this);
}


antlrcpp::Any JavaScriptParser::SourceElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitSourceElement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::SourceElementContext* JavaScriptParser::sourceElement() {
  SourceElementContext *_localctx = _tracker.createInstance<SourceElementContext>(_ctx, getState());
  enterRule(_localctx, 2, JavaScriptParser::RuleSourceElement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(145);
      match(JavaScriptParser::Export);
      break;
    }

    }
    setState(148);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

JavaScriptParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaScriptParser::BlockContext* JavaScriptParser::StatementContext::block() {
  return getRuleContext<JavaScriptParser::BlockContext>(0);
}

JavaScriptParser::VariableStatementContext* JavaScriptParser::StatementContext::variableStatement() {
  return getRuleContext<JavaScriptParser::VariableStatementContext>(0);
}

JavaScriptParser::ImportStatementContext* JavaScriptParser::StatementContext::importStatement() {
  return getRuleContext<JavaScriptParser::ImportStatementContext>(0);
}

JavaScriptParser::ExportStatementContext* JavaScriptParser::StatementContext::exportStatement() {
  return getRuleContext<JavaScriptParser::ExportStatementContext>(0);
}

JavaScriptParser::EmptyStatementContext* JavaScriptParser::StatementContext::emptyStatement() {
  return getRuleContext<JavaScriptParser::EmptyStatementContext>(0);
}

JavaScriptParser::ClassDeclarationContext* JavaScriptParser::StatementContext::classDeclaration() {
  return getRuleContext<JavaScriptParser::ClassDeclarationContext>(0);
}

JavaScriptParser::ExpressionStatementContext* JavaScriptParser::StatementContext::expressionStatement() {
  return getRuleContext<JavaScriptParser::ExpressionStatementContext>(0);
}

JavaScriptParser::IfStatementContext* JavaScriptParser::StatementContext::ifStatement() {
  return getRuleContext<JavaScriptParser::IfStatementContext>(0);
}

JavaScriptParser::IterationStatementContext* JavaScriptParser::StatementContext::iterationStatement() {
  return getRuleContext<JavaScriptParser::IterationStatementContext>(0);
}

JavaScriptParser::ContinueStatementContext* JavaScriptParser::StatementContext::continueStatement() {
  return getRuleContext<JavaScriptParser::ContinueStatementContext>(0);
}

JavaScriptParser::BreakStatementContext* JavaScriptParser::StatementContext::breakStatement() {
  return getRuleContext<JavaScriptParser::BreakStatementContext>(0);
}

JavaScriptParser::ReturnStatementContext* JavaScriptParser::StatementContext::returnStatement() {
  return getRuleContext<JavaScriptParser::ReturnStatementContext>(0);
}

JavaScriptParser::YieldStatementContext* JavaScriptParser::StatementContext::yieldStatement() {
  return getRuleContext<JavaScriptParser::YieldStatementContext>(0);
}

JavaScriptParser::WithStatementContext* JavaScriptParser::StatementContext::withStatement() {
  return getRuleContext<JavaScriptParser::WithStatementContext>(0);
}

JavaScriptParser::LabelledStatementContext* JavaScriptParser::StatementContext::labelledStatement() {
  return getRuleContext<JavaScriptParser::LabelledStatementContext>(0);
}

JavaScriptParser::SwitchStatementContext* JavaScriptParser::StatementContext::switchStatement() {
  return getRuleContext<JavaScriptParser::SwitchStatementContext>(0);
}

JavaScriptParser::ThrowStatementContext* JavaScriptParser::StatementContext::throwStatement() {
  return getRuleContext<JavaScriptParser::ThrowStatementContext>(0);
}

JavaScriptParser::TryStatementContext* JavaScriptParser::StatementContext::tryStatement() {
  return getRuleContext<JavaScriptParser::TryStatementContext>(0);
}

JavaScriptParser::DebuggerStatementContext* JavaScriptParser::StatementContext::debuggerStatement() {
  return getRuleContext<JavaScriptParser::DebuggerStatementContext>(0);
}

JavaScriptParser::FunctionDeclarationContext* JavaScriptParser::StatementContext::functionDeclaration() {
  return getRuleContext<JavaScriptParser::FunctionDeclarationContext>(0);
}

JavaScriptParser::GeneratorFunctionDeclarationContext* JavaScriptParser::StatementContext::generatorFunctionDeclaration() {
  return getRuleContext<JavaScriptParser::GeneratorFunctionDeclarationContext>(0);
}


size_t JavaScriptParser::StatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleStatement;
}

void JavaScriptParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void JavaScriptParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any JavaScriptParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::StatementContext* JavaScriptParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, JavaScriptParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(150);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(151);
      variableStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(152);
      importStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(153);
      exportStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(154);
      emptyStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(155);
      classDeclaration();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(156);
      expressionStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(157);
      ifStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(158);
      iterationStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(159);
      continueStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(160);
      breakStatement();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(161);
      returnStatement();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(162);
      yieldStatement();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(163);
      withStatement();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(164);
      labelledStatement();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(165);
      switchStatement();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(166);
      throwStatement();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(167);
      tryStatement();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(168);
      debuggerStatement();
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(169);
      functionDeclaration();
      break;
    }

    case 21: {
      enterOuterAlt(_localctx, 21);
      setState(170);
      generatorFunctionDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

JavaScriptParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::BlockContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

tree::TerminalNode* JavaScriptParser::BlockContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

JavaScriptParser::StatementListContext* JavaScriptParser::BlockContext::statementList() {
  return getRuleContext<JavaScriptParser::StatementListContext>(0);
}


size_t JavaScriptParser::BlockContext::getRuleIndex() const {
  return JavaScriptParser::RuleBlock;
}

void JavaScriptParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void JavaScriptParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any JavaScriptParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::BlockContext* JavaScriptParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 6, JavaScriptParser::RuleBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    match(JavaScriptParser::OpenBrace);
    setState(175);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(174);
      statementList();
      break;
    }

    }
    setState(177);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

JavaScriptParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaScriptParser::StatementContext *> JavaScriptParser::StatementListContext::statement() {
  return getRuleContexts<JavaScriptParser::StatementContext>();
}

JavaScriptParser::StatementContext* JavaScriptParser::StatementListContext::statement(size_t i) {
  return getRuleContext<JavaScriptParser::StatementContext>(i);
}


size_t JavaScriptParser::StatementListContext::getRuleIndex() const {
  return JavaScriptParser::RuleStatementList;
}

void JavaScriptParser::StatementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementList(this);
}

void JavaScriptParser::StatementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementList(this);
}


antlrcpp::Any JavaScriptParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::StatementListContext* JavaScriptParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 8, JavaScriptParser::RuleStatementList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(180); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(179);
              statement();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(182); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportStatementContext ------------------------------------------------------------------

JavaScriptParser::ImportStatementContext::ImportStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ImportStatementContext::Import() {
  return getToken(JavaScriptParser::Import, 0);
}

JavaScriptParser::FromBlockContext* JavaScriptParser::ImportStatementContext::fromBlock() {
  return getRuleContext<JavaScriptParser::FromBlockContext>(0);
}


size_t JavaScriptParser::ImportStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleImportStatement;
}

void JavaScriptParser::ImportStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportStatement(this);
}

void JavaScriptParser::ImportStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportStatement(this);
}


antlrcpp::Any JavaScriptParser::ImportStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitImportStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ImportStatementContext* JavaScriptParser::importStatement() {
  ImportStatementContext *_localctx = _tracker.createInstance<ImportStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, JavaScriptParser::RuleImportStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(JavaScriptParser::Import);
    setState(185);
    fromBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FromBlockContext ------------------------------------------------------------------

JavaScriptParser::FromBlockContext::FromBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::FromBlockContext::From() {
  return getToken(JavaScriptParser::From, 0);
}

tree::TerminalNode* JavaScriptParser::FromBlockContext::StringLiteral() {
  return getToken(JavaScriptParser::StringLiteral, 0);
}

JavaScriptParser::EosContext* JavaScriptParser::FromBlockContext::eos() {
  return getRuleContext<JavaScriptParser::EosContext>(0);
}

tree::TerminalNode* JavaScriptParser::FromBlockContext::Multiply() {
  return getToken(JavaScriptParser::Multiply, 0);
}

JavaScriptParser::MultipleImportStatementContext* JavaScriptParser::FromBlockContext::multipleImportStatement() {
  return getRuleContext<JavaScriptParser::MultipleImportStatementContext>(0);
}

tree::TerminalNode* JavaScriptParser::FromBlockContext::As() {
  return getToken(JavaScriptParser::As, 0);
}

JavaScriptParser::IdentifierNameContext* JavaScriptParser::FromBlockContext::identifierName() {
  return getRuleContext<JavaScriptParser::IdentifierNameContext>(0);
}


size_t JavaScriptParser::FromBlockContext::getRuleIndex() const {
  return JavaScriptParser::RuleFromBlock;
}

void JavaScriptParser::FromBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFromBlock(this);
}

void JavaScriptParser::FromBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFromBlock(this);
}


antlrcpp::Any JavaScriptParser::FromBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitFromBlock(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::FromBlockContext* JavaScriptParser::fromBlock() {
  FromBlockContext *_localctx = _tracker.createInstance<FromBlockContext>(_ctx, getState());
  enterRule(_localctx, 12, JavaScriptParser::RuleFromBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::Multiply: {
        setState(187);
        match(JavaScriptParser::Multiply);
        break;
      }

      case JavaScriptParser::OpenBrace:
      case JavaScriptParser::NullLiteral:
      case JavaScriptParser::BooleanLiteral:
      case JavaScriptParser::Break:
      case JavaScriptParser::Do:
      case JavaScriptParser::Instanceof:
      case JavaScriptParser::Typeof:
      case JavaScriptParser::Case:
      case JavaScriptParser::Else:
      case JavaScriptParser::New:
      case JavaScriptParser::Var:
      case JavaScriptParser::Catch:
      case JavaScriptParser::Finally:
      case JavaScriptParser::Return:
      case JavaScriptParser::Void:
      case JavaScriptParser::Continue:
      case JavaScriptParser::For:
      case JavaScriptParser::Switch:
      case JavaScriptParser::While:
      case JavaScriptParser::Debugger:
      case JavaScriptParser::Function:
      case JavaScriptParser::This:
      case JavaScriptParser::With:
      case JavaScriptParser::Default:
      case JavaScriptParser::If:
      case JavaScriptParser::Throw:
      case JavaScriptParser::Delete:
      case JavaScriptParser::In:
      case JavaScriptParser::Try:
      case JavaScriptParser::Class:
      case JavaScriptParser::Enum:
      case JavaScriptParser::Extends:
      case JavaScriptParser::Super:
      case JavaScriptParser::Const:
      case JavaScriptParser::Export:
      case JavaScriptParser::Import:
      case JavaScriptParser::Implements:
      case JavaScriptParser::Let:
      case JavaScriptParser::Private:
      case JavaScriptParser::Public:
      case JavaScriptParser::Interface:
      case JavaScriptParser::Package:
      case JavaScriptParser::Protected:
      case JavaScriptParser::Static:
      case JavaScriptParser::Yield:
      case JavaScriptParser::Identifier: {
        setState(188);
        multipleImportStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(193);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::As) {
      setState(191);
      match(JavaScriptParser::As);
      setState(192);
      identifierName();
    }
    setState(195);
    match(JavaScriptParser::From);
    setState(196);
    match(JavaScriptParser::StringLiteral);
    setState(197);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultipleImportStatementContext ------------------------------------------------------------------

JavaScriptParser::MultipleImportStatementContext::MultipleImportStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::MultipleImportStatementContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

std::vector<JavaScriptParser::IdentifierNameContext *> JavaScriptParser::MultipleImportStatementContext::identifierName() {
  return getRuleContexts<JavaScriptParser::IdentifierNameContext>();
}

JavaScriptParser::IdentifierNameContext* JavaScriptParser::MultipleImportStatementContext::identifierName(size_t i) {
  return getRuleContext<JavaScriptParser::IdentifierNameContext>(i);
}

tree::TerminalNode* JavaScriptParser::MultipleImportStatementContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

std::vector<tree::TerminalNode *> JavaScriptParser::MultipleImportStatementContext::Comma() {
  return getTokens(JavaScriptParser::Comma);
}

tree::TerminalNode* JavaScriptParser::MultipleImportStatementContext::Comma(size_t i) {
  return getToken(JavaScriptParser::Comma, i);
}


size_t JavaScriptParser::MultipleImportStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleMultipleImportStatement;
}

void JavaScriptParser::MultipleImportStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultipleImportStatement(this);
}

void JavaScriptParser::MultipleImportStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultipleImportStatement(this);
}


antlrcpp::Any JavaScriptParser::MultipleImportStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitMultipleImportStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::MultipleImportStatementContext* JavaScriptParser::multipleImportStatement() {
  MultipleImportStatementContext *_localctx = _tracker.createInstance<MultipleImportStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, JavaScriptParser::RuleMultipleImportStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 54) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 54)) & ((1ULL << (JavaScriptParser::NullLiteral - 54))
      | (1ULL << (JavaScriptParser::BooleanLiteral - 54))
      | (1ULL << (JavaScriptParser::Break - 54))
      | (1ULL << (JavaScriptParser::Do - 54))
      | (1ULL << (JavaScriptParser::Instanceof - 54))
      | (1ULL << (JavaScriptParser::Typeof - 54))
      | (1ULL << (JavaScriptParser::Case - 54))
      | (1ULL << (JavaScriptParser::Else - 54))
      | (1ULL << (JavaScriptParser::New - 54))
      | (1ULL << (JavaScriptParser::Var - 54))
      | (1ULL << (JavaScriptParser::Catch - 54))
      | (1ULL << (JavaScriptParser::Finally - 54))
      | (1ULL << (JavaScriptParser::Return - 54))
      | (1ULL << (JavaScriptParser::Void - 54))
      | (1ULL << (JavaScriptParser::Continue - 54))
      | (1ULL << (JavaScriptParser::For - 54))
      | (1ULL << (JavaScriptParser::Switch - 54))
      | (1ULL << (JavaScriptParser::While - 54))
      | (1ULL << (JavaScriptParser::Debugger - 54))
      | (1ULL << (JavaScriptParser::Function - 54))
      | (1ULL << (JavaScriptParser::This - 54))
      | (1ULL << (JavaScriptParser::With - 54))
      | (1ULL << (JavaScriptParser::Default - 54))
      | (1ULL << (JavaScriptParser::If - 54))
      | (1ULL << (JavaScriptParser::Throw - 54))
      | (1ULL << (JavaScriptParser::Delete - 54))
      | (1ULL << (JavaScriptParser::In - 54))
      | (1ULL << (JavaScriptParser::Try - 54))
      | (1ULL << (JavaScriptParser::Class - 54))
      | (1ULL << (JavaScriptParser::Enum - 54))
      | (1ULL << (JavaScriptParser::Extends - 54))
      | (1ULL << (JavaScriptParser::Super - 54))
      | (1ULL << (JavaScriptParser::Const - 54))
      | (1ULL << (JavaScriptParser::Export - 54))
      | (1ULL << (JavaScriptParser::Import - 54))
      | (1ULL << (JavaScriptParser::Implements - 54))
      | (1ULL << (JavaScriptParser::Let - 54))
      | (1ULL << (JavaScriptParser::Private - 54))
      | (1ULL << (JavaScriptParser::Public - 54))
      | (1ULL << (JavaScriptParser::Interface - 54))
      | (1ULL << (JavaScriptParser::Package - 54))
      | (1ULL << (JavaScriptParser::Protected - 54))
      | (1ULL << (JavaScriptParser::Static - 54))
      | (1ULL << (JavaScriptParser::Yield - 54))
      | (1ULL << (JavaScriptParser::Identifier - 54)))) != 0)) {
      setState(199);
      identifierName();
      setState(200);
      match(JavaScriptParser::Comma);
    }
    setState(204);
    match(JavaScriptParser::OpenBrace);
    setState(205);
    identifierName();
    setState(210);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == JavaScriptParser::Comma) {
      setState(206);
      match(JavaScriptParser::Comma);
      setState(207);
      identifierName();
      setState(212);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(213);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExportStatementContext ------------------------------------------------------------------

JavaScriptParser::ExportStatementContext::ExportStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ExportStatementContext::Export() {
  return getToken(JavaScriptParser::Export, 0);
}

JavaScriptParser::FromBlockContext* JavaScriptParser::ExportStatementContext::fromBlock() {
  return getRuleContext<JavaScriptParser::FromBlockContext>(0);
}

JavaScriptParser::StatementContext* JavaScriptParser::ExportStatementContext::statement() {
  return getRuleContext<JavaScriptParser::StatementContext>(0);
}

tree::TerminalNode* JavaScriptParser::ExportStatementContext::Default() {
  return getToken(JavaScriptParser::Default, 0);
}


size_t JavaScriptParser::ExportStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleExportStatement;
}

void JavaScriptParser::ExportStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExportStatement(this);
}

void JavaScriptParser::ExportStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExportStatement(this);
}


antlrcpp::Any JavaScriptParser::ExportStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitExportStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ExportStatementContext* JavaScriptParser::exportStatement() {
  ExportStatementContext *_localctx = _tracker.createInstance<ExportStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, JavaScriptParser::RuleExportStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(JavaScriptParser::Export);
    setState(217);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(216);
      match(JavaScriptParser::Default);
      break;
    }

    }
    setState(221);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(219);
      fromBlock();
      break;
    }

    case 2: {
      setState(220);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableStatementContext ------------------------------------------------------------------

JavaScriptParser::VariableStatementContext::VariableStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaScriptParser::VarModifierContext* JavaScriptParser::VariableStatementContext::varModifier() {
  return getRuleContext<JavaScriptParser::VarModifierContext>(0);
}

JavaScriptParser::VariableDeclarationListContext* JavaScriptParser::VariableStatementContext::variableDeclarationList() {
  return getRuleContext<JavaScriptParser::VariableDeclarationListContext>(0);
}

JavaScriptParser::EosContext* JavaScriptParser::VariableStatementContext::eos() {
  return getRuleContext<JavaScriptParser::EosContext>(0);
}


size_t JavaScriptParser::VariableStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleVariableStatement;
}

void JavaScriptParser::VariableStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableStatement(this);
}

void JavaScriptParser::VariableStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableStatement(this);
}


antlrcpp::Any JavaScriptParser::VariableStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::VariableStatementContext* JavaScriptParser::variableStatement() {
  VariableStatementContext *_localctx = _tracker.createInstance<VariableStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, JavaScriptParser::RuleVariableStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    varModifier();
    setState(224);
    variableDeclarationList();
    setState(225);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationListContext ------------------------------------------------------------------

JavaScriptParser::VariableDeclarationListContext::VariableDeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaScriptParser::VariableDeclarationContext *> JavaScriptParser::VariableDeclarationListContext::variableDeclaration() {
  return getRuleContexts<JavaScriptParser::VariableDeclarationContext>();
}

JavaScriptParser::VariableDeclarationContext* JavaScriptParser::VariableDeclarationListContext::variableDeclaration(size_t i) {
  return getRuleContext<JavaScriptParser::VariableDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> JavaScriptParser::VariableDeclarationListContext::Comma() {
  return getTokens(JavaScriptParser::Comma);
}

tree::TerminalNode* JavaScriptParser::VariableDeclarationListContext::Comma(size_t i) {
  return getToken(JavaScriptParser::Comma, i);
}


size_t JavaScriptParser::VariableDeclarationListContext::getRuleIndex() const {
  return JavaScriptParser::RuleVariableDeclarationList;
}

void JavaScriptParser::VariableDeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclarationList(this);
}

void JavaScriptParser::VariableDeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclarationList(this);
}


antlrcpp::Any JavaScriptParser::VariableDeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationList(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::VariableDeclarationListContext* JavaScriptParser::variableDeclarationList() {
  VariableDeclarationListContext *_localctx = _tracker.createInstance<VariableDeclarationListContext>(_ctx, getState());
  enterRule(_localctx, 20, JavaScriptParser::RuleVariableDeclarationList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(227);
    variableDeclaration();
    setState(232);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(228);
        match(JavaScriptParser::Comma);
        setState(229);
        variableDeclaration(); 
      }
      setState(234);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

JavaScriptParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::VariableDeclarationContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::ArrayLiteralContext* JavaScriptParser::VariableDeclarationContext::arrayLiteral() {
  return getRuleContext<JavaScriptParser::ArrayLiteralContext>(0);
}

JavaScriptParser::ObjectLiteralContext* JavaScriptParser::VariableDeclarationContext::objectLiteral() {
  return getRuleContext<JavaScriptParser::ObjectLiteralContext>(0);
}

tree::TerminalNode* JavaScriptParser::VariableDeclarationContext::Assign() {
  return getToken(JavaScriptParser::Assign, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::VariableDeclarationContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}


size_t JavaScriptParser::VariableDeclarationContext::getRuleIndex() const {
  return JavaScriptParser::RuleVariableDeclaration;
}

void JavaScriptParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void JavaScriptParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}


antlrcpp::Any JavaScriptParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::VariableDeclarationContext* JavaScriptParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 22, JavaScriptParser::RuleVariableDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::Identifier: {
        setState(235);
        match(JavaScriptParser::Identifier);
        break;
      }

      case JavaScriptParser::OpenBracket: {
        setState(236);
        arrayLiteral();
        break;
      }

      case JavaScriptParser::OpenBrace: {
        setState(237);
        objectLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(242);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(240);
      match(JavaScriptParser::Assign);
      setState(241);
      singleExpression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

JavaScriptParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::EmptyStatementContext::SemiColon() {
  return getToken(JavaScriptParser::SemiColon, 0);
}


size_t JavaScriptParser::EmptyStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleEmptyStatement;
}

void JavaScriptParser::EmptyStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyStatement(this);
}

void JavaScriptParser::EmptyStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyStatement(this);
}


antlrcpp::Any JavaScriptParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::EmptyStatementContext* JavaScriptParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, JavaScriptParser::RuleEmptyStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(JavaScriptParser::SemiColon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

JavaScriptParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::ExpressionStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

JavaScriptParser::EosContext* JavaScriptParser::ExpressionStatementContext::eos() {
  return getRuleContext<JavaScriptParser::EosContext>(0);
}


size_t JavaScriptParser::ExpressionStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleExpressionStatement;
}

void JavaScriptParser::ExpressionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStatement(this);
}

void JavaScriptParser::ExpressionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStatement(this);
}


antlrcpp::Any JavaScriptParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ExpressionStatementContext* JavaScriptParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, JavaScriptParser::RuleExpressionStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);

    if (!(this->notOpenBraceAndNotFunction())) throw FailedPredicateException(this, "this->notOpenBraceAndNotFunction()");
    setState(247);
    expressionSequence();
    setState(248);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

JavaScriptParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::IfStatementContext::If() {
  return getToken(JavaScriptParser::If, 0);
}

tree::TerminalNode* JavaScriptParser::IfStatementContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::IfStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* JavaScriptParser::IfStatementContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

std::vector<JavaScriptParser::StatementContext *> JavaScriptParser::IfStatementContext::statement() {
  return getRuleContexts<JavaScriptParser::StatementContext>();
}

JavaScriptParser::StatementContext* JavaScriptParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<JavaScriptParser::StatementContext>(i);
}

tree::TerminalNode* JavaScriptParser::IfStatementContext::Else() {
  return getToken(JavaScriptParser::Else, 0);
}


size_t JavaScriptParser::IfStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleIfStatement;
}

void JavaScriptParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void JavaScriptParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}


antlrcpp::Any JavaScriptParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::IfStatementContext* JavaScriptParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, JavaScriptParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(JavaScriptParser::If);
    setState(251);
    match(JavaScriptParser::OpenParen);
    setState(252);
    expressionSequence();
    setState(253);
    match(JavaScriptParser::CloseParen);
    setState(254);
    statement();
    setState(257);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(255);
      match(JavaScriptParser::Else);
      setState(256);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

JavaScriptParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JavaScriptParser::IterationStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleIterationStatement;
}

void JavaScriptParser::IterationStatementContext::copyFrom(IterationStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DoStatementContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::DoStatementContext::Do() {
  return getToken(JavaScriptParser::Do, 0);
}

JavaScriptParser::StatementContext* JavaScriptParser::DoStatementContext::statement() {
  return getRuleContext<JavaScriptParser::StatementContext>(0);
}

tree::TerminalNode* JavaScriptParser::DoStatementContext::While() {
  return getToken(JavaScriptParser::While, 0);
}

tree::TerminalNode* JavaScriptParser::DoStatementContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::DoStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* JavaScriptParser::DoStatementContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::EosContext* JavaScriptParser::DoStatementContext::eos() {
  return getRuleContext<JavaScriptParser::EosContext>(0);
}

JavaScriptParser::DoStatementContext::DoStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::DoStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoStatement(this);
}
void JavaScriptParser::DoStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoStatement(this);
}

antlrcpp::Any JavaScriptParser::DoStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitDoStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForVarStatementContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::ForVarStatementContext::For() {
  return getToken(JavaScriptParser::For, 0);
}

tree::TerminalNode* JavaScriptParser::ForVarStatementContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

JavaScriptParser::VarModifierContext* JavaScriptParser::ForVarStatementContext::varModifier() {
  return getRuleContext<JavaScriptParser::VarModifierContext>(0);
}

JavaScriptParser::VariableDeclarationListContext* JavaScriptParser::ForVarStatementContext::variableDeclarationList() {
  return getRuleContext<JavaScriptParser::VariableDeclarationListContext>(0);
}

std::vector<tree::TerminalNode *> JavaScriptParser::ForVarStatementContext::SemiColon() {
  return getTokens(JavaScriptParser::SemiColon);
}

tree::TerminalNode* JavaScriptParser::ForVarStatementContext::SemiColon(size_t i) {
  return getToken(JavaScriptParser::SemiColon, i);
}

tree::TerminalNode* JavaScriptParser::ForVarStatementContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::StatementContext* JavaScriptParser::ForVarStatementContext::statement() {
  return getRuleContext<JavaScriptParser::StatementContext>(0);
}

std::vector<JavaScriptParser::ExpressionSequenceContext *> JavaScriptParser::ForVarStatementContext::expressionSequence() {
  return getRuleContexts<JavaScriptParser::ExpressionSequenceContext>();
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::ForVarStatementContext::expressionSequence(size_t i) {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(i);
}

JavaScriptParser::ForVarStatementContext::ForVarStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ForVarStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForVarStatement(this);
}
void JavaScriptParser::ForVarStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForVarStatement(this);
}

antlrcpp::Any JavaScriptParser::ForVarStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitForVarStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForVarInStatementContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::ForVarInStatementContext::For() {
  return getToken(JavaScriptParser::For, 0);
}

tree::TerminalNode* JavaScriptParser::ForVarInStatementContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

JavaScriptParser::VarModifierContext* JavaScriptParser::ForVarInStatementContext::varModifier() {
  return getRuleContext<JavaScriptParser::VarModifierContext>(0);
}

JavaScriptParser::VariableDeclarationContext* JavaScriptParser::ForVarInStatementContext::variableDeclaration() {
  return getRuleContext<JavaScriptParser::VariableDeclarationContext>(0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::ForVarInStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* JavaScriptParser::ForVarInStatementContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::StatementContext* JavaScriptParser::ForVarInStatementContext::statement() {
  return getRuleContext<JavaScriptParser::StatementContext>(0);
}

tree::TerminalNode* JavaScriptParser::ForVarInStatementContext::In() {
  return getToken(JavaScriptParser::In, 0);
}

tree::TerminalNode* JavaScriptParser::ForVarInStatementContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::ForVarInStatementContext::ForVarInStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ForVarInStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForVarInStatement(this);
}
void JavaScriptParser::ForVarInStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForVarInStatement(this);
}

antlrcpp::Any JavaScriptParser::ForVarInStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitForVarInStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStatementContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::WhileStatementContext::While() {
  return getToken(JavaScriptParser::While, 0);
}

tree::TerminalNode* JavaScriptParser::WhileStatementContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::WhileStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* JavaScriptParser::WhileStatementContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::StatementContext* JavaScriptParser::WhileStatementContext::statement() {
  return getRuleContext<JavaScriptParser::StatementContext>(0);
}

JavaScriptParser::WhileStatementContext::WhileStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}
void JavaScriptParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}

antlrcpp::Any JavaScriptParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForStatementContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::ForStatementContext::For() {
  return getToken(JavaScriptParser::For, 0);
}

tree::TerminalNode* JavaScriptParser::ForStatementContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

std::vector<tree::TerminalNode *> JavaScriptParser::ForStatementContext::SemiColon() {
  return getTokens(JavaScriptParser::SemiColon);
}

tree::TerminalNode* JavaScriptParser::ForStatementContext::SemiColon(size_t i) {
  return getToken(JavaScriptParser::SemiColon, i);
}

tree::TerminalNode* JavaScriptParser::ForStatementContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::StatementContext* JavaScriptParser::ForStatementContext::statement() {
  return getRuleContext<JavaScriptParser::StatementContext>(0);
}

std::vector<JavaScriptParser::ExpressionSequenceContext *> JavaScriptParser::ForStatementContext::expressionSequence() {
  return getRuleContexts<JavaScriptParser::ExpressionSequenceContext>();
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::ForStatementContext::expressionSequence(size_t i) {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(i);
}

JavaScriptParser::ForStatementContext::ForStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}
void JavaScriptParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}

antlrcpp::Any JavaScriptParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForInStatementContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::ForInStatementContext::For() {
  return getToken(JavaScriptParser::For, 0);
}

tree::TerminalNode* JavaScriptParser::ForInStatementContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::ForInStatementContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::ForInStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* JavaScriptParser::ForInStatementContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::StatementContext* JavaScriptParser::ForInStatementContext::statement() {
  return getRuleContext<JavaScriptParser::StatementContext>(0);
}

tree::TerminalNode* JavaScriptParser::ForInStatementContext::In() {
  return getToken(JavaScriptParser::In, 0);
}

tree::TerminalNode* JavaScriptParser::ForInStatementContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::ForInStatementContext::ForInStatementContext(IterationStatementContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ForInStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForInStatement(this);
}
void JavaScriptParser::ForInStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForInStatement(this);
}

antlrcpp::Any JavaScriptParser::ForInStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitForInStatement(this);
  else
    return visitor->visitChildren(this);
}
JavaScriptParser::IterationStatementContext* JavaScriptParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, JavaScriptParser::RuleIterationStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(328);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<JavaScriptParser::DoStatementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(259);
      match(JavaScriptParser::Do);
      setState(260);
      statement();
      setState(261);
      match(JavaScriptParser::While);
      setState(262);
      match(JavaScriptParser::OpenParen);
      setState(263);
      expressionSequence();
      setState(264);
      match(JavaScriptParser::CloseParen);
      setState(265);
      eos();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<JavaScriptParser::WhileStatementContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(267);
      match(JavaScriptParser::While);
      setState(268);
      match(JavaScriptParser::OpenParen);
      setState(269);
      expressionSequence();
      setState(270);
      match(JavaScriptParser::CloseParen);
      setState(271);
      statement();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<JavaScriptParser::ForStatementContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(273);
      match(JavaScriptParser::For);
      setState(274);
      match(JavaScriptParser::OpenParen);
      setState(276);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaScriptParser::RegularExpressionLiteral)
        | (1ULL << JavaScriptParser::OpenBracket)
        | (1ULL << JavaScriptParser::OpenParen)
        | (1ULL << JavaScriptParser::OpenBrace)
        | (1ULL << JavaScriptParser::PlusPlus)
        | (1ULL << JavaScriptParser::MinusMinus)
        | (1ULL << JavaScriptParser::Plus)
        | (1ULL << JavaScriptParser::Minus)
        | (1ULL << JavaScriptParser::BitNot)
        | (1ULL << JavaScriptParser::Not)
        | (1ULL << JavaScriptParser::NullLiteral)
        | (1ULL << JavaScriptParser::BooleanLiteral)
        | (1ULL << JavaScriptParser::DecimalLiteral)
        | (1ULL << JavaScriptParser::HexIntegerLiteral)
        | (1ULL << JavaScriptParser::OctalIntegerLiteral)
        | (1ULL << JavaScriptParser::OctalIntegerLiteral2)
        | (1ULL << JavaScriptParser::BinaryIntegerLiteral))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (JavaScriptParser::Typeof - 64))
        | (1ULL << (JavaScriptParser::New - 64))
        | (1ULL << (JavaScriptParser::Void - 64))
        | (1ULL << (JavaScriptParser::Function - 64))
        | (1ULL << (JavaScriptParser::This - 64))
        | (1ULL << (JavaScriptParser::Delete - 64))
        | (1ULL << (JavaScriptParser::Class - 64))
        | (1ULL << (JavaScriptParser::Super - 64))
        | (1ULL << (JavaScriptParser::Yield - 64))
        | (1ULL << (JavaScriptParser::Identifier - 64))
        | (1ULL << (JavaScriptParser::StringLiteral - 64))
        | (1ULL << (JavaScriptParser::TemplateStringLiteral - 64)))) != 0)) {
        setState(275);
        expressionSequence();
      }
      setState(278);
      match(JavaScriptParser::SemiColon);
      setState(280);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaScriptParser::RegularExpressionLiteral)
        | (1ULL << JavaScriptParser::OpenBracket)
        | (1ULL << JavaScriptParser::OpenParen)
        | (1ULL << JavaScriptParser::OpenBrace)
        | (1ULL << JavaScriptParser::PlusPlus)
        | (1ULL << JavaScriptParser::MinusMinus)
        | (1ULL << JavaScriptParser::Plus)
        | (1ULL << JavaScriptParser::Minus)
        | (1ULL << JavaScriptParser::BitNot)
        | (1ULL << JavaScriptParser::Not)
        | (1ULL << JavaScriptParser::NullLiteral)
        | (1ULL << JavaScriptParser::BooleanLiteral)
        | (1ULL << JavaScriptParser::DecimalLiteral)
        | (1ULL << JavaScriptParser::HexIntegerLiteral)
        | (1ULL << JavaScriptParser::OctalIntegerLiteral)
        | (1ULL << JavaScriptParser::OctalIntegerLiteral2)
        | (1ULL << JavaScriptParser::BinaryIntegerLiteral))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (JavaScriptParser::Typeof - 64))
        | (1ULL << (JavaScriptParser::New - 64))
        | (1ULL << (JavaScriptParser::Void - 64))
        | (1ULL << (JavaScriptParser::Function - 64))
        | (1ULL << (JavaScriptParser::This - 64))
        | (1ULL << (JavaScriptParser::Delete - 64))
        | (1ULL << (JavaScriptParser::Class - 64))
        | (1ULL << (JavaScriptParser::Super - 64))
        | (1ULL << (JavaScriptParser::Yield - 64))
        | (1ULL << (JavaScriptParser::Identifier - 64))
        | (1ULL << (JavaScriptParser::StringLiteral - 64))
        | (1ULL << (JavaScriptParser::TemplateStringLiteral - 64)))) != 0)) {
        setState(279);
        expressionSequence();
      }
      setState(282);
      match(JavaScriptParser::SemiColon);
      setState(284);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaScriptParser::RegularExpressionLiteral)
        | (1ULL << JavaScriptParser::OpenBracket)
        | (1ULL << JavaScriptParser::OpenParen)
        | (1ULL << JavaScriptParser::OpenBrace)
        | (1ULL << JavaScriptParser::PlusPlus)
        | (1ULL << JavaScriptParser::MinusMinus)
        | (1ULL << JavaScriptParser::Plus)
        | (1ULL << JavaScriptParser::Minus)
        | (1ULL << JavaScriptParser::BitNot)
        | (1ULL << JavaScriptParser::Not)
        | (1ULL << JavaScriptParser::NullLiteral)
        | (1ULL << JavaScriptParser::BooleanLiteral)
        | (1ULL << JavaScriptParser::DecimalLiteral)
        | (1ULL << JavaScriptParser::HexIntegerLiteral)
        | (1ULL << JavaScriptParser::OctalIntegerLiteral)
        | (1ULL << JavaScriptParser::OctalIntegerLiteral2)
        | (1ULL << JavaScriptParser::BinaryIntegerLiteral))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (JavaScriptParser::Typeof - 64))
        | (1ULL << (JavaScriptParser::New - 64))
        | (1ULL << (JavaScriptParser::Void - 64))
        | (1ULL << (JavaScriptParser::Function - 64))
        | (1ULL << (JavaScriptParser::This - 64))
        | (1ULL << (JavaScriptParser::Delete - 64))
        | (1ULL << (JavaScriptParser::Class - 64))
        | (1ULL << (JavaScriptParser::Super - 64))
        | (1ULL << (JavaScriptParser::Yield - 64))
        | (1ULL << (JavaScriptParser::Identifier - 64))
        | (1ULL << (JavaScriptParser::StringLiteral - 64))
        | (1ULL << (JavaScriptParser::TemplateStringLiteral - 64)))) != 0)) {
        setState(283);
        expressionSequence();
      }
      setState(286);
      match(JavaScriptParser::CloseParen);
      setState(287);
      statement();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<JavaScriptParser::ForVarStatementContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(288);
      match(JavaScriptParser::For);
      setState(289);
      match(JavaScriptParser::OpenParen);
      setState(290);
      varModifier();
      setState(291);
      variableDeclarationList();
      setState(292);
      match(JavaScriptParser::SemiColon);
      setState(294);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaScriptParser::RegularExpressionLiteral)
        | (1ULL << JavaScriptParser::OpenBracket)
        | (1ULL << JavaScriptParser::OpenParen)
        | (1ULL << JavaScriptParser::OpenBrace)
        | (1ULL << JavaScriptParser::PlusPlus)
        | (1ULL << JavaScriptParser::MinusMinus)
        | (1ULL << JavaScriptParser::Plus)
        | (1ULL << JavaScriptParser::Minus)
        | (1ULL << JavaScriptParser::BitNot)
        | (1ULL << JavaScriptParser::Not)
        | (1ULL << JavaScriptParser::NullLiteral)
        | (1ULL << JavaScriptParser::BooleanLiteral)
        | (1ULL << JavaScriptParser::DecimalLiteral)
        | (1ULL << JavaScriptParser::HexIntegerLiteral)
        | (1ULL << JavaScriptParser::OctalIntegerLiteral)
        | (1ULL << JavaScriptParser::OctalIntegerLiteral2)
        | (1ULL << JavaScriptParser::BinaryIntegerLiteral))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (JavaScriptParser::Typeof - 64))
        | (1ULL << (JavaScriptParser::New - 64))
        | (1ULL << (JavaScriptParser::Void - 64))
        | (1ULL << (JavaScriptParser::Function - 64))
        | (1ULL << (JavaScriptParser::This - 64))
        | (1ULL << (JavaScriptParser::Delete - 64))
        | (1ULL << (JavaScriptParser::Class - 64))
        | (1ULL << (JavaScriptParser::Super - 64))
        | (1ULL << (JavaScriptParser::Yield - 64))
        | (1ULL << (JavaScriptParser::Identifier - 64))
        | (1ULL << (JavaScriptParser::StringLiteral - 64))
        | (1ULL << (JavaScriptParser::TemplateStringLiteral - 64)))) != 0)) {
        setState(293);
        expressionSequence();
      }
      setState(296);
      match(JavaScriptParser::SemiColon);
      setState(298);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaScriptParser::RegularExpressionLiteral)
        | (1ULL << JavaScriptParser::OpenBracket)
        | (1ULL << JavaScriptParser::OpenParen)
        | (1ULL << JavaScriptParser::OpenBrace)
        | (1ULL << JavaScriptParser::PlusPlus)
        | (1ULL << JavaScriptParser::MinusMinus)
        | (1ULL << JavaScriptParser::Plus)
        | (1ULL << JavaScriptParser::Minus)
        | (1ULL << JavaScriptParser::BitNot)
        | (1ULL << JavaScriptParser::Not)
        | (1ULL << JavaScriptParser::NullLiteral)
        | (1ULL << JavaScriptParser::BooleanLiteral)
        | (1ULL << JavaScriptParser::DecimalLiteral)
        | (1ULL << JavaScriptParser::HexIntegerLiteral)
        | (1ULL << JavaScriptParser::OctalIntegerLiteral)
        | (1ULL << JavaScriptParser::OctalIntegerLiteral2)
        | (1ULL << JavaScriptParser::BinaryIntegerLiteral))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (JavaScriptParser::Typeof - 64))
        | (1ULL << (JavaScriptParser::New - 64))
        | (1ULL << (JavaScriptParser::Void - 64))
        | (1ULL << (JavaScriptParser::Function - 64))
        | (1ULL << (JavaScriptParser::This - 64))
        | (1ULL << (JavaScriptParser::Delete - 64))
        | (1ULL << (JavaScriptParser::Class - 64))
        | (1ULL << (JavaScriptParser::Super - 64))
        | (1ULL << (JavaScriptParser::Yield - 64))
        | (1ULL << (JavaScriptParser::Identifier - 64))
        | (1ULL << (JavaScriptParser::StringLiteral - 64))
        | (1ULL << (JavaScriptParser::TemplateStringLiteral - 64)))) != 0)) {
        setState(297);
        expressionSequence();
      }
      setState(300);
      match(JavaScriptParser::CloseParen);
      setState(301);
      statement();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<JavaScriptParser::ForInStatementContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(303);
      match(JavaScriptParser::For);
      setState(304);
      match(JavaScriptParser::OpenParen);
      setState(305);
      singleExpression(0);
      setState(309);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case JavaScriptParser::In: {
          setState(306);
          match(JavaScriptParser::In);
          break;
        }

        case JavaScriptParser::Identifier: {
          setState(307);
          match(JavaScriptParser::Identifier);
          setState(308);

          if (!(this->p("of"))) throw FailedPredicateException(this, "this->p(\"of\")");
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(311);
      expressionSequence();
      setState(312);
      match(JavaScriptParser::CloseParen);
      setState(313);
      statement();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<IterationStatementContext *>(_tracker.createInstance<JavaScriptParser::ForVarInStatementContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(315);
      match(JavaScriptParser::For);
      setState(316);
      match(JavaScriptParser::OpenParen);
      setState(317);
      varModifier();
      setState(318);
      variableDeclaration();
      setState(322);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case JavaScriptParser::In: {
          setState(319);
          match(JavaScriptParser::In);
          break;
        }

        case JavaScriptParser::Identifier: {
          setState(320);
          match(JavaScriptParser::Identifier);
          setState(321);

          if (!(this->p("of"))) throw FailedPredicateException(this, "this->p(\"of\")");
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(324);
      expressionSequence();
      setState(325);
      match(JavaScriptParser::CloseParen);
      setState(326);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarModifierContext ------------------------------------------------------------------

JavaScriptParser::VarModifierContext::VarModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::VarModifierContext::Var() {
  return getToken(JavaScriptParser::Var, 0);
}

tree::TerminalNode* JavaScriptParser::VarModifierContext::Let() {
  return getToken(JavaScriptParser::Let, 0);
}

tree::TerminalNode* JavaScriptParser::VarModifierContext::Const() {
  return getToken(JavaScriptParser::Const, 0);
}


size_t JavaScriptParser::VarModifierContext::getRuleIndex() const {
  return JavaScriptParser::RuleVarModifier;
}

void JavaScriptParser::VarModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarModifier(this);
}

void JavaScriptParser::VarModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarModifier(this);
}


antlrcpp::Any JavaScriptParser::VarModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitVarModifier(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::VarModifierContext* JavaScriptParser::varModifier() {
  VarModifierContext *_localctx = _tracker.createInstance<VarModifierContext>(_ctx, getState());
  enterRule(_localctx, 32, JavaScriptParser::RuleVarModifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    _la = _input->LA(1);
    if (!(((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (JavaScriptParser::Var - 68))
      | (1ULL << (JavaScriptParser::Const - 68))
      | (1ULL << (JavaScriptParser::Let - 68)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

JavaScriptParser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ContinueStatementContext::Continue() {
  return getToken(JavaScriptParser::Continue, 0);
}

JavaScriptParser::EosContext* JavaScriptParser::ContinueStatementContext::eos() {
  return getRuleContext<JavaScriptParser::EosContext>(0);
}

tree::TerminalNode* JavaScriptParser::ContinueStatementContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}


size_t JavaScriptParser::ContinueStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleContinueStatement;
}

void JavaScriptParser::ContinueStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStatement(this);
}

void JavaScriptParser::ContinueStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStatement(this);
}


antlrcpp::Any JavaScriptParser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ContinueStatementContext* JavaScriptParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, JavaScriptParser::RuleContinueStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    match(JavaScriptParser::Continue);
    setState(335);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(333);

      if (!(this->notLineTerminator())) throw FailedPredicateException(this, "this->notLineTerminator()");
      setState(334);
      match(JavaScriptParser::Identifier);
      break;
    }

    }
    setState(337);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

JavaScriptParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::BreakStatementContext::Break() {
  return getToken(JavaScriptParser::Break, 0);
}

JavaScriptParser::EosContext* JavaScriptParser::BreakStatementContext::eos() {
  return getRuleContext<JavaScriptParser::EosContext>(0);
}

tree::TerminalNode* JavaScriptParser::BreakStatementContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}


size_t JavaScriptParser::BreakStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleBreakStatement;
}

void JavaScriptParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void JavaScriptParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}


antlrcpp::Any JavaScriptParser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::BreakStatementContext* JavaScriptParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, JavaScriptParser::RuleBreakStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    match(JavaScriptParser::Break);
    setState(342);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(340);

      if (!(this->notLineTerminator())) throw FailedPredicateException(this, "this->notLineTerminator()");
      setState(341);
      match(JavaScriptParser::Identifier);
      break;
    }

    }
    setState(344);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

JavaScriptParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ReturnStatementContext::Return() {
  return getToken(JavaScriptParser::Return, 0);
}

JavaScriptParser::EosContext* JavaScriptParser::ReturnStatementContext::eos() {
  return getRuleContext<JavaScriptParser::EosContext>(0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::ReturnStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}


size_t JavaScriptParser::ReturnStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleReturnStatement;
}

void JavaScriptParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void JavaScriptParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


antlrcpp::Any JavaScriptParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ReturnStatementContext* JavaScriptParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, JavaScriptParser::RuleReturnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    match(JavaScriptParser::Return);
    setState(349);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(347);

      if (!(this->notLineTerminator())) throw FailedPredicateException(this, "this->notLineTerminator()");
      setState(348);
      expressionSequence();
      break;
    }

    }
    setState(351);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- YieldStatementContext ------------------------------------------------------------------

JavaScriptParser::YieldStatementContext::YieldStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::YieldStatementContext::Yield() {
  return getToken(JavaScriptParser::Yield, 0);
}

JavaScriptParser::EosContext* JavaScriptParser::YieldStatementContext::eos() {
  return getRuleContext<JavaScriptParser::EosContext>(0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::YieldStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}


size_t JavaScriptParser::YieldStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleYieldStatement;
}

void JavaScriptParser::YieldStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterYieldStatement(this);
}

void JavaScriptParser::YieldStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitYieldStatement(this);
}


antlrcpp::Any JavaScriptParser::YieldStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitYieldStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::YieldStatementContext* JavaScriptParser::yieldStatement() {
  YieldStatementContext *_localctx = _tracker.createInstance<YieldStatementContext>(_ctx, getState());
  enterRule(_localctx, 40, JavaScriptParser::RuleYieldStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    match(JavaScriptParser::Yield);
    setState(356);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(354);

      if (!(this->notLineTerminator())) throw FailedPredicateException(this, "this->notLineTerminator()");
      setState(355);
      expressionSequence();
      break;
    }

    }
    setState(358);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithStatementContext ------------------------------------------------------------------

JavaScriptParser::WithStatementContext::WithStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::WithStatementContext::With() {
  return getToken(JavaScriptParser::With, 0);
}

tree::TerminalNode* JavaScriptParser::WithStatementContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::WithStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* JavaScriptParser::WithStatementContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::StatementContext* JavaScriptParser::WithStatementContext::statement() {
  return getRuleContext<JavaScriptParser::StatementContext>(0);
}


size_t JavaScriptParser::WithStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleWithStatement;
}

void JavaScriptParser::WithStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithStatement(this);
}

void JavaScriptParser::WithStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithStatement(this);
}


antlrcpp::Any JavaScriptParser::WithStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitWithStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::WithStatementContext* JavaScriptParser::withStatement() {
  WithStatementContext *_localctx = _tracker.createInstance<WithStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, JavaScriptParser::RuleWithStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
    match(JavaScriptParser::With);
    setState(361);
    match(JavaScriptParser::OpenParen);
    setState(362);
    expressionSequence();
    setState(363);
    match(JavaScriptParser::CloseParen);
    setState(364);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchStatementContext ------------------------------------------------------------------

JavaScriptParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::SwitchStatementContext::Switch() {
  return getToken(JavaScriptParser::Switch, 0);
}

tree::TerminalNode* JavaScriptParser::SwitchStatementContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::SwitchStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* JavaScriptParser::SwitchStatementContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::CaseBlockContext* JavaScriptParser::SwitchStatementContext::caseBlock() {
  return getRuleContext<JavaScriptParser::CaseBlockContext>(0);
}


size_t JavaScriptParser::SwitchStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleSwitchStatement;
}

void JavaScriptParser::SwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStatement(this);
}

void JavaScriptParser::SwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStatement(this);
}


antlrcpp::Any JavaScriptParser::SwitchStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitSwitchStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::SwitchStatementContext* JavaScriptParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 44, JavaScriptParser::RuleSwitchStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(366);
    match(JavaScriptParser::Switch);
    setState(367);
    match(JavaScriptParser::OpenParen);
    setState(368);
    expressionSequence();
    setState(369);
    match(JavaScriptParser::CloseParen);
    setState(370);
    caseBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseBlockContext ------------------------------------------------------------------

JavaScriptParser::CaseBlockContext::CaseBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::CaseBlockContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

tree::TerminalNode* JavaScriptParser::CaseBlockContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

std::vector<JavaScriptParser::CaseClausesContext *> JavaScriptParser::CaseBlockContext::caseClauses() {
  return getRuleContexts<JavaScriptParser::CaseClausesContext>();
}

JavaScriptParser::CaseClausesContext* JavaScriptParser::CaseBlockContext::caseClauses(size_t i) {
  return getRuleContext<JavaScriptParser::CaseClausesContext>(i);
}

JavaScriptParser::DefaultClauseContext* JavaScriptParser::CaseBlockContext::defaultClause() {
  return getRuleContext<JavaScriptParser::DefaultClauseContext>(0);
}


size_t JavaScriptParser::CaseBlockContext::getRuleIndex() const {
  return JavaScriptParser::RuleCaseBlock;
}

void JavaScriptParser::CaseBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseBlock(this);
}

void JavaScriptParser::CaseBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseBlock(this);
}


antlrcpp::Any JavaScriptParser::CaseBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitCaseBlock(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::CaseBlockContext* JavaScriptParser::caseBlock() {
  CaseBlockContext *_localctx = _tracker.createInstance<CaseBlockContext>(_ctx, getState());
  enterRule(_localctx, 46, JavaScriptParser::RuleCaseBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    match(JavaScriptParser::OpenBrace);
    setState(374);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::Case) {
      setState(373);
      caseClauses();
    }
    setState(380);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::Default) {
      setState(376);
      defaultClause();
      setState(378);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JavaScriptParser::Case) {
        setState(377);
        caseClauses();
      }
    }
    setState(382);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseClausesContext ------------------------------------------------------------------

JavaScriptParser::CaseClausesContext::CaseClausesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaScriptParser::CaseClauseContext *> JavaScriptParser::CaseClausesContext::caseClause() {
  return getRuleContexts<JavaScriptParser::CaseClauseContext>();
}

JavaScriptParser::CaseClauseContext* JavaScriptParser::CaseClausesContext::caseClause(size_t i) {
  return getRuleContext<JavaScriptParser::CaseClauseContext>(i);
}


size_t JavaScriptParser::CaseClausesContext::getRuleIndex() const {
  return JavaScriptParser::RuleCaseClauses;
}

void JavaScriptParser::CaseClausesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseClauses(this);
}

void JavaScriptParser::CaseClausesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseClauses(this);
}


antlrcpp::Any JavaScriptParser::CaseClausesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitCaseClauses(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::CaseClausesContext* JavaScriptParser::caseClauses() {
  CaseClausesContext *_localctx = _tracker.createInstance<CaseClausesContext>(_ctx, getState());
  enterRule(_localctx, 48, JavaScriptParser::RuleCaseClauses);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(385); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(384);
      caseClause();
      setState(387); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == JavaScriptParser::Case);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseClauseContext ------------------------------------------------------------------

JavaScriptParser::CaseClauseContext::CaseClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::CaseClauseContext::Case() {
  return getToken(JavaScriptParser::Case, 0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::CaseClauseContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* JavaScriptParser::CaseClauseContext::Colon() {
  return getToken(JavaScriptParser::Colon, 0);
}

JavaScriptParser::StatementListContext* JavaScriptParser::CaseClauseContext::statementList() {
  return getRuleContext<JavaScriptParser::StatementListContext>(0);
}


size_t JavaScriptParser::CaseClauseContext::getRuleIndex() const {
  return JavaScriptParser::RuleCaseClause;
}

void JavaScriptParser::CaseClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseClause(this);
}

void JavaScriptParser::CaseClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseClause(this);
}


antlrcpp::Any JavaScriptParser::CaseClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitCaseClause(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::CaseClauseContext* JavaScriptParser::caseClause() {
  CaseClauseContext *_localctx = _tracker.createInstance<CaseClauseContext>(_ctx, getState());
  enterRule(_localctx, 50, JavaScriptParser::RuleCaseClause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    match(JavaScriptParser::Case);
    setState(390);
    expressionSequence();
    setState(391);
    match(JavaScriptParser::Colon);
    setState(393);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(392);
      statementList();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefaultClauseContext ------------------------------------------------------------------

JavaScriptParser::DefaultClauseContext::DefaultClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::DefaultClauseContext::Default() {
  return getToken(JavaScriptParser::Default, 0);
}

tree::TerminalNode* JavaScriptParser::DefaultClauseContext::Colon() {
  return getToken(JavaScriptParser::Colon, 0);
}

JavaScriptParser::StatementListContext* JavaScriptParser::DefaultClauseContext::statementList() {
  return getRuleContext<JavaScriptParser::StatementListContext>(0);
}


size_t JavaScriptParser::DefaultClauseContext::getRuleIndex() const {
  return JavaScriptParser::RuleDefaultClause;
}

void JavaScriptParser::DefaultClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultClause(this);
}

void JavaScriptParser::DefaultClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultClause(this);
}


antlrcpp::Any JavaScriptParser::DefaultClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitDefaultClause(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::DefaultClauseContext* JavaScriptParser::defaultClause() {
  DefaultClauseContext *_localctx = _tracker.createInstance<DefaultClauseContext>(_ctx, getState());
  enterRule(_localctx, 52, JavaScriptParser::RuleDefaultClause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    match(JavaScriptParser::Default);
    setState(396);
    match(JavaScriptParser::Colon);
    setState(398);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(397);
      statementList();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelledStatementContext ------------------------------------------------------------------

JavaScriptParser::LabelledStatementContext::LabelledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::LabelledStatementContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

tree::TerminalNode* JavaScriptParser::LabelledStatementContext::Colon() {
  return getToken(JavaScriptParser::Colon, 0);
}

JavaScriptParser::StatementContext* JavaScriptParser::LabelledStatementContext::statement() {
  return getRuleContext<JavaScriptParser::StatementContext>(0);
}


size_t JavaScriptParser::LabelledStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleLabelledStatement;
}

void JavaScriptParser::LabelledStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabelledStatement(this);
}

void JavaScriptParser::LabelledStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabelledStatement(this);
}


antlrcpp::Any JavaScriptParser::LabelledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitLabelledStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::LabelledStatementContext* JavaScriptParser::labelledStatement() {
  LabelledStatementContext *_localctx = _tracker.createInstance<LabelledStatementContext>(_ctx, getState());
  enterRule(_localctx, 54, JavaScriptParser::RuleLabelledStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(400);
    match(JavaScriptParser::Identifier);
    setState(401);
    match(JavaScriptParser::Colon);
    setState(402);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThrowStatementContext ------------------------------------------------------------------

JavaScriptParser::ThrowStatementContext::ThrowStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ThrowStatementContext::Throw() {
  return getToken(JavaScriptParser::Throw, 0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::ThrowStatementContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

JavaScriptParser::EosContext* JavaScriptParser::ThrowStatementContext::eos() {
  return getRuleContext<JavaScriptParser::EosContext>(0);
}


size_t JavaScriptParser::ThrowStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleThrowStatement;
}

void JavaScriptParser::ThrowStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThrowStatement(this);
}

void JavaScriptParser::ThrowStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThrowStatement(this);
}


antlrcpp::Any JavaScriptParser::ThrowStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitThrowStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ThrowStatementContext* JavaScriptParser::throwStatement() {
  ThrowStatementContext *_localctx = _tracker.createInstance<ThrowStatementContext>(_ctx, getState());
  enterRule(_localctx, 56, JavaScriptParser::RuleThrowStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    match(JavaScriptParser::Throw);
    setState(405);

    if (!(this->notLineTerminator())) throw FailedPredicateException(this, "this->notLineTerminator()");
    setState(406);
    expressionSequence();
    setState(407);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TryStatementContext ------------------------------------------------------------------

JavaScriptParser::TryStatementContext::TryStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::TryStatementContext::Try() {
  return getToken(JavaScriptParser::Try, 0);
}

JavaScriptParser::BlockContext* JavaScriptParser::TryStatementContext::block() {
  return getRuleContext<JavaScriptParser::BlockContext>(0);
}

JavaScriptParser::CatchProductionContext* JavaScriptParser::TryStatementContext::catchProduction() {
  return getRuleContext<JavaScriptParser::CatchProductionContext>(0);
}

JavaScriptParser::FinallyProductionContext* JavaScriptParser::TryStatementContext::finallyProduction() {
  return getRuleContext<JavaScriptParser::FinallyProductionContext>(0);
}


size_t JavaScriptParser::TryStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleTryStatement;
}

void JavaScriptParser::TryStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTryStatement(this);
}

void JavaScriptParser::TryStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTryStatement(this);
}


antlrcpp::Any JavaScriptParser::TryStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitTryStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::TryStatementContext* JavaScriptParser::tryStatement() {
  TryStatementContext *_localctx = _tracker.createInstance<TryStatementContext>(_ctx, getState());
  enterRule(_localctx, 58, JavaScriptParser::RuleTryStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    match(JavaScriptParser::Try);
    setState(410);
    block();
    setState(416);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::Catch: {
        setState(411);
        catchProduction();
        setState(413);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
        case 1: {
          setState(412);
          finallyProduction();
          break;
        }

        }
        break;
      }

      case JavaScriptParser::Finally: {
        setState(415);
        finallyProduction();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchProductionContext ------------------------------------------------------------------

JavaScriptParser::CatchProductionContext::CatchProductionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::CatchProductionContext::Catch() {
  return getToken(JavaScriptParser::Catch, 0);
}

tree::TerminalNode* JavaScriptParser::CatchProductionContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::CatchProductionContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

tree::TerminalNode* JavaScriptParser::CatchProductionContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::BlockContext* JavaScriptParser::CatchProductionContext::block() {
  return getRuleContext<JavaScriptParser::BlockContext>(0);
}


size_t JavaScriptParser::CatchProductionContext::getRuleIndex() const {
  return JavaScriptParser::RuleCatchProduction;
}

void JavaScriptParser::CatchProductionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatchProduction(this);
}

void JavaScriptParser::CatchProductionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatchProduction(this);
}


antlrcpp::Any JavaScriptParser::CatchProductionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitCatchProduction(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::CatchProductionContext* JavaScriptParser::catchProduction() {
  CatchProductionContext *_localctx = _tracker.createInstance<CatchProductionContext>(_ctx, getState());
  enterRule(_localctx, 60, JavaScriptParser::RuleCatchProduction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    match(JavaScriptParser::Catch);
    setState(419);
    match(JavaScriptParser::OpenParen);
    setState(420);
    match(JavaScriptParser::Identifier);
    setState(421);
    match(JavaScriptParser::CloseParen);
    setState(422);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FinallyProductionContext ------------------------------------------------------------------

JavaScriptParser::FinallyProductionContext::FinallyProductionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::FinallyProductionContext::Finally() {
  return getToken(JavaScriptParser::Finally, 0);
}

JavaScriptParser::BlockContext* JavaScriptParser::FinallyProductionContext::block() {
  return getRuleContext<JavaScriptParser::BlockContext>(0);
}


size_t JavaScriptParser::FinallyProductionContext::getRuleIndex() const {
  return JavaScriptParser::RuleFinallyProduction;
}

void JavaScriptParser::FinallyProductionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFinallyProduction(this);
}

void JavaScriptParser::FinallyProductionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFinallyProduction(this);
}


antlrcpp::Any JavaScriptParser::FinallyProductionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitFinallyProduction(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::FinallyProductionContext* JavaScriptParser::finallyProduction() {
  FinallyProductionContext *_localctx = _tracker.createInstance<FinallyProductionContext>(_ctx, getState());
  enterRule(_localctx, 62, JavaScriptParser::RuleFinallyProduction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    match(JavaScriptParser::Finally);
    setState(425);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DebuggerStatementContext ------------------------------------------------------------------

JavaScriptParser::DebuggerStatementContext::DebuggerStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::DebuggerStatementContext::Debugger() {
  return getToken(JavaScriptParser::Debugger, 0);
}

JavaScriptParser::EosContext* JavaScriptParser::DebuggerStatementContext::eos() {
  return getRuleContext<JavaScriptParser::EosContext>(0);
}


size_t JavaScriptParser::DebuggerStatementContext::getRuleIndex() const {
  return JavaScriptParser::RuleDebuggerStatement;
}

void JavaScriptParser::DebuggerStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDebuggerStatement(this);
}

void JavaScriptParser::DebuggerStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDebuggerStatement(this);
}


antlrcpp::Any JavaScriptParser::DebuggerStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitDebuggerStatement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::DebuggerStatementContext* JavaScriptParser::debuggerStatement() {
  DebuggerStatementContext *_localctx = _tracker.createInstance<DebuggerStatementContext>(_ctx, getState());
  enterRule(_localctx, 64, JavaScriptParser::RuleDebuggerStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(427);
    match(JavaScriptParser::Debugger);
    setState(428);
    eos();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

JavaScriptParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::FunctionDeclarationContext::Function() {
  return getToken(JavaScriptParser::Function, 0);
}

tree::TerminalNode* JavaScriptParser::FunctionDeclarationContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

tree::TerminalNode* JavaScriptParser::FunctionDeclarationContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::FunctionDeclarationContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

tree::TerminalNode* JavaScriptParser::FunctionDeclarationContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

JavaScriptParser::FunctionBodyContext* JavaScriptParser::FunctionDeclarationContext::functionBody() {
  return getRuleContext<JavaScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* JavaScriptParser::FunctionDeclarationContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

JavaScriptParser::FormalParameterListContext* JavaScriptParser::FunctionDeclarationContext::formalParameterList() {
  return getRuleContext<JavaScriptParser::FormalParameterListContext>(0);
}


size_t JavaScriptParser::FunctionDeclarationContext::getRuleIndex() const {
  return JavaScriptParser::RuleFunctionDeclaration;
}

void JavaScriptParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void JavaScriptParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}


antlrcpp::Any JavaScriptParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::FunctionDeclarationContext* JavaScriptParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 66, JavaScriptParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(430);
    match(JavaScriptParser::Function);
    setState(431);
    match(JavaScriptParser::Identifier);
    setState(432);
    match(JavaScriptParser::OpenParen);
    setState(434);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaScriptParser::OpenBracket)
      | (1ULL << JavaScriptParser::OpenBrace)
      | (1ULL << JavaScriptParser::Ellipsis))) != 0) || _la == JavaScriptParser::Identifier) {
      setState(433);
      formalParameterList();
    }
    setState(436);
    match(JavaScriptParser::CloseParen);
    setState(437);
    match(JavaScriptParser::OpenBrace);
    setState(438);
    functionBody();
    setState(439);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDeclarationContext ------------------------------------------------------------------

JavaScriptParser::ClassDeclarationContext::ClassDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ClassDeclarationContext::Class() {
  return getToken(JavaScriptParser::Class, 0);
}

tree::TerminalNode* JavaScriptParser::ClassDeclarationContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::ClassTailContext* JavaScriptParser::ClassDeclarationContext::classTail() {
  return getRuleContext<JavaScriptParser::ClassTailContext>(0);
}


size_t JavaScriptParser::ClassDeclarationContext::getRuleIndex() const {
  return JavaScriptParser::RuleClassDeclaration;
}

void JavaScriptParser::ClassDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDeclaration(this);
}

void JavaScriptParser::ClassDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDeclaration(this);
}


antlrcpp::Any JavaScriptParser::ClassDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitClassDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ClassDeclarationContext* JavaScriptParser::classDeclaration() {
  ClassDeclarationContext *_localctx = _tracker.createInstance<ClassDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 68, JavaScriptParser::RuleClassDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(441);
    match(JavaScriptParser::Class);
    setState(442);
    match(JavaScriptParser::Identifier);
    setState(443);
    classTail();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassTailContext ------------------------------------------------------------------

JavaScriptParser::ClassTailContext::ClassTailContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ClassTailContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

tree::TerminalNode* JavaScriptParser::ClassTailContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

tree::TerminalNode* JavaScriptParser::ClassTailContext::Extends() {
  return getToken(JavaScriptParser::Extends, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::ClassTailContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

std::vector<JavaScriptParser::ClassElementContext *> JavaScriptParser::ClassTailContext::classElement() {
  return getRuleContexts<JavaScriptParser::ClassElementContext>();
}

JavaScriptParser::ClassElementContext* JavaScriptParser::ClassTailContext::classElement(size_t i) {
  return getRuleContext<JavaScriptParser::ClassElementContext>(i);
}


size_t JavaScriptParser::ClassTailContext::getRuleIndex() const {
  return JavaScriptParser::RuleClassTail;
}

void JavaScriptParser::ClassTailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassTail(this);
}

void JavaScriptParser::ClassTailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassTail(this);
}


antlrcpp::Any JavaScriptParser::ClassTailContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitClassTail(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ClassTailContext* JavaScriptParser::classTail() {
  ClassTailContext *_localctx = _tracker.createInstance<ClassTailContext>(_ctx, getState());
  enterRule(_localctx, 70, JavaScriptParser::RuleClassTail);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(447);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::Extends) {
      setState(445);
      match(JavaScriptParser::Extends);
      setState(446);
      singleExpression(0);
    }
    setState(449);
    match(JavaScriptParser::OpenBrace);
    setState(453);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(450);
        classElement(); 
      }
      setState(455);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    }
    setState(456);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassElementContext ------------------------------------------------------------------

JavaScriptParser::ClassElementContext::ClassElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaScriptParser::MethodDefinitionContext* JavaScriptParser::ClassElementContext::methodDefinition() {
  return getRuleContext<JavaScriptParser::MethodDefinitionContext>(0);
}

tree::TerminalNode* JavaScriptParser::ClassElementContext::Static() {
  return getToken(JavaScriptParser::Static, 0);
}

tree::TerminalNode* JavaScriptParser::ClassElementContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::EmptyStatementContext* JavaScriptParser::ClassElementContext::emptyStatement() {
  return getRuleContext<JavaScriptParser::EmptyStatementContext>(0);
}


size_t JavaScriptParser::ClassElementContext::getRuleIndex() const {
  return JavaScriptParser::RuleClassElement;
}

void JavaScriptParser::ClassElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassElement(this);
}

void JavaScriptParser::ClassElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassElement(this);
}


antlrcpp::Any JavaScriptParser::ClassElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitClassElement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ClassElementContext* JavaScriptParser::classElement() {
  ClassElementContext *_localctx = _tracker.createInstance<ClassElementContext>(_ctx, getState());
  enterRule(_localctx, 72, JavaScriptParser::RuleClassElement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(465);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(461);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
      case 1: {
        setState(458);
        match(JavaScriptParser::Static);
        break;
      }

      case 2: {
        setState(459);

        if (!(this->n("static"))) throw FailedPredicateException(this, "this->n(\"static\")");
        setState(460);
        match(JavaScriptParser::Identifier);
        break;
      }

      }
      setState(463);
      methodDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(464);
      emptyStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDefinitionContext ------------------------------------------------------------------

JavaScriptParser::MethodDefinitionContext::MethodDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaScriptParser::PropertyNameContext* JavaScriptParser::MethodDefinitionContext::propertyName() {
  return getRuleContext<JavaScriptParser::PropertyNameContext>(0);
}

tree::TerminalNode* JavaScriptParser::MethodDefinitionContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::MethodDefinitionContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

tree::TerminalNode* JavaScriptParser::MethodDefinitionContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

JavaScriptParser::FunctionBodyContext* JavaScriptParser::MethodDefinitionContext::functionBody() {
  return getRuleContext<JavaScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* JavaScriptParser::MethodDefinitionContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

JavaScriptParser::FormalParameterListContext* JavaScriptParser::MethodDefinitionContext::formalParameterList() {
  return getRuleContext<JavaScriptParser::FormalParameterListContext>(0);
}

JavaScriptParser::GetterContext* JavaScriptParser::MethodDefinitionContext::getter() {
  return getRuleContext<JavaScriptParser::GetterContext>(0);
}

JavaScriptParser::SetterContext* JavaScriptParser::MethodDefinitionContext::setter() {
  return getRuleContext<JavaScriptParser::SetterContext>(0);
}

JavaScriptParser::GeneratorMethodContext* JavaScriptParser::MethodDefinitionContext::generatorMethod() {
  return getRuleContext<JavaScriptParser::GeneratorMethodContext>(0);
}


size_t JavaScriptParser::MethodDefinitionContext::getRuleIndex() const {
  return JavaScriptParser::RuleMethodDefinition;
}

void JavaScriptParser::MethodDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDefinition(this);
}

void JavaScriptParser::MethodDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDefinition(this);
}


antlrcpp::Any JavaScriptParser::MethodDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitMethodDefinition(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::MethodDefinitionContext* JavaScriptParser::methodDefinition() {
  MethodDefinitionContext *_localctx = _tracker.createInstance<MethodDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 74, JavaScriptParser::RuleMethodDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(495);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(467);
      propertyName();
      setState(468);
      match(JavaScriptParser::OpenParen);
      setState(470);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaScriptParser::OpenBracket)
        | (1ULL << JavaScriptParser::OpenBrace)
        | (1ULL << JavaScriptParser::Ellipsis))) != 0) || _la == JavaScriptParser::Identifier) {
        setState(469);
        formalParameterList();
      }
      setState(472);
      match(JavaScriptParser::CloseParen);
      setState(473);
      match(JavaScriptParser::OpenBrace);
      setState(474);
      functionBody();
      setState(475);
      match(JavaScriptParser::CloseBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(477);
      getter();
      setState(478);
      match(JavaScriptParser::OpenParen);
      setState(479);
      match(JavaScriptParser::CloseParen);
      setState(480);
      match(JavaScriptParser::OpenBrace);
      setState(481);
      functionBody();
      setState(482);
      match(JavaScriptParser::CloseBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(484);
      setter();
      setState(485);
      match(JavaScriptParser::OpenParen);
      setState(487);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaScriptParser::OpenBracket)
        | (1ULL << JavaScriptParser::OpenBrace)
        | (1ULL << JavaScriptParser::Ellipsis))) != 0) || _la == JavaScriptParser::Identifier) {
        setState(486);
        formalParameterList();
      }
      setState(489);
      match(JavaScriptParser::CloseParen);
      setState(490);
      match(JavaScriptParser::OpenBrace);
      setState(491);
      functionBody();
      setState(492);
      match(JavaScriptParser::CloseBrace);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(494);
      generatorMethod();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GeneratorMethodContext ------------------------------------------------------------------

JavaScriptParser::GeneratorMethodContext::GeneratorMethodContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::GeneratorMethodContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

tree::TerminalNode* JavaScriptParser::GeneratorMethodContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::GeneratorMethodContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

tree::TerminalNode* JavaScriptParser::GeneratorMethodContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

JavaScriptParser::FunctionBodyContext* JavaScriptParser::GeneratorMethodContext::functionBody() {
  return getRuleContext<JavaScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* JavaScriptParser::GeneratorMethodContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

tree::TerminalNode* JavaScriptParser::GeneratorMethodContext::Multiply() {
  return getToken(JavaScriptParser::Multiply, 0);
}

JavaScriptParser::FormalParameterListContext* JavaScriptParser::GeneratorMethodContext::formalParameterList() {
  return getRuleContext<JavaScriptParser::FormalParameterListContext>(0);
}


size_t JavaScriptParser::GeneratorMethodContext::getRuleIndex() const {
  return JavaScriptParser::RuleGeneratorMethod;
}

void JavaScriptParser::GeneratorMethodContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneratorMethod(this);
}

void JavaScriptParser::GeneratorMethodContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneratorMethod(this);
}


antlrcpp::Any JavaScriptParser::GeneratorMethodContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitGeneratorMethod(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::GeneratorMethodContext* JavaScriptParser::generatorMethod() {
  GeneratorMethodContext *_localctx = _tracker.createInstance<GeneratorMethodContext>(_ctx, getState());
  enterRule(_localctx, 76, JavaScriptParser::RuleGeneratorMethod);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(498);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::Multiply) {
      setState(497);
      match(JavaScriptParser::Multiply);
    }
    setState(500);
    match(JavaScriptParser::Identifier);
    setState(501);
    match(JavaScriptParser::OpenParen);
    setState(503);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaScriptParser::OpenBracket)
      | (1ULL << JavaScriptParser::OpenBrace)
      | (1ULL << JavaScriptParser::Ellipsis))) != 0) || _la == JavaScriptParser::Identifier) {
      setState(502);
      formalParameterList();
    }
    setState(505);
    match(JavaScriptParser::CloseParen);
    setState(506);
    match(JavaScriptParser::OpenBrace);
    setState(507);
    functionBody();
    setState(508);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GeneratorFunctionDeclarationContext ------------------------------------------------------------------

JavaScriptParser::GeneratorFunctionDeclarationContext::GeneratorFunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::GeneratorFunctionDeclarationContext::Function() {
  return getToken(JavaScriptParser::Function, 0);
}

tree::TerminalNode* JavaScriptParser::GeneratorFunctionDeclarationContext::Multiply() {
  return getToken(JavaScriptParser::Multiply, 0);
}

tree::TerminalNode* JavaScriptParser::GeneratorFunctionDeclarationContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::GeneratorFunctionDeclarationContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

tree::TerminalNode* JavaScriptParser::GeneratorFunctionDeclarationContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

JavaScriptParser::FunctionBodyContext* JavaScriptParser::GeneratorFunctionDeclarationContext::functionBody() {
  return getRuleContext<JavaScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* JavaScriptParser::GeneratorFunctionDeclarationContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

tree::TerminalNode* JavaScriptParser::GeneratorFunctionDeclarationContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::FormalParameterListContext* JavaScriptParser::GeneratorFunctionDeclarationContext::formalParameterList() {
  return getRuleContext<JavaScriptParser::FormalParameterListContext>(0);
}


size_t JavaScriptParser::GeneratorFunctionDeclarationContext::getRuleIndex() const {
  return JavaScriptParser::RuleGeneratorFunctionDeclaration;
}

void JavaScriptParser::GeneratorFunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneratorFunctionDeclaration(this);
}

void JavaScriptParser::GeneratorFunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneratorFunctionDeclaration(this);
}


antlrcpp::Any JavaScriptParser::GeneratorFunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitGeneratorFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::GeneratorFunctionDeclarationContext* JavaScriptParser::generatorFunctionDeclaration() {
  GeneratorFunctionDeclarationContext *_localctx = _tracker.createInstance<GeneratorFunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 78, JavaScriptParser::RuleGeneratorFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(510);
    match(JavaScriptParser::Function);
    setState(511);
    match(JavaScriptParser::Multiply);
    setState(513);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::Identifier) {
      setState(512);
      match(JavaScriptParser::Identifier);
    }
    setState(515);
    match(JavaScriptParser::OpenParen);
    setState(517);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaScriptParser::OpenBracket)
      | (1ULL << JavaScriptParser::OpenBrace)
      | (1ULL << JavaScriptParser::Ellipsis))) != 0) || _la == JavaScriptParser::Identifier) {
      setState(516);
      formalParameterList();
    }
    setState(519);
    match(JavaScriptParser::CloseParen);
    setState(520);
    match(JavaScriptParser::OpenBrace);
    setState(521);
    functionBody();
    setState(522);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GeneratorBlockContext ------------------------------------------------------------------

JavaScriptParser::GeneratorBlockContext::GeneratorBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::GeneratorBlockContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

tree::TerminalNode* JavaScriptParser::GeneratorBlockContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

std::vector<JavaScriptParser::GeneratorDefinitionContext *> JavaScriptParser::GeneratorBlockContext::generatorDefinition() {
  return getRuleContexts<JavaScriptParser::GeneratorDefinitionContext>();
}

JavaScriptParser::GeneratorDefinitionContext* JavaScriptParser::GeneratorBlockContext::generatorDefinition(size_t i) {
  return getRuleContext<JavaScriptParser::GeneratorDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> JavaScriptParser::GeneratorBlockContext::Comma() {
  return getTokens(JavaScriptParser::Comma);
}

tree::TerminalNode* JavaScriptParser::GeneratorBlockContext::Comma(size_t i) {
  return getToken(JavaScriptParser::Comma, i);
}


size_t JavaScriptParser::GeneratorBlockContext::getRuleIndex() const {
  return JavaScriptParser::RuleGeneratorBlock;
}

void JavaScriptParser::GeneratorBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneratorBlock(this);
}

void JavaScriptParser::GeneratorBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneratorBlock(this);
}


antlrcpp::Any JavaScriptParser::GeneratorBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitGeneratorBlock(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::GeneratorBlockContext* JavaScriptParser::generatorBlock() {
  GeneratorBlockContext *_localctx = _tracker.createInstance<GeneratorBlockContext>(_ctx, getState());
  enterRule(_localctx, 80, JavaScriptParser::RuleGeneratorBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(524);
    match(JavaScriptParser::OpenBrace);
    setState(533);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::Multiply) {
      setState(525);
      generatorDefinition();
      setState(530);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(526);
          match(JavaScriptParser::Comma);
          setState(527);
          generatorDefinition(); 
        }
        setState(532);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
      }
    }
    setState(536);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::Comma) {
      setState(535);
      match(JavaScriptParser::Comma);
    }
    setState(538);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GeneratorDefinitionContext ------------------------------------------------------------------

JavaScriptParser::GeneratorDefinitionContext::GeneratorDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::GeneratorDefinitionContext::Multiply() {
  return getToken(JavaScriptParser::Multiply, 0);
}

JavaScriptParser::IteratorDefinitionContext* JavaScriptParser::GeneratorDefinitionContext::iteratorDefinition() {
  return getRuleContext<JavaScriptParser::IteratorDefinitionContext>(0);
}


size_t JavaScriptParser::GeneratorDefinitionContext::getRuleIndex() const {
  return JavaScriptParser::RuleGeneratorDefinition;
}

void JavaScriptParser::GeneratorDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneratorDefinition(this);
}

void JavaScriptParser::GeneratorDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneratorDefinition(this);
}


antlrcpp::Any JavaScriptParser::GeneratorDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitGeneratorDefinition(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::GeneratorDefinitionContext* JavaScriptParser::generatorDefinition() {
  GeneratorDefinitionContext *_localctx = _tracker.createInstance<GeneratorDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 82, JavaScriptParser::RuleGeneratorDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(540);
    match(JavaScriptParser::Multiply);
    setState(541);
    iteratorDefinition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IteratorBlockContext ------------------------------------------------------------------

JavaScriptParser::IteratorBlockContext::IteratorBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::IteratorBlockContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

tree::TerminalNode* JavaScriptParser::IteratorBlockContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

std::vector<JavaScriptParser::IteratorDefinitionContext *> JavaScriptParser::IteratorBlockContext::iteratorDefinition() {
  return getRuleContexts<JavaScriptParser::IteratorDefinitionContext>();
}

JavaScriptParser::IteratorDefinitionContext* JavaScriptParser::IteratorBlockContext::iteratorDefinition(size_t i) {
  return getRuleContext<JavaScriptParser::IteratorDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> JavaScriptParser::IteratorBlockContext::Comma() {
  return getTokens(JavaScriptParser::Comma);
}

tree::TerminalNode* JavaScriptParser::IteratorBlockContext::Comma(size_t i) {
  return getToken(JavaScriptParser::Comma, i);
}


size_t JavaScriptParser::IteratorBlockContext::getRuleIndex() const {
  return JavaScriptParser::RuleIteratorBlock;
}

void JavaScriptParser::IteratorBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIteratorBlock(this);
}

void JavaScriptParser::IteratorBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIteratorBlock(this);
}


antlrcpp::Any JavaScriptParser::IteratorBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitIteratorBlock(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::IteratorBlockContext* JavaScriptParser::iteratorBlock() {
  IteratorBlockContext *_localctx = _tracker.createInstance<IteratorBlockContext>(_ctx, getState());
  enterRule(_localctx, 84, JavaScriptParser::RuleIteratorBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(543);
    match(JavaScriptParser::OpenBrace);
    setState(552);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::OpenBracket) {
      setState(544);
      iteratorDefinition();
      setState(549);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(545);
          match(JavaScriptParser::Comma);
          setState(546);
          iteratorDefinition(); 
        }
        setState(551);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
      }
    }
    setState(555);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::Comma) {
      setState(554);
      match(JavaScriptParser::Comma);
    }
    setState(557);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IteratorDefinitionContext ------------------------------------------------------------------

JavaScriptParser::IteratorDefinitionContext::IteratorDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::IteratorDefinitionContext::OpenBracket() {
  return getToken(JavaScriptParser::OpenBracket, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::IteratorDefinitionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* JavaScriptParser::IteratorDefinitionContext::CloseBracket() {
  return getToken(JavaScriptParser::CloseBracket, 0);
}

tree::TerminalNode* JavaScriptParser::IteratorDefinitionContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::IteratorDefinitionContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

tree::TerminalNode* JavaScriptParser::IteratorDefinitionContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

JavaScriptParser::FunctionBodyContext* JavaScriptParser::IteratorDefinitionContext::functionBody() {
  return getRuleContext<JavaScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* JavaScriptParser::IteratorDefinitionContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

JavaScriptParser::FormalParameterListContext* JavaScriptParser::IteratorDefinitionContext::formalParameterList() {
  return getRuleContext<JavaScriptParser::FormalParameterListContext>(0);
}


size_t JavaScriptParser::IteratorDefinitionContext::getRuleIndex() const {
  return JavaScriptParser::RuleIteratorDefinition;
}

void JavaScriptParser::IteratorDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIteratorDefinition(this);
}

void JavaScriptParser::IteratorDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIteratorDefinition(this);
}


antlrcpp::Any JavaScriptParser::IteratorDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitIteratorDefinition(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::IteratorDefinitionContext* JavaScriptParser::iteratorDefinition() {
  IteratorDefinitionContext *_localctx = _tracker.createInstance<IteratorDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 86, JavaScriptParser::RuleIteratorDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(559);
    match(JavaScriptParser::OpenBracket);
    setState(560);
    singleExpression(0);
    setState(561);
    match(JavaScriptParser::CloseBracket);
    setState(562);
    match(JavaScriptParser::OpenParen);
    setState(564);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaScriptParser::OpenBracket)
      | (1ULL << JavaScriptParser::OpenBrace)
      | (1ULL << JavaScriptParser::Ellipsis))) != 0) || _la == JavaScriptParser::Identifier) {
      setState(563);
      formalParameterList();
    }
    setState(566);
    match(JavaScriptParser::CloseParen);
    setState(567);
    match(JavaScriptParser::OpenBrace);
    setState(568);
    functionBody();
    setState(569);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterListContext ------------------------------------------------------------------

JavaScriptParser::FormalParameterListContext::FormalParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaScriptParser::FormalParameterArgContext *> JavaScriptParser::FormalParameterListContext::formalParameterArg() {
  return getRuleContexts<JavaScriptParser::FormalParameterArgContext>();
}

JavaScriptParser::FormalParameterArgContext* JavaScriptParser::FormalParameterListContext::formalParameterArg(size_t i) {
  return getRuleContext<JavaScriptParser::FormalParameterArgContext>(i);
}

std::vector<tree::TerminalNode *> JavaScriptParser::FormalParameterListContext::Comma() {
  return getTokens(JavaScriptParser::Comma);
}

tree::TerminalNode* JavaScriptParser::FormalParameterListContext::Comma(size_t i) {
  return getToken(JavaScriptParser::Comma, i);
}

JavaScriptParser::LastFormalParameterArgContext* JavaScriptParser::FormalParameterListContext::lastFormalParameterArg() {
  return getRuleContext<JavaScriptParser::LastFormalParameterArgContext>(0);
}

JavaScriptParser::ArrayLiteralContext* JavaScriptParser::FormalParameterListContext::arrayLiteral() {
  return getRuleContext<JavaScriptParser::ArrayLiteralContext>(0);
}

JavaScriptParser::ObjectLiteralContext* JavaScriptParser::FormalParameterListContext::objectLiteral() {
  return getRuleContext<JavaScriptParser::ObjectLiteralContext>(0);
}


size_t JavaScriptParser::FormalParameterListContext::getRuleIndex() const {
  return JavaScriptParser::RuleFormalParameterList;
}

void JavaScriptParser::FormalParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameterList(this);
}

void JavaScriptParser::FormalParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameterList(this);
}


antlrcpp::Any JavaScriptParser::FormalParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitFormalParameterList(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::FormalParameterListContext* JavaScriptParser::formalParameterList() {
  FormalParameterListContext *_localctx = _tracker.createInstance<FormalParameterListContext>(_ctx, getState());
  enterRule(_localctx, 88, JavaScriptParser::RuleFormalParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(586);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(571);
        formalParameterArg();
        setState(576);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(572);
            match(JavaScriptParser::Comma);
            setState(573);
            formalParameterArg(); 
          }
          setState(578);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
        }
        setState(581);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == JavaScriptParser::Comma) {
          setState(579);
          match(JavaScriptParser::Comma);
          setState(580);
          lastFormalParameterArg();
        }
        break;
      }

      case JavaScriptParser::Ellipsis: {
        enterOuterAlt(_localctx, 2);
        setState(583);
        lastFormalParameterArg();
        break;
      }

      case JavaScriptParser::OpenBracket: {
        enterOuterAlt(_localctx, 3);
        setState(584);
        arrayLiteral();
        break;
      }

      case JavaScriptParser::OpenBrace: {
        enterOuterAlt(_localctx, 4);
        setState(585);
        objectLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParameterArgContext ------------------------------------------------------------------

JavaScriptParser::FormalParameterArgContext::FormalParameterArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::FormalParameterArgContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

tree::TerminalNode* JavaScriptParser::FormalParameterArgContext::Assign() {
  return getToken(JavaScriptParser::Assign, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::FormalParameterArgContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}


size_t JavaScriptParser::FormalParameterArgContext::getRuleIndex() const {
  return JavaScriptParser::RuleFormalParameterArg;
}

void JavaScriptParser::FormalParameterArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameterArg(this);
}

void JavaScriptParser::FormalParameterArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameterArg(this);
}


antlrcpp::Any JavaScriptParser::FormalParameterArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitFormalParameterArg(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::FormalParameterArgContext* JavaScriptParser::formalParameterArg() {
  FormalParameterArgContext *_localctx = _tracker.createInstance<FormalParameterArgContext>(_ctx, getState());
  enterRule(_localctx, 90, JavaScriptParser::RuleFormalParameterArg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(588);
    match(JavaScriptParser::Identifier);
    setState(591);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::Assign) {
      setState(589);
      match(JavaScriptParser::Assign);
      setState(590);
      singleExpression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LastFormalParameterArgContext ------------------------------------------------------------------

JavaScriptParser::LastFormalParameterArgContext::LastFormalParameterArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::LastFormalParameterArgContext::Ellipsis() {
  return getToken(JavaScriptParser::Ellipsis, 0);
}

tree::TerminalNode* JavaScriptParser::LastFormalParameterArgContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}


size_t JavaScriptParser::LastFormalParameterArgContext::getRuleIndex() const {
  return JavaScriptParser::RuleLastFormalParameterArg;
}

void JavaScriptParser::LastFormalParameterArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLastFormalParameterArg(this);
}

void JavaScriptParser::LastFormalParameterArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLastFormalParameterArg(this);
}


antlrcpp::Any JavaScriptParser::LastFormalParameterArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitLastFormalParameterArg(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::LastFormalParameterArgContext* JavaScriptParser::lastFormalParameterArg() {
  LastFormalParameterArgContext *_localctx = _tracker.createInstance<LastFormalParameterArgContext>(_ctx, getState());
  enterRule(_localctx, 92, JavaScriptParser::RuleLastFormalParameterArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(593);
    match(JavaScriptParser::Ellipsis);
    setState(594);
    match(JavaScriptParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionBodyContext ------------------------------------------------------------------

JavaScriptParser::FunctionBodyContext::FunctionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaScriptParser::SourceElementsContext* JavaScriptParser::FunctionBodyContext::sourceElements() {
  return getRuleContext<JavaScriptParser::SourceElementsContext>(0);
}


size_t JavaScriptParser::FunctionBodyContext::getRuleIndex() const {
  return JavaScriptParser::RuleFunctionBody;
}

void JavaScriptParser::FunctionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionBody(this);
}

void JavaScriptParser::FunctionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionBody(this);
}


antlrcpp::Any JavaScriptParser::FunctionBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionBody(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::FunctionBodyContext* JavaScriptParser::functionBody() {
  FunctionBodyContext *_localctx = _tracker.createInstance<FunctionBodyContext>(_ctx, getState());
  enterRule(_localctx, 94, JavaScriptParser::RuleFunctionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(597);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
    case 1: {
      setState(596);
      sourceElements();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SourceElementsContext ------------------------------------------------------------------

JavaScriptParser::SourceElementsContext::SourceElementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaScriptParser::SourceElementContext *> JavaScriptParser::SourceElementsContext::sourceElement() {
  return getRuleContexts<JavaScriptParser::SourceElementContext>();
}

JavaScriptParser::SourceElementContext* JavaScriptParser::SourceElementsContext::sourceElement(size_t i) {
  return getRuleContext<JavaScriptParser::SourceElementContext>(i);
}


size_t JavaScriptParser::SourceElementsContext::getRuleIndex() const {
  return JavaScriptParser::RuleSourceElements;
}

void JavaScriptParser::SourceElementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSourceElements(this);
}

void JavaScriptParser::SourceElementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSourceElements(this);
}


antlrcpp::Any JavaScriptParser::SourceElementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitSourceElements(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::SourceElementsContext* JavaScriptParser::sourceElements() {
  SourceElementsContext *_localctx = _tracker.createInstance<SourceElementsContext>(_ctx, getState());
  enterRule(_localctx, 96, JavaScriptParser::RuleSourceElements);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(600); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(599);
              sourceElement();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(602); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayLiteralContext ------------------------------------------------------------------

JavaScriptParser::ArrayLiteralContext::ArrayLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ArrayLiteralContext::OpenBracket() {
  return getToken(JavaScriptParser::OpenBracket, 0);
}

tree::TerminalNode* JavaScriptParser::ArrayLiteralContext::CloseBracket() {
  return getToken(JavaScriptParser::CloseBracket, 0);
}

JavaScriptParser::ElementListContext* JavaScriptParser::ArrayLiteralContext::elementList() {
  return getRuleContext<JavaScriptParser::ElementListContext>(0);
}


size_t JavaScriptParser::ArrayLiteralContext::getRuleIndex() const {
  return JavaScriptParser::RuleArrayLiteral;
}

void JavaScriptParser::ArrayLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayLiteral(this);
}

void JavaScriptParser::ArrayLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayLiteral(this);
}


antlrcpp::Any JavaScriptParser::ArrayLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrayLiteral(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ArrayLiteralContext* JavaScriptParser::arrayLiteral() {
  ArrayLiteralContext *_localctx = _tracker.createInstance<ArrayLiteralContext>(_ctx, getState());
  enterRule(_localctx, 98, JavaScriptParser::RuleArrayLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(604);
    match(JavaScriptParser::OpenBracket);
    setState(606);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaScriptParser::RegularExpressionLiteral)
      | (1ULL << JavaScriptParser::OpenBracket)
      | (1ULL << JavaScriptParser::OpenParen)
      | (1ULL << JavaScriptParser::OpenBrace)
      | (1ULL << JavaScriptParser::Ellipsis)
      | (1ULL << JavaScriptParser::PlusPlus)
      | (1ULL << JavaScriptParser::MinusMinus)
      | (1ULL << JavaScriptParser::Plus)
      | (1ULL << JavaScriptParser::Minus)
      | (1ULL << JavaScriptParser::BitNot)
      | (1ULL << JavaScriptParser::Not)
      | (1ULL << JavaScriptParser::NullLiteral)
      | (1ULL << JavaScriptParser::BooleanLiteral)
      | (1ULL << JavaScriptParser::DecimalLiteral)
      | (1ULL << JavaScriptParser::HexIntegerLiteral)
      | (1ULL << JavaScriptParser::OctalIntegerLiteral)
      | (1ULL << JavaScriptParser::OctalIntegerLiteral2)
      | (1ULL << JavaScriptParser::BinaryIntegerLiteral))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (JavaScriptParser::Typeof - 64))
      | (1ULL << (JavaScriptParser::New - 64))
      | (1ULL << (JavaScriptParser::Void - 64))
      | (1ULL << (JavaScriptParser::Function - 64))
      | (1ULL << (JavaScriptParser::This - 64))
      | (1ULL << (JavaScriptParser::Delete - 64))
      | (1ULL << (JavaScriptParser::Class - 64))
      | (1ULL << (JavaScriptParser::Super - 64))
      | (1ULL << (JavaScriptParser::Yield - 64))
      | (1ULL << (JavaScriptParser::Identifier - 64))
      | (1ULL << (JavaScriptParser::StringLiteral - 64))
      | (1ULL << (JavaScriptParser::TemplateStringLiteral - 64)))) != 0)) {
      setState(605);
      elementList();
    }
    setState(608);
    match(JavaScriptParser::CloseBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementListContext ------------------------------------------------------------------

JavaScriptParser::ElementListContext::ElementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::ElementListContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::ElementListContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

JavaScriptParser::LastElementContext* JavaScriptParser::ElementListContext::lastElement() {
  return getRuleContext<JavaScriptParser::LastElementContext>(0);
}

std::vector<tree::TerminalNode *> JavaScriptParser::ElementListContext::Comma() {
  return getTokens(JavaScriptParser::Comma);
}

tree::TerminalNode* JavaScriptParser::ElementListContext::Comma(size_t i) {
  return getToken(JavaScriptParser::Comma, i);
}


size_t JavaScriptParser::ElementListContext::getRuleIndex() const {
  return JavaScriptParser::RuleElementList;
}

void JavaScriptParser::ElementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementList(this);
}

void JavaScriptParser::ElementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementList(this);
}


antlrcpp::Any JavaScriptParser::ElementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitElementList(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ElementListContext* JavaScriptParser::elementList() {
  ElementListContext *_localctx = _tracker.createInstance<ElementListContext>(_ctx, getState());
  enterRule(_localctx, 100, JavaScriptParser::RuleElementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(631);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::RegularExpressionLiteral:
      case JavaScriptParser::OpenBracket:
      case JavaScriptParser::OpenParen:
      case JavaScriptParser::OpenBrace:
      case JavaScriptParser::PlusPlus:
      case JavaScriptParser::MinusMinus:
      case JavaScriptParser::Plus:
      case JavaScriptParser::Minus:
      case JavaScriptParser::BitNot:
      case JavaScriptParser::Not:
      case JavaScriptParser::NullLiteral:
      case JavaScriptParser::BooleanLiteral:
      case JavaScriptParser::DecimalLiteral:
      case JavaScriptParser::HexIntegerLiteral:
      case JavaScriptParser::OctalIntegerLiteral:
      case JavaScriptParser::OctalIntegerLiteral2:
      case JavaScriptParser::BinaryIntegerLiteral:
      case JavaScriptParser::Typeof:
      case JavaScriptParser::New:
      case JavaScriptParser::Void:
      case JavaScriptParser::Function:
      case JavaScriptParser::This:
      case JavaScriptParser::Delete:
      case JavaScriptParser::Class:
      case JavaScriptParser::Super:
      case JavaScriptParser::Yield:
      case JavaScriptParser::Identifier:
      case JavaScriptParser::StringLiteral:
      case JavaScriptParser::TemplateStringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(610);
        singleExpression(0);
        setState(619);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(612); 
            _errHandler->sync(this);
            _la = _input->LA(1);
            do {
              setState(611);
              match(JavaScriptParser::Comma);
              setState(614); 
              _errHandler->sync(this);
              _la = _input->LA(1);
            } while (_la == JavaScriptParser::Comma);
            setState(616);
            singleExpression(0); 
          }
          setState(621);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
        }
        setState(628);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == JavaScriptParser::Comma) {
          setState(623); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(622);
            match(JavaScriptParser::Comma);
            setState(625); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == JavaScriptParser::Comma);
          setState(627);
          lastElement();
        }
        break;
      }

      case JavaScriptParser::Ellipsis: {
        enterOuterAlt(_localctx, 2);
        setState(630);
        lastElement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LastElementContext ------------------------------------------------------------------

JavaScriptParser::LastElementContext::LastElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::LastElementContext::Ellipsis() {
  return getToken(JavaScriptParser::Ellipsis, 0);
}

tree::TerminalNode* JavaScriptParser::LastElementContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::LastElementContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}


size_t JavaScriptParser::LastElementContext::getRuleIndex() const {
  return JavaScriptParser::RuleLastElement;
}

void JavaScriptParser::LastElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLastElement(this);
}

void JavaScriptParser::LastElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLastElement(this);
}


antlrcpp::Any JavaScriptParser::LastElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitLastElement(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::LastElementContext* JavaScriptParser::lastElement() {
  LastElementContext *_localctx = _tracker.createInstance<LastElementContext>(_ctx, getState());
  enterRule(_localctx, 102, JavaScriptParser::RuleLastElement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(633);
    match(JavaScriptParser::Ellipsis);
    setState(636);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      setState(634);
      match(JavaScriptParser::Identifier);
      break;
    }

    case 2: {
      setState(635);
      singleExpression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectLiteralContext ------------------------------------------------------------------

JavaScriptParser::ObjectLiteralContext::ObjectLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ObjectLiteralContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

tree::TerminalNode* JavaScriptParser::ObjectLiteralContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

std::vector<JavaScriptParser::PropertyAssignmentContext *> JavaScriptParser::ObjectLiteralContext::propertyAssignment() {
  return getRuleContexts<JavaScriptParser::PropertyAssignmentContext>();
}

JavaScriptParser::PropertyAssignmentContext* JavaScriptParser::ObjectLiteralContext::propertyAssignment(size_t i) {
  return getRuleContext<JavaScriptParser::PropertyAssignmentContext>(i);
}

std::vector<tree::TerminalNode *> JavaScriptParser::ObjectLiteralContext::Comma() {
  return getTokens(JavaScriptParser::Comma);
}

tree::TerminalNode* JavaScriptParser::ObjectLiteralContext::Comma(size_t i) {
  return getToken(JavaScriptParser::Comma, i);
}


size_t JavaScriptParser::ObjectLiteralContext::getRuleIndex() const {
  return JavaScriptParser::RuleObjectLiteral;
}

void JavaScriptParser::ObjectLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjectLiteral(this);
}

void JavaScriptParser::ObjectLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjectLiteral(this);
}


antlrcpp::Any JavaScriptParser::ObjectLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitObjectLiteral(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ObjectLiteralContext* JavaScriptParser::objectLiteral() {
  ObjectLiteralContext *_localctx = _tracker.createInstance<ObjectLiteralContext>(_ctx, getState());
  enterRule(_localctx, 104, JavaScriptParser::RuleObjectLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(638);
    match(JavaScriptParser::OpenBrace);
    setState(647);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaScriptParser::OpenBracket)
      | (1ULL << JavaScriptParser::Multiply)
      | (1ULL << JavaScriptParser::NullLiteral)
      | (1ULL << JavaScriptParser::BooleanLiteral)
      | (1ULL << JavaScriptParser::DecimalLiteral)
      | (1ULL << JavaScriptParser::HexIntegerLiteral)
      | (1ULL << JavaScriptParser::OctalIntegerLiteral)
      | (1ULL << JavaScriptParser::OctalIntegerLiteral2)
      | (1ULL << JavaScriptParser::BinaryIntegerLiteral)
      | (1ULL << JavaScriptParser::Break)
      | (1ULL << JavaScriptParser::Do)
      | (1ULL << JavaScriptParser::Instanceof))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (JavaScriptParser::Typeof - 64))
      | (1ULL << (JavaScriptParser::Case - 64))
      | (1ULL << (JavaScriptParser::Else - 64))
      | (1ULL << (JavaScriptParser::New - 64))
      | (1ULL << (JavaScriptParser::Var - 64))
      | (1ULL << (JavaScriptParser::Catch - 64))
      | (1ULL << (JavaScriptParser::Finally - 64))
      | (1ULL << (JavaScriptParser::Return - 64))
      | (1ULL << (JavaScriptParser::Void - 64))
      | (1ULL << (JavaScriptParser::Continue - 64))
      | (1ULL << (JavaScriptParser::For - 64))
      | (1ULL << (JavaScriptParser::Switch - 64))
      | (1ULL << (JavaScriptParser::While - 64))
      | (1ULL << (JavaScriptParser::Debugger - 64))
      | (1ULL << (JavaScriptParser::Function - 64))
      | (1ULL << (JavaScriptParser::This - 64))
      | (1ULL << (JavaScriptParser::With - 64))
      | (1ULL << (JavaScriptParser::Default - 64))
      | (1ULL << (JavaScriptParser::If - 64))
      | (1ULL << (JavaScriptParser::Throw - 64))
      | (1ULL << (JavaScriptParser::Delete - 64))
      | (1ULL << (JavaScriptParser::In - 64))
      | (1ULL << (JavaScriptParser::Try - 64))
      | (1ULL << (JavaScriptParser::Class - 64))
      | (1ULL << (JavaScriptParser::Enum - 64))
      | (1ULL << (JavaScriptParser::Extends - 64))
      | (1ULL << (JavaScriptParser::Super - 64))
      | (1ULL << (JavaScriptParser::Const - 64))
      | (1ULL << (JavaScriptParser::Export - 64))
      | (1ULL << (JavaScriptParser::Import - 64))
      | (1ULL << (JavaScriptParser::Implements - 64))
      | (1ULL << (JavaScriptParser::Let - 64))
      | (1ULL << (JavaScriptParser::Private - 64))
      | (1ULL << (JavaScriptParser::Public - 64))
      | (1ULL << (JavaScriptParser::Interface - 64))
      | (1ULL << (JavaScriptParser::Package - 64))
      | (1ULL << (JavaScriptParser::Protected - 64))
      | (1ULL << (JavaScriptParser::Static - 64))
      | (1ULL << (JavaScriptParser::Yield - 64))
      | (1ULL << (JavaScriptParser::Identifier - 64))
      | (1ULL << (JavaScriptParser::StringLiteral - 64)))) != 0)) {
      setState(639);
      propertyAssignment();
      setState(644);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(640);
          match(JavaScriptParser::Comma);
          setState(641);
          propertyAssignment(); 
        }
        setState(646);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
    }
    setState(650);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == JavaScriptParser::Comma) {
      setState(649);
      match(JavaScriptParser::Comma);
    }
    setState(652);
    match(JavaScriptParser::CloseBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyAssignmentContext ------------------------------------------------------------------

JavaScriptParser::PropertyAssignmentContext::PropertyAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JavaScriptParser::PropertyAssignmentContext::getRuleIndex() const {
  return JavaScriptParser::RulePropertyAssignment;
}

void JavaScriptParser::PropertyAssignmentContext::copyFrom(PropertyAssignmentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PropertyExpressionAssignmentContext ------------------------------------------------------------------

JavaScriptParser::PropertyNameContext* JavaScriptParser::PropertyExpressionAssignmentContext::propertyName() {
  return getRuleContext<JavaScriptParser::PropertyNameContext>(0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::PropertyExpressionAssignmentContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* JavaScriptParser::PropertyExpressionAssignmentContext::Colon() {
  return getToken(JavaScriptParser::Colon, 0);
}

tree::TerminalNode* JavaScriptParser::PropertyExpressionAssignmentContext::Assign() {
  return getToken(JavaScriptParser::Assign, 0);
}

JavaScriptParser::PropertyExpressionAssignmentContext::PropertyExpressionAssignmentContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::PropertyExpressionAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyExpressionAssignment(this);
}
void JavaScriptParser::PropertyExpressionAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyExpressionAssignment(this);
}

antlrcpp::Any JavaScriptParser::PropertyExpressionAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertyExpressionAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComputedPropertyExpressionAssignmentContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::ComputedPropertyExpressionAssignmentContext::OpenBracket() {
  return getToken(JavaScriptParser::OpenBracket, 0);
}

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::ComputedPropertyExpressionAssignmentContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::ComputedPropertyExpressionAssignmentContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::ComputedPropertyExpressionAssignmentContext::CloseBracket() {
  return getToken(JavaScriptParser::CloseBracket, 0);
}

tree::TerminalNode* JavaScriptParser::ComputedPropertyExpressionAssignmentContext::Colon() {
  return getToken(JavaScriptParser::Colon, 0);
}

JavaScriptParser::ComputedPropertyExpressionAssignmentContext::ComputedPropertyExpressionAssignmentContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ComputedPropertyExpressionAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComputedPropertyExpressionAssignment(this);
}
void JavaScriptParser::ComputedPropertyExpressionAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComputedPropertyExpressionAssignment(this);
}

antlrcpp::Any JavaScriptParser::ComputedPropertyExpressionAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitComputedPropertyExpressionAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PropertyShorthandContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::PropertyShorthandContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::PropertyShorthandContext::PropertyShorthandContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::PropertyShorthandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyShorthand(this);
}
void JavaScriptParser::PropertyShorthandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyShorthand(this);
}

antlrcpp::Any JavaScriptParser::PropertyShorthandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertyShorthand(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PropertySetterContext ------------------------------------------------------------------

JavaScriptParser::SetterContext* JavaScriptParser::PropertySetterContext::setter() {
  return getRuleContext<JavaScriptParser::SetterContext>(0);
}

tree::TerminalNode* JavaScriptParser::PropertySetterContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::PropertySetterContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

tree::TerminalNode* JavaScriptParser::PropertySetterContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

tree::TerminalNode* JavaScriptParser::PropertySetterContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

JavaScriptParser::FunctionBodyContext* JavaScriptParser::PropertySetterContext::functionBody() {
  return getRuleContext<JavaScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* JavaScriptParser::PropertySetterContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

JavaScriptParser::PropertySetterContext::PropertySetterContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::PropertySetterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertySetter(this);
}
void JavaScriptParser::PropertySetterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertySetter(this);
}

antlrcpp::Any JavaScriptParser::PropertySetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertySetter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PropertyGetterContext ------------------------------------------------------------------

JavaScriptParser::GetterContext* JavaScriptParser::PropertyGetterContext::getter() {
  return getRuleContext<JavaScriptParser::GetterContext>(0);
}

tree::TerminalNode* JavaScriptParser::PropertyGetterContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::PropertyGetterContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

tree::TerminalNode* JavaScriptParser::PropertyGetterContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

JavaScriptParser::FunctionBodyContext* JavaScriptParser::PropertyGetterContext::functionBody() {
  return getRuleContext<JavaScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* JavaScriptParser::PropertyGetterContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

JavaScriptParser::PropertyGetterContext::PropertyGetterContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::PropertyGetterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyGetter(this);
}
void JavaScriptParser::PropertyGetterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyGetter(this);
}

antlrcpp::Any JavaScriptParser::PropertyGetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertyGetter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodPropertyContext ------------------------------------------------------------------

JavaScriptParser::GeneratorMethodContext* JavaScriptParser::MethodPropertyContext::generatorMethod() {
  return getRuleContext<JavaScriptParser::GeneratorMethodContext>(0);
}

JavaScriptParser::MethodPropertyContext::MethodPropertyContext(PropertyAssignmentContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::MethodPropertyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodProperty(this);
}
void JavaScriptParser::MethodPropertyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodProperty(this);
}

antlrcpp::Any JavaScriptParser::MethodPropertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitMethodProperty(this);
  else
    return visitor->visitChildren(this);
}
JavaScriptParser::PropertyAssignmentContext* JavaScriptParser::propertyAssignment() {
  PropertyAssignmentContext *_localctx = _tracker.createInstance<PropertyAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 106, JavaScriptParser::RulePropertyAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(681);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<JavaScriptParser::PropertyExpressionAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(654);
      propertyName();
      setState(655);
      _la = _input->LA(1);
      if (!(_la == JavaScriptParser::Assign

      || _la == JavaScriptParser::Colon)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(656);
      singleExpression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<JavaScriptParser::ComputedPropertyExpressionAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(658);
      match(JavaScriptParser::OpenBracket);
      setState(659);
      singleExpression(0);
      setState(660);
      match(JavaScriptParser::CloseBracket);
      setState(661);
      match(JavaScriptParser::Colon);
      setState(662);
      singleExpression(0);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<JavaScriptParser::PropertyGetterContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(664);
      getter();
      setState(665);
      match(JavaScriptParser::OpenParen);
      setState(666);
      match(JavaScriptParser::CloseParen);
      setState(667);
      match(JavaScriptParser::OpenBrace);
      setState(668);
      functionBody();
      setState(669);
      match(JavaScriptParser::CloseBrace);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<JavaScriptParser::PropertySetterContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(671);
      setter();
      setState(672);
      match(JavaScriptParser::OpenParen);
      setState(673);
      match(JavaScriptParser::Identifier);
      setState(674);
      match(JavaScriptParser::CloseParen);
      setState(675);
      match(JavaScriptParser::OpenBrace);
      setState(676);
      functionBody();
      setState(677);
      match(JavaScriptParser::CloseBrace);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<JavaScriptParser::MethodPropertyContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(679);
      generatorMethod();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<PropertyAssignmentContext *>(_tracker.createInstance<JavaScriptParser::PropertyShorthandContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(680);
      match(JavaScriptParser::Identifier);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyNameContext ------------------------------------------------------------------

JavaScriptParser::PropertyNameContext::PropertyNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaScriptParser::IdentifierNameContext* JavaScriptParser::PropertyNameContext::identifierName() {
  return getRuleContext<JavaScriptParser::IdentifierNameContext>(0);
}

tree::TerminalNode* JavaScriptParser::PropertyNameContext::StringLiteral() {
  return getToken(JavaScriptParser::StringLiteral, 0);
}

JavaScriptParser::NumericLiteralContext* JavaScriptParser::PropertyNameContext::numericLiteral() {
  return getRuleContext<JavaScriptParser::NumericLiteralContext>(0);
}


size_t JavaScriptParser::PropertyNameContext::getRuleIndex() const {
  return JavaScriptParser::RulePropertyName;
}

void JavaScriptParser::PropertyNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyName(this);
}

void JavaScriptParser::PropertyNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyName(this);
}


antlrcpp::Any JavaScriptParser::PropertyNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitPropertyName(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::PropertyNameContext* JavaScriptParser::propertyName() {
  PropertyNameContext *_localctx = _tracker.createInstance<PropertyNameContext>(_ctx, getState());
  enterRule(_localctx, 108, JavaScriptParser::RulePropertyName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(686);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::NullLiteral:
      case JavaScriptParser::BooleanLiteral:
      case JavaScriptParser::Break:
      case JavaScriptParser::Do:
      case JavaScriptParser::Instanceof:
      case JavaScriptParser::Typeof:
      case JavaScriptParser::Case:
      case JavaScriptParser::Else:
      case JavaScriptParser::New:
      case JavaScriptParser::Var:
      case JavaScriptParser::Catch:
      case JavaScriptParser::Finally:
      case JavaScriptParser::Return:
      case JavaScriptParser::Void:
      case JavaScriptParser::Continue:
      case JavaScriptParser::For:
      case JavaScriptParser::Switch:
      case JavaScriptParser::While:
      case JavaScriptParser::Debugger:
      case JavaScriptParser::Function:
      case JavaScriptParser::This:
      case JavaScriptParser::With:
      case JavaScriptParser::Default:
      case JavaScriptParser::If:
      case JavaScriptParser::Throw:
      case JavaScriptParser::Delete:
      case JavaScriptParser::In:
      case JavaScriptParser::Try:
      case JavaScriptParser::Class:
      case JavaScriptParser::Enum:
      case JavaScriptParser::Extends:
      case JavaScriptParser::Super:
      case JavaScriptParser::Const:
      case JavaScriptParser::Export:
      case JavaScriptParser::Import:
      case JavaScriptParser::Implements:
      case JavaScriptParser::Let:
      case JavaScriptParser::Private:
      case JavaScriptParser::Public:
      case JavaScriptParser::Interface:
      case JavaScriptParser::Package:
      case JavaScriptParser::Protected:
      case JavaScriptParser::Static:
      case JavaScriptParser::Yield:
      case JavaScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(683);
        identifierName();
        break;
      }

      case JavaScriptParser::StringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(684);
        match(JavaScriptParser::StringLiteral);
        break;
      }

      case JavaScriptParser::DecimalLiteral:
      case JavaScriptParser::HexIntegerLiteral:
      case JavaScriptParser::OctalIntegerLiteral:
      case JavaScriptParser::OctalIntegerLiteral2:
      case JavaScriptParser::BinaryIntegerLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(685);
        numericLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

JavaScriptParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ArgumentsContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::ArgumentsContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::ArgumentsContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::ArgumentsContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

JavaScriptParser::LastArgumentContext* JavaScriptParser::ArgumentsContext::lastArgument() {
  return getRuleContext<JavaScriptParser::LastArgumentContext>(0);
}

std::vector<tree::TerminalNode *> JavaScriptParser::ArgumentsContext::Comma() {
  return getTokens(JavaScriptParser::Comma);
}

tree::TerminalNode* JavaScriptParser::ArgumentsContext::Comma(size_t i) {
  return getToken(JavaScriptParser::Comma, i);
}


size_t JavaScriptParser::ArgumentsContext::getRuleIndex() const {
  return JavaScriptParser::RuleArguments;
}

void JavaScriptParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void JavaScriptParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


antlrcpp::Any JavaScriptParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ArgumentsContext* JavaScriptParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 110, JavaScriptParser::RuleArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(688);
    match(JavaScriptParser::OpenParen);
    setState(702);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::RegularExpressionLiteral:
      case JavaScriptParser::OpenBracket:
      case JavaScriptParser::OpenParen:
      case JavaScriptParser::OpenBrace:
      case JavaScriptParser::PlusPlus:
      case JavaScriptParser::MinusMinus:
      case JavaScriptParser::Plus:
      case JavaScriptParser::Minus:
      case JavaScriptParser::BitNot:
      case JavaScriptParser::Not:
      case JavaScriptParser::NullLiteral:
      case JavaScriptParser::BooleanLiteral:
      case JavaScriptParser::DecimalLiteral:
      case JavaScriptParser::HexIntegerLiteral:
      case JavaScriptParser::OctalIntegerLiteral:
      case JavaScriptParser::OctalIntegerLiteral2:
      case JavaScriptParser::BinaryIntegerLiteral:
      case JavaScriptParser::Typeof:
      case JavaScriptParser::New:
      case JavaScriptParser::Void:
      case JavaScriptParser::Function:
      case JavaScriptParser::This:
      case JavaScriptParser::Delete:
      case JavaScriptParser::Class:
      case JavaScriptParser::Super:
      case JavaScriptParser::Yield:
      case JavaScriptParser::Identifier:
      case JavaScriptParser::StringLiteral:
      case JavaScriptParser::TemplateStringLiteral: {
        setState(689);
        singleExpression(0);
        setState(694);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(690);
            match(JavaScriptParser::Comma);
            setState(691);
            singleExpression(0); 
          }
          setState(696);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
        }
        setState(699);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == JavaScriptParser::Comma) {
          setState(697);
          match(JavaScriptParser::Comma);
          setState(698);
          lastArgument();
        }
        break;
      }

      case JavaScriptParser::Ellipsis: {
        setState(701);
        lastArgument();
        break;
      }

      case JavaScriptParser::CloseParen: {
        break;
      }

    default:
      break;
    }
    setState(704);
    match(JavaScriptParser::CloseParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LastArgumentContext ------------------------------------------------------------------

JavaScriptParser::LastArgumentContext::LastArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::LastArgumentContext::Ellipsis() {
  return getToken(JavaScriptParser::Ellipsis, 0);
}

tree::TerminalNode* JavaScriptParser::LastArgumentContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}


size_t JavaScriptParser::LastArgumentContext::getRuleIndex() const {
  return JavaScriptParser::RuleLastArgument;
}

void JavaScriptParser::LastArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLastArgument(this);
}

void JavaScriptParser::LastArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLastArgument(this);
}


antlrcpp::Any JavaScriptParser::LastArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitLastArgument(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::LastArgumentContext* JavaScriptParser::lastArgument() {
  LastArgumentContext *_localctx = _tracker.createInstance<LastArgumentContext>(_ctx, getState());
  enterRule(_localctx, 112, JavaScriptParser::RuleLastArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(706);
    match(JavaScriptParser::Ellipsis);
    setState(707);
    match(JavaScriptParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionSequenceContext ------------------------------------------------------------------

JavaScriptParser::ExpressionSequenceContext::ExpressionSequenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::ExpressionSequenceContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::ExpressionSequenceContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

std::vector<tree::TerminalNode *> JavaScriptParser::ExpressionSequenceContext::Comma() {
  return getTokens(JavaScriptParser::Comma);
}

tree::TerminalNode* JavaScriptParser::ExpressionSequenceContext::Comma(size_t i) {
  return getToken(JavaScriptParser::Comma, i);
}


size_t JavaScriptParser::ExpressionSequenceContext::getRuleIndex() const {
  return JavaScriptParser::RuleExpressionSequence;
}

void JavaScriptParser::ExpressionSequenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionSequence(this);
}

void JavaScriptParser::ExpressionSequenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionSequence(this);
}


antlrcpp::Any JavaScriptParser::ExpressionSequenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitExpressionSequence(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::expressionSequence() {
  ExpressionSequenceContext *_localctx = _tracker.createInstance<ExpressionSequenceContext>(_ctx, getState());
  enterRule(_localctx, 114, JavaScriptParser::RuleExpressionSequence);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(709);
    singleExpression(0);
    setState(714);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(710);
        match(JavaScriptParser::Comma);
        setState(711);
        singleExpression(0); 
      }
      setState(716);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleExpressionContext ------------------------------------------------------------------

JavaScriptParser::SingleExpressionContext::SingleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t JavaScriptParser::SingleExpressionContext::getRuleIndex() const {
  return JavaScriptParser::RuleSingleExpression;
}

void JavaScriptParser::SingleExpressionContext::copyFrom(SingleExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TemplateStringExpressionContext ------------------------------------------------------------------

JavaScriptParser::SingleExpressionContext* JavaScriptParser::TemplateStringExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* JavaScriptParser::TemplateStringExpressionContext::TemplateStringLiteral() {
  return getToken(JavaScriptParser::TemplateStringLiteral, 0);
}

JavaScriptParser::TemplateStringExpressionContext::TemplateStringExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::TemplateStringExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTemplateStringExpression(this);
}
void JavaScriptParser::TemplateStringExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTemplateStringExpression(this);
}

antlrcpp::Any JavaScriptParser::TemplateStringExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitTemplateStringExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TernaryExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::TernaryExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::TernaryExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::TernaryExpressionContext::QuestionMark() {
  return getToken(JavaScriptParser::QuestionMark, 0);
}

tree::TerminalNode* JavaScriptParser::TernaryExpressionContext::Colon() {
  return getToken(JavaScriptParser::Colon, 0);
}

JavaScriptParser::TernaryExpressionContext::TernaryExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::TernaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTernaryExpression(this);
}
void JavaScriptParser::TernaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTernaryExpression(this);
}

antlrcpp::Any JavaScriptParser::TernaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitTernaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::LogicalAndExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::LogicalAndExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::LogicalAndExpressionContext::And() {
  return getToken(JavaScriptParser::And, 0);
}

JavaScriptParser::LogicalAndExpressionContext::LogicalAndExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::LogicalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndExpression(this);
}
void JavaScriptParser::LogicalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndExpression(this);
}

antlrcpp::Any JavaScriptParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GeneratorsExpressionContext ------------------------------------------------------------------

JavaScriptParser::GeneratorBlockContext* JavaScriptParser::GeneratorsExpressionContext::generatorBlock() {
  return getRuleContext<JavaScriptParser::GeneratorBlockContext>(0);
}

JavaScriptParser::GeneratorsExpressionContext::GeneratorsExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::GeneratorsExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneratorsExpression(this);
}
void JavaScriptParser::GeneratorsExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneratorsExpression(this);
}

antlrcpp::Any JavaScriptParser::GeneratorsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitGeneratorsExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PreIncrementExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::PreIncrementExpressionContext::PlusPlus() {
  return getToken(JavaScriptParser::PlusPlus, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::PreIncrementExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::PreIncrementExpressionContext::PreIncrementExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::PreIncrementExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreIncrementExpression(this);
}
void JavaScriptParser::PreIncrementExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreIncrementExpression(this);
}

antlrcpp::Any JavaScriptParser::PreIncrementExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitPreIncrementExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjectLiteralExpressionContext ------------------------------------------------------------------

JavaScriptParser::ObjectLiteralContext* JavaScriptParser::ObjectLiteralExpressionContext::objectLiteral() {
  return getRuleContext<JavaScriptParser::ObjectLiteralContext>(0);
}

JavaScriptParser::ObjectLiteralExpressionContext::ObjectLiteralExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ObjectLiteralExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjectLiteralExpression(this);
}
void JavaScriptParser::ObjectLiteralExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjectLiteralExpression(this);
}

antlrcpp::Any JavaScriptParser::ObjectLiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitObjectLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::InExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::InExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::InExpressionContext::In() {
  return getToken(JavaScriptParser::In, 0);
}

JavaScriptParser::InExpressionContext::InExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::InExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInExpression(this);
}
void JavaScriptParser::InExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInExpression(this);
}

antlrcpp::Any JavaScriptParser::InExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitInExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::LogicalOrExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::LogicalOrExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::LogicalOrExpressionContext::Or() {
  return getToken(JavaScriptParser::Or, 0);
}

JavaScriptParser::LogicalOrExpressionContext::LogicalOrExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::LogicalOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrExpression(this);
}
void JavaScriptParser::LogicalOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrExpression(this);
}

antlrcpp::Any JavaScriptParser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::NotExpressionContext::Not() {
  return getToken(JavaScriptParser::Not, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::NotExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::NotExpressionContext::NotExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::NotExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpression(this);
}
void JavaScriptParser::NotExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpression(this);
}

antlrcpp::Any JavaScriptParser::NotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitNotExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PreDecreaseExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::PreDecreaseExpressionContext::MinusMinus() {
  return getToken(JavaScriptParser::MinusMinus, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::PreDecreaseExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::PreDecreaseExpressionContext::PreDecreaseExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::PreDecreaseExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreDecreaseExpression(this);
}
void JavaScriptParser::PreDecreaseExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreDecreaseExpression(this);
}

antlrcpp::Any JavaScriptParser::PreDecreaseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitPreDecreaseExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgumentsExpressionContext ------------------------------------------------------------------

JavaScriptParser::SingleExpressionContext* JavaScriptParser::ArgumentsExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::ArgumentsContext* JavaScriptParser::ArgumentsExpressionContext::arguments() {
  return getRuleContext<JavaScriptParser::ArgumentsContext>(0);
}

JavaScriptParser::ArgumentsExpressionContext::ArgumentsExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ArgumentsExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentsExpression(this);
}
void JavaScriptParser::ArgumentsExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentsExpression(this);
}

antlrcpp::Any JavaScriptParser::ArgumentsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitArgumentsExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ThisExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::ThisExpressionContext::This() {
  return getToken(JavaScriptParser::This, 0);
}

JavaScriptParser::ThisExpressionContext::ThisExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ThisExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThisExpression(this);
}
void JavaScriptParser::ThisExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThisExpression(this);
}

antlrcpp::Any JavaScriptParser::ThisExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitThisExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::FunctionExpressionContext::Function() {
  return getToken(JavaScriptParser::Function, 0);
}

tree::TerminalNode* JavaScriptParser::FunctionExpressionContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::FunctionExpressionContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

tree::TerminalNode* JavaScriptParser::FunctionExpressionContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

JavaScriptParser::FunctionBodyContext* JavaScriptParser::FunctionExpressionContext::functionBody() {
  return getRuleContext<JavaScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* JavaScriptParser::FunctionExpressionContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}

tree::TerminalNode* JavaScriptParser::FunctionExpressionContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::FormalParameterListContext* JavaScriptParser::FunctionExpressionContext::formalParameterList() {
  return getRuleContext<JavaScriptParser::FormalParameterListContext>(0);
}

JavaScriptParser::FunctionExpressionContext::FunctionExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::FunctionExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionExpression(this);
}
void JavaScriptParser::FunctionExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionExpression(this);
}

antlrcpp::Any JavaScriptParser::FunctionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitFunctionExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryMinusExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::UnaryMinusExpressionContext::Minus() {
  return getToken(JavaScriptParser::Minus, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::UnaryMinusExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::UnaryMinusExpressionContext::UnaryMinusExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::UnaryMinusExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryMinusExpression(this);
}
void JavaScriptParser::UnaryMinusExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryMinusExpression(this);
}

antlrcpp::Any JavaScriptParser::UnaryMinusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitUnaryMinusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::AssignmentExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::AssignmentExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::AssignmentExpressionContext::Assign() {
  return getToken(JavaScriptParser::Assign, 0);
}

JavaScriptParser::AssignmentExpressionContext::AssignmentExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}
void JavaScriptParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}

antlrcpp::Any JavaScriptParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostDecreaseExpressionContext ------------------------------------------------------------------

JavaScriptParser::SingleExpressionContext* JavaScriptParser::PostDecreaseExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* JavaScriptParser::PostDecreaseExpressionContext::MinusMinus() {
  return getToken(JavaScriptParser::MinusMinus, 0);
}

JavaScriptParser::PostDecreaseExpressionContext::PostDecreaseExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::PostDecreaseExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostDecreaseExpression(this);
}
void JavaScriptParser::PostDecreaseExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostDecreaseExpression(this);
}

antlrcpp::Any JavaScriptParser::PostDecreaseExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitPostDecreaseExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeofExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::TypeofExpressionContext::Typeof() {
  return getToken(JavaScriptParser::Typeof, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::TypeofExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::TypeofExpressionContext::TypeofExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::TypeofExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeofExpression(this);
}
void JavaScriptParser::TypeofExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeofExpression(this);
}

antlrcpp::Any JavaScriptParser::TypeofExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitTypeofExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InstanceofExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::InstanceofExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::InstanceofExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::InstanceofExpressionContext::Instanceof() {
  return getToken(JavaScriptParser::Instanceof, 0);
}

JavaScriptParser::InstanceofExpressionContext::InstanceofExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::InstanceofExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstanceofExpression(this);
}
void JavaScriptParser::InstanceofExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstanceofExpression(this);
}

antlrcpp::Any JavaScriptParser::InstanceofExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitInstanceofExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryPlusExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::UnaryPlusExpressionContext::Plus() {
  return getToken(JavaScriptParser::Plus, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::UnaryPlusExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::UnaryPlusExpressionContext::UnaryPlusExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::UnaryPlusExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryPlusExpression(this);
}
void JavaScriptParser::UnaryPlusExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryPlusExpression(this);
}

antlrcpp::Any JavaScriptParser::UnaryPlusExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitUnaryPlusExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeleteExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::DeleteExpressionContext::Delete() {
  return getToken(JavaScriptParser::Delete, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::DeleteExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::DeleteExpressionContext::DeleteExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::DeleteExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeleteExpression(this);
}
void JavaScriptParser::DeleteExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeleteExpression(this);
}

antlrcpp::Any JavaScriptParser::DeleteExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitDeleteExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GeneratorsFunctionExpressionContext ------------------------------------------------------------------

JavaScriptParser::GeneratorFunctionDeclarationContext* JavaScriptParser::GeneratorsFunctionExpressionContext::generatorFunctionDeclaration() {
  return getRuleContext<JavaScriptParser::GeneratorFunctionDeclarationContext>(0);
}

JavaScriptParser::GeneratorsFunctionExpressionContext::GeneratorsFunctionExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::GeneratorsFunctionExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeneratorsFunctionExpression(this);
}
void JavaScriptParser::GeneratorsFunctionExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeneratorsFunctionExpression(this);
}

antlrcpp::Any JavaScriptParser::GeneratorsFunctionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitGeneratorsFunctionExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IteratorsExpressionContext ------------------------------------------------------------------

JavaScriptParser::IteratorBlockContext* JavaScriptParser::IteratorsExpressionContext::iteratorBlock() {
  return getRuleContext<JavaScriptParser::IteratorBlockContext>(0);
}

JavaScriptParser::IteratorsExpressionContext::IteratorsExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::IteratorsExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIteratorsExpression(this);
}
void JavaScriptParser::IteratorsExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIteratorsExpression(this);
}

antlrcpp::Any JavaScriptParser::IteratorsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitIteratorsExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrowFunctionExpressionContext ------------------------------------------------------------------

JavaScriptParser::ArrowFunctionParametersContext* JavaScriptParser::ArrowFunctionExpressionContext::arrowFunctionParameters() {
  return getRuleContext<JavaScriptParser::ArrowFunctionParametersContext>(0);
}

tree::TerminalNode* JavaScriptParser::ArrowFunctionExpressionContext::ARROW() {
  return getToken(JavaScriptParser::ARROW, 0);
}

JavaScriptParser::ArrowFunctionBodyContext* JavaScriptParser::ArrowFunctionExpressionContext::arrowFunctionBody() {
  return getRuleContext<JavaScriptParser::ArrowFunctionBodyContext>(0);
}

JavaScriptParser::ArrowFunctionExpressionContext::ArrowFunctionExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ArrowFunctionExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrowFunctionExpression(this);
}
void JavaScriptParser::ArrowFunctionExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrowFunctionExpression(this);
}

antlrcpp::Any JavaScriptParser::ArrowFunctionExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrowFunctionExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualityExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::EqualityExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::EqualityExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::EqualityExpressionContext::Equals_() {
  return getToken(JavaScriptParser::Equals_, 0);
}

tree::TerminalNode* JavaScriptParser::EqualityExpressionContext::NotEquals() {
  return getToken(JavaScriptParser::NotEquals, 0);
}

tree::TerminalNode* JavaScriptParser::EqualityExpressionContext::IdentityEquals() {
  return getToken(JavaScriptParser::IdentityEquals, 0);
}

tree::TerminalNode* JavaScriptParser::EqualityExpressionContext::IdentityNotEquals() {
  return getToken(JavaScriptParser::IdentityNotEquals, 0);
}

JavaScriptParser::EqualityExpressionContext::EqualityExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::EqualityExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}
void JavaScriptParser::EqualityExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}

antlrcpp::Any JavaScriptParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitXOrExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::BitXOrExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::BitXOrExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::BitXOrExpressionContext::BitXOr() {
  return getToken(JavaScriptParser::BitXOr, 0);
}

JavaScriptParser::BitXOrExpressionContext::BitXOrExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::BitXOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitXOrExpression(this);
}
void JavaScriptParser::BitXOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitXOrExpression(this);
}

antlrcpp::Any JavaScriptParser::BitXOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitBitXOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SuperExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::SuperExpressionContext::Super() {
  return getToken(JavaScriptParser::Super, 0);
}

JavaScriptParser::SuperExpressionContext::SuperExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::SuperExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuperExpression(this);
}
void JavaScriptParser::SuperExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuperExpression(this);
}

antlrcpp::Any JavaScriptParser::SuperExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitSuperExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::MultiplicativeExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::MultiplicativeExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::MultiplicativeExpressionContext::Multiply() {
  return getToken(JavaScriptParser::Multiply, 0);
}

tree::TerminalNode* JavaScriptParser::MultiplicativeExpressionContext::Divide() {
  return getToken(JavaScriptParser::Divide, 0);
}

tree::TerminalNode* JavaScriptParser::MultiplicativeExpressionContext::Modulus() {
  return getToken(JavaScriptParser::Modulus, 0);
}

JavaScriptParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}
void JavaScriptParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}

antlrcpp::Any JavaScriptParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitShiftExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::BitShiftExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::BitShiftExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::BitShiftExpressionContext::LeftShiftArithmetic() {
  return getToken(JavaScriptParser::LeftShiftArithmetic, 0);
}

tree::TerminalNode* JavaScriptParser::BitShiftExpressionContext::RightShiftArithmetic() {
  return getToken(JavaScriptParser::RightShiftArithmetic, 0);
}

tree::TerminalNode* JavaScriptParser::BitShiftExpressionContext::RightShiftLogical() {
  return getToken(JavaScriptParser::RightShiftLogical, 0);
}

JavaScriptParser::BitShiftExpressionContext::BitShiftExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::BitShiftExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitShiftExpression(this);
}
void JavaScriptParser::BitShiftExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitShiftExpression(this);
}

antlrcpp::Any JavaScriptParser::BitShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitBitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::ParenthesizedExpressionContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::ParenthesizedExpressionContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* JavaScriptParser::ParenthesizedExpressionContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::ParenthesizedExpressionContext::ParenthesizedExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ParenthesizedExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesizedExpression(this);
}
void JavaScriptParser::ParenthesizedExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesizedExpression(this);
}

antlrcpp::Any JavaScriptParser::ParenthesizedExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitParenthesizedExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditiveExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::AdditiveExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::AdditiveExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::AdditiveExpressionContext::Plus() {
  return getToken(JavaScriptParser::Plus, 0);
}

tree::TerminalNode* JavaScriptParser::AdditiveExpressionContext::Minus() {
  return getToken(JavaScriptParser::Minus, 0);
}

JavaScriptParser::AdditiveExpressionContext::AdditiveExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}
void JavaScriptParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}

antlrcpp::Any JavaScriptParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::RelationalExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::RelationalExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::RelationalExpressionContext::LessThan() {
  return getToken(JavaScriptParser::LessThan, 0);
}

tree::TerminalNode* JavaScriptParser::RelationalExpressionContext::MoreThan() {
  return getToken(JavaScriptParser::MoreThan, 0);
}

tree::TerminalNode* JavaScriptParser::RelationalExpressionContext::LessThanEquals() {
  return getToken(JavaScriptParser::LessThanEquals, 0);
}

tree::TerminalNode* JavaScriptParser::RelationalExpressionContext::GreaterThanEquals() {
  return getToken(JavaScriptParser::GreaterThanEquals, 0);
}

JavaScriptParser::RelationalExpressionContext::RelationalExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::RelationalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpression(this);
}
void JavaScriptParser::RelationalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpression(this);
}

antlrcpp::Any JavaScriptParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PostIncrementExpressionContext ------------------------------------------------------------------

JavaScriptParser::SingleExpressionContext* JavaScriptParser::PostIncrementExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* JavaScriptParser::PostIncrementExpressionContext::PlusPlus() {
  return getToken(JavaScriptParser::PlusPlus, 0);
}

JavaScriptParser::PostIncrementExpressionContext::PostIncrementExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::PostIncrementExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostIncrementExpression(this);
}
void JavaScriptParser::PostIncrementExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostIncrementExpression(this);
}

antlrcpp::Any JavaScriptParser::PostIncrementExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitPostIncrementExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- YieldExpressionContext ------------------------------------------------------------------

JavaScriptParser::YieldStatementContext* JavaScriptParser::YieldExpressionContext::yieldStatement() {
  return getRuleContext<JavaScriptParser::YieldStatementContext>(0);
}

JavaScriptParser::YieldExpressionContext::YieldExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::YieldExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterYieldExpression(this);
}
void JavaScriptParser::YieldExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitYieldExpression(this);
}

antlrcpp::Any JavaScriptParser::YieldExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitYieldExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitNotExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::BitNotExpressionContext::BitNot() {
  return getToken(JavaScriptParser::BitNot, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::BitNotExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::BitNotExpressionContext::BitNotExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::BitNotExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitNotExpression(this);
}
void JavaScriptParser::BitNotExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitNotExpression(this);
}

antlrcpp::Any JavaScriptParser::BitNotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitBitNotExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::NewExpressionContext::New() {
  return getToken(JavaScriptParser::New, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::NewExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::ArgumentsContext* JavaScriptParser::NewExpressionContext::arguments() {
  return getRuleContext<JavaScriptParser::ArgumentsContext>(0);
}

JavaScriptParser::NewExpressionContext::NewExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::NewExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewExpression(this);
}
void JavaScriptParser::NewExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewExpression(this);
}

antlrcpp::Any JavaScriptParser::NewExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitNewExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExpressionContext ------------------------------------------------------------------

JavaScriptParser::LiteralContext* JavaScriptParser::LiteralExpressionContext::literal() {
  return getRuleContext<JavaScriptParser::LiteralContext>(0);
}

JavaScriptParser::LiteralExpressionContext::LiteralExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::LiteralExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralExpression(this);
}
void JavaScriptParser::LiteralExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralExpression(this);
}

antlrcpp::Any JavaScriptParser::LiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayLiteralExpressionContext ------------------------------------------------------------------

JavaScriptParser::ArrayLiteralContext* JavaScriptParser::ArrayLiteralExpressionContext::arrayLiteral() {
  return getRuleContext<JavaScriptParser::ArrayLiteralContext>(0);
}

JavaScriptParser::ArrayLiteralExpressionContext::ArrayLiteralExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ArrayLiteralExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayLiteralExpression(this);
}
void JavaScriptParser::ArrayLiteralExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayLiteralExpression(this);
}

antlrcpp::Any JavaScriptParser::ArrayLiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrayLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberDotExpressionContext ------------------------------------------------------------------

JavaScriptParser::SingleExpressionContext* JavaScriptParser::MemberDotExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* JavaScriptParser::MemberDotExpressionContext::Dot() {
  return getToken(JavaScriptParser::Dot, 0);
}

JavaScriptParser::IdentifierNameContext* JavaScriptParser::MemberDotExpressionContext::identifierName() {
  return getRuleContext<JavaScriptParser::IdentifierNameContext>(0);
}

JavaScriptParser::MemberDotExpressionContext::MemberDotExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::MemberDotExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberDotExpression(this);
}
void JavaScriptParser::MemberDotExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberDotExpression(this);
}

antlrcpp::Any JavaScriptParser::MemberDotExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitMemberDotExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::ClassExpressionContext::Class() {
  return getToken(JavaScriptParser::Class, 0);
}

JavaScriptParser::ClassTailContext* JavaScriptParser::ClassExpressionContext::classTail() {
  return getRuleContext<JavaScriptParser::ClassTailContext>(0);
}

tree::TerminalNode* JavaScriptParser::ClassExpressionContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::ClassExpressionContext::ClassExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::ClassExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassExpression(this);
}
void JavaScriptParser::ClassExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassExpression(this);
}

antlrcpp::Any JavaScriptParser::ClassExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitClassExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberIndexExpressionContext ------------------------------------------------------------------

JavaScriptParser::SingleExpressionContext* JavaScriptParser::MemberIndexExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* JavaScriptParser::MemberIndexExpressionContext::OpenBracket() {
  return getToken(JavaScriptParser::OpenBracket, 0);
}

JavaScriptParser::ExpressionSequenceContext* JavaScriptParser::MemberIndexExpressionContext::expressionSequence() {
  return getRuleContext<JavaScriptParser::ExpressionSequenceContext>(0);
}

tree::TerminalNode* JavaScriptParser::MemberIndexExpressionContext::CloseBracket() {
  return getToken(JavaScriptParser::CloseBracket, 0);
}

JavaScriptParser::MemberIndexExpressionContext::MemberIndexExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::MemberIndexExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberIndexExpression(this);
}
void JavaScriptParser::MemberIndexExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberIndexExpression(this);
}

antlrcpp::Any JavaScriptParser::MemberIndexExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitMemberIndexExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::IdentifierExpressionContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::IdentifierExpressionContext::IdentifierExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::IdentifierExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierExpression(this);
}
void JavaScriptParser::IdentifierExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierExpression(this);
}

antlrcpp::Any JavaScriptParser::IdentifierExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitAndExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::BitAndExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::BitAndExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::BitAndExpressionContext::BitAnd() {
  return getToken(JavaScriptParser::BitAnd, 0);
}

JavaScriptParser::BitAndExpressionContext::BitAndExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::BitAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitAndExpression(this);
}
void JavaScriptParser::BitAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitAndExpression(this);
}

antlrcpp::Any JavaScriptParser::BitAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitBitAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitOrExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::BitOrExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::BitOrExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

tree::TerminalNode* JavaScriptParser::BitOrExpressionContext::BitOr() {
  return getToken(JavaScriptParser::BitOr, 0);
}

JavaScriptParser::BitOrExpressionContext::BitOrExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::BitOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitOrExpression(this);
}
void JavaScriptParser::BitOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitOrExpression(this);
}

antlrcpp::Any JavaScriptParser::BitOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitBitOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentOperatorExpressionContext ------------------------------------------------------------------

std::vector<JavaScriptParser::SingleExpressionContext *> JavaScriptParser::AssignmentOperatorExpressionContext::singleExpression() {
  return getRuleContexts<JavaScriptParser::SingleExpressionContext>();
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::AssignmentOperatorExpressionContext::singleExpression(size_t i) {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(i);
}

JavaScriptParser::AssignmentOperatorContext* JavaScriptParser::AssignmentOperatorExpressionContext::assignmentOperator() {
  return getRuleContext<JavaScriptParser::AssignmentOperatorContext>(0);
}

JavaScriptParser::AssignmentOperatorExpressionContext::AssignmentOperatorExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::AssignmentOperatorExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperatorExpression(this);
}
void JavaScriptParser::AssignmentOperatorExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperatorExpression(this);
}

antlrcpp::Any JavaScriptParser::AssignmentOperatorExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperatorExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VoidExpressionContext ------------------------------------------------------------------

tree::TerminalNode* JavaScriptParser::VoidExpressionContext::Void() {
  return getToken(JavaScriptParser::Void, 0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::VoidExpressionContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

JavaScriptParser::VoidExpressionContext::VoidExpressionContext(SingleExpressionContext *ctx) { copyFrom(ctx); }

void JavaScriptParser::VoidExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoidExpression(this);
}
void JavaScriptParser::VoidExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoidExpression(this);
}

antlrcpp::Any JavaScriptParser::VoidExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitVoidExpression(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::singleExpression() {
   return singleExpression(0);
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::singleExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  JavaScriptParser::SingleExpressionContext *_localctx = _tracker.createInstance<SingleExpressionContext>(_ctx, parentState);
  JavaScriptParser::SingleExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 116;
  enterRecursionRule(_localctx, 116, JavaScriptParser::RuleSingleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(777);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<FunctionExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(718);
      match(JavaScriptParser::Function);
      setState(720);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JavaScriptParser::Identifier) {
        setState(719);
        match(JavaScriptParser::Identifier);
      }
      setState(722);
      match(JavaScriptParser::OpenParen);
      setState(724);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << JavaScriptParser::OpenBracket)
        | (1ULL << JavaScriptParser::OpenBrace)
        | (1ULL << JavaScriptParser::Ellipsis))) != 0) || _la == JavaScriptParser::Identifier) {
        setState(723);
        formalParameterList();
      }
      setState(726);
      match(JavaScriptParser::CloseParen);
      setState(727);
      match(JavaScriptParser::OpenBrace);
      setState(728);
      functionBody();
      setState(729);
      match(JavaScriptParser::CloseBrace);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ClassExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(731);
      match(JavaScriptParser::Class);
      setState(733);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == JavaScriptParser::Identifier) {
        setState(732);
        match(JavaScriptParser::Identifier);
      }
      setState(735);
      classTail();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NewExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(736);
      match(JavaScriptParser::New);
      setState(737);
      singleExpression(0);
      setState(739);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
      case 1: {
        setState(738);
        arguments();
        break;
      }

      }
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<DeleteExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(741);
      match(JavaScriptParser::Delete);
      setState(742);
      singleExpression(37);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<VoidExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(743);
      match(JavaScriptParser::Void);
      setState(744);
      singleExpression(36);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<TypeofExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(745);
      match(JavaScriptParser::Typeof);
      setState(746);
      singleExpression(35);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<PreIncrementExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(747);
      match(JavaScriptParser::PlusPlus);
      setState(748);
      singleExpression(34);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<PreDecreaseExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(749);
      match(JavaScriptParser::MinusMinus);
      setState(750);
      singleExpression(33);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<UnaryPlusExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(751);
      match(JavaScriptParser::Plus);
      setState(752);
      singleExpression(32);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<UnaryMinusExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(753);
      match(JavaScriptParser::Minus);
      setState(754);
      singleExpression(31);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<BitNotExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(755);
      match(JavaScriptParser::BitNot);
      setState(756);
      singleExpression(30);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<NotExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(757);
      match(JavaScriptParser::Not);
      setState(758);
      singleExpression(29);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<IteratorsExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(759);
      iteratorBlock();
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<GeneratorsExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(760);
      generatorBlock();
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<GeneratorsFunctionExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(761);
      generatorFunctionDeclaration();
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<YieldExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(762);
      yieldStatement();
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<ThisExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(763);
      match(JavaScriptParser::This);
      break;
    }

    case 18: {
      _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(764);
      match(JavaScriptParser::Identifier);
      break;
    }

    case 19: {
      _localctx = _tracker.createInstance<SuperExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(765);
      match(JavaScriptParser::Super);
      break;
    }

    case 20: {
      _localctx = _tracker.createInstance<LiteralExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(766);
      literal();
      break;
    }

    case 21: {
      _localctx = _tracker.createInstance<ArrayLiteralExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(767);
      arrayLiteral();
      break;
    }

    case 22: {
      _localctx = _tracker.createInstance<ObjectLiteralExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(768);
      objectLiteral();
      break;
    }

    case 23: {
      _localctx = _tracker.createInstance<ParenthesizedExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(769);
      match(JavaScriptParser::OpenParen);
      setState(770);
      expressionSequence();
      setState(771);
      match(JavaScriptParser::CloseParen);
      break;
    }

    case 24: {
      _localctx = _tracker.createInstance<ArrowFunctionExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(773);
      arrowFunctionParameters();
      setState(774);
      match(JavaScriptParser::ARROW);
      setState(775);
      arrowFunctionBody();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(848);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(846);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplicativeExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(779);

          if (!(precpred(_ctx, 28))) throw FailedPredicateException(this, "precpred(_ctx, 28)");
          setState(780);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << JavaScriptParser::Multiply)
            | (1ULL << JavaScriptParser::Divide)
            | (1ULL << JavaScriptParser::Modulus))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(781);
          singleExpression(29);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AdditiveExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(782);

          if (!(precpred(_ctx, 27))) throw FailedPredicateException(this, "precpred(_ctx, 27)");
          setState(783);
          _la = _input->LA(1);
          if (!(_la == JavaScriptParser::Plus

          || _la == JavaScriptParser::Minus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(784);
          singleExpression(28);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitShiftExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(785);

          if (!(precpred(_ctx, 26))) throw FailedPredicateException(this, "precpred(_ctx, 26)");
          setState(786);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << JavaScriptParser::RightShiftArithmetic)
            | (1ULL << JavaScriptParser::LeftShiftArithmetic)
            | (1ULL << JavaScriptParser::RightShiftLogical))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(787);
          singleExpression(27);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<RelationalExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(788);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(789);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << JavaScriptParser::LessThan)
            | (1ULL << JavaScriptParser::MoreThan)
            | (1ULL << JavaScriptParser::LessThanEquals)
            | (1ULL << JavaScriptParser::GreaterThanEquals))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(790);
          singleExpression(26);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<InstanceofExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(791);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(792);
          match(JavaScriptParser::Instanceof);
          setState(793);
          singleExpression(25);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<InExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(794);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(795);
          match(JavaScriptParser::In);
          setState(796);
          singleExpression(24);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<EqualityExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(797);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(798);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << JavaScriptParser::Equals_)
            | (1ULL << JavaScriptParser::NotEquals)
            | (1ULL << JavaScriptParser::IdentityEquals)
            | (1ULL << JavaScriptParser::IdentityNotEquals))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(799);
          singleExpression(23);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitAndExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(800);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(801);
          match(JavaScriptParser::BitAnd);
          setState(802);
          singleExpression(22);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BitXOrExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(803);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(804);
          match(JavaScriptParser::BitXOr);
          setState(805);
          singleExpression(21);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BitOrExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(806);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(807);
          match(JavaScriptParser::BitOr);
          setState(808);
          singleExpression(20);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<LogicalAndExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(809);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(810);
          match(JavaScriptParser::And);
          setState(811);
          singleExpression(19);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<LogicalOrExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(812);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(813);
          match(JavaScriptParser::Or);
          setState(814);
          singleExpression(18);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<TernaryExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(815);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(816);
          match(JavaScriptParser::QuestionMark);
          setState(817);
          singleExpression(0);
          setState(818);
          match(JavaScriptParser::Colon);
          setState(819);
          singleExpression(17);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<AssignmentExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(821);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(822);
          match(JavaScriptParser::Assign);
          setState(823);
          singleExpression(16);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<AssignmentOperatorExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(824);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(825);
          assignmentOperator();
          setState(826);
          singleExpression(15);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<MemberIndexExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(828);

          if (!(precpred(_ctx, 43))) throw FailedPredicateException(this, "precpred(_ctx, 43)");
          setState(829);
          match(JavaScriptParser::OpenBracket);
          setState(830);
          expressionSequence();
          setState(831);
          match(JavaScriptParser::CloseBracket);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<MemberDotExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(833);

          if (!(precpred(_ctx, 42))) throw FailedPredicateException(this, "precpred(_ctx, 42)");
          setState(834);
          match(JavaScriptParser::Dot);
          setState(835);
          identifierName();
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<ArgumentsExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(836);

          if (!(precpred(_ctx, 41))) throw FailedPredicateException(this, "precpred(_ctx, 41)");
          setState(837);
          arguments();
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<PostIncrementExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(838);

          if (!(precpred(_ctx, 39))) throw FailedPredicateException(this, "precpred(_ctx, 39)");
          setState(839);

          if (!(this->notLineTerminator())) throw FailedPredicateException(this, "this->notLineTerminator()");
          setState(840);
          match(JavaScriptParser::PlusPlus);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<PostDecreaseExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(841);

          if (!(precpred(_ctx, 38))) throw FailedPredicateException(this, "precpred(_ctx, 38)");
          setState(842);

          if (!(this->notLineTerminator())) throw FailedPredicateException(this, "this->notLineTerminator()");
          setState(843);
          match(JavaScriptParser::MinusMinus);
          break;
        }

        case 21: {
          auto newContext = _tracker.createInstance<TemplateStringExpressionContext>(_tracker.createInstance<SingleExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleSingleExpression);
          setState(844);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(845);
          match(JavaScriptParser::TemplateStringLiteral);
          break;
        }

        } 
      }
      setState(850);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArrowFunctionParametersContext ------------------------------------------------------------------

JavaScriptParser::ArrowFunctionParametersContext::ArrowFunctionParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::ArrowFunctionParametersContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

tree::TerminalNode* JavaScriptParser::ArrowFunctionParametersContext::OpenParen() {
  return getToken(JavaScriptParser::OpenParen, 0);
}

tree::TerminalNode* JavaScriptParser::ArrowFunctionParametersContext::CloseParen() {
  return getToken(JavaScriptParser::CloseParen, 0);
}

JavaScriptParser::FormalParameterListContext* JavaScriptParser::ArrowFunctionParametersContext::formalParameterList() {
  return getRuleContext<JavaScriptParser::FormalParameterListContext>(0);
}


size_t JavaScriptParser::ArrowFunctionParametersContext::getRuleIndex() const {
  return JavaScriptParser::RuleArrowFunctionParameters;
}

void JavaScriptParser::ArrowFunctionParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrowFunctionParameters(this);
}

void JavaScriptParser::ArrowFunctionParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrowFunctionParameters(this);
}


antlrcpp::Any JavaScriptParser::ArrowFunctionParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrowFunctionParameters(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ArrowFunctionParametersContext* JavaScriptParser::arrowFunctionParameters() {
  ArrowFunctionParametersContext *_localctx = _tracker.createInstance<ArrowFunctionParametersContext>(_ctx, getState());
  enterRule(_localctx, 118, JavaScriptParser::RuleArrowFunctionParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(857);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(851);
        match(JavaScriptParser::Identifier);
        break;
      }

      case JavaScriptParser::OpenParen: {
        enterOuterAlt(_localctx, 2);
        setState(852);
        match(JavaScriptParser::OpenParen);
        setState(854);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << JavaScriptParser::OpenBracket)
          | (1ULL << JavaScriptParser::OpenBrace)
          | (1ULL << JavaScriptParser::Ellipsis))) != 0) || _la == JavaScriptParser::Identifier) {
          setState(853);
          formalParameterList();
        }
        setState(856);
        match(JavaScriptParser::CloseParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrowFunctionBodyContext ------------------------------------------------------------------

JavaScriptParser::ArrowFunctionBodyContext::ArrowFunctionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaScriptParser::SingleExpressionContext* JavaScriptParser::ArrowFunctionBodyContext::singleExpression() {
  return getRuleContext<JavaScriptParser::SingleExpressionContext>(0);
}

tree::TerminalNode* JavaScriptParser::ArrowFunctionBodyContext::OpenBrace() {
  return getToken(JavaScriptParser::OpenBrace, 0);
}

JavaScriptParser::FunctionBodyContext* JavaScriptParser::ArrowFunctionBodyContext::functionBody() {
  return getRuleContext<JavaScriptParser::FunctionBodyContext>(0);
}

tree::TerminalNode* JavaScriptParser::ArrowFunctionBodyContext::CloseBrace() {
  return getToken(JavaScriptParser::CloseBrace, 0);
}


size_t JavaScriptParser::ArrowFunctionBodyContext::getRuleIndex() const {
  return JavaScriptParser::RuleArrowFunctionBody;
}

void JavaScriptParser::ArrowFunctionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrowFunctionBody(this);
}

void JavaScriptParser::ArrowFunctionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrowFunctionBody(this);
}


antlrcpp::Any JavaScriptParser::ArrowFunctionBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitArrowFunctionBody(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ArrowFunctionBodyContext* JavaScriptParser::arrowFunctionBody() {
  ArrowFunctionBodyContext *_localctx = _tracker.createInstance<ArrowFunctionBodyContext>(_ctx, getState());
  enterRule(_localctx, 120, JavaScriptParser::RuleArrowFunctionBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(864);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(859);
      singleExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(860);
      match(JavaScriptParser::OpenBrace);
      setState(861);
      functionBody();
      setState(862);
      match(JavaScriptParser::CloseBrace);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

JavaScriptParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::MultiplyAssign() {
  return getToken(JavaScriptParser::MultiplyAssign, 0);
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::DivideAssign() {
  return getToken(JavaScriptParser::DivideAssign, 0);
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::ModulusAssign() {
  return getToken(JavaScriptParser::ModulusAssign, 0);
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::PlusAssign() {
  return getToken(JavaScriptParser::PlusAssign, 0);
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::MinusAssign() {
  return getToken(JavaScriptParser::MinusAssign, 0);
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::LeftShiftArithmeticAssign() {
  return getToken(JavaScriptParser::LeftShiftArithmeticAssign, 0);
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::RightShiftArithmeticAssign() {
  return getToken(JavaScriptParser::RightShiftArithmeticAssign, 0);
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::RightShiftLogicalAssign() {
  return getToken(JavaScriptParser::RightShiftLogicalAssign, 0);
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::BitAndAssign() {
  return getToken(JavaScriptParser::BitAndAssign, 0);
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::BitXorAssign() {
  return getToken(JavaScriptParser::BitXorAssign, 0);
}

tree::TerminalNode* JavaScriptParser::AssignmentOperatorContext::BitOrAssign() {
  return getToken(JavaScriptParser::BitOrAssign, 0);
}


size_t JavaScriptParser::AssignmentOperatorContext::getRuleIndex() const {
  return JavaScriptParser::RuleAssignmentOperator;
}

void JavaScriptParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void JavaScriptParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


antlrcpp::Any JavaScriptParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::AssignmentOperatorContext* JavaScriptParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 122, JavaScriptParser::RuleAssignmentOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(866);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaScriptParser::MultiplyAssign)
      | (1ULL << JavaScriptParser::DivideAssign)
      | (1ULL << JavaScriptParser::ModulusAssign)
      | (1ULL << JavaScriptParser::PlusAssign)
      | (1ULL << JavaScriptParser::MinusAssign)
      | (1ULL << JavaScriptParser::LeftShiftArithmeticAssign)
      | (1ULL << JavaScriptParser::RightShiftArithmeticAssign)
      | (1ULL << JavaScriptParser::RightShiftLogicalAssign)
      | (1ULL << JavaScriptParser::BitAndAssign)
      | (1ULL << JavaScriptParser::BitXorAssign)
      | (1ULL << JavaScriptParser::BitOrAssign))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

JavaScriptParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::LiteralContext::NullLiteral() {
  return getToken(JavaScriptParser::NullLiteral, 0);
}

tree::TerminalNode* JavaScriptParser::LiteralContext::BooleanLiteral() {
  return getToken(JavaScriptParser::BooleanLiteral, 0);
}

tree::TerminalNode* JavaScriptParser::LiteralContext::StringLiteral() {
  return getToken(JavaScriptParser::StringLiteral, 0);
}

tree::TerminalNode* JavaScriptParser::LiteralContext::TemplateStringLiteral() {
  return getToken(JavaScriptParser::TemplateStringLiteral, 0);
}

tree::TerminalNode* JavaScriptParser::LiteralContext::RegularExpressionLiteral() {
  return getToken(JavaScriptParser::RegularExpressionLiteral, 0);
}

JavaScriptParser::NumericLiteralContext* JavaScriptParser::LiteralContext::numericLiteral() {
  return getRuleContext<JavaScriptParser::NumericLiteralContext>(0);
}


size_t JavaScriptParser::LiteralContext::getRuleIndex() const {
  return JavaScriptParser::RuleLiteral;
}

void JavaScriptParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void JavaScriptParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any JavaScriptParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::LiteralContext* JavaScriptParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 124, JavaScriptParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(874);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::NullLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(868);
        match(JavaScriptParser::NullLiteral);
        break;
      }

      case JavaScriptParser::BooleanLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(869);
        match(JavaScriptParser::BooleanLiteral);
        break;
      }

      case JavaScriptParser::StringLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(870);
        match(JavaScriptParser::StringLiteral);
        break;
      }

      case JavaScriptParser::TemplateStringLiteral: {
        enterOuterAlt(_localctx, 4);
        setState(871);
        match(JavaScriptParser::TemplateStringLiteral);
        break;
      }

      case JavaScriptParser::RegularExpressionLiteral: {
        enterOuterAlt(_localctx, 5);
        setState(872);
        match(JavaScriptParser::RegularExpressionLiteral);
        break;
      }

      case JavaScriptParser::DecimalLiteral:
      case JavaScriptParser::HexIntegerLiteral:
      case JavaScriptParser::OctalIntegerLiteral:
      case JavaScriptParser::OctalIntegerLiteral2:
      case JavaScriptParser::BinaryIntegerLiteral: {
        enterOuterAlt(_localctx, 6);
        setState(873);
        numericLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericLiteralContext ------------------------------------------------------------------

JavaScriptParser::NumericLiteralContext::NumericLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::NumericLiteralContext::DecimalLiteral() {
  return getToken(JavaScriptParser::DecimalLiteral, 0);
}

tree::TerminalNode* JavaScriptParser::NumericLiteralContext::HexIntegerLiteral() {
  return getToken(JavaScriptParser::HexIntegerLiteral, 0);
}

tree::TerminalNode* JavaScriptParser::NumericLiteralContext::OctalIntegerLiteral() {
  return getToken(JavaScriptParser::OctalIntegerLiteral, 0);
}

tree::TerminalNode* JavaScriptParser::NumericLiteralContext::OctalIntegerLiteral2() {
  return getToken(JavaScriptParser::OctalIntegerLiteral2, 0);
}

tree::TerminalNode* JavaScriptParser::NumericLiteralContext::BinaryIntegerLiteral() {
  return getToken(JavaScriptParser::BinaryIntegerLiteral, 0);
}


size_t JavaScriptParser::NumericLiteralContext::getRuleIndex() const {
  return JavaScriptParser::RuleNumericLiteral;
}

void JavaScriptParser::NumericLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericLiteral(this);
}

void JavaScriptParser::NumericLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericLiteral(this);
}


antlrcpp::Any JavaScriptParser::NumericLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitNumericLiteral(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::NumericLiteralContext* JavaScriptParser::numericLiteral() {
  NumericLiteralContext *_localctx = _tracker.createInstance<NumericLiteralContext>(_ctx, getState());
  enterRule(_localctx, 126, JavaScriptParser::RuleNumericLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(876);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << JavaScriptParser::DecimalLiteral)
      | (1ULL << JavaScriptParser::HexIntegerLiteral)
      | (1ULL << JavaScriptParser::OctalIntegerLiteral)
      | (1ULL << JavaScriptParser::OctalIntegerLiteral2)
      | (1ULL << JavaScriptParser::BinaryIntegerLiteral))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierNameContext ------------------------------------------------------------------

JavaScriptParser::IdentifierNameContext::IdentifierNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::IdentifierNameContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::ReservedWordContext* JavaScriptParser::IdentifierNameContext::reservedWord() {
  return getRuleContext<JavaScriptParser::ReservedWordContext>(0);
}


size_t JavaScriptParser::IdentifierNameContext::getRuleIndex() const {
  return JavaScriptParser::RuleIdentifierName;
}

void JavaScriptParser::IdentifierNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierName(this);
}

void JavaScriptParser::IdentifierNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierName(this);
}


antlrcpp::Any JavaScriptParser::IdentifierNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierName(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::IdentifierNameContext* JavaScriptParser::identifierName() {
  IdentifierNameContext *_localctx = _tracker.createInstance<IdentifierNameContext>(_ctx, getState());
  enterRule(_localctx, 128, JavaScriptParser::RuleIdentifierName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(880);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(878);
        match(JavaScriptParser::Identifier);
        break;
      }

      case JavaScriptParser::NullLiteral:
      case JavaScriptParser::BooleanLiteral:
      case JavaScriptParser::Break:
      case JavaScriptParser::Do:
      case JavaScriptParser::Instanceof:
      case JavaScriptParser::Typeof:
      case JavaScriptParser::Case:
      case JavaScriptParser::Else:
      case JavaScriptParser::New:
      case JavaScriptParser::Var:
      case JavaScriptParser::Catch:
      case JavaScriptParser::Finally:
      case JavaScriptParser::Return:
      case JavaScriptParser::Void:
      case JavaScriptParser::Continue:
      case JavaScriptParser::For:
      case JavaScriptParser::Switch:
      case JavaScriptParser::While:
      case JavaScriptParser::Debugger:
      case JavaScriptParser::Function:
      case JavaScriptParser::This:
      case JavaScriptParser::With:
      case JavaScriptParser::Default:
      case JavaScriptParser::If:
      case JavaScriptParser::Throw:
      case JavaScriptParser::Delete:
      case JavaScriptParser::In:
      case JavaScriptParser::Try:
      case JavaScriptParser::Class:
      case JavaScriptParser::Enum:
      case JavaScriptParser::Extends:
      case JavaScriptParser::Super:
      case JavaScriptParser::Const:
      case JavaScriptParser::Export:
      case JavaScriptParser::Import:
      case JavaScriptParser::Implements:
      case JavaScriptParser::Let:
      case JavaScriptParser::Private:
      case JavaScriptParser::Public:
      case JavaScriptParser::Interface:
      case JavaScriptParser::Package:
      case JavaScriptParser::Protected:
      case JavaScriptParser::Static:
      case JavaScriptParser::Yield: {
        enterOuterAlt(_localctx, 2);
        setState(879);
        reservedWord();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReservedWordContext ------------------------------------------------------------------

JavaScriptParser::ReservedWordContext::ReservedWordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

JavaScriptParser::KeywordContext* JavaScriptParser::ReservedWordContext::keyword() {
  return getRuleContext<JavaScriptParser::KeywordContext>(0);
}

tree::TerminalNode* JavaScriptParser::ReservedWordContext::NullLiteral() {
  return getToken(JavaScriptParser::NullLiteral, 0);
}

tree::TerminalNode* JavaScriptParser::ReservedWordContext::BooleanLiteral() {
  return getToken(JavaScriptParser::BooleanLiteral, 0);
}


size_t JavaScriptParser::ReservedWordContext::getRuleIndex() const {
  return JavaScriptParser::RuleReservedWord;
}

void JavaScriptParser::ReservedWordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReservedWord(this);
}

void JavaScriptParser::ReservedWordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReservedWord(this);
}


antlrcpp::Any JavaScriptParser::ReservedWordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitReservedWord(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::ReservedWordContext* JavaScriptParser::reservedWord() {
  ReservedWordContext *_localctx = _tracker.createInstance<ReservedWordContext>(_ctx, getState());
  enterRule(_localctx, 130, JavaScriptParser::RuleReservedWord);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(885);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case JavaScriptParser::Break:
      case JavaScriptParser::Do:
      case JavaScriptParser::Instanceof:
      case JavaScriptParser::Typeof:
      case JavaScriptParser::Case:
      case JavaScriptParser::Else:
      case JavaScriptParser::New:
      case JavaScriptParser::Var:
      case JavaScriptParser::Catch:
      case JavaScriptParser::Finally:
      case JavaScriptParser::Return:
      case JavaScriptParser::Void:
      case JavaScriptParser::Continue:
      case JavaScriptParser::For:
      case JavaScriptParser::Switch:
      case JavaScriptParser::While:
      case JavaScriptParser::Debugger:
      case JavaScriptParser::Function:
      case JavaScriptParser::This:
      case JavaScriptParser::With:
      case JavaScriptParser::Default:
      case JavaScriptParser::If:
      case JavaScriptParser::Throw:
      case JavaScriptParser::Delete:
      case JavaScriptParser::In:
      case JavaScriptParser::Try:
      case JavaScriptParser::Class:
      case JavaScriptParser::Enum:
      case JavaScriptParser::Extends:
      case JavaScriptParser::Super:
      case JavaScriptParser::Const:
      case JavaScriptParser::Export:
      case JavaScriptParser::Import:
      case JavaScriptParser::Implements:
      case JavaScriptParser::Let:
      case JavaScriptParser::Private:
      case JavaScriptParser::Public:
      case JavaScriptParser::Interface:
      case JavaScriptParser::Package:
      case JavaScriptParser::Protected:
      case JavaScriptParser::Static:
      case JavaScriptParser::Yield: {
        enterOuterAlt(_localctx, 1);
        setState(882);
        keyword();
        break;
      }

      case JavaScriptParser::NullLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(883);
        match(JavaScriptParser::NullLiteral);
        break;
      }

      case JavaScriptParser::BooleanLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(884);
        match(JavaScriptParser::BooleanLiteral);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

JavaScriptParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Break() {
  return getToken(JavaScriptParser::Break, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Do() {
  return getToken(JavaScriptParser::Do, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Instanceof() {
  return getToken(JavaScriptParser::Instanceof, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Typeof() {
  return getToken(JavaScriptParser::Typeof, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Case() {
  return getToken(JavaScriptParser::Case, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Else() {
  return getToken(JavaScriptParser::Else, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::New() {
  return getToken(JavaScriptParser::New, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Var() {
  return getToken(JavaScriptParser::Var, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Catch() {
  return getToken(JavaScriptParser::Catch, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Finally() {
  return getToken(JavaScriptParser::Finally, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Return() {
  return getToken(JavaScriptParser::Return, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Void() {
  return getToken(JavaScriptParser::Void, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Continue() {
  return getToken(JavaScriptParser::Continue, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::For() {
  return getToken(JavaScriptParser::For, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Switch() {
  return getToken(JavaScriptParser::Switch, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::While() {
  return getToken(JavaScriptParser::While, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Debugger() {
  return getToken(JavaScriptParser::Debugger, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Function() {
  return getToken(JavaScriptParser::Function, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::This() {
  return getToken(JavaScriptParser::This, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::With() {
  return getToken(JavaScriptParser::With, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Default() {
  return getToken(JavaScriptParser::Default, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::If() {
  return getToken(JavaScriptParser::If, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Throw() {
  return getToken(JavaScriptParser::Throw, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Delete() {
  return getToken(JavaScriptParser::Delete, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::In() {
  return getToken(JavaScriptParser::In, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Try() {
  return getToken(JavaScriptParser::Try, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Class() {
  return getToken(JavaScriptParser::Class, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Enum() {
  return getToken(JavaScriptParser::Enum, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Extends() {
  return getToken(JavaScriptParser::Extends, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Super() {
  return getToken(JavaScriptParser::Super, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Const() {
  return getToken(JavaScriptParser::Const, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Export() {
  return getToken(JavaScriptParser::Export, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Import() {
  return getToken(JavaScriptParser::Import, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Implements() {
  return getToken(JavaScriptParser::Implements, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Let() {
  return getToken(JavaScriptParser::Let, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Private() {
  return getToken(JavaScriptParser::Private, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Public() {
  return getToken(JavaScriptParser::Public, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Interface() {
  return getToken(JavaScriptParser::Interface, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Package() {
  return getToken(JavaScriptParser::Package, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Protected() {
  return getToken(JavaScriptParser::Protected, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Static() {
  return getToken(JavaScriptParser::Static, 0);
}

tree::TerminalNode* JavaScriptParser::KeywordContext::Yield() {
  return getToken(JavaScriptParser::Yield, 0);
}


size_t JavaScriptParser::KeywordContext::getRuleIndex() const {
  return JavaScriptParser::RuleKeyword;
}

void JavaScriptParser::KeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword(this);
}

void JavaScriptParser::KeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword(this);
}


antlrcpp::Any JavaScriptParser::KeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitKeyword(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::KeywordContext* JavaScriptParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 132, JavaScriptParser::RuleKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(887);
    _la = _input->LA(1);
    if (!(((((_la - 61) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 61)) & ((1ULL << (JavaScriptParser::Break - 61))
      | (1ULL << (JavaScriptParser::Do - 61))
      | (1ULL << (JavaScriptParser::Instanceof - 61))
      | (1ULL << (JavaScriptParser::Typeof - 61))
      | (1ULL << (JavaScriptParser::Case - 61))
      | (1ULL << (JavaScriptParser::Else - 61))
      | (1ULL << (JavaScriptParser::New - 61))
      | (1ULL << (JavaScriptParser::Var - 61))
      | (1ULL << (JavaScriptParser::Catch - 61))
      | (1ULL << (JavaScriptParser::Finally - 61))
      | (1ULL << (JavaScriptParser::Return - 61))
      | (1ULL << (JavaScriptParser::Void - 61))
      | (1ULL << (JavaScriptParser::Continue - 61))
      | (1ULL << (JavaScriptParser::For - 61))
      | (1ULL << (JavaScriptParser::Switch - 61))
      | (1ULL << (JavaScriptParser::While - 61))
      | (1ULL << (JavaScriptParser::Debugger - 61))
      | (1ULL << (JavaScriptParser::Function - 61))
      | (1ULL << (JavaScriptParser::This - 61))
      | (1ULL << (JavaScriptParser::With - 61))
      | (1ULL << (JavaScriptParser::Default - 61))
      | (1ULL << (JavaScriptParser::If - 61))
      | (1ULL << (JavaScriptParser::Throw - 61))
      | (1ULL << (JavaScriptParser::Delete - 61))
      | (1ULL << (JavaScriptParser::In - 61))
      | (1ULL << (JavaScriptParser::Try - 61))
      | (1ULL << (JavaScriptParser::Class - 61))
      | (1ULL << (JavaScriptParser::Enum - 61))
      | (1ULL << (JavaScriptParser::Extends - 61))
      | (1ULL << (JavaScriptParser::Super - 61))
      | (1ULL << (JavaScriptParser::Const - 61))
      | (1ULL << (JavaScriptParser::Export - 61))
      | (1ULL << (JavaScriptParser::Import - 61))
      | (1ULL << (JavaScriptParser::Implements - 61))
      | (1ULL << (JavaScriptParser::Let - 61))
      | (1ULL << (JavaScriptParser::Private - 61))
      | (1ULL << (JavaScriptParser::Public - 61))
      | (1ULL << (JavaScriptParser::Interface - 61))
      | (1ULL << (JavaScriptParser::Package - 61))
      | (1ULL << (JavaScriptParser::Protected - 61))
      | (1ULL << (JavaScriptParser::Static - 61))
      | (1ULL << (JavaScriptParser::Yield - 61)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GetterContext ------------------------------------------------------------------

JavaScriptParser::GetterContext::GetterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::GetterContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::PropertyNameContext* JavaScriptParser::GetterContext::propertyName() {
  return getRuleContext<JavaScriptParser::PropertyNameContext>(0);
}


size_t JavaScriptParser::GetterContext::getRuleIndex() const {
  return JavaScriptParser::RuleGetter;
}

void JavaScriptParser::GetterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGetter(this);
}

void JavaScriptParser::GetterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGetter(this);
}


antlrcpp::Any JavaScriptParser::GetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitGetter(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::GetterContext* JavaScriptParser::getter() {
  GetterContext *_localctx = _tracker.createInstance<GetterContext>(_ctx, getState());
  enterRule(_localctx, 134, JavaScriptParser::RuleGetter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(889);
    match(JavaScriptParser::Identifier);
    setState(890);

    if (!(this->p("get"))) throw FailedPredicateException(this, "this->p(\"get\")");
    setState(891);
    propertyName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetterContext ------------------------------------------------------------------

JavaScriptParser::SetterContext::SetterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::SetterContext::Identifier() {
  return getToken(JavaScriptParser::Identifier, 0);
}

JavaScriptParser::PropertyNameContext* JavaScriptParser::SetterContext::propertyName() {
  return getRuleContext<JavaScriptParser::PropertyNameContext>(0);
}


size_t JavaScriptParser::SetterContext::getRuleIndex() const {
  return JavaScriptParser::RuleSetter;
}

void JavaScriptParser::SetterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetter(this);
}

void JavaScriptParser::SetterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetter(this);
}


antlrcpp::Any JavaScriptParser::SetterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitSetter(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::SetterContext* JavaScriptParser::setter() {
  SetterContext *_localctx = _tracker.createInstance<SetterContext>(_ctx, getState());
  enterRule(_localctx, 136, JavaScriptParser::RuleSetter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(893);
    match(JavaScriptParser::Identifier);
    setState(894);

    if (!(this->p("set"))) throw FailedPredicateException(this, "this->p(\"set\")");
    setState(895);
    propertyName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EosContext ------------------------------------------------------------------

JavaScriptParser::EosContext::EosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* JavaScriptParser::EosContext::SemiColon() {
  return getToken(JavaScriptParser::SemiColon, 0);
}

tree::TerminalNode* JavaScriptParser::EosContext::EOF() {
  return getToken(JavaScriptParser::EOF, 0);
}


size_t JavaScriptParser::EosContext::getRuleIndex() const {
  return JavaScriptParser::RuleEos;
}

void JavaScriptParser::EosContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEos(this);
}

void JavaScriptParser::EosContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<JavaScriptParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEos(this);
}


antlrcpp::Any JavaScriptParser::EosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<JavaScriptParserVisitor*>(visitor))
    return parserVisitor->visitEos(this);
  else
    return visitor->visitChildren(this);
}

JavaScriptParser::EosContext* JavaScriptParser::eos() {
  EosContext *_localctx = _tracker.createInstance<EosContext>(_ctx, getState());
  enterRule(_localctx, 138, JavaScriptParser::RuleEos);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(901);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(897);
      match(JavaScriptParser::SemiColon);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(898);
      match(JavaScriptParser::EOF);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(899);

      if (!(this->lineTerminatorAhead())) throw FailedPredicateException(this, "this->lineTerminatorAhead()");
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(900);

      if (!(this->closeBrace())) throw FailedPredicateException(this, "this->closeBrace()");
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool JavaScriptParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 13: return expressionStatementSempred(dynamic_cast<ExpressionStatementContext *>(context), predicateIndex);
    case 15: return iterationStatementSempred(dynamic_cast<IterationStatementContext *>(context), predicateIndex);
    case 17: return continueStatementSempred(dynamic_cast<ContinueStatementContext *>(context), predicateIndex);
    case 18: return breakStatementSempred(dynamic_cast<BreakStatementContext *>(context), predicateIndex);
    case 19: return returnStatementSempred(dynamic_cast<ReturnStatementContext *>(context), predicateIndex);
    case 20: return yieldStatementSempred(dynamic_cast<YieldStatementContext *>(context), predicateIndex);
    case 28: return throwStatementSempred(dynamic_cast<ThrowStatementContext *>(context), predicateIndex);
    case 36: return classElementSempred(dynamic_cast<ClassElementContext *>(context), predicateIndex);
    case 58: return singleExpressionSempred(dynamic_cast<SingleExpressionContext *>(context), predicateIndex);
    case 67: return getterSempred(dynamic_cast<GetterContext *>(context), predicateIndex);
    case 68: return setterSempred(dynamic_cast<SetterContext *>(context), predicateIndex);
    case 69: return eosSempred(dynamic_cast<EosContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::expressionStatementSempred(ExpressionStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return this->notOpenBraceAndNotFunction();

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::iterationStatementSempred(IterationStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return this->p("of");
    case 2: return this->p("of");

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::continueStatementSempred(ContinueStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return this->notLineTerminator();

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::breakStatementSempred(BreakStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return this->notLineTerminator();

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::returnStatementSempred(ReturnStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return this->notLineTerminator();

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::yieldStatementSempred(YieldStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return this->notLineTerminator();

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::throwStatementSempred(ThrowStatementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return this->notLineTerminator();

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::classElementSempred(ClassElementContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return this->n("static");

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::singleExpressionSempred(SingleExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 28);
    case 10: return precpred(_ctx, 27);
    case 11: return precpred(_ctx, 26);
    case 12: return precpred(_ctx, 25);
    case 13: return precpred(_ctx, 24);
    case 14: return precpred(_ctx, 23);
    case 15: return precpred(_ctx, 22);
    case 16: return precpred(_ctx, 21);
    case 17: return precpred(_ctx, 20);
    case 18: return precpred(_ctx, 19);
    case 19: return precpred(_ctx, 18);
    case 20: return precpred(_ctx, 17);
    case 21: return precpred(_ctx, 16);
    case 22: return precpred(_ctx, 15);
    case 23: return precpred(_ctx, 14);
    case 24: return precpred(_ctx, 43);
    case 25: return precpred(_ctx, 42);
    case 26: return precpred(_ctx, 41);
    case 27: return precpred(_ctx, 39);
    case 28: return this->notLineTerminator();
    case 29: return precpred(_ctx, 38);
    case 30: return this->notLineTerminator();
    case 31: return precpred(_ctx, 13);

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::getterSempred(GetterContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 32: return this->p("get");

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::setterSempred(SetterContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 33: return this->p("set");

  default:
    break;
  }
  return true;
}

bool JavaScriptParser::eosSempred(EosContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 34: return this->lineTerminatorAhead();
    case 35: return this->closeBrace();

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> JavaScriptParser::_decisionToDFA;
atn::PredictionContextCache JavaScriptParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN JavaScriptParser::_atn;
std::vector<uint16_t> JavaScriptParser::_serializedATN;

std::vector<std::string> JavaScriptParser::_ruleNames = {
  "program", "sourceElement", "statement", "block", "statementList", "importStatement", 
  "fromBlock", "multipleImportStatement", "exportStatement", "variableStatement", 
  "variableDeclarationList", "variableDeclaration", "emptyStatement", "expressionStatement", 
  "ifStatement", "iterationStatement", "varModifier", "continueStatement", 
  "breakStatement", "returnStatement", "yieldStatement", "withStatement", 
  "switchStatement", "caseBlock", "caseClauses", "caseClause", "defaultClause", 
  "labelledStatement", "throwStatement", "tryStatement", "catchProduction", 
  "finallyProduction", "debuggerStatement", "functionDeclaration", "classDeclaration", 
  "classTail", "classElement", "methodDefinition", "generatorMethod", "generatorFunctionDeclaration", 
  "generatorBlock", "generatorDefinition", "iteratorBlock", "iteratorDefinition", 
  "formalParameterList", "formalParameterArg", "lastFormalParameterArg", 
  "functionBody", "sourceElements", "arrayLiteral", "elementList", "lastElement", 
  "objectLiteral", "propertyAssignment", "propertyName", "arguments", "lastArgument", 
  "expressionSequence", "singleExpression", "arrowFunctionParameters", "arrowFunctionBody", 
  "assignmentOperator", "literal", "numericLiteral", "identifierName", "reservedWord", 
  "keyword", "getter", "setter", "eos"
};

std::vector<std::string> JavaScriptParser::_literalNames = {
  "", "", "", "", "'['", "']'", "'('", "')'", "'{'", "'}'", "';'", "','", 
  "'='", "'?'", "':'", "'...'", "'.'", "'++'", "'--'", "'+'", "'-'", "'~'", 
  "'!'", "'*'", "'/'", "'%'", "'>>'", "'<<'", "'>>>'", "'<'", "'>'", "'<='", 
  "'>='", "'=='", "'!='", "'==='", "'!=='", "'&'", "'^'", "'|'", "'&&'", 
  "'||'", "'*='", "'/='", "'%='", "'+='", "'-='", "'<<='", "'>>='", "'>>>='", 
  "'&='", "'^='", "'|='", "'=>'", "'null'", "", "", "", "", "", "", "'break'", 
  "'do'", "'instanceof'", "'typeof'", "'case'", "'else'", "'new'", "'var'", 
  "'catch'", "'finally'", "'return'", "'void'", "'continue'", "'for'", "'switch'", 
  "'while'", "'debugger'", "'function'", "'this'", "'with'", "'default'", 
  "'if'", "'throw'", "'delete'", "'in'", "'try'", "'as'", "'from'", "'class'", 
  "'enum'", "'extends'", "'super'", "'const'", "'export'", "'import'", "'implements'", 
  "'let'", "'private'", "'public'", "'interface'", "'package'", "'protected'", 
  "'static'", "'yield'"
};

std::vector<std::string> JavaScriptParser::_symbolicNames = {
  "", "MultiLineComment", "SingleLineComment", "RegularExpressionLiteral", 
  "OpenBracket", "CloseBracket", "OpenParen", "CloseParen", "OpenBrace", 
  "CloseBrace", "SemiColon", "Comma", "Assign", "QuestionMark", "Colon", 
  "Ellipsis", "Dot", "PlusPlus", "MinusMinus", "Plus", "Minus", "BitNot", 
  "Not", "Multiply", "Divide", "Modulus", "RightShiftArithmetic", "LeftShiftArithmetic", 
  "RightShiftLogical", "LessThan", "MoreThan", "LessThanEquals", "GreaterThanEquals", 
  "Equals_", "NotEquals", "IdentityEquals", "IdentityNotEquals", "BitAnd", 
  "BitXOr", "BitOr", "And", "Or", "MultiplyAssign", "DivideAssign", "ModulusAssign", 
  "PlusAssign", "MinusAssign", "LeftShiftArithmeticAssign", "RightShiftArithmeticAssign", 
  "RightShiftLogicalAssign", "BitAndAssign", "BitXorAssign", "BitOrAssign", 
  "ARROW", "NullLiteral", "BooleanLiteral", "DecimalLiteral", "HexIntegerLiteral", 
  "OctalIntegerLiteral", "OctalIntegerLiteral2", "BinaryIntegerLiteral", 
  "Break", "Do", "Instanceof", "Typeof", "Case", "Else", "New", "Var", "Catch", 
  "Finally", "Return", "Void", "Continue", "For", "Switch", "While", "Debugger", 
  "Function", "This", "With", "Default", "If", "Throw", "Delete", "In", 
  "Try", "As", "From", "Class", "Enum", "Extends", "Super", "Const", "Export", 
  "Import", "Implements", "Let", "Private", "Public", "Interface", "Package", 
  "Protected", "Static", "Yield", "Identifier", "StringLiteral", "TemplateStringLiteral", 
  "WhiteSpaces", "LineTerminator", "HtmlComment", "CDataComment", "UnexpectedCharacter"
};

dfa::Vocabulary JavaScriptParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> JavaScriptParser::_tokenNames;

JavaScriptParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x72, 0x38a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x3, 0x2, 0x5, 0x2, 0x90, 0xa, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x5, 0x3, 0x95, 0xa, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0xae, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xb2, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x6, 0x6, 0xb7, 0xa, 0x6, 0xd, 
    0x6, 0xe, 0x6, 0xb8, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0xc0, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xc4, 0xa, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0xcd, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 
    0x9, 0xd3, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xd6, 0xb, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xdc, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0xe0, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xe9, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 
    0xec, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xf1, 0xa, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xf5, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x104, 0xa, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x117, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x11b, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x11f, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x129, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x12d, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x5, 0x11, 0x138, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x5, 0x11, 0x145, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x14b, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x152, 0xa, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x159, 0xa, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x160, 
    0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 
    0x16, 0x167, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 
    0x179, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x17d, 0xa, 0x19, 
    0x5, 0x19, 0x17f, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x6, 0x1a, 
    0x184, 0xa, 0x1a, 0xd, 0x1a, 0xe, 0x1a, 0x185, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x18c, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x5, 0x1c, 0x191, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x1a0, 0xa, 0x1f, 
    0x3, 0x1f, 0x5, 0x1f, 0x1a3, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x5, 0x23, 0x1b5, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 
    0x25, 0x5, 0x25, 0x1c2, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 
    0x1c6, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x1c9, 0xb, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x1d0, 0xa, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x1d4, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x5, 0x27, 0x1d9, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 
    0x1ea, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x5, 0x27, 0x1f2, 0xa, 0x27, 0x3, 0x28, 0x5, 0x28, 0x1f5, 
    0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1fa, 0xa, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x5, 0x29, 0x204, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x5, 0x29, 0x208, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x213, 
    0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x216, 0xb, 0x2a, 0x5, 0x2a, 0x218, 
    0xa, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x21b, 0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
    0x2c, 0x7, 0x2c, 0x226, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x229, 0xb, 
    0x2c, 0x5, 0x2c, 0x22b, 0xa, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x22e, 0xa, 
    0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x5, 0x2d, 0x237, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x241, 
    0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x244, 0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x5, 0x2e, 0x248, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 
    0x24d, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x252, 
    0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x5, 0x31, 0x258, 
    0xa, 0x31, 0x3, 0x32, 0x6, 0x32, 0x25b, 0xa, 0x32, 0xd, 0x32, 0xe, 0x32, 
    0x25c, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x261, 0xa, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x6, 0x34, 0x267, 0xa, 0x34, 0xd, 0x34, 
    0xe, 0x34, 0x268, 0x3, 0x34, 0x7, 0x34, 0x26c, 0xa, 0x34, 0xc, 0x34, 
    0xe, 0x34, 0x26f, 0xb, 0x34, 0x3, 0x34, 0x6, 0x34, 0x272, 0xa, 0x34, 
    0xd, 0x34, 0xe, 0x34, 0x273, 0x3, 0x34, 0x5, 0x34, 0x277, 0xa, 0x34, 
    0x3, 0x34, 0x5, 0x34, 0x27a, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x5, 0x35, 0x27f, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
    0x7, 0x36, 0x285, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x288, 0xb, 0x36, 
    0x5, 0x36, 0x28a, 0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x28d, 0xa, 0x36, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x2ac, 0xa, 0x37, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x2b1, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x2b7, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 
    0x2ba, 0xb, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x2be, 0xa, 0x39, 
    0x3, 0x39, 0x5, 0x39, 0x2c1, 0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x2cb, 
    0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x2ce, 0xb, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x5, 0x3c, 0x2d3, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 
    0x2d7, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x2e0, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x2e6, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x30c, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x7, 0x3c, 0x351, 0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x354, 0xb, 0x3c, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x359, 0xa, 0x3d, 0x3, 0x3d, 
    0x5, 0x3d, 0x35c, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x5, 0x3e, 0x363, 0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x36d, 
    0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x373, 
    0xa, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x378, 0xa, 0x43, 
    0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 
    0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 
    0x3, 0x47, 0x5, 0x47, 0x388, 0xa, 0x47, 0x3, 0x47, 0x2, 0x3, 0x76, 0x48, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
    0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 
    0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 
    0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x2, 0xc, 0x5, 
    0x2, 0x46, 0x46, 0x5f, 0x5f, 0x63, 0x63, 0x4, 0x2, 0xe, 0xe, 0x10, 0x10, 
    0x3, 0x2, 0x19, 0x1b, 0x3, 0x2, 0x15, 0x16, 0x3, 0x2, 0x1c, 0x1e, 0x3, 
    0x2, 0x1f, 0x22, 0x3, 0x2, 0x23, 0x26, 0x3, 0x2, 0x2c, 0x36, 0x3, 0x2, 
    0x3a, 0x3e, 0x4, 0x2, 0x3f, 0x58, 0x5b, 0x6a, 0x2, 0x3f0, 0x2, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x94, 0x3, 0x2, 0x2, 0x2, 0x6, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0x12, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x14, 0xe1, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x18, 0xf0, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x20, 0x14a, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x24, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x155, 0x3, 0x2, 0x2, 0x2, 0x28, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x163, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x170, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x176, 0x3, 0x2, 0x2, 0x2, 0x32, 0x183, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x187, 0x3, 0x2, 0x2, 0x2, 0x36, 0x18d, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x192, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x196, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1a4, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x1b0, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1c1, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1f1, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x50, 0x200, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x54, 0x21e, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x221, 0x3, 0x2, 0x2, 0x2, 0x58, 0x231, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x253, 0x3, 0x2, 0x2, 0x2, 0x60, 0x257, 0x3, 0x2, 0x2, 0x2, 0x62, 0x25a, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x66, 0x279, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x280, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x2b0, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x72, 0x2c4, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x76, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x35b, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x362, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x364, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x80, 0x36e, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x372, 0x3, 0x2, 0x2, 0x2, 0x84, 0x377, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x379, 0x3, 0x2, 0x2, 0x2, 0x88, 0x37b, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x387, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x90, 0x5, 0x62, 0x32, 0x2, 0x8f, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8f, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 
    0x7, 0x2, 0x2, 0x3, 0x92, 0x3, 0x3, 0x2, 0x2, 0x2, 0x93, 0x95, 0x7, 
    0x60, 0x2, 0x2, 0x94, 0x93, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 
    0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x5, 0x6, 0x4, 
    0x2, 0x97, 0x5, 0x3, 0x2, 0x2, 0x2, 0x98, 0xae, 0x5, 0x8, 0x5, 0x2, 
    0x99, 0xae, 0x5, 0x14, 0xb, 0x2, 0x9a, 0xae, 0x5, 0xc, 0x7, 0x2, 0x9b, 
    0xae, 0x5, 0x12, 0xa, 0x2, 0x9c, 0xae, 0x5, 0x1a, 0xe, 0x2, 0x9d, 0xae, 
    0x5, 0x46, 0x24, 0x2, 0x9e, 0xae, 0x5, 0x1c, 0xf, 0x2, 0x9f, 0xae, 0x5, 
    0x1e, 0x10, 0x2, 0xa0, 0xae, 0x5, 0x20, 0x11, 0x2, 0xa1, 0xae, 0x5, 
    0x24, 0x13, 0x2, 0xa2, 0xae, 0x5, 0x26, 0x14, 0x2, 0xa3, 0xae, 0x5, 
    0x28, 0x15, 0x2, 0xa4, 0xae, 0x5, 0x2a, 0x16, 0x2, 0xa5, 0xae, 0x5, 
    0x2c, 0x17, 0x2, 0xa6, 0xae, 0x5, 0x38, 0x1d, 0x2, 0xa7, 0xae, 0x5, 
    0x2e, 0x18, 0x2, 0xa8, 0xae, 0x5, 0x3a, 0x1e, 0x2, 0xa9, 0xae, 0x5, 
    0x3c, 0x1f, 0x2, 0xaa, 0xae, 0x5, 0x42, 0x22, 0x2, 0xab, 0xae, 0x5, 
    0x44, 0x23, 0x2, 0xac, 0xae, 0x5, 0x50, 0x29, 0x2, 0xad, 0x98, 0x3, 
    0x2, 0x2, 0x2, 0xad, 0x99, 0x3, 0x2, 0x2, 0x2, 0xad, 0x9a, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0x9b, 0x3, 0x2, 0x2, 0x2, 0xad, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xad, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0xad, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0xa1, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0xad, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0xad, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa7, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa9, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 
    0xad, 0xac, 0x3, 0x2, 0x2, 0x2, 0xae, 0x7, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb1, 0x7, 0xa, 0x2, 0x2, 0xb0, 0xb2, 0x5, 0xa, 0x6, 0x2, 0xb1, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0xb, 0x2, 0x2, 0xb4, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xb7, 0x5, 0x6, 0x4, 0x2, 0xb6, 0xb5, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb, 0x3, 0x2, 0x2, 0x2, 0xba, 
    0xbb, 0x7, 0x61, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0xe, 0x8, 0x2, 0xbc, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0xbd, 0xc0, 0x7, 0x19, 0x2, 0x2, 0xbe, 0xc0, 0x5, 
    0x10, 0x9, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x59, 0x2, 
    0x2, 0xc2, 0xc4, 0x5, 0x82, 0x42, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 
    0xc6, 0x7, 0x5a, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x6c, 0x2, 0x2, 0xc7, 0xc8, 
    0x5, 0x8c, 0x47, 0x2, 0xc8, 0xf, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x5, 
    0x82, 0x42, 0x2, 0xca, 0xcb, 0x7, 0xd, 0x2, 0x2, 0xcb, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x7, 0xa, 0x2, 0x2, 
    0xcf, 0xd4, 0x5, 0x82, 0x42, 0x2, 0xd0, 0xd1, 0x7, 0xd, 0x2, 0x2, 0xd1, 
    0xd3, 0x5, 0x82, 0x42, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd6, 
    0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd8, 0x7, 0xb, 0x2, 0x2, 0xd8, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0xdb, 0x7, 0x60, 0x2, 0x2, 0xda, 0xdc, 0x7, 0x53, 0x2, 0x2, 
    0xdb, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xe0, 0x5, 0xe, 0x8, 0x2, 0xde, 0xe0, 
    0x5, 0x6, 0x4, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0x13, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x5, 0x22, 
    0x12, 0x2, 0xe2, 0xe3, 0x5, 0x16, 0xc, 0x2, 0xe3, 0xe4, 0x5, 0x8c, 0x47, 
    0x2, 0xe4, 0x15, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xea, 0x5, 0x18, 0xd, 0x2, 
    0xe6, 0xe7, 0x7, 0xd, 0x2, 0x2, 0xe7, 0xe9, 0x5, 0x18, 0xd, 0x2, 0xe8, 
    0xe6, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xec, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 
    0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xed, 0xf1, 0x7, 0x6b, 
    0x2, 0x2, 0xee, 0xf1, 0x5, 0x64, 0x33, 0x2, 0xef, 0xf1, 0x5, 0x6a, 0x36, 
    0x2, 0xf0, 0xed, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0xf3, 0x7, 0xe, 0x2, 0x2, 0xf3, 0xf5, 0x5, 0x76, 0x3c, 0x2, 0xf4, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0xc, 0x2, 0x2, 0xf7, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0xf8, 0xf9, 0x6, 0xf, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0x74, 0x3b, 
    0x2, 0xfa, 0xfb, 0x5, 0x8c, 0x47, 0x2, 0xfb, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xfd, 0x7, 0x54, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x8, 0x2, 0x2, 0xfe, 
    0xff, 0x5, 0x74, 0x3b, 0x2, 0xff, 0x100, 0x7, 0x9, 0x2, 0x2, 0x100, 
    0x103, 0x5, 0x6, 0x4, 0x2, 0x101, 0x102, 0x7, 0x44, 0x2, 0x2, 0x102, 
    0x104, 0x5, 0x6, 0x4, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 
    0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 
    0x7, 0x40, 0x2, 0x2, 0x106, 0x107, 0x5, 0x6, 0x4, 0x2, 0x107, 0x108, 
    0x7, 0x4e, 0x2, 0x2, 0x108, 0x109, 0x7, 0x8, 0x2, 0x2, 0x109, 0x10a, 
    0x5, 0x74, 0x3b, 0x2, 0x10a, 0x10b, 0x7, 0x9, 0x2, 0x2, 0x10b, 0x10c, 
    0x5, 0x8c, 0x47, 0x2, 0x10c, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 
    0x7, 0x4e, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x8, 0x2, 0x2, 0x10f, 0x110, 
    0x5, 0x74, 0x3b, 0x2, 0x110, 0x111, 0x7, 0x9, 0x2, 0x2, 0x111, 0x112, 
    0x5, 0x6, 0x4, 0x2, 0x112, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 
    0x7, 0x4c, 0x2, 0x2, 0x114, 0x116, 0x7, 0x8, 0x2, 0x2, 0x115, 0x117, 
    0x5, 0x74, 0x3b, 0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 
    0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11a, 
    0x7, 0xc, 0x2, 0x2, 0x119, 0x11b, 0x5, 0x74, 0x3b, 0x2, 0x11a, 0x119, 
    0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 
    0x3, 0x2, 0x2, 0x2, 0x11c, 0x11e, 0x7, 0xc, 0x2, 0x2, 0x11d, 0x11f, 
    0x5, 0x74, 0x3b, 0x2, 0x11e, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 
    0x7, 0x9, 0x2, 0x2, 0x121, 0x14b, 0x5, 0x6, 0x4, 0x2, 0x122, 0x123, 
    0x7, 0x4c, 0x2, 0x2, 0x123, 0x124, 0x7, 0x8, 0x2, 0x2, 0x124, 0x125, 
    0x5, 0x22, 0x12, 0x2, 0x125, 0x126, 0x5, 0x16, 0xc, 0x2, 0x126, 0x128, 
    0x7, 0xc, 0x2, 0x2, 0x127, 0x129, 0x5, 0x74, 0x3b, 0x2, 0x128, 0x127, 
    0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 
    0x3, 0x2, 0x2, 0x2, 0x12a, 0x12c, 0x7, 0xc, 0x2, 0x2, 0x12b, 0x12d, 
    0x5, 0x74, 0x3b, 0x2, 0x12c, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 
    0x7, 0x9, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x6, 0x4, 0x2, 0x130, 0x14b, 
    0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x7, 0x4c, 0x2, 0x2, 0x132, 0x133, 
    0x7, 0x8, 0x2, 0x2, 0x133, 0x137, 0x5, 0x76, 0x3c, 0x2, 0x134, 0x138, 
    0x7, 0x57, 0x2, 0x2, 0x135, 0x136, 0x7, 0x6b, 0x2, 0x2, 0x136, 0x138, 
    0x6, 0x11, 0x3, 0x2, 0x137, 0x134, 0x3, 0x2, 0x2, 0x2, 0x137, 0x135, 
    0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 
    0x5, 0x74, 0x3b, 0x2, 0x13a, 0x13b, 0x7, 0x9, 0x2, 0x2, 0x13b, 0x13c, 
    0x5, 0x6, 0x4, 0x2, 0x13c, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 
    0x7, 0x4c, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x8, 0x2, 0x2, 0x13f, 0x140, 
    0x5, 0x22, 0x12, 0x2, 0x140, 0x144, 0x5, 0x18, 0xd, 0x2, 0x141, 0x145, 
    0x7, 0x57, 0x2, 0x2, 0x142, 0x143, 0x7, 0x6b, 0x2, 0x2, 0x143, 0x145, 
    0x6, 0x11, 0x4, 0x2, 0x144, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x142, 
    0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 
    0x5, 0x74, 0x3b, 0x2, 0x147, 0x148, 0x7, 0x9, 0x2, 0x2, 0x148, 0x149, 
    0x5, 0x6, 0x4, 0x2, 0x149, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x14a, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x14a, 0x122, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x131, 
    0x3, 0x2, 0x2, 0x2, 0x14a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x14c, 0x14d, 0x9, 0x2, 0x2, 0x2, 0x14d, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x151, 0x7, 0x4b, 0x2, 0x2, 0x14f, 0x150, 0x6, 0x13, 
    0x5, 0x2, 0x150, 0x152, 0x7, 0x6b, 0x2, 0x2, 0x151, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x151, 0x152, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x3, 0x2, 
    0x2, 0x2, 0x153, 0x154, 0x5, 0x8c, 0x47, 0x2, 0x154, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x155, 0x158, 0x7, 0x3f, 0x2, 0x2, 0x156, 0x157, 0x6, 0x14, 
    0x6, 0x2, 0x157, 0x159, 0x7, 0x6b, 0x2, 0x2, 0x158, 0x156, 0x3, 0x2, 
    0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x15b, 0x5, 0x8c, 0x47, 0x2, 0x15b, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x15c, 0x15f, 0x7, 0x49, 0x2, 0x2, 0x15d, 0x15e, 0x6, 0x15, 
    0x7, 0x2, 0x15e, 0x160, 0x5, 0x74, 0x3b, 0x2, 0x15f, 0x15d, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x160, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x161, 0x162, 0x5, 0x8c, 0x47, 0x2, 0x162, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x163, 0x166, 0x7, 0x6a, 0x2, 0x2, 0x164, 0x165, 0x6, 0x16, 
    0x8, 0x2, 0x165, 0x167, 0x5, 0x74, 0x3b, 0x2, 0x166, 0x164, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x3, 0x2, 
    0x2, 0x2, 0x168, 0x169, 0x5, 0x8c, 0x47, 0x2, 0x169, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x16a, 0x16b, 0x7, 0x52, 0x2, 0x2, 0x16b, 0x16c, 0x7, 0x8, 
    0x2, 0x2, 0x16c, 0x16d, 0x5, 0x74, 0x3b, 0x2, 0x16d, 0x16e, 0x7, 0x9, 
    0x2, 0x2, 0x16e, 0x16f, 0x5, 0x6, 0x4, 0x2, 0x16f, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x170, 0x171, 0x7, 0x4d, 0x2, 0x2, 0x171, 0x172, 0x7, 0x8, 0x2, 
    0x2, 0x172, 0x173, 0x5, 0x74, 0x3b, 0x2, 0x173, 0x174, 0x7, 0x9, 0x2, 
    0x2, 0x174, 0x175, 0x5, 0x30, 0x19, 0x2, 0x175, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x176, 0x178, 0x7, 0xa, 0x2, 0x2, 0x177, 0x179, 0x5, 0x32, 0x1a, 
    0x2, 0x178, 0x177, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 0x2, 0x2, 
    0x2, 0x179, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17c, 0x5, 0x36, 0x1c, 
    0x2, 0x17b, 0x17d, 0x5, 0x32, 0x1a, 0x2, 0x17c, 0x17b, 0x3, 0x2, 0x2, 
    0x2, 0x17c, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17f, 0x3, 0x2, 0x2, 
    0x2, 0x17e, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x3, 0x2, 0x2, 
    0x2, 0x17f, 0x180, 0x3, 0x2, 0x2, 0x2, 0x180, 0x181, 0x7, 0xb, 0x2, 
    0x2, 0x181, 0x31, 0x3, 0x2, 0x2, 0x2, 0x182, 0x184, 0x5, 0x34, 0x1b, 
    0x2, 0x183, 0x182, 0x3, 0x2, 0x2, 0x2, 0x184, 0x185, 0x3, 0x2, 0x2, 
    0x2, 0x185, 0x183, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x3, 0x2, 0x2, 
    0x2, 0x186, 0x33, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x7, 0x43, 0x2, 
    0x2, 0x188, 0x189, 0x5, 0x74, 0x3b, 0x2, 0x189, 0x18b, 0x7, 0x10, 0x2, 
    0x2, 0x18a, 0x18c, 0x5, 0xa, 0x6, 0x2, 0x18b, 0x18a, 0x3, 0x2, 0x2, 
    0x2, 0x18b, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x18d, 0x18e, 0x7, 0x53, 0x2, 0x2, 0x18e, 0x190, 0x7, 0x10, 0x2, 0x2, 
    0x18f, 0x191, 0x5, 0xa, 0x6, 0x2, 0x190, 0x18f, 0x3, 0x2, 0x2, 0x2, 
    0x190, 0x191, 0x3, 0x2, 0x2, 0x2, 0x191, 0x37, 0x3, 0x2, 0x2, 0x2, 0x192, 
    0x193, 0x7, 0x6b, 0x2, 0x2, 0x193, 0x194, 0x7, 0x10, 0x2, 0x2, 0x194, 
    0x195, 0x5, 0x6, 0x4, 0x2, 0x195, 0x39, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 
    0x7, 0x55, 0x2, 0x2, 0x197, 0x198, 0x6, 0x1e, 0x9, 0x2, 0x198, 0x199, 
    0x5, 0x74, 0x3b, 0x2, 0x199, 0x19a, 0x5, 0x8c, 0x47, 0x2, 0x19a, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x58, 0x2, 0x2, 0x19c, 0x1a2, 
    0x5, 0x8, 0x5, 0x2, 0x19d, 0x19f, 0x5, 0x3e, 0x20, 0x2, 0x19e, 0x1a0, 
    0x5, 0x40, 0x21, 0x2, 0x19f, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 
    0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a3, 
    0x5, 0x40, 0x21, 0x2, 0x1a2, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a1, 
    0x3, 0x2, 0x2, 0x2, 0x1a3, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x7, 
    0x47, 0x2, 0x2, 0x1a5, 0x1a6, 0x7, 0x8, 0x2, 0x2, 0x1a6, 0x1a7, 0x7, 
    0x6b, 0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x9, 0x2, 0x2, 0x1a8, 0x1a9, 0x5, 
    0x8, 0x5, 0x2, 0x1a9, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x7, 0x48, 
    0x2, 0x2, 0x1ab, 0x1ac, 0x5, 0x8, 0x5, 0x2, 0x1ac, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x1ad, 0x1ae, 0x7, 0x4f, 0x2, 0x2, 0x1ae, 0x1af, 0x5, 0x8c, 0x47, 
    0x2, 0x1af, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x7, 0x50, 0x2, 
    0x2, 0x1b1, 0x1b2, 0x7, 0x6b, 0x2, 0x2, 0x1b2, 0x1b4, 0x7, 0x8, 0x2, 
    0x2, 0x1b3, 0x1b5, 0x5, 0x5a, 0x2e, 0x2, 0x1b4, 0x1b3, 0x3, 0x2, 0x2, 
    0x2, 0x1b4, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 0x3, 0x2, 0x2, 
    0x2, 0x1b6, 0x1b7, 0x7, 0x9, 0x2, 0x2, 0x1b7, 0x1b8, 0x7, 0xa, 0x2, 
    0x2, 0x1b8, 0x1b9, 0x5, 0x60, 0x31, 0x2, 0x1b9, 0x1ba, 0x7, 0xb, 0x2, 
    0x2, 0x1ba, 0x45, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x7, 0x5b, 0x2, 
    0x2, 0x1bc, 0x1bd, 0x7, 0x6b, 0x2, 0x2, 0x1bd, 0x1be, 0x5, 0x48, 0x25, 
    0x2, 0x1be, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x7, 0x5d, 0x2, 
    0x2, 0x1c0, 0x1c2, 0x5, 0x76, 0x3c, 0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 
    0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 
    0x2, 0x1c3, 0x1c7, 0x7, 0xa, 0x2, 0x2, 0x1c4, 0x1c6, 0x5, 0x4a, 0x26, 
    0x2, 0x1c5, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c9, 0x3, 0x2, 0x2, 
    0x2, 0x1c7, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x3, 0x2, 0x2, 
    0x2, 0x1c8, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 
    0x2, 0x1ca, 0x1cb, 0x7, 0xb, 0x2, 0x2, 0x1cb, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x1cc, 0x1d0, 0x7, 0x69, 0x2, 0x2, 0x1cd, 0x1ce, 0x6, 0x26, 0xa, 0x2, 
    0x1ce, 0x1d0, 0x7, 0x6b, 0x2, 0x2, 0x1cf, 0x1cc, 0x3, 0x2, 0x2, 0x2, 
    0x1cf, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x3, 0x2, 0x2, 0x2, 
    0x1d0, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d4, 0x5, 0x4c, 0x27, 0x2, 
    0x1d2, 0x1d4, 0x5, 0x1a, 0xe, 0x2, 0x1d3, 0x1cf, 0x3, 0x2, 0x2, 0x2, 
    0x1d3, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1d5, 
    0x1d6, 0x5, 0x6e, 0x38, 0x2, 0x1d6, 0x1d8, 0x7, 0x8, 0x2, 0x2, 0x1d7, 
    0x1d9, 0x5, 0x5a, 0x2e, 0x2, 0x1d8, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d8, 
    0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1da, 
    0x1db, 0x7, 0x9, 0x2, 0x2, 0x1db, 0x1dc, 0x7, 0xa, 0x2, 0x2, 0x1dc, 
    0x1dd, 0x5, 0x60, 0x31, 0x2, 0x1dd, 0x1de, 0x7, 0xb, 0x2, 0x2, 0x1de, 
    0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x5, 0x88, 0x45, 0x2, 0x1e0, 
    0x1e1, 0x7, 0x8, 0x2, 0x2, 0x1e1, 0x1e2, 0x7, 0x9, 0x2, 0x2, 0x1e2, 
    0x1e3, 0x7, 0xa, 0x2, 0x2, 0x1e3, 0x1e4, 0x5, 0x60, 0x31, 0x2, 0x1e4, 
    0x1e5, 0x7, 0xb, 0x2, 0x2, 0x1e5, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1e6, 
    0x1e7, 0x5, 0x8a, 0x46, 0x2, 0x1e7, 0x1e9, 0x7, 0x8, 0x2, 0x2, 0x1e8, 
    0x1ea, 0x5, 0x5a, 0x2e, 0x2, 0x1e9, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e9, 
    0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1eb, 
    0x1ec, 0x7, 0x9, 0x2, 0x2, 0x1ec, 0x1ed, 0x7, 0xa, 0x2, 0x2, 0x1ed, 
    0x1ee, 0x5, 0x60, 0x31, 0x2, 0x1ee, 0x1ef, 0x7, 0xb, 0x2, 0x2, 0x1ef, 
    0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f2, 0x5, 0x4e, 0x28, 0x2, 0x1f1, 
    0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
    0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f2, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f5, 0x7, 0x19, 0x2, 0x2, 0x1f4, 
    0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
    0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x7, 0x6b, 0x2, 0x2, 0x1f7, 
    0x1f9, 0x7, 0x8, 0x2, 0x2, 0x1f8, 0x1fa, 0x5, 0x5a, 0x2e, 0x2, 0x1f9, 
    0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fa, 
    0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x7, 0x9, 0x2, 0x2, 0x1fc, 
    0x1fd, 0x7, 0xa, 0x2, 0x2, 0x1fd, 0x1fe, 0x5, 0x60, 0x31, 0x2, 0x1fe, 
    0x1ff, 0x7, 0xb, 0x2, 0x2, 0x1ff, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 
    0x7, 0x50, 0x2, 0x2, 0x201, 0x203, 0x7, 0x19, 0x2, 0x2, 0x202, 0x204, 
    0x7, 0x6b, 0x2, 0x2, 0x203, 0x202, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 
    0x3, 0x2, 0x2, 0x2, 0x204, 0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x207, 
    0x7, 0x8, 0x2, 0x2, 0x206, 0x208, 0x5, 0x5a, 0x2e, 0x2, 0x207, 0x206, 
    0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x3, 0x2, 0x2, 0x2, 0x208, 0x209, 
    0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x7, 0x9, 0x2, 0x2, 0x20a, 0x20b, 
    0x7, 0xa, 0x2, 0x2, 0x20b, 0x20c, 0x5, 0x60, 0x31, 0x2, 0x20c, 0x20d, 
    0x7, 0xb, 0x2, 0x2, 0x20d, 0x51, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x217, 0x7, 
    0xa, 0x2, 0x2, 0x20f, 0x214, 0x5, 0x54, 0x2b, 0x2, 0x210, 0x211, 0x7, 
    0xd, 0x2, 0x2, 0x211, 0x213, 0x5, 0x54, 0x2b, 0x2, 0x212, 0x210, 0x3, 
    0x2, 0x2, 0x2, 0x213, 0x216, 0x3, 0x2, 0x2, 0x2, 0x214, 0x212, 0x3, 
    0x2, 0x2, 0x2, 0x214, 0x215, 0x3, 0x2, 0x2, 0x2, 0x215, 0x218, 0x3, 
    0x2, 0x2, 0x2, 0x216, 0x214, 0x3, 0x2, 0x2, 0x2, 0x217, 0x20f, 0x3, 
    0x2, 0x2, 0x2, 0x217, 0x218, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21a, 0x3, 
    0x2, 0x2, 0x2, 0x219, 0x21b, 0x7, 0xd, 0x2, 0x2, 0x21a, 0x219, 0x3, 
    0x2, 0x2, 0x2, 0x21a, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x3, 
    0x2, 0x2, 0x2, 0x21c, 0x21d, 0x7, 0xb, 0x2, 0x2, 0x21d, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x21e, 0x21f, 0x7, 0x19, 0x2, 0x2, 0x21f, 0x220, 0x5, 0x58, 
    0x2d, 0x2, 0x220, 0x55, 0x3, 0x2, 0x2, 0x2, 0x221, 0x22a, 0x7, 0xa, 
    0x2, 0x2, 0x222, 0x227, 0x5, 0x58, 0x2d, 0x2, 0x223, 0x224, 0x7, 0xd, 
    0x2, 0x2, 0x224, 0x226, 0x5, 0x58, 0x2d, 0x2, 0x225, 0x223, 0x3, 0x2, 
    0x2, 0x2, 0x226, 0x229, 0x3, 0x2, 0x2, 0x2, 0x227, 0x225, 0x3, 0x2, 
    0x2, 0x2, 0x227, 0x228, 0x3, 0x2, 0x2, 0x2, 0x228, 0x22b, 0x3, 0x2, 
    0x2, 0x2, 0x229, 0x227, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x222, 0x3, 0x2, 
    0x2, 0x2, 0x22a, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22d, 0x3, 0x2, 
    0x2, 0x2, 0x22c, 0x22e, 0x7, 0xd, 0x2, 0x2, 0x22d, 0x22c, 0x3, 0x2, 
    0x2, 0x2, 0x22d, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 0x3, 0x2, 
    0x2, 0x2, 0x22f, 0x230, 0x7, 0xb, 0x2, 0x2, 0x230, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x231, 0x232, 0x7, 0x6, 0x2, 0x2, 0x232, 0x233, 0x5, 0x76, 0x3c, 
    0x2, 0x233, 0x234, 0x7, 0x7, 0x2, 0x2, 0x234, 0x236, 0x7, 0x8, 0x2, 
    0x2, 0x235, 0x237, 0x5, 0x5a, 0x2e, 0x2, 0x236, 0x235, 0x3, 0x2, 0x2, 
    0x2, 0x236, 0x237, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x3, 0x2, 0x2, 
    0x2, 0x238, 0x239, 0x7, 0x9, 0x2, 0x2, 0x239, 0x23a, 0x7, 0xa, 0x2, 
    0x2, 0x23a, 0x23b, 0x5, 0x60, 0x31, 0x2, 0x23b, 0x23c, 0x7, 0xb, 0x2, 
    0x2, 0x23c, 0x59, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x242, 0x5, 0x5c, 0x2f, 
    0x2, 0x23e, 0x23f, 0x7, 0xd, 0x2, 0x2, 0x23f, 0x241, 0x5, 0x5c, 0x2f, 
    0x2, 0x240, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x241, 0x244, 0x3, 0x2, 0x2, 
    0x2, 0x242, 0x240, 0x3, 0x2, 0x2, 0x2, 0x242, 0x243, 0x3, 0x2, 0x2, 
    0x2, 0x243, 0x247, 0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 
    0x2, 0x245, 0x246, 0x7, 0xd, 0x2, 0x2, 0x246, 0x248, 0x5, 0x5e, 0x30, 
    0x2, 0x247, 0x245, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 0x3, 0x2, 0x2, 
    0x2, 0x248, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24d, 0x5, 0x5e, 0x30, 
    0x2, 0x24a, 0x24d, 0x5, 0x64, 0x33, 0x2, 0x24b, 0x24d, 0x5, 0x6a, 0x36, 
    0x2, 0x24c, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x249, 0x3, 0x2, 0x2, 
    0x2, 0x24c, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24b, 0x3, 0x2, 0x2, 
    0x2, 0x24d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x251, 0x7, 0x6b, 0x2, 
    0x2, 0x24f, 0x250, 0x7, 0xe, 0x2, 0x2, 0x250, 0x252, 0x5, 0x76, 0x3c, 
    0x2, 0x251, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 0x3, 0x2, 0x2, 
    0x2, 0x252, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x7, 0x11, 0x2, 
    0x2, 0x254, 0x255, 0x7, 0x6b, 0x2, 0x2, 0x255, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x256, 0x258, 0x5, 0x62, 0x32, 0x2, 0x257, 0x256, 0x3, 0x2, 0x2, 
    0x2, 0x257, 0x258, 0x3, 0x2, 0x2, 0x2, 0x258, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x259, 0x25b, 0x5, 0x4, 0x3, 0x2, 0x25a, 0x259, 0x3, 0x2, 0x2, 0x2, 
    0x25b, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25a, 0x3, 0x2, 0x2, 0x2, 
    0x25c, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x63, 0x3, 0x2, 0x2, 0x2, 0x25e, 
    0x260, 0x7, 0x6, 0x2, 0x2, 0x25f, 0x261, 0x5, 0x66, 0x34, 0x2, 0x260, 
    0x25f, 0x3, 0x2, 0x2, 0x2, 0x260, 0x261, 0x3, 0x2, 0x2, 0x2, 0x261, 
    0x262, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x7, 0x7, 0x2, 0x2, 0x263, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x264, 0x26d, 0x5, 0x76, 0x3c, 0x2, 0x265, 
    0x267, 0x7, 0xd, 0x2, 0x2, 0x266, 0x265, 0x3, 0x2, 0x2, 0x2, 0x267, 
    0x268, 0x3, 0x2, 0x2, 0x2, 0x268, 0x266, 0x3, 0x2, 0x2, 0x2, 0x268, 
    0x269, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x26a, 
    0x26c, 0x5, 0x76, 0x3c, 0x2, 0x26b, 0x266, 0x3, 0x2, 0x2, 0x2, 0x26c, 
    0x26f, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26d, 
    0x26e, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x276, 0x3, 0x2, 0x2, 0x2, 0x26f, 
    0x26d, 0x3, 0x2, 0x2, 0x2, 0x270, 0x272, 0x7, 0xd, 0x2, 0x2, 0x271, 
    0x270, 0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x3, 0x2, 0x2, 0x2, 0x273, 
    0x271, 0x3, 0x2, 0x2, 0x2, 0x273, 0x274, 0x3, 0x2, 0x2, 0x2, 0x274, 
    0x275, 0x3, 0x2, 0x2, 0x2, 0x275, 0x277, 0x5, 0x68, 0x35, 0x2, 0x276, 
    0x271, 0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x3, 0x2, 0x2, 0x2, 0x277, 
    0x27a, 0x3, 0x2, 0x2, 0x2, 0x278, 0x27a, 0x5, 0x68, 0x35, 0x2, 0x279, 
    0x264, 0x3, 0x2, 0x2, 0x2, 0x279, 0x278, 0x3, 0x2, 0x2, 0x2, 0x27a, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x27e, 0x7, 0x11, 0x2, 0x2, 0x27c, 
    0x27f, 0x7, 0x6b, 0x2, 0x2, 0x27d, 0x27f, 0x5, 0x76, 0x3c, 0x2, 0x27e, 
    0x27c, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27f, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x280, 0x289, 0x7, 0xa, 0x2, 0x2, 0x281, 0x286, 
    0x5, 0x6c, 0x37, 0x2, 0x282, 0x283, 0x7, 0xd, 0x2, 0x2, 0x283, 0x285, 
    0x5, 0x6c, 0x37, 0x2, 0x284, 0x282, 0x3, 0x2, 0x2, 0x2, 0x285, 0x288, 
    0x3, 0x2, 0x2, 0x2, 0x286, 0x284, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 
    0x3, 0x2, 0x2, 0x2, 0x287, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x288, 0x286, 
    0x3, 0x2, 0x2, 0x2, 0x289, 0x281, 0x3, 0x2, 0x2, 0x2, 0x289, 0x28a, 
    0x3, 0x2, 0x2, 0x2, 0x28a, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28d, 
    0x7, 0xd, 0x2, 0x2, 0x28c, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 
    0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 
    0x7, 0xb, 0x2, 0x2, 0x28f, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x290, 0x291, 0x5, 
    0x6e, 0x38, 0x2, 0x291, 0x292, 0x9, 0x3, 0x2, 0x2, 0x292, 0x293, 0x5, 
    0x76, 0x3c, 0x2, 0x293, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x7, 
    0x6, 0x2, 0x2, 0x295, 0x296, 0x5, 0x76, 0x3c, 0x2, 0x296, 0x297, 0x7, 
    0x7, 0x2, 0x2, 0x297, 0x298, 0x7, 0x10, 0x2, 0x2, 0x298, 0x299, 0x5, 
    0x76, 0x3c, 0x2, 0x299, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29b, 0x5, 
    0x88, 0x45, 0x2, 0x29b, 0x29c, 0x7, 0x8, 0x2, 0x2, 0x29c, 0x29d, 0x7, 
    0x9, 0x2, 0x2, 0x29d, 0x29e, 0x7, 0xa, 0x2, 0x2, 0x29e, 0x29f, 0x5, 
    0x60, 0x31, 0x2, 0x29f, 0x2a0, 0x7, 0xb, 0x2, 0x2, 0x2a0, 0x2ac, 0x3, 
    0x2, 0x2, 0x2, 0x2a1, 0x2a2, 0x5, 0x8a, 0x46, 0x2, 0x2a2, 0x2a3, 0x7, 
    0x8, 0x2, 0x2, 0x2a3, 0x2a4, 0x7, 0x6b, 0x2, 0x2, 0x2a4, 0x2a5, 0x7, 
    0x9, 0x2, 0x2, 0x2a5, 0x2a6, 0x7, 0xa, 0x2, 0x2, 0x2a6, 0x2a7, 0x5, 
    0x60, 0x31, 0x2, 0x2a7, 0x2a8, 0x7, 0xb, 0x2, 0x2, 0x2a8, 0x2ac, 0x3, 
    0x2, 0x2, 0x2, 0x2a9, 0x2ac, 0x5, 0x4e, 0x28, 0x2, 0x2aa, 0x2ac, 0x7, 
    0x6b, 0x2, 0x2, 0x2ab, 0x290, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x294, 0x3, 
    0x2, 0x2, 0x2, 0x2ab, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2a1, 0x3, 
    0x2, 0x2, 0x2, 0x2ab, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2aa, 0x3, 
    0x2, 0x2, 0x2, 0x2ac, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2b1, 0x5, 0x82, 
    0x42, 0x2, 0x2ae, 0x2b1, 0x7, 0x6c, 0x2, 0x2, 0x2af, 0x2b1, 0x5, 0x80, 
    0x41, 0x2, 0x2b0, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2ae, 0x3, 0x2, 
    0x2, 0x2, 0x2b0, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x2b2, 0x2c0, 0x7, 0x8, 0x2, 0x2, 0x2b3, 0x2b8, 0x5, 0x76, 0x3c, 
    0x2, 0x2b4, 0x2b5, 0x7, 0xd, 0x2, 0x2, 0x2b5, 0x2b7, 0x5, 0x76, 0x3c, 
    0x2, 0x2b6, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2ba, 0x3, 0x2, 0x2, 
    0x2, 0x2b8, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b9, 0x3, 0x2, 0x2, 
    0x2, 0x2b9, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2b8, 0x3, 0x2, 0x2, 
    0x2, 0x2bb, 0x2bc, 0x7, 0xd, 0x2, 0x2, 0x2bc, 0x2be, 0x5, 0x72, 0x3a, 
    0x2, 0x2bd, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 0x3, 0x2, 0x2, 
    0x2, 0x2be, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2c1, 0x5, 0x72, 0x3a, 
    0x2, 0x2c0, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2bf, 0x3, 0x2, 0x2, 
    0x2, 0x2c0, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c2, 0x3, 0x2, 0x2, 
    0x2, 0x2c2, 0x2c3, 0x7, 0x9, 0x2, 0x2, 0x2c3, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x2c4, 0x2c5, 0x7, 0x11, 0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x6b, 0x2, 0x2, 
    0x2c6, 0x73, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2cc, 0x5, 0x76, 0x3c, 0x2, 
    0x2c8, 0x2c9, 0x7, 0xd, 0x2, 0x2, 0x2c9, 0x2cb, 0x5, 0x76, 0x3c, 0x2, 
    0x2ca, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2ce, 0x3, 0x2, 0x2, 0x2, 
    0x2cc, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cd, 0x3, 0x2, 0x2, 0x2, 
    0x2cd, 0x75, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2cf, 
    0x2d0, 0x8, 0x3c, 0x1, 0x2, 0x2d0, 0x2d2, 0x7, 0x50, 0x2, 0x2, 0x2d1, 
    0x2d3, 0x7, 0x6b, 0x2, 0x2, 0x2d2, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d2, 
    0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d4, 
    0x2d6, 0x7, 0x8, 0x2, 0x2, 0x2d5, 0x2d7, 0x5, 0x5a, 0x2e, 0x2, 0x2d6, 
    0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d7, 
    0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2d9, 0x7, 0x9, 0x2, 0x2, 0x2d9, 
    0x2da, 0x7, 0xa, 0x2, 0x2, 0x2da, 0x2db, 0x5, 0x60, 0x31, 0x2, 0x2db, 
    0x2dc, 0x7, 0xb, 0x2, 0x2, 0x2dc, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x2dd, 
    0x2df, 0x7, 0x5b, 0x2, 0x2, 0x2de, 0x2e0, 0x7, 0x6b, 0x2, 0x2, 0x2df, 
    0x2de, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e0, 
    0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x30c, 0x5, 0x48, 0x25, 0x2, 0x2e2, 
    0x2e3, 0x7, 0x45, 0x2, 0x2, 0x2e3, 0x2e5, 0x5, 0x76, 0x3c, 0x2, 0x2e4, 
    0x2e6, 0x5, 0x70, 0x39, 0x2, 0x2e5, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e5, 
    0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x2e7, 
    0x2e8, 0x7, 0x56, 0x2, 0x2, 0x2e8, 0x30c, 0x5, 0x76, 0x3c, 0x27, 0x2e9, 
    0x2ea, 0x7, 0x4a, 0x2, 0x2, 0x2ea, 0x30c, 0x5, 0x76, 0x3c, 0x26, 0x2eb, 
    0x2ec, 0x7, 0x42, 0x2, 0x2, 0x2ec, 0x30c, 0x5, 0x76, 0x3c, 0x25, 0x2ed, 
    0x2ee, 0x7, 0x13, 0x2, 0x2, 0x2ee, 0x30c, 0x5, 0x76, 0x3c, 0x24, 0x2ef, 
    0x2f0, 0x7, 0x14, 0x2, 0x2, 0x2f0, 0x30c, 0x5, 0x76, 0x3c, 0x23, 0x2f1, 
    0x2f2, 0x7, 0x15, 0x2, 0x2, 0x2f2, 0x30c, 0x5, 0x76, 0x3c, 0x22, 0x2f3, 
    0x2f4, 0x7, 0x16, 0x2, 0x2, 0x2f4, 0x30c, 0x5, 0x76, 0x3c, 0x21, 0x2f5, 
    0x2f6, 0x7, 0x17, 0x2, 0x2, 0x2f6, 0x30c, 0x5, 0x76, 0x3c, 0x20, 0x2f7, 
    0x2f8, 0x7, 0x18, 0x2, 0x2, 0x2f8, 0x30c, 0x5, 0x76, 0x3c, 0x1f, 0x2f9, 
    0x30c, 0x5, 0x56, 0x2c, 0x2, 0x2fa, 0x30c, 0x5, 0x52, 0x2a, 0x2, 0x2fb, 
    0x30c, 0x5, 0x50, 0x29, 0x2, 0x2fc, 0x30c, 0x5, 0x2a, 0x16, 0x2, 0x2fd, 
    0x30c, 0x7, 0x51, 0x2, 0x2, 0x2fe, 0x30c, 0x7, 0x6b, 0x2, 0x2, 0x2ff, 
    0x30c, 0x7, 0x5e, 0x2, 0x2, 0x300, 0x30c, 0x5, 0x7e, 0x40, 0x2, 0x301, 
    0x30c, 0x5, 0x64, 0x33, 0x2, 0x302, 0x30c, 0x5, 0x6a, 0x36, 0x2, 0x303, 
    0x304, 0x7, 0x8, 0x2, 0x2, 0x304, 0x305, 0x5, 0x74, 0x3b, 0x2, 0x305, 
    0x306, 0x7, 0x9, 0x2, 0x2, 0x306, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x307, 
    0x308, 0x5, 0x78, 0x3d, 0x2, 0x308, 0x309, 0x7, 0x37, 0x2, 0x2, 0x309, 
    0x30a, 0x5, 0x7a, 0x3e, 0x2, 0x30a, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x2cf, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x2e2, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x2e9, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x2ed, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x2f1, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x2f5, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x2f9, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x2fb, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x2fd, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x2ff, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x300, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x301, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x302, 0x3, 0x2, 0x2, 0x2, 0x30b, 
    0x303, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x307, 0x3, 0x2, 0x2, 0x2, 0x30c, 
    0x352, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x30e, 0xc, 0x1e, 0x2, 0x2, 0x30e, 
    0x30f, 0x9, 0x4, 0x2, 0x2, 0x30f, 0x351, 0x5, 0x76, 0x3c, 0x1f, 0x310, 
    0x311, 0xc, 0x1d, 0x2, 0x2, 0x311, 0x312, 0x9, 0x5, 0x2, 0x2, 0x312, 
    0x351, 0x5, 0x76, 0x3c, 0x1e, 0x313, 0x314, 0xc, 0x1c, 0x2, 0x2, 0x314, 
    0x315, 0x9, 0x6, 0x2, 0x2, 0x315, 0x351, 0x5, 0x76, 0x3c, 0x1d, 0x316, 
    0x317, 0xc, 0x1b, 0x2, 0x2, 0x317, 0x318, 0x9, 0x7, 0x2, 0x2, 0x318, 
    0x351, 0x5, 0x76, 0x3c, 0x1c, 0x319, 0x31a, 0xc, 0x1a, 0x2, 0x2, 0x31a, 
    0x31b, 0x7, 0x41, 0x2, 0x2, 0x31b, 0x351, 0x5, 0x76, 0x3c, 0x1b, 0x31c, 
    0x31d, 0xc, 0x19, 0x2, 0x2, 0x31d, 0x31e, 0x7, 0x57, 0x2, 0x2, 0x31e, 
    0x351, 0x5, 0x76, 0x3c, 0x1a, 0x31f, 0x320, 0xc, 0x18, 0x2, 0x2, 0x320, 
    0x321, 0x9, 0x8, 0x2, 0x2, 0x321, 0x351, 0x5, 0x76, 0x3c, 0x19, 0x322, 
    0x323, 0xc, 0x17, 0x2, 0x2, 0x323, 0x324, 0x7, 0x27, 0x2, 0x2, 0x324, 
    0x351, 0x5, 0x76, 0x3c, 0x18, 0x325, 0x326, 0xc, 0x16, 0x2, 0x2, 0x326, 
    0x327, 0x7, 0x28, 0x2, 0x2, 0x327, 0x351, 0x5, 0x76, 0x3c, 0x17, 0x328, 
    0x329, 0xc, 0x15, 0x2, 0x2, 0x329, 0x32a, 0x7, 0x29, 0x2, 0x2, 0x32a, 
    0x351, 0x5, 0x76, 0x3c, 0x16, 0x32b, 0x32c, 0xc, 0x14, 0x2, 0x2, 0x32c, 
    0x32d, 0x7, 0x2a, 0x2, 0x2, 0x32d, 0x351, 0x5, 0x76, 0x3c, 0x15, 0x32e, 
    0x32f, 0xc, 0x13, 0x2, 0x2, 0x32f, 0x330, 0x7, 0x2b, 0x2, 0x2, 0x330, 
    0x351, 0x5, 0x76, 0x3c, 0x14, 0x331, 0x332, 0xc, 0x12, 0x2, 0x2, 0x332, 
    0x333, 0x7, 0xf, 0x2, 0x2, 0x333, 0x334, 0x5, 0x76, 0x3c, 0x2, 0x334, 
    0x335, 0x7, 0x10, 0x2, 0x2, 0x335, 0x336, 0x5, 0x76, 0x3c, 0x13, 0x336, 
    0x351, 0x3, 0x2, 0x2, 0x2, 0x337, 0x338, 0xc, 0x11, 0x2, 0x2, 0x338, 
    0x339, 0x7, 0xe, 0x2, 0x2, 0x339, 0x351, 0x5, 0x76, 0x3c, 0x12, 0x33a, 
    0x33b, 0xc, 0x10, 0x2, 0x2, 0x33b, 0x33c, 0x5, 0x7c, 0x3f, 0x2, 0x33c, 
    0x33d, 0x5, 0x76, 0x3c, 0x11, 0x33d, 0x351, 0x3, 0x2, 0x2, 0x2, 0x33e, 
    0x33f, 0xc, 0x2d, 0x2, 0x2, 0x33f, 0x340, 0x7, 0x6, 0x2, 0x2, 0x340, 
    0x341, 0x5, 0x74, 0x3b, 0x2, 0x341, 0x342, 0x7, 0x7, 0x2, 0x2, 0x342, 
    0x351, 0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 0xc, 0x2c, 0x2, 0x2, 0x344, 
    0x345, 0x7, 0x12, 0x2, 0x2, 0x345, 0x351, 0x5, 0x82, 0x42, 0x2, 0x346, 
    0x347, 0xc, 0x2b, 0x2, 0x2, 0x347, 0x351, 0x5, 0x70, 0x39, 0x2, 0x348, 
    0x349, 0xc, 0x29, 0x2, 0x2, 0x349, 0x34a, 0x6, 0x3c, 0x1e, 0x2, 0x34a, 
    0x351, 0x7, 0x13, 0x2, 0x2, 0x34b, 0x34c, 0xc, 0x28, 0x2, 0x2, 0x34c, 
    0x34d, 0x6, 0x3c, 0x20, 0x2, 0x34d, 0x351, 0x7, 0x14, 0x2, 0x2, 0x34e, 
    0x34f, 0xc, 0xf, 0x2, 0x2, 0x34f, 0x351, 0x7, 0x6d, 0x2, 0x2, 0x350, 
    0x30d, 0x3, 0x2, 0x2, 0x2, 0x350, 0x310, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x313, 0x3, 0x2, 0x2, 0x2, 0x350, 0x316, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x319, 0x3, 0x2, 0x2, 0x2, 0x350, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x31f, 0x3, 0x2, 0x2, 0x2, 0x350, 0x322, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x325, 0x3, 0x2, 0x2, 0x2, 0x350, 0x328, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x32b, 0x3, 0x2, 0x2, 0x2, 0x350, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x331, 0x3, 0x2, 0x2, 0x2, 0x350, 0x337, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x33a, 0x3, 0x2, 0x2, 0x2, 0x350, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x343, 0x3, 0x2, 0x2, 0x2, 0x350, 0x346, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x348, 0x3, 0x2, 0x2, 0x2, 0x350, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x350, 
    0x34e, 0x3, 0x2, 0x2, 0x2, 0x351, 0x354, 0x3, 0x2, 0x2, 0x2, 0x352, 
    0x350, 0x3, 0x2, 0x2, 0x2, 0x352, 0x353, 0x3, 0x2, 0x2, 0x2, 0x353, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0x354, 0x352, 0x3, 0x2, 0x2, 0x2, 0x355, 0x35c, 
    0x7, 0x6b, 0x2, 0x2, 0x356, 0x358, 0x7, 0x8, 0x2, 0x2, 0x357, 0x359, 
    0x5, 0x5a, 0x2e, 0x2, 0x358, 0x357, 0x3, 0x2, 0x2, 0x2, 0x358, 0x359, 
    0x3, 0x2, 0x2, 0x2, 0x359, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35c, 
    0x7, 0x9, 0x2, 0x2, 0x35b, 0x355, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x356, 
    0x3, 0x2, 0x2, 0x2, 0x35c, 0x79, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x363, 0x5, 
    0x76, 0x3c, 0x2, 0x35e, 0x35f, 0x7, 0xa, 0x2, 0x2, 0x35f, 0x360, 0x5, 
    0x60, 0x31, 0x2, 0x360, 0x361, 0x7, 0xb, 0x2, 0x2, 0x361, 0x363, 0x3, 
    0x2, 0x2, 0x2, 0x362, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x362, 0x35e, 0x3, 
    0x2, 0x2, 0x2, 0x363, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x364, 0x365, 0x9, 0x9, 
    0x2, 0x2, 0x365, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x366, 0x36d, 0x7, 0x38, 
    0x2, 0x2, 0x367, 0x36d, 0x7, 0x39, 0x2, 0x2, 0x368, 0x36d, 0x7, 0x6c, 
    0x2, 0x2, 0x369, 0x36d, 0x7, 0x6d, 0x2, 0x2, 0x36a, 0x36d, 0x7, 0x5, 
    0x2, 0x2, 0x36b, 0x36d, 0x5, 0x80, 0x41, 0x2, 0x36c, 0x366, 0x3, 0x2, 
    0x2, 0x2, 0x36c, 0x367, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x368, 0x3, 0x2, 
    0x2, 0x2, 0x36c, 0x369, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36a, 0x3, 0x2, 
    0x2, 0x2, 0x36c, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x36e, 0x36f, 0x9, 0xa, 0x2, 0x2, 0x36f, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x370, 0x373, 0x7, 0x6b, 0x2, 0x2, 0x371, 0x373, 0x5, 0x84, 0x43, 0x2, 
    0x372, 0x370, 0x3, 0x2, 0x2, 0x2, 0x372, 0x371, 0x3, 0x2, 0x2, 0x2, 
    0x373, 0x83, 0x3, 0x2, 0x2, 0x2, 0x374, 0x378, 0x5, 0x86, 0x44, 0x2, 
    0x375, 0x378, 0x7, 0x38, 0x2, 0x2, 0x376, 0x378, 0x7, 0x39, 0x2, 0x2, 
    0x377, 0x374, 0x3, 0x2, 0x2, 0x2, 0x377, 0x375, 0x3, 0x2, 0x2, 0x2, 
    0x377, 0x376, 0x3, 0x2, 0x2, 0x2, 0x378, 0x85, 0x3, 0x2, 0x2, 0x2, 0x379, 
    0x37a, 0x9, 0xb, 0x2, 0x2, 0x37a, 0x87, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x37c, 
    0x7, 0x6b, 0x2, 0x2, 0x37c, 0x37d, 0x6, 0x45, 0x22, 0x2, 0x37d, 0x37e, 
    0x5, 0x6e, 0x38, 0x2, 0x37e, 0x89, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x380, 
    0x7, 0x6b, 0x2, 0x2, 0x380, 0x381, 0x6, 0x46, 0x23, 0x2, 0x381, 0x382, 
    0x5, 0x6e, 0x38, 0x2, 0x382, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x383, 0x388, 
    0x7, 0xc, 0x2, 0x2, 0x384, 0x388, 0x7, 0x2, 0x2, 0x3, 0x385, 0x388, 
    0x6, 0x47, 0x24, 0x2, 0x386, 0x388, 0x6, 0x47, 0x25, 0x2, 0x387, 0x383, 
    0x3, 0x2, 0x2, 0x2, 0x387, 0x384, 0x3, 0x2, 0x2, 0x2, 0x387, 0x385, 
    0x3, 0x2, 0x2, 0x2, 0x387, 0x386, 0x3, 0x2, 0x2, 0x2, 0x388, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x8f, 0x94, 0xad, 0xb1, 0xb8, 0xbf, 0xc3, 0xcc, 
    0xd4, 0xdb, 0xdf, 0xea, 0xf0, 0xf4, 0x103, 0x116, 0x11a, 0x11e, 0x128, 
    0x12c, 0x137, 0x144, 0x14a, 0x151, 0x158, 0x15f, 0x166, 0x178, 0x17c, 
    0x17e, 0x185, 0x18b, 0x190, 0x19f, 0x1a2, 0x1b4, 0x1c1, 0x1c7, 0x1cf, 
    0x1d3, 0x1d8, 0x1e9, 0x1f1, 0x1f4, 0x1f9, 0x203, 0x207, 0x214, 0x217, 
    0x21a, 0x227, 0x22a, 0x22d, 0x236, 0x242, 0x247, 0x24c, 0x251, 0x257, 
    0x25c, 0x260, 0x268, 0x26d, 0x273, 0x276, 0x279, 0x27e, 0x286, 0x289, 
    0x28c, 0x2ab, 0x2b0, 0x2b8, 0x2bd, 0x2c0, 0x2cc, 0x2d2, 0x2d6, 0x2df, 
    0x2e5, 0x30b, 0x350, 0x352, 0x358, 0x35b, 0x362, 0x36c, 0x372, 0x377, 
    0x387, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

JavaScriptParser::Initializer JavaScriptParser::_init;
