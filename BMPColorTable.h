#ifndef __BMPCOLORTABLE_H_INCLUDED__
#define __BMPCOLORTABLE_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <vector>

#include "BMPHeader.h"
#include "BMPInfoHeader.h"

struct BMPColor {
	char RED;
	char GREEN;
	char BLUE;
};

class BMPColorTable {
	public:
		//ifstream for reading data
		//ofstream for logging
		//BMPHeader for offset of piel data
		//BMPInfoheader for number of colours, compression
		BMPColorTable(std::ifstream&, std::ofstream&, BMPHeader&, BMPInfoHeader&);
		BMPColorTable() { };

		~BMPColorTable();

		std::vector<BMPColor> BMPColorData;
};

#endif
