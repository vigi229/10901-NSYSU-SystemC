#include "systemc.h"
#include <iostream>
#define CYCLE 9

using namespace std;

SC_MODULE( Pattern ) {	

	sc_in < bool > rst;
	sc_in_clk clock;
	sc_out < sc_int<16> > A, B;
	sc_out < sc_bv<3> > OpCode;
	
	sc_uint <32> cycle;
	sc_uint <3> temp_OpCode;
	sc_int <16> temp_C;
		
	void run();
	
	SC_CTOR( Pattern )
	{	
		cycle = 0;
		SC_METHOD( run );
		sensitive << clock.neg();
	}
};


