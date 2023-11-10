#ifndef __BMPCOLORTABLE_H_INCLUDED__
#define __BMPCOLORTABLE_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <vector>

struct BMPColor {
	uint8_t RED;
	uint8_t GREEN;
	uint8_t BLUE;
};

class BMPColorTable {
	public:
		BMPColorTable(std::ifstream&);
		~BMPColorTable();

		std::vector<BMPColor> BMPColorData;
};

#endif
