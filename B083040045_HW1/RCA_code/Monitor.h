#include "systemc.h"
#include <iostream>

using namespace std;

SC_MODULE( Monitor ) {	

	sc_in < bool > rst;
	sc_in_clk clock;
	sc_in < sc_uint<4> > A, B, S;
	sc_in < bool > C_in, C_out;
	
	int cycle;
	
	void run();
	
	SC_CTOR( Monitor )
	{	
		cycle = 0;
	
		SC_METHOD( run );
		sensitive << clock.pos();
	}
};

