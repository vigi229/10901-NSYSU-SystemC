#include <systemc.h>

SC_MODULE( Save ) {
	sc_in_clk clock;
	sc_in < sc_int<9> > result;
	sc_in < bool > output_valid;
	
	void run();
	
	ifstream fin;
	ofstream fout;
	int counter;
	char temp;
	
	SC_CTOR( Save )
	{
		counter = 0;
		// change your path of input file here
		fin.open( "/home/b083040045/Desktop/Lab04/balloon_GRAY.bmp" );
		fout.open( "/home/b083040045/Desktop/Lab04/balloon_Y.bmp", ios::out );
		for ( int i = 0 ; i < 54 ; i++ ) {
			temp = fin.get();
			fout << temp;
		}
		fin.close();
			
		SC_METHOD( run );
		sensitive << clock.pos();
	}
};

