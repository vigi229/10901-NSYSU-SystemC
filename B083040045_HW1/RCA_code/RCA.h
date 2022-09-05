#include "systemc.h"

SC_MODULE( OR ) {
	sc_in < bool > cin1, cin2;
	sc_out < bool > cout;
	
	void run() {
		// vvvvv put your code here vvvvv
    cout=cin1|cin2;
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
    sum=a^b;
    c_out=a&b;
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
    s=a^b^c_in;
    c_out=(a^b)&c_in|(a&b);
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
   sc_signal<bool> s0,s1,s2,s3,a0,a1,a2,a3,b0,b1,b2,b3,c0,c1,c2,c3;
   sc_lv < 4 > s4;
   void assign(){
     s4[0]=s0;
     s4[1]=s1;
     s4[2]=s2;
     s4[3]=s3;
     
     S.write(s4);
     C_out=c3;
   }
   void appand(){
     a3=A.read()[3];
     a2=A.read()[2];
     a1=A.read()[1];
     a0=A.read()[0];
     
     b3=B.read()[3];
     b2=B.read()[2];
     b1=B.read()[1];
     b0=B.read()[0];
   }
	// ^^^^^ put your code here ^^^^^
		
	SC_CTOR( RCA )
	{
		// vvvvv put your code here vvvvv
  SC_METHOD(appand);
    sensitive << A << B << C_in;
  
     FA_1=new Full_adder("FA_1");
     (*FA_1)(a0,b0,C_in,s0,c0);
     FA_2=new Full_adder("FA_2");
     (*FA_2)(a1,b1,c0,s1,c1);
     FA_3=new Full_adder("FA_3");
     (*FA_3)(a2,b2,c1,s2,c2);
     FA_4=new Full_adder("FA_4");
     (*FA_4)(a3,b3,c2,s3,c3);
    
    SC_METHOD(assign);
      sensitive << s0 << s1 << s2 << s3;
		// ^^^^^ put your code here ^^^^^
	}
};
