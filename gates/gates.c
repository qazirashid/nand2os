#include "../header/qbool.h"
#include "../header/gates.h"

qbool qnot(qbool a){
  return(nand(a,a)); // call the nand gate with both inputs connected.
  // The nand gate will act as not gate.
}

qbool qand(qbool a, qbool b){
  
  qbool c = nand(a,b);
  return(qnot(c));
  //return(qnot(nand(a,b)));
}

qbool qor(qbool a, qbool b){
  qbool in1, in2;
  qbool out;
  in1 = qnot(a);
  in2 = qnot(b);
  out = nand(in1, in2);
  return(out);
}

qbool qnor(qbool a, qbool b){
  qbool in1 = qor(a,b);
  return( qnot(in1)); 
}

qbool qxor(qbool a, qbool b){
   
  qbool r, s, t, out;
  r = nand(a,b);
  s = nand(a,r);
  t = nand(b,r);
  out = nand(s,t);
  return(out);
}

qbool qxnor(qbool a, qbool b){
  qbool t,out;
  t = qxor(a,b);
  out = qnot(t);
  return(out);
}
qbool qmux(qbool a, qbool b, qbool s){
  
  qbool ns, p, q, out;
  ns = qnot(s);
  p = qand(a,ns);
  q = qand(b,s);
  out = qor(p,q);
  return(out);
}

void qdemux(qbool in, qbool s1, qbool s2, qbool *out){
 
  qbool s00, s01, s10, s11;
  s00 = qand(qnot(s1), qnot(s2));
  s01 = qand(qnot(s1), s2);
  s10 = qand(s1, qnot(s2));
  s11 = qand(s1, s2);  
  out[0] = qand(in, s00);
  out[1] = qand(in, s01);
  out[2] = qand(in, s10);  
  out[3] = qand(in, s11);
  //o1 = qor(o00,o01);
  //o2 = qor(o10,o11);
  //out = qor(o1, o2);
  //return(out);
  
}
