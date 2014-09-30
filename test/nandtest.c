#include "../header/qbool.h"
#include <stdio.h>


void printnand(qbool a, qbool b, qbool c);

int main(void)
{
  //qbool a=T, b=F; //define two booleans
  qbool c, i=F, j=F;

  for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      c = nand(i,j);
      printnand(i,j,c);
    }
  }

  //c = nand(a,b); //will call a function declared in qbool.h and defined in libnand.so
  
  
  printf("\n DONE \n");
  
}

void printnand(qbool a, qbool b, qbool c){
  printqbool(a); printf(" NAND "); printqbool(b); printf(" = "); 
  printqbool(c); printf("\n");  // call another function from libnand.
  
}
