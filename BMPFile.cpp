#include <fstream>
#include <iostream>

#include "BMPFile.h"
#include "BMPHeader.h"
#include "BMPInfoHeader.h"
#include "BMPColorTable.h"
#include "BMPPixelData.h"

BMPFile::BMPFile(char* filename) {
	input.open(filename, std::ios::in|std::ios::binary|std::ios::ate);
	log.open("log.log", std::ios::out);

	if(input.is_open() == true) {
		log << "Opened: " << filename << std::endl;
		std::streampos FileSize = input.tellg();

		FileData = new char[FileSize];
		input.seekg(0, std::ios::beg);
		input.read(FileData, FileSize);		

		BMPFile::Header = new BMPHeader(input, log);

		BMPFile::InfoHeader = new BMPInfoHeader(input, log);

		if(InfoHeader->BMPBitsPerPixel <= 8) {	
			BMPFile::ColorTable = new BMPColorTable(input, log, *Header, *InfoHeader);
		}
		else {
			BMPFile::ColorTable = new BMPColorTable();
		}
		
		this->PixelData = new BMPPixelData(input, log, *Header, *InfoHeader, *ColorTable);
	}
	else {
		log << "Failed to open: " << filename;
	}

	input.close();
}

BMPFile::~BMPFile() {

}

