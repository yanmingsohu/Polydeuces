'use strict'

function a() {
}

let b = function() {};
let c = function*() {};

(function() {
  var a=1, b=2;
  let c=3, d=1;
  let [a, b, c] = [];
  let {d, e, f} = [];
  //c++;
  {
    //a = 1+2*5+3*4 /c;
  }
  if (1) {
    // console.log('ok');
  }/*
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
  }*/
  {
    a = "123" + "abc";
    a = "1" - "a";
    a = 10;
    a += 1;
  }
  {
    //b= c = a += 1+1;
  }
});
/*
(function() {
  const a2 = 20;
  console.log(a2);
  try {
    a2 = 1
  } catch(e) {}
  console.log(a2);  
})()*/

a =199;
a += 1;
d = 1;
d = d++ +d// 3
d = d-- +d; // 5
d = ++d +d; // 12
d = --d -d; // 0

[]==0 //ture
[]>0 
[]<0 

[0]==0 //ture
[0]>0
[0]<0 

[1]==0 
[1]>0 //ture
[1]<0 

[1,0]==0 
[1,0]>0
[1,0]<0

[-1]==0
[-1]>0
[-1]<0 //ture

[-1,0]==0
[-1,0]>0
[-1,0]<0

''==0, //ture
''==false //true
[]=='', //ture
null==0,
undefined==0,
null==undefined //true
[]>0 //true
1>'' //true
1>'2'
1>{}
1=={}
1<{}

true=='1' //true
true=='a'
true==[1] // true
true==[]
true==1 //true
true==2
if(2)console.log('T') //print
if(2==true)console.log('T') //not print