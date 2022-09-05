#include "ALU.h"
#include "Pattern.h"
#include "Monitor.h"
#include "clockreset.h"
#include <iostream>

using namespace std;

int sc_main( int argc, char* argv[] ) {
	sc_signal < bool > clk, rst, Zero, Overflow;
	sc_signal < sc_int<16> > A, B, Result;
	sc_signal < sc_bv<3> > OpCode;
	
	Reset m_Reset( "m_Reset", 10 );
	Clock m_Clock( "m_Clock", 5, 40 );
	Pattern m_Pattern( "m_Pattern" );
	ALU m_ALU( "m_ALU" );
	Monitor m_Monitor( "m_Monitor" );
	
	m_Reset( rst );
	m_Clock( clk );
	m_Pattern( rst, clk, A, B, OpCode );
	
	m_ALU( A, B, OpCode, Result, Zero, Overflow );
	
	m_Monitor( rst, clk, A, B, OpCode, Result, Zero, Overflow );
	
	sc_start( 500, SC_NS );
	return 0;
}


