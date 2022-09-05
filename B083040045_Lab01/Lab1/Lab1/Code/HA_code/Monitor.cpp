#include "Monitor.h"

void Monitor:: run() {
	
	if ( rst.read() == 1 )
	   cout << "A\tB\tC_in\tS\tC_out\n";
	else if ( cycle != 0 )
		cout << A << "\t" << B << "\t" << C_in << "\t" << S << "\t" << C_out << endl;
	
	cycle ++;
}