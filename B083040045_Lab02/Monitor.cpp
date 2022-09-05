#include "Monitor.h"

void Monitor:: run() {
	
	if ( rst.read() == 1 )
	   cout << "A\t\t\tB\t\t\tOpCode\tResult\t\t\tZero\tOverflow\n";
	else if ( cycle != 0 ) {
		bv_A = A.read();
		bv_B = B.read();
		bv_Result = Result.read();
		
		if ( OpCode.read() == "000" || OpCode.read() == "001" || OpCode.read() == "101" ) // show bit
			cout << bv_A.to_string() << "\t" << bv_B.to_string() << "\t" << OpCode << "\t"
				 << bv_Result.to_string() << "\t" << Zero << "\t" << Overflow << endl;
		else
			cout << bv_A.to_int() << "\t\t\t" << bv_B.to_int() << "\t\t\t" << OpCode << "\t"
				 << bv_Result.to_int() << "\t\t\t" << Zero << "\t" << Overflow << endl;
	}
	
	cycle ++;
}