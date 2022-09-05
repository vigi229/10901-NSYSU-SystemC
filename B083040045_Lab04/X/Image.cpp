#include "Image.h"

void Image::image_proc() {
	if ( i_rd.read() == 1 )
		Pixel = ROM[i_addr.read()];
}
