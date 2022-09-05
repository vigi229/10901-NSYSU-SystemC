#include "systemc.h"

SC_MODULE( ALU ) {	
	
	sc_in < sc_int<16> > A, B;
	sc_in < sc_bv<3> > OpCode;
	sc_out < sc_int<16> > Result;
	sc_out < bool > Zero, Overflow;
	
	void run();
	
	SC_CTOR( ALU )
	{
		SC_METHOD( run );
		sensitive << A << B << OpCode;
	}
};




