#include "Pattern.h"
#include <time.h>

void Pattern::run() {

	if ( rst.read() == 1 )
		return;

	C_in = temp_uint[0] == 1? 1:0; 
	B = temp_uint[1] == 1? 1:0;
	A = temp_uint[2] == 1? 1:0;
	
	temp_uint = temp_uint.to_uint() + 1;

	cycle++;
	if ( cycle == CYCLE )
		sc_stop();
}


