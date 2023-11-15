#ifndef __BMPFILE_H_INCLUDED__
#define __BMPFILE_H_INCLUDED__

#include <iostream>
#include <string>
#include <fstream>

#include "BMPHeader.h"
#include "BMPInfoHeader.h"
#include "BMPColorTable.h"
#include "BMPPixelData.h"

class BMPFile {
	public:
		BMPFile(char*, std::ofstream&);
		~BMPFile();
		
		std::ifstream input;

		char* FileData;

		BMPHeader* Header;
		BMPInfoHeader* InfoHeader;
		BMPColorTable* ColorTable;
		BMPPixelData* PixelData;
};

#endif
