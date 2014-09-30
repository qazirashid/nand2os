#include "../header/qbool.h"
#include "../header/gates.h"

extern qboolP qnand(qboolP a, qboolP b, qboolP out);
extern void printqbool(qboolP a);
 

qboolP qnot(qboolP in, qboolP out){
  return(qnand(in,in,out)); // call the nand gate with both inputs connected.
  // The nand gate will act as not gate.
  //return(out);
}

qboolP qand(qboolP a, qboolP b, qboolP out){
  
  return(qnot(qnand(a,b,out), out));
  //return(qnot(nand(a,b)));
}


qboolP qor(qboolP a, qboolP b, qboolP out){
  qbool na, nb;
  qboolP nap = &na, nbp=&nb;
  qnot(a, nap);
  qnot(b, nbp);
  return(qnand(nap, nbp, out));
}



qboolP qnor(qboolP a, qboolP b, qboolP out){
  
  return(qnot(qor(a,b,out), out)); 
}

qboolP qxor(qboolP a, qboolP b, qboolP out){
  
  qbool r,s,t; 
  qboolP rp=&r, sp=&s, tp=&t;
  qnand(a,b,rp);
  qnand(a,rp,sp);
  qnand(b,rp,tp);
  return(qnand(sp,tp,out));
}

qboolP qxnor(qboolP a, qboolP b, qboolP out){
  
  return(qnot(qxor(a,b,out),out));
}

qboolP qmux(qboolP a, qboolP b, qboolP s, qboolP out){
  
  qbool ns, p, q;
  qboolP nsp = &ns, pp=&p, qp=&q;
  
  qnot(s,nsp);
  qand(a,nsp,pp);
  qand(b,s,qp);
  return(qor(pp,qp,out));
 }

qboolP qdemux(qboolP in, qboolP s1, qboolP s2, qboolP out){
 
  qbool s00, s01, s10, s11;
  qbool ns1, ns2;
  
  qnot(s1, &ns1);
  qnot(s2, &ns2);

  qand(&ns1, &ns2, &s00);
  qand(&ns1, s2, &s01);
  qand(s1, &ns2, &s10);
  qand(s1, s2,&s11);
  
  qand(in, &s00,&out[0]);
  qand(in, &s01, &out[1]);
  qand(in, &s10, &out[2]);  
  qand(in, &s11, &out[3]);
  //o1 = qor(o00,o01);
  //o2 = qor(o10,o11);
  //out = qor(o1, o2);
  return(out);
  
}

qboolP qfulladder(qboolP in1, qboolP in2, qboolP carryin, qboolP sum, qboolP carryout){
  
  qbool r,s, x; qboolP rp=&r, sp=&s, xp=&x;
  
  qxor(in1,in2,xp);
  qxor(xp,carryin,sum);
  qand(xp,carryin,rp);
  qand(in1,in2,sp);
  qor(rp,sp,carryout);
  return(carryout);
}
