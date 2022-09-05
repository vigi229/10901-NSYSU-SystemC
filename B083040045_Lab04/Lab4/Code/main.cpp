#include "Save.h"
#include "Image.h"
#include "Sobel.h"
#include "clockreset.h"


int sc_main( int argc, char* argv[] ) {
	sc_signal < sc_int<9> > Pixel;
	sc_signal < sc_int<9> > result;
	sc_signal < sc_uint<16> > i_addr;
	sc_signal < bool > i_rd, rst, clk;
	sc_signal < bool > output_valid;
	
	Reset m_Reset( "m_Reset", 20 );
	Clock m_Clock( "m_Clock", 5, 100000000 );
	Image m_Image( "m_Image" );
	Sobel m_Sobel( "m_Sobel" );
	Save m_Save( "m_Save" );
	
	m_Reset( rst );
	m_Clock( clk );
	m_Image( clk, Pixel, i_addr, i_rd );
	m_Sobel( clk, rst, Pixel, result, i_addr, i_rd, output_valid );
	m_Save( clk, result, output_valid );
	
	sc_start(100000000, SC_NS);
	
	return 0;
}

