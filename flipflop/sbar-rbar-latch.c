#include "../header/qbool.h"
#include "../header/gates.h"
#include "../header/flipflops.h"
#include <stdio.h>

extern qboolP qnand(qboolP a, qboolP b, qboolP out);
extern void printqbool(qboolP a);

qboolP sbar_rbar_latch( qboolP sbar, qboolP rbar, qboolP Qout, qboolP Qbarout) 
{ 
  /* I got this circuit diagram on wikipedia. sbar_rbar_latch. It wll be later used to build a D-Latch*/
  qbool sin[2], rin[2], Q[2], Qbar[2]; 
  // Since flip flop is a sequential circuit, we want to evaluate it 
  // continuously untill it is stable. We will do this in a loop. 
  // at the end of loop we will check whether all signals have the same 
  // value as their previous value. If so, stabilization is assumed and 
  // the return is called.
  
  int unstable=1; // assume unstable at first 

  while(unstable){
    // if flip flop is unstable, do another iteration.
    //printf("latch: unstable\n");
    sin[0] = Qbar[0];
    qnand(sbar, &sin[0], &Q[0]);
    rin[0] = Q[0];  
    qnand(rbar, &rin[0], &Qbar[0]);
    
    // iteration complete. Check whether current state is stable.
    // check that all signals values are the same same now as they were previously.
    unstable = 0; //declare it stable.
    if((sin[0] != sin[1]) || (rin[0] != rin[1]) || (Q[0] != Q[1]) || (Qbar[0] != Qbar[1])){
      unstable =1;  // declare it unstable.
    // now do the shifting of current values to previous values.
    }
     
    sin[1] = sin[0];
    rin[1] = rin[0];
    Q[1]   = Q[0];
    Qbar[1] = Qbar[0];
	  //continue to loop.

   } 
  //printf("latch stable\n");
  *Qout = Q[0];
  *Qbarout = Qbar[0]; 
  return(Qout);
}


qboolP srlatch(qboolP s, qboolP r, qboolP Qout, qboolP Qbarout){
  
  //Note previous state of latch.
  qbool Qp=*Qout, Qbarp=*Qbarout;
  qbool nor1, nor2;
 
  qnor(r,&Qbarp, &nor1);
  qnor(s,&Qp, &nor2); 
Qcheck:      
              if(nor1 != Qp) 
                goto Qchanged; 
	     else 
	        goto Qbarcheck;
Qbarcheck:    
              if(nor2 != Qbarp) 
		goto Qbarchanged; 
             else 
                goto finish;

 Qbarchanged: //printf("Qbar changed");
              Qbarp = nor2;    
              qnor(r,&Qbarp, &nor1); 
              goto Qcheck;

 Qchanged:    //printf("Q changed");
              Qp=nor1;
              qnor(s,&Qp, &nor2); 
              goto Qbarcheck;
   //check whether
 finish: 
              *Qout = nor1;
              *Qbarout = nor2;
              return(Qout); 
 
  }

qboolP gatedsrlatch(qboolP enable, qboolP s, qboolP r, qboolP Qout, qboolP Qbarout){ 
  qbool es, er;
  qand(enable,s,&es);
  qand(enable,r,&er);
  srlatch(&es, &er, Qout, Qbarout);
  return Qout;
}

qboolP Dlatch(qboolP enable, qboolP D, qboolP Qout, qboolP Qbarout){
  qbool nD;
  qnot(D, &nD);
  gatedsrlatch(enable, D, &nD, Qout, Qbarout);
  return(Qout);
 }

qboolP Dflipflop(qboolP clk, qboolP D, qboolP Qout, qboolP Qbarout){
  
  qbool Q, Qbar, clk2;  
  //
  //qnot(clk,&clk1);            //clk inverter
  Dlatch(clk,D,&Q,&Qbar); // firt transparent D latch for flip flop. Mater D latch
  qnot(clk,&clk2);            //clk inverter
  gatedsrlatch(&clk2, &Q, &Qbar, Qout, Qbarout);   
  return(Qout);

}
