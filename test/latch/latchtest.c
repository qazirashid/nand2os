

#include "../../header/qbool.h"
#include "../../header/gates.h"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

extern qboolP qnand(qboolP a, qboolP b, qboolP out);
extern void printqbool(qboolP a);



extern qboolP sbar_rbar_latch( qboolP sbar, qboolP rbar, qboolP Qout, qboolP Qbarout);
extern qboolP Dlatch(qboolP clk, qboolP D, qboolP Qout, qboolP Qbarout);
extern qboolP Dflipflop(qboolP clk, qboolP D, qboolP Qout, qboolP Qbarout);
extern qboolP srlatch(qboolP s, qboolP r, qboolP Qout, qboolP Qbarout);
int main(void){
  

  
  qbool  truebool=T, falsebool=F, Qout, Qbarout, sbar, rbar;
  char n;
  
  printf("need input from user\n press:\n\t's': to supply pulse at s input\n");
  printf("\t'r': to supply pulse at r input\n\t'n': to supply s=0 r=0 \n\t'x': to exit");
  
  Qout = 1; Qbarout=0;
  
  printf("*************** testing srlatch ****************** \n");
  printf("\nin\ts\tr\t|\tQ\tQbar\n");
  printf("----------------------------------------------------\n");
  
  while( (n=getchar()) != 'x' ){   
      
    if(n=='s'){
      srlatch(&truebool, &falsebool , &Qout, &Qbarout);
      printf("s\t%d\t%d\t|\t%d\t%d\n",truebool, falsebool, Qout, Qbarout);
    }

    if(n=='r'){
      srlatch(&falsebool, &truebool, &Qout, &Qbarout);
      printf("r\t%d\t%d\t|\t%d\t%d\n", falsebool, truebool, Qout, Qbarout);
    }
    if(n=='n'){
      srlatch(&falsebool, &falsebool , &Qout, &Qbarout);
      printf("n\t%d\t%d\t|\t%d\t%d\n",falsebool, falsebool, Qout, Qbarout);
    }
      
  }

  printf("************* Finished Test ************************\n");

  printf("*************** testing D-latch ****************** \n");
  printf("\nclk\tD\t|\tQout\tQbarout\n");
  printf("----------------------------------------------------\n");
  
  //qbool sbar, rbar, Qout, Qbarout;
  
  for(sbar=F; sbar<=T; sbar++)
    for(rbar=F; rbar<=T; rbar++){
      Dlatch(&sbar, &rbar, &Qout, &Qbarout);
      printf("%d\t%d\t|\t%d\t%d\n", sbar, rbar, Qout, Qbarout);
    }
  printf("************* Finished Test ************************\n");
  
  
  int i, Dcount=0; qbool clk=F, D=T;
  D = T ;
  printf(" *************** Sequence test ******************");
  printf("*************** testing transparent D-latch ****************** \n");
  printf("\nclk\tD\t|\tQout\tQbarout\n");
  printf("----------------------------------------------------\n");
    
     
  for(i=1; i<=20; i++)
    { 
      
      qnot(&clk, &clk); //toggles the clock
      Dlatch(&clk,&D, &Qout, &Qbarout);
      printf("%d\t%d\t|\t%d\t%d\n", clk, D, Qout, Qbarout);
      Dcount++;
      if(Dcount>10){
	Dcount =0;
	qnot(&D,&D);
      }
    }
  printf("************* Finished Test ************************\n");
  printf(" *************** Sequence test ******************");
  printf("*************** testing D flip flop ****************** \n");
  printf("\nclk\tD\t|\tQout\tQbarout\n");
  printf("----------------------------------------------------\n");
    
     
  for(i=1; i<=20; i++)
    { 
      
      qnot(&clk, &clk); //toggles the clock
      Dflipflop(&clk,&D, &Qout, &Qbarout);
      printf("%d\t%d\t|\t%d\t%d\n", clk, D, Qout, Qbarout);
      Dcount++;
      if(Dcount>10){
	Dcount =0;
	qnot(&D,&D);
      }
    }
  printf("************* Finished Test ************************\n");
  
  return(0);
}
