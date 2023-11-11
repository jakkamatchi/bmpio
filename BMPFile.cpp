#include <fstream>
#include <iostream>

#include "BMPFile.h"
#include "BMPHeader.h"

BMPFile::BMPFile(char* filename) {
	input.open(filename, std::ios::in|std::ios::binary|std::ios::ate);
	log.open("log.log", std::ios::out);

	if(input.is_open() == true) {
		log << "Opened: " << filename << std::endl;
		std::streampos FileSize = input.tellg();

		FileData = new char[FileSize];
		input.seekg(0, std::ios::beg);
		input.read(FileData, FileSize);		

		BMPHeader* Header = new BMPHeader(input, log);
		BMPInfoHeader* InfoHeader = new BMPInfoHeader(input, log);
		BMPColorTable* ColorTable = new BMPColorTable(input);
		BMPPixelData* PixelData = new BMPPixelData(input);
	}
	else {
		log << "Failed to open: " << filename;
	}

	input.close();
}

BMPFile::~BMPFile() {

}

