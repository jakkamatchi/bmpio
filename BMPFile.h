#ifndef __BMPFILE_H_INCLUDED__
#define __BMPFILE_H_INCLUDED__

#include <string>
#include <fstream>

class BMPFile {
	BMPFile(std::string);
	~BMPFile();

	std::ifstream input;
	
	Header BMPHeader;
	InfoHeader BMPInfoHeader;
	ColorTable BMPColorTable;
	PixelData BMPPixelData;	
};

#endif
