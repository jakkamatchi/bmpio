#ifndef __BMPPIXELDATA_H_INCLUDED__
#define __BMPPIXELDATA_H_INCLUDED__

#include <fstream>
#include <iostream>

class BMPPixelData {
	public:
		BMPPixelData(std::ifstream*);
		~BMPPixelData();
};

#endif
