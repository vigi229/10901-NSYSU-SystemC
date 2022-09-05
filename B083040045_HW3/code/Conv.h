#include "systemc.h"
#include <iostream>
#include <fstream>

using namespace std;

SC_MODULE( Conv ) {	
	sc_in < bool > rst;
	sc_in_clk clk;
	sc_out < bool > rom_rd;
	sc_out < sc_uint<7> > rom_addr;
	sc_in < float > data_in;
	sc_out < sc_int<19> > data_out;
	sc_out < bool > data_out_signal;
	float rom_m [111];
  sc_int<19> sum;
  int count,first;
  int idx;
	void run();
//  void rom();
	SC_CTOR( Conv )
	{	
    count=0;
    first=0;
		SC_METHOD( run );
		  sensitive << rst.pos() << clk.pos();
 
	}
};


