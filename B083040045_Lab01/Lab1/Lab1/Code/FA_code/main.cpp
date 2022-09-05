#include "RCA.h"
#include "Pattern.h"
#include "Monitor.h"
#include "clockreset.h"
#include <iostream>

using namespace std;

int sc_main( int argc, char* argv[] ) {
	sc_signal < bool > clk, rst;
	sc_signal < bool > C_out, C_in;
	sc_signal < bool > A, B, S;
	
	Reset m_Reset( "m_Reset", 10 );
	Clock m_clock( "m_clock", 5, 40 );
	Pattern m_Pattern( "m_Pattern" );
	
	Full_adder m_Full_adder( "m_Full_adder" );
	
	Monitor m_Monitor( "m_Monitor" );
	
	m_Reset( rst );
	m_clock( clk );
	m_Pattern( rst, clk, A, B, C_in );
	
	m_Full_adder( A,  B, C_in, S, C_out );
	
	m_Monitor( rst, clk, A, B, S, C_in, C_out );
	
	sc_start( 500, SC_NS );
	return 0;

}


