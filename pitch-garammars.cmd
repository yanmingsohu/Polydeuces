@echo off

set LIB=%cd%\deps\javascript-grammars\javascript
set I_LEXER=%LIB%\JavaScriptLexer.g4
set I_PARSER=%LIB%\JavaScriptParser.g4

set OUTDIR=%cd%\generate
set O_LEXER=%OUTDIR%\JavaScriptLexer.g4
set O_PARSER=%OUTDIR%\JavaScriptParser.g4
set SED_SCRIPT=%OUTDIR%\pitch.sed

rem 从源代码中的 g4 文件生成 cpp 运行时的最终 g4 文件
sed -f %SED_SCRIPT% %I_PARSER% > %O_PARSER%
sed -f %SED_SCRIPT% %I_LEXER%  > %O_LEXER%

echo ok