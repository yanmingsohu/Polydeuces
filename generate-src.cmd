@echo off

set ANTLR=%cd%\deps/antlr/antlr-4.7.2-complete.jar
set LIB=%cd%\deps\javascript-grammars\javascript
set LEXER=%LIB%\JavaScriptLexer.g4
set PARSER=%LIB%\JavaScriptParser.g4
set OUTDIR=%cd%\generate

java -jar %ANTLR% -Dlanguage=Cpp -listener -visitor -o %OUTDIR% -lib %LIB% -package PolydeucesEngine %LEXER% %PARSER%
copy %LIB%/Cpp %OUTDIR%