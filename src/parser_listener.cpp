#include "parser_listener.h"
#include "instructions.h"
#include "operator.h"
#include "stdio.h"

using namespace PolydeucesEngine;


CoreListener::CoreListener(Manager& m) : manager(m), instruct(0) {
}


void CoreListener::enterProgram(JavaScriptParser::ProgramContext* ctx) {
  printf(">> programe enter\n");
  process = new Process(manager.genNextID());
  instruct = process->getInstructionSet();
}


void CoreListener::exitProgram(JavaScriptParser::ProgramContext* ctx) {
  printf("<< programe exit\n");
  process->parseEnd();
  manager.add(process);
}


void CoreListener::visitTerminal(antlr4::tree::TerminalNode* node) {
  //printf("? visit Terminal\n");
}


void CoreListener::visitErrorNode(antlr4::tree::ErrorNode* node) {
  printf("? visit error node\n");
  Ref<JSError> err(new JSError(node->getText()));
  manager.sendError(process, err);
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

void CoreListener::exitStatement(JavaScriptParser::StatementContext* ctx) {
  std::cout << std::endl;
  
}


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


void CoreListener::enterVariableDeclaration(JavaScriptParser::VariableDeclarationContext* ctx) {
}


void CoreListener::exitVariableDeclaration(JavaScriptParser::VariableDeclarationContext* ctx) {
  auto ass = ctx->assignable();
  auto id = ass->Identifier();
  if (id) {
    auto name = id->getText();
    printf(" %s=", name.c_str());
    if (varType == t_var) {
      instruct->push_top(new DefineVar(name));
    }
    else if (varType == t_let || varType == t_const) {
      instruct->push(new DefineLet(name));
    }
    instruct->push(new IdentifierExp(name));
    instruct->push(new VariableDeclarationAssignmentOperator());
    if (varType == t_const) {
      instruct->push(new DefineLock(name));
    }
    return;
  }

  auto arr = ass->arrayLiteral();
  if (arr) {
    printf(" %s=", arr->getText().c_str());
    return;
  }

  auto obj = ass->objectLiteral();
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
  printf("IF {");
}

void CoreListener::exitIfStatement(JavaScriptParser::IfStatementContext* ctx)
{
  printf(" IF}");
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

void CoreListener::enterForInStatement(JavaScriptParser::ForInStatementContext* ctx)
{
}

void CoreListener::exitForInStatement(JavaScriptParser::ForInStatementContext* ctx)
{
}


void CoreListener::enterVarModifier(JavaScriptParser::VarModifierContext* mod) {}


void CoreListener::exitVarModifier(JavaScriptParser::VarModifierContext* mod){
  if (mod->Var()) {
    // TODO: 在函数范围提前定义
    printf(" Var {");
    varType = t_var;
  } else if (mod->Let()) {
    // TODO: 在当前位置定义
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
  printf("Function(...){");
}

void CoreListener::exitFunctionDeclaration(JavaScriptParser::FunctionDeclarationContext* ctx)
{
  printf(" Function}");
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
  printf("<<FunctionBody");
}

void CoreListener::exitFunctionBody(JavaScriptParser::FunctionBodyContext* ctx)
{
  printf(" FB>>");
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


void CoreListener::enterExpressionSequence(JavaScriptParser::ExpressionSequenceContext* ctx) {
  instruct->push(new ClearCalcStack());
}


void CoreListener::exitExpressionSequence(JavaScriptParser::ExpressionSequenceContext* ctx)
{
  printf("EXP END\n");
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

void CoreListener::exitLogicalAndExpression(JavaScriptParser::LogicalAndExpressionContext* ctx) {
  instruct->push(new LogicalAndExp);
}

void CoreListener::enterPreIncrementExpression(JavaScriptParser::PreIncrementExpressionContext* ctx)
{
}

void CoreListener
::exitPreIncrementExpression(JavaScriptParser::PreIncrementExpressionContext* ctx) {
  instruct->push(UnaryExpressionCreator(IncrementOp, PreSave));
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


void CoreListener::exitLogicalOrExpression(JavaScriptParser::LogicalOrExpressionContext* ctx) {
  instruct->push(new LogicalOrExp);
}


void CoreListener::enterNotExpression(JavaScriptParser::NotExpressionContext* ctx)
{
}


void CoreListener::exitNotExpression(JavaScriptParser::NotExpressionContext* ctx) {
  instruct->push(new NotExp);
}


void CoreListener::enterPreDecreaseExpression(JavaScriptParser::PreDecreaseExpressionContext* ctx)
{
}


void CoreListener::
exitPreDecreaseExpression(JavaScriptParser::PreDecreaseExpressionContext* ctx) {
  instruct->push(UnaryExpressionCreator(DecreaseOp, PreSave));
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
  printf(" FunctionExp-{");
}

void CoreListener::exitFunctionExpression(JavaScriptParser::FunctionExpressionContext* ctx)
{
  printf(" Function-}");
}


void CoreListener::enterUnaryMinusExpression(JavaScriptParser::UnaryMinusExpressionContext* ctx) {
}


void CoreListener::exitUnaryMinusExpression(JavaScriptParser::UnaryMinusExpressionContext* ctx) {
  instruct->push(new UnaryMinusExp());
}


void CoreListener::enterAssignmentExpression(JavaScriptParser::AssignmentExpressionContext* ctx) {
  //printf("?");
}


void CoreListener::exitAssignmentExpression(JavaScriptParser::AssignmentExpressionContext* ctx) {
  printf("{=}");
  instruct->push(new AssignmentExp());
}


void CoreListener::enterPostDecreaseExpression(JavaScriptParser::PostDecreaseExpressionContext* ctx)
{
}

void CoreListener::
exitPostDecreaseExpression(JavaScriptParser::PostDecreaseExpressionContext* ctx) {
  instruct->push(UnaryExpressionCreator(DecreaseOp, PostSave));
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


void CoreListener::enterEqualityExpression(JavaScriptParser::EqualityExpressionContext* ctx)
{
}


void CoreListener::exitEqualityExpression(JavaScriptParser::EqualityExpressionContext* ctx) {
  if (ctx->Equals_()) {
    instruct->push(RelationalExpressionCreator(EqualsExp, SkipType));
  }
  else if (ctx->NotEquals()) {
    instruct->push(RelationalExpressionCreator(NotEqualsExp, SkipType));
  }
  else if (ctx->IdentityEquals()) {
    instruct->push(RelationalExpressionCreator(EqualsExp, IdentityEqualsExp));
  }
  else if (ctx->IdentityNotEquals()) {
    instruct->push(RelationalExpressionCreator(NotEqualsExp, IdentityNotEqualsExp));
  }
}


void CoreListener::enterBitXOrExpression(JavaScriptParser::BitXOrExpressionContext* ctx) {}


void CoreListener::exitBitXOrExpression(JavaScriptParser::BitXOrExpressionContext* ctx) {
  instruct->push(new BitXOrExp());
}


void CoreListener::enterSuperExpression(JavaScriptParser::SuperExpressionContext* ctx)
{
}

void CoreListener::exitSuperExpression(JavaScriptParser::SuperExpressionContext* ctx)
{
}

void CoreListener
::enterMultiplicativeExpression(JavaScriptParser::MultiplicativeExpressionContext* ctx) {
}

void CoreListener
::exitMultiplicativeExpression(JavaScriptParser::MultiplicativeExpressionContext* ctx) {
  if (ctx->Divide()) {
    printf(" {/}");
    instruct->push(new DivideExp());
  }
  else if (ctx->Multiply()) {
    printf(" {*}");
    instruct->push(new MultiplyExp());
  }
  else if (ctx->Modulus()) {
    printf(" {%%}");
    instruct->push(new ModulusExp());
  }
}

void CoreListener::enterBitShiftExpression(JavaScriptParser::BitShiftExpressionContext* ctx) {
}

void CoreListener::exitBitShiftExpression(JavaScriptParser::BitShiftExpressionContext* ctx) {
  if (ctx->LeftShiftArithmetic()) {
    instruct->push(new LeftShiftExp());
  }
  else if (ctx->RightShiftArithmetic()) {
    instruct->push(new RightShiftExp());
  }
  else if (ctx->RightShiftLogical()) {
    instruct->push(new RightShiftLogExp());
  }
}

void CoreListener::enterParenthesizedExpression(JavaScriptParser::ParenthesizedExpressionContext* ctx)
{
  printf(" ( ");
}

void CoreListener::exitParenthesizedExpression(JavaScriptParser::ParenthesizedExpressionContext* ctx)
{
  printf(" )");
}

void CoreListener::enterAdditiveExpression(JavaScriptParser::AdditiveExpressionContext* ctx) {
}


void CoreListener::exitAdditiveExpression(JavaScriptParser::AdditiveExpressionContext* ctx)
{
  if (ctx->Plus()) {
    printf(" {+}");
    instruct->push(new PlusExp());
  } 
  else if (ctx->Minus()) {
    printf(" {-}");
    instruct->push(new MinusExp());
  }
}


void CoreListener::enterRelationalExpression(JavaScriptParser::RelationalExpressionContext* ctx) {
}


void CoreListener::exitRelationalExpression(JavaScriptParser::RelationalExpressionContext* ctx) {
  if (ctx->LessThan()) {
    instruct->push(RelationalExpressionCreator(LessThanExp, SkipType));
  } else if (ctx->LessThanEquals()) {
    instruct->push(RelationalExpressionCreator(LessThanEqualsExp, SkipType));
  } else if (ctx->MoreThan()) {
    instruct->push(RelationalExpressionCreator(MoreThanExp, SkipType));
  } else if (ctx->GreaterThanEquals()) {
    instruct->push(RelationalExpressionCreator(GreaterThanEqualsExp, SkipType));
  }
}


void CoreListener::enterPostIncrementExpression(JavaScriptParser::PostIncrementExpressionContext* ctx)
{
}

void CoreListener::exitPostIncrementExpression(JavaScriptParser::PostIncrementExpressionContext* ctx)
{
  //printf("{++}");
  instruct->push(UnaryExpressionCreator(IncrementOp, PostSave));
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


void CoreListener::exitBitNotExpression(JavaScriptParser::BitNotExpressionContext* ctx) {
  instruct->push(new BitNotEx);
}


void CoreListener::enterNewExpression(JavaScriptParser::NewExpressionContext* ctx)
{
}

void CoreListener::exitNewExpression(JavaScriptParser::NewExpressionContext* ctx)
{
}

void CoreListener::enterLiteralExpression(JavaScriptParser::LiteralExpressionContext* ctx) {
}

void CoreListener::exitLiteralExpression(JavaScriptParser::LiteralExpressionContext* ctx) {
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

void CoreListener::exitIdentifierExpression(JavaScriptParser::IdentifierExpressionContext* ctx) {
  auto name = ctx->Identifier();
  printf(" %s ", name->toString().c_str());
  instruct->push(new IdentifierExp(name->toString()));
}


void CoreListener::enterBitAndExpression(JavaScriptParser::BitAndExpressionContext* ctx) {}


void CoreListener::exitBitAndExpression(JavaScriptParser::BitAndExpressionContext* ctx) {
  instruct->push(new BitAndExp());
}


void CoreListener::enterBitOrExpression(JavaScriptParser::BitOrExpressionContext* ctx) {}


void CoreListener::exitBitOrExpression(JavaScriptParser::BitOrExpressionContext* ctx) {
  instruct->push(new BitOrExp());
}


void CoreListener::enterAssignmentOperatorExpression(JavaScriptParser::AssignmentOperatorExpressionContext* ctx)
{
}

void CoreListener::exitAssignmentOperatorExpression(
    JavaScriptParser::AssignmentOperatorExpressionContext* ctx) {
  auto op = ctx->assignmentOperator();
  
  if (op->MultiplyAssign()) {
    instruct->push(new AssignmentOperatorExp<MultiplyExp>());
  }
  else if (op->DivideAssign()) {
    instruct->push(new AssignmentOperatorExp<DivideExp>());
  }
  else if (op->ModulusAssign()) {
    instruct->push(new AssignmentOperatorExp<ModulusExp>());
  }
  else if (op->PlusAssign()) {
    instruct->push(new AssignmentOperatorExp<PlusExp>());
  }
  else if (op->MinusAssign()) {
    instruct->push(new AssignmentOperatorExp<MinusExp>());
  }
  else if (op->LeftShiftArithmeticAssign()) {
    instruct->push(new AssignmentOperatorExp<LeftShiftExp>());
  }
  else if (op->RightShiftArithmeticAssign()) {
    instruct->push(new AssignmentOperatorExp<RightShiftExp>());
  }
  else if (op->RightShiftLogicalAssign()) {
    instruct->push(new AssignmentOperatorExp<RightShiftLogExp>());
  }
  else if (op->BitAndAssign()) {
    instruct->push(new AssignmentOperatorExp<BitAndExp>());
  }
  else if (op->BitXorAssign()) {
    instruct->push(new AssignmentOperatorExp<BitXOrExp>());
  }
  else if (op->BitOrAssign()) {
    instruct->push(new AssignmentOperatorExp<BitOrExp>());
  }
}

void CoreListener::enterVoidExpression(JavaScriptParser::VoidExpressionContext* ctx)
{
}


void CoreListener::exitVoidExpression(JavaScriptParser::VoidExpressionContext* ctx) {
  instruct->push(new PushUndefined());
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


void CoreListener::enterLiteral(JavaScriptParser::LiteralContext* ctx) {}


void CoreListener::exitLiteral(JavaScriptParser::LiteralContext* ctx) {
  if (ctx->NullLiteral()) {
    instruct->push(new PushLiteral(new JSNull));
  }
  else if (ctx->BooleanLiteral()) {
    auto txt = ctx->BooleanLiteral()->toString();
    bool val = txt == "true";
    instruct->push(new PushLiteral(new JSBoolean(val)));
  }
  else if (ctx->StringLiteral()) {
    auto txt = ctx->StringLiteral()->getText();
    instruct->push(new PushLiteral(new JSString( txt.substr(1, txt.length()-2) )));
  }
  else if (ctx->TemplateStringLiteral()) { // TODO: 未完成
    auto txt = ctx->TemplateStringLiteral()->getText();
    instruct->push(new PushLiteral(new JSString(txt)));
  }
  else if (ctx->RegularExpressionLiteral()) { // // TODO: 未完成
    auto txt = ctx->RegularExpressionLiteral()->getText();
    instruct->push(new PushLiteral(new JSString(txt)));
  }
}


void CoreListener::enterNumericLiteral(JavaScriptParser::NumericLiteralContext* ctx)
{
  printf("NUM(");
}


inline double str2number(std::string& str, const int begin, const int leftbit) {
  unsigned long r = 0;
  for (size_t i = begin, z = str.length(); i < z; ++i) {
    char n = str[i] - '0';
    r = (r << leftbit) | n;
  }
  return r;
}


inline double binary(std::string str) {
  if (str[0] != '0') return 0;
  if (str[1] != 'b' && str[1] != 'B') return 0;
  return str2number(str, 2, 1);
}


inline double octal2(std::string str) {
  if (str[0] != '0') return 0;
  if (str[1] != 'o' && str[1] != 'O') return 0;
  return str2number(str, 2, 3);
}


inline double octal(std::string str) {
  if (str[0] != '0') return 0;
  return str2number(str, 1, 3);
}


void CoreListener::exitNumericLiteral(JavaScriptParser::NumericLiteralContext* ctx)
{
  double d = 0;
  if (ctx->DecimalLiteral()) {
    d = std::stod(ctx->DecimalLiteral()->getText());
    //printf(" D %s ", ctx->DecimalLiteral()->getText().c_str());
  }
  else if (ctx->BinaryIntegerLiteral()) {
    d = binary(ctx->BinaryIntegerLiteral()->getText());
    //printf(" B %s ", ctx->BinaryIntegerLiteral()->getText().c_str());
  }
  else if (ctx->HexIntegerLiteral()) {
    d = std::stod(ctx->HexIntegerLiteral()->getText());
    //printf(" H %s ", ctx->HexIntegerLiteral()->getText().c_str());
  }
  else if (ctx->OctalIntegerLiteral()) {
    d = octal(ctx->OctalIntegerLiteral()->getText());
    //printf(" O %s ", ctx->OctalIntegerLiteral()->getText().c_str());
  }
  else if (ctx->OctalIntegerLiteral2()) {
    d = octal2(ctx->OctalIntegerLiteral2()->getText());
    //printf(" o2 %s ", ctx->OctalIntegerLiteral2()->getText().c_str());
  }
  else {
    printf(" ! %s ", ctx->getText().c_str());
  }

  printf(" %lf)", d);
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

// 升级到 ES2020

void CoreListener::enterImportFromBlock(JavaScriptParser::ImportFromBlockContext* ctx) {
}

void CoreListener::exitImportFromBlock(JavaScriptParser::ImportFromBlockContext* ctx) {
}

void CoreListener::enterModuleItems(JavaScriptParser::ModuleItemsContext* ctx) {
}

void CoreListener::exitModuleItems(JavaScriptParser::ModuleItemsContext* ctx) {
}

void CoreListener::enterImportDefault(JavaScriptParser::ImportDefaultContext* ctx) {
}

void CoreListener::exitImportDefault(JavaScriptParser::ImportDefaultContext* ctx) {
}

void CoreListener::enterImportNamespace(JavaScriptParser::ImportNamespaceContext* ctx) {
}

void CoreListener::exitImportNamespace(JavaScriptParser::ImportNamespaceContext* ctx) {
}

void CoreListener::enterImportFrom(JavaScriptParser::ImportFromContext* ctx) {
}

void CoreListener::exitImportFrom(JavaScriptParser::ImportFromContext* ctx) {
}

void CoreListener::enterAliasName(JavaScriptParser::AliasNameContext* ctx) {
}

void CoreListener::exitAliasName(JavaScriptParser::AliasNameContext* ctx) {
}

void CoreListener::enterExportDeclaration(JavaScriptParser::ExportDeclarationContext* ctx) {
}

void CoreListener::exitExportDeclaration(JavaScriptParser::ExportDeclarationContext* ctx) {
}

void CoreListener::enterExportDefaultDeclaration(JavaScriptParser::ExportDefaultDeclarationContext* ctx) {
}

void CoreListener::exitExportDefaultDeclaration(JavaScriptParser::ExportDefaultDeclarationContext* ctx) {
}

void CoreListener::enterExportFromBlock(JavaScriptParser::ExportFromBlockContext* ctx) {
}

void CoreListener::exitExportFromBlock(JavaScriptParser::ExportFromBlockContext* ctx) {
}

void CoreListener::enterDeclaration(JavaScriptParser::DeclarationContext* ctx) {
}

void CoreListener::exitDeclaration(JavaScriptParser::DeclarationContext* ctx) {
}

void CoreListener::enterForOfStatement(JavaScriptParser::ForOfStatementContext* ctx) {
}

void CoreListener::exitForOfStatement(JavaScriptParser::ForOfStatementContext* ctx) {
}

void CoreListener::enterArrayElement(JavaScriptParser::ArrayElementContext* ctx) {
}

void CoreListener::exitArrayElement(JavaScriptParser::ArrayElementContext* ctx) {
}

void CoreListener::enterFunctionProperty(JavaScriptParser::FunctionPropertyContext* ctx) {
}

void CoreListener::exitFunctionProperty(JavaScriptParser::FunctionPropertyContext* ctx) {
}

void CoreListener::enterArgument(JavaScriptParser::ArgumentContext* ctx) {
}

void CoreListener::exitArgument(JavaScriptParser::ArgumentContext* ctx) {
}

void CoreListener::enterPowerExpression(JavaScriptParser::PowerExpressionContext* ctx) {
}

void CoreListener::exitPowerExpression(JavaScriptParser::PowerExpressionContext* ctx) {
}

void CoreListener::enterMetaExpression(JavaScriptParser::MetaExpressionContext* ctx) {
}

void CoreListener::exitMetaExpression(JavaScriptParser::MetaExpressionContext* ctx) {
}

void CoreListener::enterAwaitExpression(JavaScriptParser::AwaitExpressionContext* ctx) {
}

void CoreListener::exitAwaitExpression(JavaScriptParser::AwaitExpressionContext* ctx) {
}

void CoreListener::enterImportExpression(JavaScriptParser::ImportExpressionContext* ctx) {
}

void CoreListener::exitImportExpression(JavaScriptParser::ImportExpressionContext* ctx) {
}

void CoreListener::enterCoalesceExpression(JavaScriptParser::CoalesceExpressionContext* ctx) {
}

void CoreListener::exitCoalesceExpression(JavaScriptParser::CoalesceExpressionContext* ctx) {
}

void CoreListener::enterAssignable(JavaScriptParser::AssignableContext* ctx) {
}

void CoreListener::exitAssignable(JavaScriptParser::AssignableContext* ctx) {
}

void CoreListener::enterFunctionDecl(JavaScriptParser::FunctionDeclContext* ctx) {
}

void CoreListener::exitFunctionDecl(JavaScriptParser::FunctionDeclContext* ctx) {
}

void CoreListener::enterAnoymousFunctionDecl(JavaScriptParser::AnoymousFunctionDeclContext* ctx) {
}

void CoreListener::exitAnoymousFunctionDecl(JavaScriptParser::AnoymousFunctionDeclContext* ctx) {
}

void CoreListener::enterArrowFunction(JavaScriptParser::ArrowFunctionContext* ctx) {
}

void CoreListener::exitArrowFunction(JavaScriptParser::ArrowFunctionContext* ctx) {
}

void CoreListener::enterBigintLiteral(JavaScriptParser::BigintLiteralContext* ctx) {
}

void CoreListener::exitBigintLiteral(JavaScriptParser::BigintLiteralContext* ctx) {
}
