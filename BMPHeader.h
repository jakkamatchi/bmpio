#ifndef __BMPHEADER_H_INCLUDED__
#define __BMPHEADER_H_INCLUDED__

#include <fstream>

class BMPHeader {
	public:
		BMPHeader(std::ifstream*);
		~BMPHeader();
};

#endif 
