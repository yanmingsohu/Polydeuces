@echo off

echo 生成 cpp 解析框架代码

set ANTLR=%cd%\deps/antlr/antlr-4.7.2-complete.jar
set LIB=%cd%\deps\javascript-grammars\javascript
set LEXER=%LIB%\JavaScriptLexer.g4
set PARSER=%LIB%\JavaScriptParser.g4
set OUTDIR=%cd%\generate
set O_LEXER=%OUTDIR%\JavaScriptLexer.g4
set O_PARSER=%OUTDIR%\JavaScriptParser.g4


java -jar %ANTLR% -Dlanguage=Cpp -listener -visitor -o %OUTDIR% -lib %LIB% -package PolydeucesEngine %O_LEXER% %O_PARSER%
copy %LIB%/Cpp %OUTDIR%