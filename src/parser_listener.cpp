#include "parser_listener.h"
#include "instructions.h"
#include "operator.h"
#include "stdio.h"

using namespace PolydeucesEngine;


CoreListener::CoreListener(Manager* m) : manager(m), instruct(0) {
  assert(m);
}


void CoreListener::enterProgram(JavaScriptParser::ProgramContext* ctx) {
  printf(">> programe enter\n");
  process = new Process();
  instruct = process;
}


void CoreListener::exitProgram(JavaScriptParser::ProgramContext* ctx) {
  printf("<< programe exit\n");
  if (process) {
    process->parseEnd();
    manager->add(process);
  }
}


void CoreListener::visitTerminal(antlr4::tree::TerminalNode* node) {
  //printf("? visit Terminal\n");
}


void CoreListener::visitErrorNode(antlr4::tree::ErrorNode* node) {
  printf("? visit error node\n");
  if (process) {
    delete process;
    process = 0;
    instruct = 0;
  }
}


void CoreListener::enterEveryRule(antlr4::ParserRuleContext* ctx) {
  //printf("? enterEveryRule\n");
}


void CoreListener::exitEveryRule(antlr4::ParserRuleContext* ctx) {
  //printf("? exitEveryRule\n");
}


void CoreListener::enterSourceElement(JavaScriptParser::SourceElementContext* ctx) {}

void CoreListener::exitSourceElement(JavaScriptParser::SourceElementContext* ctx) {}

void CoreListener::enterStatement(JavaScriptParser::StatementContext* ctx) {}

void CoreListener::exitStatement(JavaScriptParser::StatementContext* ctx) {}


void CoreListener::enterBlock(JavaScriptParser::BlockContext* ctx) {
  // TODO: 执行时创建上下文
  printf("BLOCK{");
  instruct->push(new EnterBlock());
}


void CoreListener::exitBlock(JavaScriptParser::BlockContext* ctx) {
  printf(" B}\n");
  instruct->push(new DebugCalc());
  instruct->push(new ExitBlock());
}


void CoreListener::enterStatementList(JavaScriptParser::StatementListContext* ctx) {}

void CoreListener::exitStatementList(JavaScriptParser::StatementListContext* ctx) {}


void CoreListener::enterImportStatement(JavaScriptParser::ImportStatementContext* ctx) {
  printf("Import");
}


void CoreListener::exitImportStatement(JavaScriptParser::ImportStatementContext* ctx) {
  printf(" over\n");
}


void CoreListener::enterFromBlock(JavaScriptParser::FromBlockContext* ctx) {}

void CoreListener::exitFromBlock(JavaScriptParser::FromBlockContext* ctx) {}

void CoreListener
::enterMultipleImportStatement(JavaScriptParser::MultipleImportStatementContext* ctx){}

void CoreListener
::exitMultipleImportStatement(JavaScriptParser::MultipleImportStatementContext* ctx){}


void CoreListener::enterExportStatement(JavaScriptParser::ExportStatementContext* ctx) {
  printf("Export ");
}


void CoreListener::exitExportStatement(JavaScriptParser::ExportStatementContext* ctx) {
  printf(" over\n");
}


void CoreListener::enterVariableStatement(JavaScriptParser::VariableStatementContext* ctx) {
  printf("DEF {");
}


void CoreListener::exitVariableStatement(JavaScriptParser::VariableStatementContext* ctx){
  printf(" }\n");
  varType = t_none;
}


void CoreListener
::enterVariableDeclarationList(JavaScriptParser::VariableDeclarationListContext* ctx){}

void CoreListener
::exitVariableDeclarationList(JavaScriptParser::VariableDeclarationListContext* ctx){}

void CoreListener::enterVariableDeclaration(JavaScriptParser::VariableDeclarationContext* ctx) {}


void CoreListener::exitVariableDeclaration(JavaScriptParser::VariableDeclarationContext* ctx) {
  auto id = ctx->Identifier();
  if (id) {
    printf(" %s=", id->getText().c_str());
    return;
  }
  auto arr = ctx->arrayLiteral();
  if (arr) {
    printf(" %s=", arr->getText().c_str());
    return;
  }
  auto obj = ctx->objectLiteral();
  if (obj) {
    printf(" %s=", obj->getText().c_str());
    return;
  }
}


void CoreListener::enterEmptyStatement(JavaScriptParser::EmptyStatementContext* ctx)
{
}

void CoreListener::exitEmptyStatement(JavaScriptParser::EmptyStatementContext* ctx)
{
}

void CoreListener::enterExpressionStatement(JavaScriptParser::ExpressionStatementContext* ctx)
{
}

void CoreListener::exitExpressionStatement(JavaScriptParser::ExpressionStatementContext* ctx)
{
}

void CoreListener::enterIfStatement(JavaScriptParser::IfStatementContext* ctx)
{
}

void CoreListener::exitIfStatement(JavaScriptParser::IfStatementContext* ctx)
{
}

void CoreListener::enterDoStatement(JavaScriptParser::DoStatementContext* ctx)
{
}

void CoreListener::exitDoStatement(JavaScriptParser::DoStatementContext* ctx)
{
}

void CoreListener::enterWhileStatement(JavaScriptParser::WhileStatementContext* ctx)
{
}

void CoreListener::exitWhileStatement(JavaScriptParser::WhileStatementContext* ctx)
{
}

void CoreListener::enterForStatement(JavaScriptParser::ForStatementContext* ctx)
{
}

void CoreListener::exitForStatement(JavaScriptParser::ForStatementContext* ctx)
{
}

void CoreListener::enterForVarStatement(JavaScriptParser::ForVarStatementContext* ctx)
{
}

void CoreListener::exitForVarStatement(JavaScriptParser::ForVarStatementContext* ctx)
{
}

void CoreListener::enterForInStatement(JavaScriptParser::ForInStatementContext* ctx)
{
}

void CoreListener::exitForInStatement(JavaScriptParser::ForInStatementContext* ctx)
{
}

void CoreListener::enterForVarInStatement(JavaScriptParser::ForVarInStatementContext* ctx)
{
}

void CoreListener::exitForVarInStatement(JavaScriptParser::ForVarInStatementContext* ctx)
{
}

void CoreListener::enterVarModifier(JavaScriptParser::VarModifierContext* mod) {}


void CoreListener::exitVarModifier(JavaScriptParser::VarModifierContext* mod){
  if (mod->Var()) {
    printf(" Var {");
    varType = t_var;
  } else if (mod->Let()) {
    printf(" Let {");
    varType = t_let;
  } else if (mod->Const()) {
    printf(" Const {");
    varType = t_const;
  }
}


void CoreListener::enterContinueStatement(JavaScriptParser::ContinueStatementContext* ctx)
{
}

void CoreListener::exitContinueStatement(JavaScriptParser::ContinueStatementContext* ctx)
{
}

void CoreListener::enterBreakStatement(JavaScriptParser::BreakStatementContext* ctx)
{
}

void CoreListener::exitBreakStatement(JavaScriptParser::BreakStatementContext* ctx)
{
}

void CoreListener::enterReturnStatement(JavaScriptParser::ReturnStatementContext* ctx)
{
}

void CoreListener::exitReturnStatement(JavaScriptParser::ReturnStatementContext* ctx)
{
}

void CoreListener::enterYieldStatement(JavaScriptParser::YieldStatementContext* ctx)
{
}

void CoreListener::exitYieldStatement(JavaScriptParser::YieldStatementContext* ctx)
{
}

void CoreListener::enterWithStatement(JavaScriptParser::WithStatementContext* ctx)
{
}

void CoreListener::exitWithStatement(JavaScriptParser::WithStatementContext* ctx)
{
}

void CoreListener::enterSwitchStatement(JavaScriptParser::SwitchStatementContext* ctx)
{
}

void CoreListener::exitSwitchStatement(JavaScriptParser::SwitchStatementContext* ctx)
{
}

void CoreListener::enterCaseBlock(JavaScriptParser::CaseBlockContext* ctx)
{
}

void CoreListener::exitCaseBlock(JavaScriptParser::CaseBlockContext* ctx)
{
}

void CoreListener::enterCaseClauses(JavaScriptParser::CaseClausesContext* ctx)
{
}

void CoreListener::exitCaseClauses(JavaScriptParser::CaseClausesContext* ctx)
{
}

void CoreListener::enterCaseClause(JavaScriptParser::CaseClauseContext* ctx)
{
}

void CoreListener::exitCaseClause(JavaScriptParser::CaseClauseContext* ctx)
{
}

void CoreListener::enterDefaultClause(JavaScriptParser::DefaultClauseContext* ctx)
{
}

void CoreListener::exitDefaultClause(JavaScriptParser::DefaultClauseContext* ctx)
{
}

void CoreListener::enterLabelledStatement(JavaScriptParser::LabelledStatementContext* ctx)
{
}

void CoreListener::exitLabelledStatement(JavaScriptParser::LabelledStatementContext* ctx)
{
}

void CoreListener::enterThrowStatement(JavaScriptParser::ThrowStatementContext* ctx)
{
}

void CoreListener::exitThrowStatement(JavaScriptParser::ThrowStatementContext* ctx)
{
}

void CoreListener::enterTryStatement(JavaScriptParser::TryStatementContext* ctx)
{
}

void CoreListener::exitTryStatement(JavaScriptParser::TryStatementContext* ctx)
{
}

void CoreListener::enterCatchProduction(JavaScriptParser::CatchProductionContext* ctx)
{
}

void CoreListener::exitCatchProduction(JavaScriptParser::CatchProductionContext* ctx)
{
}

void CoreListener::enterFinallyProduction(JavaScriptParser::FinallyProductionContext* ctx)
{
}

void CoreListener::exitFinallyProduction(JavaScriptParser::FinallyProductionContext* ctx)
{
}

void CoreListener::enterDebuggerStatement(JavaScriptParser::DebuggerStatementContext* ctx)
{
}

void CoreListener::exitDebuggerStatement(JavaScriptParser::DebuggerStatementContext* ctx)
{
}

void CoreListener::enterFunctionDeclaration(JavaScriptParser::FunctionDeclarationContext* ctx)
{
}

void CoreListener::exitFunctionDeclaration(JavaScriptParser::FunctionDeclarationContext* ctx)
{
}

void CoreListener::enterClassDeclaration(JavaScriptParser::ClassDeclarationContext* ctx)
{
}

void CoreListener::exitClassDeclaration(JavaScriptParser::ClassDeclarationContext* ctx)
{
}

void CoreListener::enterClassTail(JavaScriptParser::ClassTailContext* ctx)
{
}

void CoreListener::exitClassTail(JavaScriptParser::ClassTailContext* ctx)
{
}

void CoreListener::enterClassElement(JavaScriptParser::ClassElementContext* ctx)
{
}

void CoreListener::exitClassElement(JavaScriptParser::ClassElementContext* ctx)
{
}

void CoreListener::enterMethodDefinition(JavaScriptParser::MethodDefinitionContext* ctx)
{
}

void CoreListener::exitMethodDefinition(JavaScriptParser::MethodDefinitionContext* ctx)
{
}

void CoreListener::enterGeneratorMethod(JavaScriptParser::GeneratorMethodContext* ctx)
{
}

void CoreListener::exitGeneratorMethod(JavaScriptParser::GeneratorMethodContext* ctx)
{
}

void CoreListener::enterGeneratorFunctionDeclaration(JavaScriptParser::GeneratorFunctionDeclarationContext* ctx)
{
}

void CoreListener::exitGeneratorFunctionDeclaration(JavaScriptParser::GeneratorFunctionDeclarationContext* ctx)
{
}

void CoreListener::enterGeneratorBlock(JavaScriptParser::GeneratorBlockContext* ctx)
{
}

void CoreListener::exitGeneratorBlock(JavaScriptParser::GeneratorBlockContext* ctx)
{
}

void CoreListener::enterGeneratorDefinition(JavaScriptParser::GeneratorDefinitionContext* ctx)
{
}

void CoreListener::exitGeneratorDefinition(JavaScriptParser::GeneratorDefinitionContext* ctx)
{
}

void CoreListener::enterIteratorBlock(JavaScriptParser::IteratorBlockContext* ctx)
{
}

void CoreListener::exitIteratorBlock(JavaScriptParser::IteratorBlockContext* ctx)
{
}

void CoreListener::enterIteratorDefinition(JavaScriptParser::IteratorDefinitionContext* ctx)
{
}

void CoreListener::exitIteratorDefinition(JavaScriptParser::IteratorDefinitionContext* ctx)
{
}

void CoreListener::enterFormalParameterList(JavaScriptParser::FormalParameterListContext* ctx)
{
}

void CoreListener::exitFormalParameterList(JavaScriptParser::FormalParameterListContext* ctx)
{
}

void CoreListener::enterFormalParameterArg(JavaScriptParser::FormalParameterArgContext* ctx)
{
}

void CoreListener::exitFormalParameterArg(JavaScriptParser::FormalParameterArgContext* ctx)
{
}

void CoreListener::enterLastFormalParameterArg(JavaScriptParser::LastFormalParameterArgContext* ctx)
{
}

void CoreListener::exitLastFormalParameterArg(JavaScriptParser::LastFormalParameterArgContext* ctx)
{
}

void CoreListener::enterFunctionBody(JavaScriptParser::FunctionBodyContext* ctx)
{
}

void CoreListener::exitFunctionBody(JavaScriptParser::FunctionBodyContext* ctx)
{
}

void CoreListener::enterSourceElements(JavaScriptParser::SourceElementsContext* ctx)
{
}

void CoreListener::exitSourceElements(JavaScriptParser::SourceElementsContext* ctx)
{
}

void CoreListener::enterArrayLiteral(JavaScriptParser::ArrayLiteralContext* ctx)
{
}

void CoreListener::exitArrayLiteral(JavaScriptParser::ArrayLiteralContext* ctx)
{
}

void CoreListener::enterElementList(JavaScriptParser::ElementListContext* ctx)
{
}

void CoreListener::exitElementList(JavaScriptParser::ElementListContext* ctx)
{
}

void CoreListener::enterLastElement(JavaScriptParser::LastElementContext* ctx)
{
}

void CoreListener::exitLastElement(JavaScriptParser::LastElementContext* ctx)
{
}

void CoreListener::enterObjectLiteral(JavaScriptParser::ObjectLiteralContext* ctx)
{
}

void CoreListener::exitObjectLiteral(JavaScriptParser::ObjectLiteralContext* ctx)
{
}

void CoreListener::enterPropertyExpressionAssignment(JavaScriptParser::PropertyExpressionAssignmentContext* ctx)
{
}

void CoreListener::exitPropertyExpressionAssignment(JavaScriptParser::PropertyExpressionAssignmentContext* ctx)
{
}

void CoreListener::enterComputedPropertyExpressionAssignment(JavaScriptParser::ComputedPropertyExpressionAssignmentContext* ctx)
{
}

void CoreListener::exitComputedPropertyExpressionAssignment(JavaScriptParser::ComputedPropertyExpressionAssignmentContext* ctx)
{
}

void CoreListener::enterPropertyGetter(JavaScriptParser::PropertyGetterContext* ctx)
{
}

void CoreListener::exitPropertyGetter(JavaScriptParser::PropertyGetterContext* ctx)
{
}

void CoreListener::enterPropertySetter(JavaScriptParser::PropertySetterContext* ctx)
{
}

void CoreListener::exitPropertySetter(JavaScriptParser::PropertySetterContext* ctx)
{
}

void CoreListener::enterMethodProperty(JavaScriptParser::MethodPropertyContext* ctx)
{
}

void CoreListener::exitMethodProperty(JavaScriptParser::MethodPropertyContext* ctx)
{
}

void CoreListener::enterPropertyShorthand(JavaScriptParser::PropertyShorthandContext* ctx)
{
}

void CoreListener::exitPropertyShorthand(JavaScriptParser::PropertyShorthandContext* ctx)
{
}

void CoreListener::enterPropertyName(JavaScriptParser::PropertyNameContext* ctx)
{
}

void CoreListener::exitPropertyName(JavaScriptParser::PropertyNameContext* ctx)
{
}

void CoreListener::enterArguments(JavaScriptParser::ArgumentsContext* ctx)
{
}

void CoreListener::exitArguments(JavaScriptParser::ArgumentsContext* ctx)
{
}

void CoreListener::enterLastArgument(JavaScriptParser::LastArgumentContext* ctx)
{
}

void CoreListener::exitLastArgument(JavaScriptParser::LastArgumentContext* ctx)
{
}

void CoreListener::enterExpressionSequence(JavaScriptParser::ExpressionSequenceContext* ctx)
{
  //printf("enterExpressionSequence{");
}

void CoreListener::exitExpressionSequence(JavaScriptParser::ExpressionSequenceContext* ctx)
{
  //printf("}\n")
}

void CoreListener::enterTemplateStringExpression(JavaScriptParser::TemplateStringExpressionContext* ctx)
{
}

void CoreListener::exitTemplateStringExpression(JavaScriptParser::TemplateStringExpressionContext* ctx)
{
}

void CoreListener::enterTernaryExpression(JavaScriptParser::TernaryExpressionContext* ctx)
{
}

void CoreListener::exitTernaryExpression(JavaScriptParser::TernaryExpressionContext* ctx)
{
}

void CoreListener::enterLogicalAndExpression(JavaScriptParser::LogicalAndExpressionContext* ctx)
{
}

void CoreListener::exitLogicalAndExpression(JavaScriptParser::LogicalAndExpressionContext* ctx)
{
}

void CoreListener::enterGeneratorsExpression(JavaScriptParser::GeneratorsExpressionContext* ctx)
{
}

void CoreListener::exitGeneratorsExpression(JavaScriptParser::GeneratorsExpressionContext* ctx)
{
}

void CoreListener::enterPreIncrementExpression(JavaScriptParser::PreIncrementExpressionContext* ctx)
{
}

void CoreListener::exitPreIncrementExpression(JavaScriptParser::PreIncrementExpressionContext* ctx)
{
}

void CoreListener::enterObjectLiteralExpression(JavaScriptParser::ObjectLiteralExpressionContext* ctx)
{
}

void CoreListener::exitObjectLiteralExpression(JavaScriptParser::ObjectLiteralExpressionContext* ctx)
{
}

void CoreListener::enterInExpression(JavaScriptParser::InExpressionContext* ctx)
{
}

void CoreListener::exitInExpression(JavaScriptParser::InExpressionContext* ctx)
{
}

void CoreListener::enterLogicalOrExpression(JavaScriptParser::LogicalOrExpressionContext* ctx)
{
}

void CoreListener::exitLogicalOrExpression(JavaScriptParser::LogicalOrExpressionContext* ctx)
{
}

void CoreListener::enterNotExpression(JavaScriptParser::NotExpressionContext* ctx)
{
}

void CoreListener::exitNotExpression(JavaScriptParser::NotExpressionContext* ctx)
{
}

void CoreListener::enterPreDecreaseExpression(JavaScriptParser::PreDecreaseExpressionContext* ctx)
{
}

void CoreListener::exitPreDecreaseExpression(JavaScriptParser::PreDecreaseExpressionContext* ctx)
{
}

void CoreListener::enterArgumentsExpression(JavaScriptParser::ArgumentsExpressionContext* ctx)
{
}

void CoreListener::exitArgumentsExpression(JavaScriptParser::ArgumentsExpressionContext* ctx)
{
}

void CoreListener::enterThisExpression(JavaScriptParser::ThisExpressionContext* ctx)
{
}

void CoreListener::exitThisExpression(JavaScriptParser::ThisExpressionContext* ctx)
{
}

void CoreListener::enterFunctionExpression(JavaScriptParser::FunctionExpressionContext* ctx)
{
}

void CoreListener::exitFunctionExpression(JavaScriptParser::FunctionExpressionContext* ctx)
{
}

void CoreListener::enterUnaryMinusExpression(JavaScriptParser::UnaryMinusExpressionContext* ctx)
{
}

void CoreListener::exitUnaryMinusExpression(JavaScriptParser::UnaryMinusExpressionContext* ctx)
{
}

void CoreListener::enterAssignmentExpression(JavaScriptParser::AssignmentExpressionContext* ctx)
{
}

void CoreListener::exitAssignmentExpression(JavaScriptParser::AssignmentExpressionContext* ctx)
{
}

void CoreListener::enterPostDecreaseExpression(JavaScriptParser::PostDecreaseExpressionContext* ctx)
{
}

void CoreListener::exitPostDecreaseExpression(JavaScriptParser::PostDecreaseExpressionContext* ctx)
{
}

void CoreListener::enterTypeofExpression(JavaScriptParser::TypeofExpressionContext* ctx)
{
}

void CoreListener::exitTypeofExpression(JavaScriptParser::TypeofExpressionContext* ctx)
{
}

void CoreListener::enterInstanceofExpression(JavaScriptParser::InstanceofExpressionContext* ctx)
{
}

void CoreListener::exitInstanceofExpression(JavaScriptParser::InstanceofExpressionContext* ctx)
{
}

void CoreListener::enterUnaryPlusExpression(JavaScriptParser::UnaryPlusExpressionContext* ctx) {
}

void CoreListener::exitUnaryPlusExpression(JavaScriptParser::UnaryPlusExpressionContext* ctx) {
}

void CoreListener::enterDeleteExpression(JavaScriptParser::DeleteExpressionContext* ctx)
{
}

void CoreListener::exitDeleteExpression(JavaScriptParser::DeleteExpressionContext* ctx)
{
}

void CoreListener::enterGeneratorsFunctionExpression(JavaScriptParser::GeneratorsFunctionExpressionContext* ctx)
{
}

void CoreListener::exitGeneratorsFunctionExpression(JavaScriptParser::GeneratorsFunctionExpressionContext* ctx)
{
}

void CoreListener::enterIteratorsExpression(JavaScriptParser::IteratorsExpressionContext* ctx)
{
}

void CoreListener::exitIteratorsExpression(JavaScriptParser::IteratorsExpressionContext* ctx)
{
}

void CoreListener::enterArrowFunctionExpression(JavaScriptParser::ArrowFunctionExpressionContext* ctx)
{
}

void CoreListener::exitArrowFunctionExpression(JavaScriptParser::ArrowFunctionExpressionContext* ctx)
{
}

void CoreListener::enterEqualityExpression(JavaScriptParser::EqualityExpressionContext* ctx)
{
}

void CoreListener::exitEqualityExpression(JavaScriptParser::EqualityExpressionContext* ctx)
{
}

void CoreListener::enterBitXOrExpression(JavaScriptParser::BitXOrExpressionContext* ctx)
{
}

void CoreListener::exitBitXOrExpression(JavaScriptParser::BitXOrExpressionContext* ctx)
{
}

void CoreListener::enterSuperExpression(JavaScriptParser::SuperExpressionContext* ctx)
{
}

void CoreListener::exitSuperExpression(JavaScriptParser::SuperExpressionContext* ctx)
{
}

void CoreListener
::enterMultiplicativeExpression(JavaScriptParser::MultiplicativeExpressionContext* ctx) {
  printf(" *{");
}

void CoreListener
::exitMultiplicativeExpression(JavaScriptParser::MultiplicativeExpressionContext* ctx) {
  printf(" *}");
  if (ctx->Divide()) {
    instruct->push(new PlusExp());
  }
  else if (ctx->Multiply()) {
    instruct->push(new MultiplyExp());
  }
  else if (ctx->Modulus()) {
    instruct->push(new ModulusExp());
  }
}

void CoreListener::enterBitShiftExpression(JavaScriptParser::BitShiftExpressionContext* ctx)
{
}

void CoreListener::exitBitShiftExpression(JavaScriptParser::BitShiftExpressionContext* ctx)
{
}

void CoreListener::enterParenthesizedExpression(JavaScriptParser::ParenthesizedExpressionContext* ctx)
{
  printf("-(-");
}

void CoreListener::exitParenthesizedExpression(JavaScriptParser::ParenthesizedExpressionContext* ctx)
{
  printf("-)-");
}

void CoreListener::enterAdditiveExpression(JavaScriptParser::AdditiveExpressionContext* ctx) {
  printf("+{");
}

void CoreListener::exitAdditiveExpression(JavaScriptParser::AdditiveExpressionContext* ctx)
{
  printf(" +}");
  if (ctx->Plus()) {
    instruct->push(new PlusExp());
  } 
  else if (ctx->Minus()) {
    instruct->push(new MinusExp());
  }
}

void CoreListener::enterRelationalExpression(JavaScriptParser::RelationalExpressionContext* ctx)
{
}

void CoreListener::exitRelationalExpression(JavaScriptParser::RelationalExpressionContext* ctx)
{
}

void CoreListener::enterPostIncrementExpression(JavaScriptParser::PostIncrementExpressionContext* ctx)
{
}

void CoreListener::exitPostIncrementExpression(JavaScriptParser::PostIncrementExpressionContext* ctx)
{
}

void CoreListener::enterYieldExpression(JavaScriptParser::YieldExpressionContext* ctx)
{
}

void CoreListener::exitYieldExpression(JavaScriptParser::YieldExpressionContext* ctx)
{
}

void CoreListener::enterBitNotExpression(JavaScriptParser::BitNotExpressionContext* ctx)
{
}

void CoreListener::exitBitNotExpression(JavaScriptParser::BitNotExpressionContext* ctx)
{
}

void CoreListener::enterNewExpression(JavaScriptParser::NewExpressionContext* ctx)
{
}

void CoreListener::exitNewExpression(JavaScriptParser::NewExpressionContext* ctx)
{
}

void CoreListener::enterLiteralExpression(JavaScriptParser::LiteralExpressionContext* ctx)
{
}

void CoreListener::exitLiteralExpression(JavaScriptParser::LiteralExpressionContext* ctx)
{
}

void CoreListener::enterArrayLiteralExpression(JavaScriptParser::ArrayLiteralExpressionContext* ctx)
{
}

void CoreListener::exitArrayLiteralExpression(JavaScriptParser::ArrayLiteralExpressionContext* ctx)
{
}

void CoreListener::enterMemberDotExpression(JavaScriptParser::MemberDotExpressionContext* ctx)
{
}

void CoreListener::exitMemberDotExpression(JavaScriptParser::MemberDotExpressionContext* ctx)
{
}

void CoreListener::enterClassExpression(JavaScriptParser::ClassExpressionContext* ctx)
{
}

void CoreListener::exitClassExpression(JavaScriptParser::ClassExpressionContext* ctx)
{
}

void CoreListener::enterMemberIndexExpression(JavaScriptParser::MemberIndexExpressionContext* ctx)
{
}

void CoreListener::exitMemberIndexExpression(JavaScriptParser::MemberIndexExpressionContext* ctx)
{
}

void CoreListener::enterIdentifierExpression(JavaScriptParser::IdentifierExpressionContext* ctx)
{
}

void CoreListener::exitIdentifierExpression(JavaScriptParser::IdentifierExpressionContext* ctx)
{
}

void CoreListener::enterBitAndExpression(JavaScriptParser::BitAndExpressionContext* ctx)
{
}

void CoreListener::exitBitAndExpression(JavaScriptParser::BitAndExpressionContext* ctx)
{
}

void CoreListener::enterBitOrExpression(JavaScriptParser::BitOrExpressionContext* ctx)
{
}

void CoreListener::exitBitOrExpression(JavaScriptParser::BitOrExpressionContext* ctx)
{
}

void CoreListener::enterAssignmentOperatorExpression(JavaScriptParser::AssignmentOperatorExpressionContext* ctx)
{
}

void CoreListener::exitAssignmentOperatorExpression(JavaScriptParser::AssignmentOperatorExpressionContext* ctx)
{
}

void CoreListener::enterVoidExpression(JavaScriptParser::VoidExpressionContext* ctx)
{
}

void CoreListener::exitVoidExpression(JavaScriptParser::VoidExpressionContext* ctx)
{
}

void CoreListener::enterArrowFunctionParameters(JavaScriptParser::ArrowFunctionParametersContext* ctx)
{
}

void CoreListener::exitArrowFunctionParameters(JavaScriptParser::ArrowFunctionParametersContext* ctx)
{
}

void CoreListener::enterArrowFunctionBody(JavaScriptParser::ArrowFunctionBodyContext* ctx)
{
}

void CoreListener::exitArrowFunctionBody(JavaScriptParser::ArrowFunctionBodyContext* ctx)
{
}

void CoreListener::enterAssignmentOperator(JavaScriptParser::AssignmentOperatorContext* ctx)
{
}

void CoreListener::exitAssignmentOperator(JavaScriptParser::AssignmentOperatorContext* ctx)
{
}

void CoreListener::enterLiteral(JavaScriptParser::LiteralContext* ctx)
{
}

void CoreListener::exitLiteral(JavaScriptParser::LiteralContext* ctx)
{
}

void CoreListener::enterNumericLiteral(JavaScriptParser::NumericLiteralContext* ctx)
{
  printf("NUM(");
}

void CoreListener::exitNumericLiteral(JavaScriptParser::NumericLiteralContext* ctx)
{
  printf(" %s)", ctx->DecimalLiteral()->getText().c_str());
  double d = std::stod(ctx->DecimalLiteral()->getText());
  instruct->push(new PushNumeric(d));
}

void CoreListener::enterIdentifierName(JavaScriptParser::IdentifierNameContext* ctx)
{
}

void CoreListener::exitIdentifierName(JavaScriptParser::IdentifierNameContext* ctx)
{
}

void CoreListener::enterReservedWord(JavaScriptParser::ReservedWordContext* ctx)
{
}

void CoreListener::exitReservedWord(JavaScriptParser::ReservedWordContext* ctx)
{
}

void CoreListener::enterKeyword(JavaScriptParser::KeywordContext* ctx)
{
}

void CoreListener::exitKeyword(JavaScriptParser::KeywordContext* ctx)
{
}

void CoreListener::enterGetter(JavaScriptParser::GetterContext* ctx)
{
}

void CoreListener::exitGetter(JavaScriptParser::GetterContext* ctx)
{
}

void CoreListener::enterSetter(JavaScriptParser::SetterContext* ctx)
{
}

void CoreListener::exitSetter(JavaScriptParser::SetterContext* ctx)
{
}

void CoreListener::enterEos(JavaScriptParser::EosContext* ctx)
{
}

void CoreListener::exitEos(JavaScriptParser::EosContext* ctx)
{
}
