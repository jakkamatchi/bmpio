#ifndef __BMPPIXELDATA_H_INCLUDED__
#define __BMPPIXELDATA_H_INCLUDED__

#include <fstream>
#include <iostream>

#include "BMPColorTable.h"
#include "BMPHeader.h"
#include "BMPInfoHeader.h"

class BMPPixelData {
	public:
		BMPPixelData(std::ifstream&, std::ofstream&, BMPHeader&, BMPInfoHeader&, BMPColorTable&);
		BMPPixelData() { } ;
		~BMPPixelData();

		std::vector<char> VPixelData;


};

#endif
