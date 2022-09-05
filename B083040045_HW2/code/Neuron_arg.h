#ifndef NEURON_H
#define NEURON_H

#include "systemc.h"

SC_MODULE( Neuron ) {
  public:
    sc_in < float > input1, input2;
  	sc_out < float > output;
		float t,i1,i2,count;
    SC_HAS_PROCESS( Neuron );

	// vvvvv put your code here vvvvv
    Neuron( sc_module_name name ) :
            sc_module( name )
    {
		SC_METHOD( neuron );
		sensitive << input1 << input2;
    } 
	// ^^^^^ put your code here ^^^^^
  
  private :
    void neuron();
	float w1;
	float w2;
	float b;
};
#endif

