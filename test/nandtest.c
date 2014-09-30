#include "../header/qbool.h"
#include <stdio.h>


void printnand(qboolP a, qboolP b, qboolP c);
extern qboolP qnand(qboolP a, qboolP b, qboolP out);
extern void printqbool(qboolP a);

int main(void)
{
  //qbool a=T, b=F; //define two booleans
  qbool out, i=F, j=F;
  qboolP outp = &out, ip = &i, jp = &j;

  for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      outp = qnand(ip, jp, outp);
      printnand(ip,jp,outp);
    }
  }

  //c = nand(a,b); //will call a function declared in qbool.h and defined in libnand.so
  
  
  printf("\n DONE \n");
  
  return(0);
}

void printnand(qboolP a, qboolP b, qboolP c){
  printqbool(a); printf(" NAND "); printqbool(b); printf(" = "); 
  printqbool(c); printf("\n");  // call another function from libnand.
  
}
