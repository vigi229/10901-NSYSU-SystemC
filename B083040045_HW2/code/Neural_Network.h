#include "systemc.h"
#include "Neuron_arg.h"

SC_MODULE( Neural_Network ) {
	
	sc_in < float > input1, input2;
	sc_out < float > output;
  sc_signal < float > i1,i2,w1,w2,w3,w4,w5,w6,o1,o2,o3;
  
  Neuron *N1,*N2,*N3;
    void appand()
    {
        i1=input1.read();
        i2=input2.read();
    }
    void run()
    {
        w1=i1*10;
        w2=i1*(-10);
        w3=i2*(-10);
        w4=i2*10;
        w5=o1*10;
        w6=o2*10;
    }
    void assign()
    {
      output.write(o3);
    }
    
    SC_CTOR( Neural_Network ) {
		
		// vvvvv put your code here vvvvv
   SC_METHOD(appand);
     sensitive<<input1<<input2;
     
   SC_METHOD(run); 
     sensitive<<i1<<i2<<o1<<o2;
     
   SC_METHOD(assign);
     sensitive<<o3;

	    N1=new Neuron("N1");
      (*N1)(w1,w3,o1);
      N2=new Neuron("N2");
      (*N2)(w2,w4,o2);
      N3=new Neuron("N3");
      (*N3)(w5,w6,o3);
		// ^^^^^ put your code here ^^^^^
    }
};