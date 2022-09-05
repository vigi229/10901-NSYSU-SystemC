#include "systemc.h"
#include <iostream>

using namespace std;

SC_MODULE( Monitor ) {	

	sc_in < bool > rst;
	sc_in_clk clock;
	sc_in < sc_int<16> > A, B;
	sc_in < sc_bv<3> > OpCode;
	
	sc_in < sc_int<16> > Result;
	sc_in < bool > Zero, Overflow;
	
	sc_bv < 16 > bv_A, bv_B, bv_Result;
	
	int cycle;
	
	void run();
	
	SC_CTOR( Monitor )
	{	
		cycle = 0;
	
		SC_METHOD( run );
		sensitive << clock.pos();
	}
};

