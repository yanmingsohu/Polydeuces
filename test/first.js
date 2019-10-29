// 崩溃: 要在 lexer 阶段检测严格模式并从解析树中删除
//"use strict"
(function() {
  var a=1, b=1;
  let c=1;
  c++;
  let [a, b, c] = [];
  let {d, e, f} = [];
  a = 1+2+3*4;
});