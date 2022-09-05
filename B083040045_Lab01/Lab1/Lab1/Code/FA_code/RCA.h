#include "systemc.h"

SC_MODULE( OR ) {
	sc_in < bool > cin1, cin2;
	sc_out < bool > cout;
	
	void run() {
		// vvvvv put your code here vvvvv

		// ^^^^^ put your code here ^^^^^
	}

	SC_CTOR( OR ) {
		SC_METHOD( run );
		sensitive << cin1 << cin2;
	}

};

SC_MODULE( Half_adder ) {
	sc_in < bool > a, b;
	sc_out < bool > sum, c_out;
	
	void run() {
		// vvvvv put your code here vvvvv

		// ^^^^^ put your code here ^^^^^
	}
	
	SC_CTOR( Half_adder ) {
		SC_METHOD( run );
		sensitive << a << b;
	}
};

SC_MODULE( Full_adder ) {
	sc_in < bool > a, b, c_in;
	sc_out < bool > s, c_out;
	
	void run() {
		// vvvvv put your code here vvvvv

		// ^^^^^ put your code here ^^^^^
	}
	
	SC_CTOR( Full_adder ) {
		SC_METHOD( run );
		sensitive << a << b << c_in;
	}
};

SC_MODULE( RCA ) {
	sc_in < sc_uint<4> > A, B;
	sc_in < bool> C_in;
	sc_out < sc_uint<4> > S;
	sc_out < bool > C_out;
  
	Full_adder *FA_1, *FA_2, *FA_3, *FA_4;
    
	// vvvvv put your code here vvvvv
		
	// ^^^^^ put your code here ^^^^^
		
	SC_CTOR( RCA )
	{
		// vvvvv put your code here vvvvv
		
		// ^^^^^ put your code here ^^^^^
	}
};
