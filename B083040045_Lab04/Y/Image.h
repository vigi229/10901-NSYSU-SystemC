#include <systemc.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

SC_MODULE( Image ) {
	sc_in_clk clock;
	sc_out < sc_int<9> > Pixel;
	sc_in < sc_uint<16> > i_addr;
	sc_in < bool > i_rd;
	
	unsigned char y, u, v;
	ifstream fin;
	char header[54];
	int width, hight, data_start;
	sc_int<9> ROM[256*256];

	
	void image_proc();
	
	SC_CTOR( Image )
	{
		// change your path of input file here
		fin.open( "/home/b083040045/Desktop/Lab04/balloon_GRAY.bmp" );

		for ( int i = 0 ; i < 54 ; i++ )
			header[i] = fin.get();
		
		width = header[21]*256*256*256 + header[20]*256*256 + header[19]*256 + header[18];
		hight = header[25]*256*256*256 + header[24]*256*256 + header[23]*256 + header[22];
		data_start = header[13]*256*256*256 + header[12]*256*256 + header[11]*256 + header[10];
		cout<< "Width: " << width << " Hight: " << hight << " Start: " << data_start << endl;
		for ( int i = 0; i < width*hight; i++ ) {
		  ROM[i] = fin.get();
		  ROM[i] = fin.get();
		  ROM[i] = fin.get();
		}
		fin.close();
		
		SC_METHOD( image_proc );
		sensitive << clock.neg();
	}
};
