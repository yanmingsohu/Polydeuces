// node generate-lexer.js
const fs = require('fs');

const LexerEnum = {};
let file;

write_cpp();
write_lexer_header();


function write_cpp() {
  file = fs.openSync(__dirname +'/parser_gen.cpp', 'w');
  write(0, `// generate by 'generate-lexer.js'
#include "parser.h"
#include "parser_gen.h"

namespace PolydeucesEngine {
`);

  operator();
  key_word();

  write(0, "\n\n}");
  fs.closeSync(file);
}


function write(tabcount) {
  for (let i=0; i<tabcount; ++i) {
    fs.writeSync(file, '  ');
  }
  for (let i=1; i<arguments.length; ++i) {
    fs.writeSync(file, arguments[i]);
  }
}


function writel() {
  write.apply(null, arguments);
  fs.writeSync(file, '\n');
}


function read_lexer(filename, online) {
  const str = fs.readFileSync(__dirname +'/'+ filename, 'utf8');
  const lines = str.split('\n');
  const re = /(\w*):\s*'(.*)'/;
  
  lines.forEach(function(s) {
    let arr = re.exec(s);
    if (arr) {
      online(arr[1], arr[2]);
      console.log(arr[1], '\t', arr[2]);
    }
  });
}


function operator() {
  write(0, `
int parser_operator(CharSequence str, int len, JSLexer& t) {
  switch (str[0]) {
`);

  let ops = {};
  read_lexer('operator.txt', function(name, op) {
    LexerEnum[name] = 1;
    if (!ops[ op[0] ]) {
      ops[ op[0] ] = [];
    }
    ops[ op[0] ].push({name, op});
  });

  for (let n in ops) {
    let op = ops[n];
    op.sort(function(a, b) {
      return a.op.length - b.op.length;
    });

    writel(2, "case '", n, "':");

    for (let i=op.length-1; i>0; --i) {
      let oop = op[i];
      write(3, "if (len >= ", oop.op.length);

      for (let j=1; j<oop.op.length; ++j) {
        write(0, " && str[", j, "] == '", oop.op[j], "'");
      }

      writel(0, ") {");
      writel(4, "t = JSLexer::", oop.name, ';');
      writel(4, "return ", oop.op.length, ";");
      writel(3, "}");
    }
    writel(3, "t = JSLexer::", op[0].name, ';');
    writel(3, "return 1;\n");
  }

  writel(1, "};");
  writel(1, "return 0;");
  writel(0, "}")
}


function key_word() {
  const BeginCase = 2;
  write(0, `
int parser_key_word(CharSequence str, int length, JSLexer& ret) {
  int state = ${BeginCase};
  JSLexer t;
  for (int i=0; i<length; ++i) {
    switch (state) {
      case 0: // break word
        return 0;
      case 1: // end word but not end
        return 0;
`);

  let id = BeginCase;
  let tree = {};

  read_lexer('key_word.txt', function(name, op) {
    LexerEnum[name] = 1;
    let node = tree;
    for (let i=0; i<op.length; ++i) {
      let tmp = node[op[i]];
      if (!tmp) {
        tmp = node[op[i]] = { id: ++id, child: {}, ch: op[i] };
      }
      if (i == op.length-1) {
        tmp.type = 'JSLexer::'+ name;
      }
      node = tmp.child;
    }
  });

  write_sw(BeginCase, tree);

  function write_sw(i, node) {
    writel(3, "case ", i, ":");
    writel(4, "switch (str[i]) {");
    writel(5, "default: state = 0; break;");

    for (let n in node) {
      write(5, "case '", n, "':");
      if (node[n].type) {
        writel(0, "state = 1; t = ", node[n].type, ";");
      } else {
        writel(0, "state = ", node[n].id, ";");
      }
      writel(6, "break;");
    }

    writel(4, "}");
    writel(4, "break;");

    for (let n in node) {
      write_sw(node[n].id, node[n].child);
    }
  }

  console.log(tree);

  writel(2, `}
  }
  if (state == 1) {
    ret = t;
    return 1;
  }
  return 0;
}`);
}


function write_lexer_header() {
  file = fs.openSync(__dirname +'/parser_gen.h', 'w');
  write(0, `// generate by 'generate-lexer.js'
#pragma once

namespace PolydeucesEngine {


enum JSLexer {
  Unknow=0, `);
  
  let i = 1;
  for (let n in LexerEnum) {
    write(0, n, ', ');
    if (++i > 3) {
      write(0, '\n  ');
      i = 0;
    }
  }
  writel(0, '\n};');

  
  write(0, `
template<class Out> void print_lexer(JSLexer t, Out& out) {
  switch(t) {
    default: return;
`);
  for (let n in LexerEnum) {
    writel(2, "case ", n, ":");
    writel(3, 'out << "', n, '"; return;');
  }
  write(1, '}\n}\n');
  
  write(0, `\n\n}`);
  fs.closeSync(file);
}