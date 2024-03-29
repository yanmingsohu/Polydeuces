#
# https://github.com/antlr/grammars-v4/blob/master/javascript/Cpp/README.md
#
# sed -f pitch.sed JavaScriptParser.g4 > JavaScriptParser-CppRuntime.g4
# sed -f pitch.sed JavaScriptLexer.g4 > JavaScriptLexer-CppRuntime.g4
#
# Replease 'this.' TO 'this->'; 
#
s/this\./this->/g

#
# Fix assignment operator error
#
s/| singleExpression '=' singleExpression/| <assoc=right> singleExpression '=' singleExpression/
s/| singleExpression assignmentOperator singleExpression/| <assoc=right> singleExpression assignmentOperator singleExpression/

#
# Add the @header{} section after the options {} section.
#
/options {/ {
  h
}

/}/ {
  p
  H
  g
  /options {.*}/ {
    a 
    a // Auto generated by 'pitch-garammars' script
    a @header {
    a // Auto generated by 'pitch-garammars'/'generate-src' script
    a #include "gcomm.h"
    a #include \"JavaScriptBaseLexer.h\"
    a #include \"JavaScriptBaseParser.h\"
    a }
  }
}

/}/ {
  z
  h
  d
}

/.*/ {
  H
}