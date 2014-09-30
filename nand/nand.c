
#include "../header/qbool.h"
#include <stdio.h>
qboolP qnand(qboolP a, qboolP b, qboolP out){

  if((*a) && (*b))
    *(out) = F;
  else
    *(out) = T;
  return(out);
 
}

void printqbool(qboolP a){
 
  if((*a) == T) printf("1");
  else       printf("0");
}
