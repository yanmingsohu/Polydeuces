'use strict'

(function() {
  var a=1, b=1;
  let c=1;
  c++;
  let [a, b, c] = [];
  let {d, e, f} = [];
  {
    //a = 1+2*5+3*4 /c;
  }
  if (1) {
    console.log('ok');
  }
  {
    c = 1+2-5;
    c = 1-2*4;
    c = 1-2;
    c = 1/2;
    c = 1-2 * (4 + 8) /3 +6*2;
    c = 1-2 * (4 + 8) /3; 
    c = -1;
    // -2.000000, -7.000000, -1.000000, 0.500000, 5.000000, -7.000000,
  }
  {
    b = 1234567890;
    b = 0x123456789ABCDEF   // 81985529216486900
    b = 1E3;
    b = 0b10000000000000000000000000000000; // 2147483648
    b = 0o10; // 8 :ES6 
    //b = 0755; // 493 error
    // b = 0888; error
  }
  {
    a = 0xffff<<16; //  -65536
    a = (0xffff<<16)>>1; //   -32768
    a = (0xffff<<16)>>>1; // 2147450880
    a = 0xf0 & 0xff; // 240
    a = 0xe0 | 0x0c; // 236
    a = 0xf0 ^ 0xff; //  15
    a = (0xffff<<16) | 0xf0; // -65296
  }
  {
    "123" + "abc";
    "1" - "a";
  }
});

199;