#include "Pattern.h"
#include <time.h>

void Pattern::run() {

	if ( rst.read() == 1 )
		return;

	if ( temp_OpCode < 6 ) {
		temp_C = rand() % 32768;
		if ( rand() % 2 == 1 )
			A = -1*temp_C.to_int();
		else
			A = temp_C.to_int();
		
		
		temp_C = rand() % 32768;
		if ( rand() % 2 == 1 )
			B = -1*temp_C.to_int();
		else
			B = temp_C.to_int();
		OpCode = temp_OpCode;
	}
	else if ( temp_OpCode == 6 ) {
		A = 5084;
		B = 18946;
		OpCode = "010";
	}
	else if ( temp_OpCode == 7 ) {
		A = 15248;
		B = 26418;
		OpCode = "011";
	}
	
	temp_OpCode = temp_OpCode + 1;
	
	cycle++;
	if ( cycle == CYCLE )
		sc_stop();
}


