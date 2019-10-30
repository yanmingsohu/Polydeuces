#pragma once

#include "gcomm.h"
#include "JavaScriptParserListener.h"
#include "javascript.h"

namespace PolydeucesEngine {

//
// 每个解析器对应一次脚本解析, 该对象不可复用
//
class CoreListener : public JavaScriptParserListener {
private:
  Manager *manager;
  Process *process;
  IInsertInstruction *instruct;

  enum VarType {
    t_none = 0, t_var, t_const, t_let,
  } varType;
  

public:
  CoreListener(Manager *m);
  CoreListener(CoreListener const&) = delete;

  virtual void enterProgram(JavaScriptParser::ProgramContext* ctx) override;

  virtual void exitProgram(JavaScriptParser::ProgramContext* ctx) override;

  virtual void visitTerminal(antlr4::tree::TerminalNode* node) override;

  virtual void visitErrorNode(antlr4::tree::ErrorNode* node) override;

  virtual void enterEveryRule(antlr4::ParserRuleContext* ctx) override;

  virtual void exitEveryRule(antlr4::ParserRuleContext* ctx) override;

  virtual void enterSourceElement(JavaScriptParser::SourceElementContext* ctx) override;

  virtual void exitSourceElement(JavaScriptParser::SourceElementContext* ctx) override;

  virtual void enterStatement(JavaScriptParser::StatementContext* ctx) override;

  virtual void exitStatement(JavaScriptParser::StatementContext* ctx) override;

  virtual void enterBlock(JavaScriptParser::BlockContext* ctx) override;

  virtual void exitBlock(JavaScriptParser::BlockContext* ctx) override;

  virtual void enterStatementList(JavaScriptParser::StatementListContext* ctx) override;

  virtual void exitStatementList(JavaScriptParser::StatementListContext* ctx) override;

  virtual void enterImportStatement(JavaScriptParser::ImportStatementContext* ctx) override;

  virtual void exitImportStatement(JavaScriptParser::ImportStatementContext* ctx) override;

  virtual void enterFromBlock(JavaScriptParser::FromBlockContext* ctx) override;

  virtual void exitFromBlock(JavaScriptParser::FromBlockContext* ctx) override;

  virtual void enterMultipleImportStatement(JavaScriptParser::MultipleImportStatementContext* ctx) override;

  virtual void exitMultipleImportStatement(JavaScriptParser::MultipleImportStatementContext* ctx) override;

  virtual void enterExportStatement(JavaScriptParser::ExportStatementContext* ctx) override;

  virtual void exitExportStatement(JavaScriptParser::ExportStatementContext* ctx) override;

  virtual void enterVariableStatement(JavaScriptParser::VariableStatementContext* ctx) override;

  virtual void exitVariableStatement(JavaScriptParser::VariableStatementContext* ctx) override;

  virtual void enterVariableDeclarationList(JavaScriptParser::VariableDeclarationListContext* ctx) override;

  virtual void exitVariableDeclarationList(JavaScriptParser::VariableDeclarationListContext* ctx) override;

  virtual void enterVariableDeclaration(JavaScriptParser::VariableDeclarationContext* ctx) override;

  virtual void exitVariableDeclaration(JavaScriptParser::VariableDeclarationContext* ctx) override;

  virtual void enterEmptyStatement(JavaScriptParser::EmptyStatementContext* ctx) override;

  virtual void exitEmptyStatement(JavaScriptParser::EmptyStatementContext* ctx) override;

  virtual void enterExpressionStatement(JavaScriptParser::ExpressionStatementContext* ctx) override;

  virtual void exitExpressionStatement(JavaScriptParser::ExpressionStatementContext* ctx) override;

  virtual void enterIfStatement(JavaScriptParser::IfStatementContext* ctx) override;

  virtual void exitIfStatement(JavaScriptParser::IfStatementContext* ctx) override;

  virtual void enterDoStatement(JavaScriptParser::DoStatementContext* ctx) override;

  virtual void exitDoStatement(JavaScriptParser::DoStatementContext* ctx) override;

  virtual void enterWhileStatement(JavaScriptParser::WhileStatementContext* ctx) override;

  virtual void exitWhileStatement(JavaScriptParser::WhileStatementContext* ctx) override;

  virtual void enterForStatement(JavaScriptParser::ForStatementContext* ctx) override;

  virtual void exitForStatement(JavaScriptParser::ForStatementContext* ctx) override;

  virtual void enterForVarStatement(JavaScriptParser::ForVarStatementContext* ctx) override;

  virtual void exitForVarStatement(JavaScriptParser::ForVarStatementContext* ctx) override;

  virtual void enterForInStatement(JavaScriptParser::ForInStatementContext* ctx) override;

  virtual void exitForInStatement(JavaScriptParser::ForInStatementContext* ctx) override;

  virtual void enterForVarInStatement(JavaScriptParser::ForVarInStatementContext* ctx) override;

  virtual void exitForVarInStatement(JavaScriptParser::ForVarInStatementContext* ctx) override;

  virtual void enterVarModifier(JavaScriptParser::VarModifierContext* ctx) override;

  virtual void exitVarModifier(JavaScriptParser::VarModifierContext* ctx) override;

  virtual void enterContinueStatement(JavaScriptParser::ContinueStatementContext* ctx) override;

  virtual void exitContinueStatement(JavaScriptParser::ContinueStatementContext* ctx) override;

  virtual void enterBreakStatement(JavaScriptParser::BreakStatementContext* ctx) override;

  virtual void exitBreakStatement(JavaScriptParser::BreakStatementContext* ctx) override;

  virtual void enterReturnStatement(JavaScriptParser::ReturnStatementContext* ctx) override;

  virtual void exitReturnStatement(JavaScriptParser::ReturnStatementContext* ctx) override;

  virtual void enterYieldStatement(JavaScriptParser::YieldStatementContext* ctx) override;

  virtual void exitYieldStatement(JavaScriptParser::YieldStatementContext* ctx) override;

  virtual void enterWithStatement(JavaScriptParser::WithStatementContext* ctx) override;

  virtual void exitWithStatement(JavaScriptParser::WithStatementContext* ctx) override;

  virtual void enterSwitchStatement(JavaScriptParser::SwitchStatementContext* ctx) override;

  virtual void exitSwitchStatement(JavaScriptParser::SwitchStatementContext* ctx) override;

  virtual void enterCaseBlock(JavaScriptParser::CaseBlockContext* ctx) override;

  virtual void exitCaseBlock(JavaScriptParser::CaseBlockContext* ctx) override;

  virtual void enterCaseClauses(JavaScriptParser::CaseClausesContext* ctx) override;

  virtual void exitCaseClauses(JavaScriptParser::CaseClausesContext* ctx) override;

  virtual void enterCaseClause(JavaScriptParser::CaseClauseContext* ctx) override;

  virtual void exitCaseClause(JavaScriptParser::CaseClauseContext* ctx) override;

  virtual void enterDefaultClause(JavaScriptParser::DefaultClauseContext* ctx) override;

  virtual void exitDefaultClause(JavaScriptParser::DefaultClauseContext* ctx) override;

  virtual void enterLabelledStatement(JavaScriptParser::LabelledStatementContext* ctx) override;

  virtual void exitLabelledStatement(JavaScriptParser::LabelledStatementContext* ctx) override;

  virtual void enterThrowStatement(JavaScriptParser::ThrowStatementContext* ctx) override;

  virtual void exitThrowStatement(JavaScriptParser::ThrowStatementContext* ctx) override;

  virtual void enterTryStatement(JavaScriptParser::TryStatementContext* ctx) override;

  virtual void exitTryStatement(JavaScriptParser::TryStatementContext* ctx) override;

  virtual void enterCatchProduction(JavaScriptParser::CatchProductionContext* ctx) override;

  virtual void exitCatchProduction(JavaScriptParser::CatchProductionContext* ctx) override;

  virtual void enterFinallyProduction(JavaScriptParser::FinallyProductionContext* ctx) override;

  virtual void exitFinallyProduction(JavaScriptParser::FinallyProductionContext* ctx) override;

  virtual void enterDebuggerStatement(JavaScriptParser::DebuggerStatementContext* ctx) override;

  virtual void exitDebuggerStatement(JavaScriptParser::DebuggerStatementContext* ctx) override;

  virtual void enterFunctionDeclaration(JavaScriptParser::FunctionDeclarationContext* ctx) override;

  virtual void exitFunctionDeclaration(JavaScriptParser::FunctionDeclarationContext* ctx) override;

  virtual void enterClassDeclaration(JavaScriptParser::ClassDeclarationContext* ctx) override;

  virtual void exitClassDeclaration(JavaScriptParser::ClassDeclarationContext* ctx) override;

  virtual void enterClassTail(JavaScriptParser::ClassTailContext* ctx) override;

  virtual void exitClassTail(JavaScriptParser::ClassTailContext* ctx) override;

  virtual void enterClassElement(JavaScriptParser::ClassElementContext* ctx) override;

  virtual void exitClassElement(JavaScriptParser::ClassElementContext* ctx) override;

  virtual void enterMethodDefinition(JavaScriptParser::MethodDefinitionContext* ctx) override;

  virtual void exitMethodDefinition(JavaScriptParser::MethodDefinitionContext* ctx) override;

  virtual void enterGeneratorMethod(JavaScriptParser::GeneratorMethodContext* ctx) override;

  virtual void exitGeneratorMethod(JavaScriptParser::GeneratorMethodContext* ctx) override;

  virtual void enterGeneratorFunctionDeclaration(JavaScriptParser::GeneratorFunctionDeclarationContext* ctx) override;

  virtual void exitGeneratorFunctionDeclaration(JavaScriptParser::GeneratorFunctionDeclarationContext* ctx) override;

  virtual void enterGeneratorBlock(JavaScriptParser::GeneratorBlockContext* ctx) override;

  virtual void exitGeneratorBlock(JavaScriptParser::GeneratorBlockContext* ctx) override;

  virtual void enterGeneratorDefinition(JavaScriptParser::GeneratorDefinitionContext* ctx) override;

  virtual void exitGeneratorDefinition(JavaScriptParser::GeneratorDefinitionContext* ctx) override;

  virtual void enterIteratorBlock(JavaScriptParser::IteratorBlockContext* ctx) override;

  virtual void exitIteratorBlock(JavaScriptParser::IteratorBlockContext* ctx) override;

  virtual void enterIteratorDefinition(JavaScriptParser::IteratorDefinitionContext* ctx) override;

  virtual void exitIteratorDefinition(JavaScriptParser::IteratorDefinitionContext* ctx) override;

  virtual void enterFormalParameterList(JavaScriptParser::FormalParameterListContext* ctx) override;

  virtual void exitFormalParameterList(JavaScriptParser::FormalParameterListContext* ctx) override;

  virtual void enterFormalParameterArg(JavaScriptParser::FormalParameterArgContext* ctx) override;

  virtual void exitFormalParameterArg(JavaScriptParser::FormalParameterArgContext* ctx) override;

  virtual void enterLastFormalParameterArg(JavaScriptParser::LastFormalParameterArgContext* ctx) override;

  virtual void exitLastFormalParameterArg(JavaScriptParser::LastFormalParameterArgContext* ctx) override;

  virtual void enterFunctionBody(JavaScriptParser::FunctionBodyContext* ctx) override;

  virtual void exitFunctionBody(JavaScriptParser::FunctionBodyContext* ctx) override;

  virtual void enterSourceElements(JavaScriptParser::SourceElementsContext* ctx) override;

  virtual void exitSourceElements(JavaScriptParser::SourceElementsContext* ctx) override;

  virtual void enterArrayLiteral(JavaScriptParser::ArrayLiteralContext* ctx) override;

  virtual void exitArrayLiteral(JavaScriptParser::ArrayLiteralContext* ctx) override;

  virtual void enterElementList(JavaScriptParser::ElementListContext* ctx) override;

  virtual void exitElementList(JavaScriptParser::ElementListContext* ctx) override;

  virtual void enterLastElement(JavaScriptParser::LastElementContext* ctx) override;

  virtual void exitLastElement(JavaScriptParser::LastElementContext* ctx) override;

  virtual void enterObjectLiteral(JavaScriptParser::ObjectLiteralContext* ctx) override;

  virtual void exitObjectLiteral(JavaScriptParser::ObjectLiteralContext* ctx) override;

  virtual void enterPropertyExpressionAssignment(JavaScriptParser::PropertyExpressionAssignmentContext* ctx) override;

  virtual void exitPropertyExpressionAssignment(JavaScriptParser::PropertyExpressionAssignmentContext* ctx) override;

  virtual void enterComputedPropertyExpressionAssignment(JavaScriptParser::ComputedPropertyExpressionAssignmentContext* ctx) override;

  virtual void exitComputedPropertyExpressionAssignment(JavaScriptParser::ComputedPropertyExpressionAssignmentContext* ctx) override;

  virtual void enterPropertyGetter(JavaScriptParser::PropertyGetterContext* ctx) override;

  virtual void exitPropertyGetter(JavaScriptParser::PropertyGetterContext* ctx) override;

  virtual void enterPropertySetter(JavaScriptParser::PropertySetterContext* ctx) override;

  virtual void exitPropertySetter(JavaScriptParser::PropertySetterContext* ctx) override;

  virtual void enterMethodProperty(JavaScriptParser::MethodPropertyContext* ctx) override;

  virtual void exitMethodProperty(JavaScriptParser::MethodPropertyContext* ctx) override;

  virtual void enterPropertyShorthand(JavaScriptParser::PropertyShorthandContext* ctx) override;

  virtual void exitPropertyShorthand(JavaScriptParser::PropertyShorthandContext* ctx) override;

  virtual void enterPropertyName(JavaScriptParser::PropertyNameContext* ctx) override;

  virtual void exitPropertyName(JavaScriptParser::PropertyNameContext* ctx) override;

  virtual void enterArguments(JavaScriptParser::ArgumentsContext* ctx) override;

  virtual void exitArguments(JavaScriptParser::ArgumentsContext* ctx) override;

  virtual void enterLastArgument(JavaScriptParser::LastArgumentContext* ctx) override;

  virtual void exitLastArgument(JavaScriptParser::LastArgumentContext* ctx) override;

  virtual void enterExpressionSequence(JavaScriptParser::ExpressionSequenceContext* ctx) override;

  virtual void exitExpressionSequence(JavaScriptParser::ExpressionSequenceContext* ctx) override;

  virtual void enterTemplateStringExpression(JavaScriptParser::TemplateStringExpressionContext* ctx) override;

  virtual void exitTemplateStringExpression(JavaScriptParser::TemplateStringExpressionContext* ctx) override;

  virtual void enterTernaryExpression(JavaScriptParser::TernaryExpressionContext* ctx) override;

  virtual void exitTernaryExpression(JavaScriptParser::TernaryExpressionContext* ctx) override;

  virtual void enterLogicalAndExpression(JavaScriptParser::LogicalAndExpressionContext* ctx) override;

  virtual void exitLogicalAndExpression(JavaScriptParser::LogicalAndExpressionContext* ctx) override;

  virtual void enterGeneratorsExpression(JavaScriptParser::GeneratorsExpressionContext* ctx) override;

  virtual void exitGeneratorsExpression(JavaScriptParser::GeneratorsExpressionContext* ctx) override;

  virtual void enterPreIncrementExpression(JavaScriptParser::PreIncrementExpressionContext* ctx) override;

  virtual void exitPreIncrementExpression(JavaScriptParser::PreIncrementExpressionContext* ctx) override;

  virtual void enterObjectLiteralExpression(JavaScriptParser::ObjectLiteralExpressionContext* ctx) override;

  virtual void exitObjectLiteralExpression(JavaScriptParser::ObjectLiteralExpressionContext* ctx) override;

  virtual void enterInExpression(JavaScriptParser::InExpressionContext* ctx) override;

  virtual void exitInExpression(JavaScriptParser::InExpressionContext* ctx) override;

  virtual void enterLogicalOrExpression(JavaScriptParser::LogicalOrExpressionContext* ctx) override;

  virtual void exitLogicalOrExpression(JavaScriptParser::LogicalOrExpressionContext* ctx) override;

  virtual void enterNotExpression(JavaScriptParser::NotExpressionContext* ctx) override;

  virtual void exitNotExpression(JavaScriptParser::NotExpressionContext* ctx) override;

  virtual void enterPreDecreaseExpression(JavaScriptParser::PreDecreaseExpressionContext* ctx) override;

  virtual void exitPreDecreaseExpression(JavaScriptParser::PreDecreaseExpressionContext* ctx) override;

  virtual void enterArgumentsExpression(JavaScriptParser::ArgumentsExpressionContext* ctx) override;

  virtual void exitArgumentsExpression(JavaScriptParser::ArgumentsExpressionContext* ctx) override;

  virtual void enterThisExpression(JavaScriptParser::ThisExpressionContext* ctx) override;

  virtual void exitThisExpression(JavaScriptParser::ThisExpressionContext* ctx) override;

  virtual void enterFunctionExpression(JavaScriptParser::FunctionExpressionContext* ctx) override;

  virtual void exitFunctionExpression(JavaScriptParser::FunctionExpressionContext* ctx) override;

  virtual void enterUnaryMinusExpression(JavaScriptParser::UnaryMinusExpressionContext* ctx) override;

  virtual void exitUnaryMinusExpression(JavaScriptParser::UnaryMinusExpressionContext* ctx) override;

  virtual void enterAssignmentExpression(JavaScriptParser::AssignmentExpressionContext* ctx) override;

  virtual void exitAssignmentExpression(JavaScriptParser::AssignmentExpressionContext* ctx) override;

  virtual void enterPostDecreaseExpression(JavaScriptParser::PostDecreaseExpressionContext* ctx) override;

  virtual void exitPostDecreaseExpression(JavaScriptParser::PostDecreaseExpressionContext* ctx) override;

  virtual void enterTypeofExpression(JavaScriptParser::TypeofExpressionContext* ctx) override;

  virtual void exitTypeofExpression(JavaScriptParser::TypeofExpressionContext* ctx) override;

  virtual void enterInstanceofExpression(JavaScriptParser::InstanceofExpressionContext* ctx) override;

  virtual void exitInstanceofExpression(JavaScriptParser::InstanceofExpressionContext* ctx) override;

  virtual void enterUnaryPlusExpression(JavaScriptParser::UnaryPlusExpressionContext* ctx) override;

  virtual void exitUnaryPlusExpression(JavaScriptParser::UnaryPlusExpressionContext* ctx) override;

  virtual void enterDeleteExpression(JavaScriptParser::DeleteExpressionContext* ctx) override;

  virtual void exitDeleteExpression(JavaScriptParser::DeleteExpressionContext* ctx) override;

  virtual void enterGeneratorsFunctionExpression(JavaScriptParser::GeneratorsFunctionExpressionContext* ctx) override;

  virtual void exitGeneratorsFunctionExpression(JavaScriptParser::GeneratorsFunctionExpressionContext* ctx) override;

  virtual void enterIteratorsExpression(JavaScriptParser::IteratorsExpressionContext* ctx) override;

  virtual void exitIteratorsExpression(JavaScriptParser::IteratorsExpressionContext* ctx) override;

  virtual void enterArrowFunctionExpression(JavaScriptParser::ArrowFunctionExpressionContext* ctx) override;

  virtual void exitArrowFunctionExpression(JavaScriptParser::ArrowFunctionExpressionContext* ctx) override;

  virtual void enterEqualityExpression(JavaScriptParser::EqualityExpressionContext* ctx) override;

  virtual void exitEqualityExpression(JavaScriptParser::EqualityExpressionContext* ctx) override;

  virtual void enterBitXOrExpression(JavaScriptParser::BitXOrExpressionContext* ctx) override;

  virtual void exitBitXOrExpression(JavaScriptParser::BitXOrExpressionContext* ctx) override;

  virtual void enterSuperExpression(JavaScriptParser::SuperExpressionContext* ctx) override;

  virtual void exitSuperExpression(JavaScriptParser::SuperExpressionContext* ctx) override;

  virtual void enterMultiplicativeExpression(JavaScriptParser::MultiplicativeExpressionContext* ctx) override;

  virtual void exitMultiplicativeExpression(JavaScriptParser::MultiplicativeExpressionContext* ctx) override;

  virtual void enterBitShiftExpression(JavaScriptParser::BitShiftExpressionContext* ctx) override;

  virtual void exitBitShiftExpression(JavaScriptParser::BitShiftExpressionContext* ctx) override;

  virtual void enterParenthesizedExpression(JavaScriptParser::ParenthesizedExpressionContext* ctx) override;

  virtual void exitParenthesizedExpression(JavaScriptParser::ParenthesizedExpressionContext* ctx) override;

  virtual void enterAdditiveExpression(JavaScriptParser::AdditiveExpressionContext* ctx) override;

  virtual void exitAdditiveExpression(JavaScriptParser::AdditiveExpressionContext* ctx) override;

  virtual void enterRelationalExpression(JavaScriptParser::RelationalExpressionContext* ctx) override;

  virtual void exitRelationalExpression(JavaScriptParser::RelationalExpressionContext* ctx) override;

  virtual void enterPostIncrementExpression(JavaScriptParser::PostIncrementExpressionContext* ctx) override;

  virtual void exitPostIncrementExpression(JavaScriptParser::PostIncrementExpressionContext* ctx) override;

  virtual void enterYieldExpression(JavaScriptParser::YieldExpressionContext* ctx) override;

  virtual void exitYieldExpression(JavaScriptParser::YieldExpressionContext* ctx) override;

  virtual void enterBitNotExpression(JavaScriptParser::BitNotExpressionContext* ctx) override;

  virtual void exitBitNotExpression(JavaScriptParser::BitNotExpressionContext* ctx) override;

  virtual void enterNewExpression(JavaScriptParser::NewExpressionContext* ctx) override;

  virtual void exitNewExpression(JavaScriptParser::NewExpressionContext* ctx) override;

  virtual void enterLiteralExpression(JavaScriptParser::LiteralExpressionContext* ctx) override;

  virtual void exitLiteralExpression(JavaScriptParser::LiteralExpressionContext* ctx) override;

  virtual void enterArrayLiteralExpression(JavaScriptParser::ArrayLiteralExpressionContext* ctx) override;

  virtual void exitArrayLiteralExpression(JavaScriptParser::ArrayLiteralExpressionContext* ctx) override;

  virtual void enterMemberDotExpression(JavaScriptParser::MemberDotExpressionContext* ctx) override;

  virtual void exitMemberDotExpression(JavaScriptParser::MemberDotExpressionContext* ctx) override;

  virtual void enterClassExpression(JavaScriptParser::ClassExpressionContext* ctx) override;

  virtual void exitClassExpression(JavaScriptParser::ClassExpressionContext* ctx) override;

  virtual void enterMemberIndexExpression(JavaScriptParser::MemberIndexExpressionContext* ctx) override;

  virtual void exitMemberIndexExpression(JavaScriptParser::MemberIndexExpressionContext* ctx) override;

  virtual void enterIdentifierExpression(JavaScriptParser::IdentifierExpressionContext* ctx) override;

  virtual void exitIdentifierExpression(JavaScriptParser::IdentifierExpressionContext* ctx) override;

  virtual void enterBitAndExpression(JavaScriptParser::BitAndExpressionContext* ctx) override;

  virtual void exitBitAndExpression(JavaScriptParser::BitAndExpressionContext* ctx) override;

  virtual void enterBitOrExpression(JavaScriptParser::BitOrExpressionContext* ctx) override;

  virtual void exitBitOrExpression(JavaScriptParser::BitOrExpressionContext* ctx) override;

  virtual void enterAssignmentOperatorExpression(JavaScriptParser::AssignmentOperatorExpressionContext* ctx) override;

  virtual void exitAssignmentOperatorExpression(JavaScriptParser::AssignmentOperatorExpressionContext* ctx) override;

  virtual void enterVoidExpression(JavaScriptParser::VoidExpressionContext* ctx) override;

  virtual void exitVoidExpression(JavaScriptParser::VoidExpressionContext* ctx) override;

  virtual void enterArrowFunctionParameters(JavaScriptParser::ArrowFunctionParametersContext* ctx) override;

  virtual void exitArrowFunctionParameters(JavaScriptParser::ArrowFunctionParametersContext* ctx) override;

  virtual void enterArrowFunctionBody(JavaScriptParser::ArrowFunctionBodyContext* ctx) override;

  virtual void exitArrowFunctionBody(JavaScriptParser::ArrowFunctionBodyContext* ctx) override;

  virtual void enterAssignmentOperator(JavaScriptParser::AssignmentOperatorContext* ctx) override;

  virtual void exitAssignmentOperator(JavaScriptParser::AssignmentOperatorContext* ctx) override;

  virtual void enterLiteral(JavaScriptParser::LiteralContext* ctx) override;

  virtual void exitLiteral(JavaScriptParser::LiteralContext* ctx) override;

  virtual void enterNumericLiteral(JavaScriptParser::NumericLiteralContext* ctx) override;

  virtual void exitNumericLiteral(JavaScriptParser::NumericLiteralContext* ctx) override;

  virtual void enterIdentifierName(JavaScriptParser::IdentifierNameContext* ctx) override;

  virtual void exitIdentifierName(JavaScriptParser::IdentifierNameContext* ctx) override;

  virtual void enterReservedWord(JavaScriptParser::ReservedWordContext* ctx) override;

  virtual void exitReservedWord(JavaScriptParser::ReservedWordContext* ctx) override;

  virtual void enterKeyword(JavaScriptParser::KeywordContext* ctx) override;

  virtual void exitKeyword(JavaScriptParser::KeywordContext* ctx) override;

  virtual void enterGetter(JavaScriptParser::GetterContext* ctx) override;

  virtual void exitGetter(JavaScriptParser::GetterContext* ctx) override;

  virtual void enterSetter(JavaScriptParser::SetterContext* ctx) override;

  virtual void exitSetter(JavaScriptParser::SetterContext* ctx) override;

  virtual void enterEos(JavaScriptParser::EosContext* ctx) override;

  virtual void exitEos(JavaScriptParser::EosContext* ctx) override;

};

}