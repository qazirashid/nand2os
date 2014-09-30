
#include "../header/qbool.h"
#include <stdio.h>
qbool nand(qbool a, qbool b){

if(a && b) 
  return(F);
return(T);
 
}

void printqbool(qbool a){
 
  if(a == T) printf("1");
  else       printf("0");
}
