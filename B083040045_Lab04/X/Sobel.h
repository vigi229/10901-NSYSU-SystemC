#include <systemc.h>

// vvvvv put your code here vvvvv
SC_MODULE( Sobel ) {
	sc_in_clk clock;
	sc_in < bool > rst;
	sc_in < sc_int<9> > Pixel;
	sc_out < sc_int<9> > result;
	sc_out < sc_uint<16> > i_addr;
	sc_out < bool > i_rd;
	sc_out < bool > output_valid;
	sc_int<9> image[258][258];
  sc_int<9> kernal[9];
  int count,mid,sum;
	void run();
	SC_CTOR( Sobel )
	{	
      for(int i=0;i<258;i++)
        for(int j=0;j<258;j++)
           image[i][j]=0;   
      count=0;
      mid=0;
      kernal[0]=1;kernal[1]=2;kernal[2]=1;
      kernal[3]=0;kernal[4]=0;kernal[5]=0;
      kernal[6]=-1;kernal[7]=-2;kernal[8]=-1;
      SC_METHOD( run );
		    sensitive << clock.pos();
	}
};
// ^^^^^ put your code here ^^^^^
