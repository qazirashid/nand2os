#include "../header/qbool.h"
#include "../header/gates.h"
#include <stdio.h>


void printnand(qbool a, qbool b, qbool c);
void printgate(qbool a, qbool b, qbool c, char * str);
void printmux(qbool s, qbool a, qbool b, qbool out);
void printdemux(qbool in, qbool s1, qbool s2, qbool *out);
int main(void)
{
  //qbool a=T, b=F; //define two booleans
  qbool c, i=F, j=F, s=F;
  
  printf("****************** Testing NAND *************************\n");
  for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      c = nand(i,j);
      printgate(i,j,c, "NAND");
      
      
    }
  }
  printf("**************** Testing AND **********************\n");

  for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      c = qand(i,j);
      printgate(i,j,c, "AND");
      
      
    }
  }
  printf("**************** Testing OR *********************\n");

  for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      c = qor(i,j);
      printgate(i,j,c, "OR");
      
      
    }
  }
  printf("**************** Testing XOR ***********************\n");

  for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      c = qxor(i,j);
      printgate(i,j,c, "XOR");
      
      
    }
  }

  //c = nand(a,b); //will call a function declared in qbool.h and defined in libnand.so
  
  printf("************** Testing Mux************************\n");
  
  for(s=F; s<=T; s++){
   for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      c = qmux(s,i,j);
      printmux(s,i,j,c);
        
    }
   }
  }

 printf("************** Testing Demux************************\n");
  
 qbool out[4];
  for(s=F; s<=T; s++){
   for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      qdemux(s,i,j, out);
      printdemux(s,i,j, out);
        
    }
   }
  }
 
  printf("\n *************** TESTING DONE ************************ \n");
  
}

void printnand(qbool a, qbool b, qbool c){
  printqbool(a); printf(" NAND "); printqbool(b); printf(" = "); 
  printqbool(c); printf("\n");  // call another function from libnand.
  
}
void printgate(qbool a, qbool b, qbool c, char * str){
  printqbool(a); printf(" %s ", str); printqbool(b); printf(" = "); 
  printqbool(c); printf("\n");  // call another function from libnand.
  
}
void printmux(qbool s, qbool a, qbool b, qbool out){
  printqbool(s); printf(" ");printqbool(a); printf(" "); printqbool(b); printf(" = "); 
  printqbool(out); printf("\n");  // call another function from libnand.
  
}

void printdemux(qbool in, qbool s1, qbool s2, qbool* out){
  printqbool(in); printf(" ");printqbool(s1); printf(" "); printqbool(s2); printf(" = "); 
  printqbool(out[0]); printf(" ");printqbool(out[1]);printf(" ");printqbool(out[2]);printf(" ");printqbool(out[3]);
  printf("\n");  // call another function from libnand.
  
}

