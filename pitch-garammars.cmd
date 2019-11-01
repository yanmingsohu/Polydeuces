@echo off

set LIB=%cd%\deps\javascript-grammars\javascript
set I_LEXER=%LIB%\JavaScriptLexer.g4
set I_PARSER=%LIB%\JavaScriptParser.g4
set OUTDIR=%cd%\generate
set O_LEXER=%OUTDIR%\JavaScriptLexer.g4
set O_PARSER=%OUTDIR%\JavaScriptParser.g4

rem 从源代码中的 g4 文件生成 cpp 运行时的最终 g4 文件
rem diff -p2  %I_LEXER% %O_LEXER%
rem diff -p2 %I_PARSER% %O_PARSER%