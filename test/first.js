'use strict'

(function() {
  var a=1, b=1;
  let c=1;
  c++;
  let [a, b, c] = [];
  let {d, e, f} = [];
  {
    a = 1+2*5+3*4 /c;
  }
  if (1) {
    console.log('ok');
  }
});