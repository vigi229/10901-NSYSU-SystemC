#include "Save.h"

void Save::run() {
	if ( output_valid ) {
		temp = result.read();
		//cout << "Counter:" << counter << ", Result: " << (int)temp << endl;
		fout << temp;
		fout << temp;
		fout << temp;
		counter++;
		if ( counter == 256*256 ) {
			fout.close();
			sc_stop();
		}
	}	
}
