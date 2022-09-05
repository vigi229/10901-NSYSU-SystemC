#include "systemc.h"
#include <iostream>
#define CYCLE 9

using namespace std;

SC_MODULE( Pattern ) {	

	sc_in < bool > rst;
	sc_in_clk clock;
	sc_out < bool > A, B;
	sc_out < bool > C_in;
	
	sc_uint <32> cycle;
	sc_uint <3> temp_uint;
		
	void run();
	
	SC_CTOR( Pattern )
	{	
		temp_uint = 0;
		cycle = 0;
		SC_METHOD( run );
		sensitive << clock.neg();
	}
};

