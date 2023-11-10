#ifndef __BMPINFOHEADER_H_INCLUDED__
#define __BMPINFOHEADER_H_INCLUDED__

#include <iostream>
#include <fstream>

class BMPInfoHeader{
	public:
		BMPInfoHeader(std::ifstream*);
		~BMPInfoHeader();
};

#endif
