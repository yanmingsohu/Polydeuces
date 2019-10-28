
    #include "JavaScriptBaseParser.h"


// Generated from D:\Polydeuces\deps\javascript-grammars\javascript\JavaScriptParser.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "JavaScriptParserVisitor.h"


namespace PolydeucesEngine {

/**
 * This class provides an empty implementation of JavaScriptParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  JavaScriptParserBaseVisitor : public JavaScriptParserVisitor {
public:

  virtual antlrcpp::Any visitProgram(JavaScriptParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSourceElement(JavaScriptParser::SourceElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(JavaScriptParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(JavaScriptParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(JavaScriptParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportStatement(JavaScriptParser::ImportStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFromBlock(JavaScriptParser::FromBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultipleImportStatement(JavaScriptParser::MultipleImportStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExportStatement(JavaScriptParser::ExportStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableStatement(JavaScriptParser::VariableStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarationList(JavaScriptParser::VariableDeclarationListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclaration(JavaScriptParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyStatement(JavaScriptParser::EmptyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(JavaScriptParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(JavaScriptParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoStatement(JavaScriptParser::DoStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(JavaScriptParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(JavaScriptParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForVarStatement(JavaScriptParser::ForVarStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForInStatement(JavaScriptParser::ForInStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForVarInStatement(JavaScriptParser::ForVarInStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarModifier(JavaScriptParser::VarModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinueStatement(JavaScriptParser::ContinueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreakStatement(JavaScriptParser::BreakStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStatement(JavaScriptParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitYieldStatement(JavaScriptParser::YieldStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWithStatement(JavaScriptParser::WithStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwitchStatement(JavaScriptParser::SwitchStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseBlock(JavaScriptParser::CaseBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseClauses(JavaScriptParser::CaseClausesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaseClause(JavaScriptParser::CaseClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefaultClause(JavaScriptParser::DefaultClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabelledStatement(JavaScriptParser::LabelledStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThrowStatement(JavaScriptParser::ThrowStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTryStatement(JavaScriptParser::TryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCatchProduction(JavaScriptParser::CatchProductionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFinallyProduction(JavaScriptParser::FinallyProductionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDebuggerStatement(JavaScriptParser::DebuggerStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(JavaScriptParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassDeclaration(JavaScriptParser::ClassDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassTail(JavaScriptParser::ClassTailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassElement(JavaScriptParser::ClassElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodDefinition(JavaScriptParser::MethodDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeneratorMethod(JavaScriptParser::GeneratorMethodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeneratorFunctionDeclaration(JavaScriptParser::GeneratorFunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeneratorBlock(JavaScriptParser::GeneratorBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeneratorDefinition(JavaScriptParser::GeneratorDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIteratorBlock(JavaScriptParser::IteratorBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIteratorDefinition(JavaScriptParser::IteratorDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParameterList(JavaScriptParser::FormalParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormalParameterArg(JavaScriptParser::FormalParameterArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLastFormalParameterArg(JavaScriptParser::LastFormalParameterArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionBody(JavaScriptParser::FunctionBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSourceElements(JavaScriptParser::SourceElementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayLiteral(JavaScriptParser::ArrayLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElementList(JavaScriptParser::ElementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLastElement(JavaScriptParser::LastElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectLiteral(JavaScriptParser::ObjectLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyExpressionAssignment(JavaScriptParser::PropertyExpressionAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComputedPropertyExpressionAssignment(JavaScriptParser::ComputedPropertyExpressionAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyGetter(JavaScriptParser::PropertyGetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertySetter(JavaScriptParser::PropertySetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodProperty(JavaScriptParser::MethodPropertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyShorthand(JavaScriptParser::PropertyShorthandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPropertyName(JavaScriptParser::PropertyNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArguments(JavaScriptParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLastArgument(JavaScriptParser::LastArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionSequence(JavaScriptParser::ExpressionSequenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTemplateStringExpression(JavaScriptParser::TemplateStringExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTernaryExpression(JavaScriptParser::TernaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalAndExpression(JavaScriptParser::LogicalAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeneratorsExpression(JavaScriptParser::GeneratorsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreIncrementExpression(JavaScriptParser::PreIncrementExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObjectLiteralExpression(JavaScriptParser::ObjectLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInExpression(JavaScriptParser::InExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalOrExpression(JavaScriptParser::LogicalOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotExpression(JavaScriptParser::NotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreDecreaseExpression(JavaScriptParser::PreDecreaseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgumentsExpression(JavaScriptParser::ArgumentsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThisExpression(JavaScriptParser::ThisExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionExpression(JavaScriptParser::FunctionExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryMinusExpression(JavaScriptParser::UnaryMinusExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentExpression(JavaScriptParser::AssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostDecreaseExpression(JavaScriptParser::PostDecreaseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeofExpression(JavaScriptParser::TypeofExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstanceofExpression(JavaScriptParser::InstanceofExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryPlusExpression(JavaScriptParser::UnaryPlusExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeleteExpression(JavaScriptParser::DeleteExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeneratorsFunctionExpression(JavaScriptParser::GeneratorsFunctionExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIteratorsExpression(JavaScriptParser::IteratorsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrowFunctionExpression(JavaScriptParser::ArrowFunctionExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityExpression(JavaScriptParser::EqualityExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitXOrExpression(JavaScriptParser::BitXOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSuperExpression(JavaScriptParser::SuperExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativeExpression(JavaScriptParser::MultiplicativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitShiftExpression(JavaScriptParser::BitShiftExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesizedExpression(JavaScriptParser::ParenthesizedExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveExpression(JavaScriptParser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationalExpression(JavaScriptParser::RelationalExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPostIncrementExpression(JavaScriptParser::PostIncrementExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitYieldExpression(JavaScriptParser::YieldExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitNotExpression(JavaScriptParser::BitNotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNewExpression(JavaScriptParser::NewExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralExpression(JavaScriptParser::LiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayLiteralExpression(JavaScriptParser::ArrayLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberDotExpression(JavaScriptParser::MemberDotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassExpression(JavaScriptParser::ClassExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberIndexExpression(JavaScriptParser::MemberIndexExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierExpression(JavaScriptParser::IdentifierExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitAndExpression(JavaScriptParser::BitAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitOrExpression(JavaScriptParser::BitOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperatorExpression(JavaScriptParser::AssignmentOperatorExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVoidExpression(JavaScriptParser::VoidExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrowFunctionParameters(JavaScriptParser::ArrowFunctionParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrowFunctionBody(JavaScriptParser::ArrowFunctionBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperator(JavaScriptParser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(JavaScriptParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumericLiteral(JavaScriptParser::NumericLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierName(JavaScriptParser::IdentifierNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReservedWord(JavaScriptParser::ReservedWordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyword(JavaScriptParser::KeywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGetter(JavaScriptParser::GetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetter(JavaScriptParser::SetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEos(JavaScriptParser::EosContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace PolydeucesEngine
