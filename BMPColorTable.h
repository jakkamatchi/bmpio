#ifndef __BMPCOLORTABLE_H_INCLUDED__
#define __BMPCOLORTABLE_H_INCLUDED__

#include <iostream>
#include <fstream>

class BMPColorTable {
	public:
		BMPColorTable(std::ifstream*);
		~BMPColorTable();
};

#endif
