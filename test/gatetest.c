#include "../header/qbool.h"
#include "../header/gates.h"
#include <stdio.h>

extern qboolP qnand(qboolP a, qboolP b, qboolP out);
extern void printqbool(qboolP a);

void printnand(qboolP a, qboolP b, qboolP c);
void printgate(qboolP a, qboolP b, qboolP c, char * str);
void printmux(qboolP s, qboolP a, qboolP b, qboolP out);
void printdemux(qboolP in, qboolP s1, qboolP s2, qboolP out);


int main(void)
{
  //qbool a=T, b=F; //define two booleans
  qbool c, i=F, j=F, s=F; qbool out[4];
  qboolP cp = &c, ip=&i, jp=&j, sp=&s;
  printf("****************** Testing NAND *************************\n");
  for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      cp = qnand(ip,jp, cp);
      printgate(ip,jp,cp, "NAND");
      
      
    }
  }
  printf("**************** Testing AND **********************\n");
  
  for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      cp = qand(ip,jp, cp);
      printgate(ip,jp,cp, "AND");
      
      
    }
  }
  
  printf("**************** Testing OR *********************\n");

  for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      cp = qor(ip,jp,cp);
      printgate(ip,jp,cp, "OR");
      
      
    }
  }
  
  printf("**************** Testing XOR ***********************\n");

  for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      cp = qxor(ip,jp,cp);
      printgate(ip,jp,cp, "XOR");
      
      
    }
  }

  //c = nand(a,b); //will call a function declared in qbool.h and defined in libnand.so
  
  printf("************** Testing Mux************************\n");
  printf("\nA\tB\tSelect\t|\tOut\n");
  printf("--------------------------------------------- \n");  
 
  for(s=F; s<=T; s++){
   for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      cp = qmux(sp,ip,jp,cp);
      printf("%d\t%d\t%d\t|\t%d\n",s,i,j,*cp);
        
    }
   }
  }

 printf("************** Testing Demux************************\n");
 
 
 printf("\nA\tS1\tS2\t|\tSO1\tO2\tO3\tO4\n");
  printf("-------------------------------------------- \n"); 
 //qbool out[4];
  for(s=F; s<=T; s++){
   for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      qdemux(sp,ip,jp, out);
      printf("%d\t%d\t%d\t|\t%d\t%d\t%d\t%d\n",s,i,j,out[0],out[1],out[2],out[3]);
      //printdemux(sp,ip,jp, out);
        
    }
   }
  }
 
  printf("************** Testing Full Adder************************\n");
 
  printf("\nA\tB\tCarry\t|\tSum\tCarry out\n");
  printf("----------------------------------------------------- \n"); 
  
  for(s=F; s<=T; s++){
   for(i=F; i<=T; i++){
    for(j=F; j<=T; j++){
      qfulladder(sp,ip,jp, &out[0], &out[1]);
      printf("%d\t%d\t%d\t|\t%d\t%d\n",s,i,j,out[0],out[1]);
      
        
    }
   }
  }
  printf("\n *************** TESTING DONE ************************ \n");
  
  return(0);
}
 

void printnand(qboolP a, qboolP b, qboolP c){
  printqbool(a); printf(" NAND "); printqbool(b); printf(" = "); 
  printqbool(c); printf("\n");  // call another function from libnand.
  
}
void printgate(qboolP a, qboolP b, qboolP c, char * str){
  printqbool(a); printf(" %s ", str); printqbool(b); printf(" = "); 
  printqbool(c); printf("\n");  // call another function from libnand.
  
}

void printmux(qboolP s, qboolP a, qboolP b, qboolP out){
  printqbool(s); printf(" ");printqbool(a); printf(" "); printqbool(b); printf(" = "); 
  printqbool(out); printf("\n");  // call another function from libnand.
  
}

void printdemux(qboolP in, qboolP s1, qboolP s2, qboolP out){
  printqbool(in); printf(" ");printqbool(s1); printf(" "); printqbool(s2); printf(" = "); 
  printqbool(&out[0]); printf(" ");printqbool(&out[1]);printf(" ");printqbool(&out[2]);printf(" ");printqbool(&out[3]);
  printf("\n");  // call another function from libnand.
  
}



  
