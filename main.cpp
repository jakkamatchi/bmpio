#include <iostream>
#include <fstream>
#include <string>

#include "BMPFile.h"

class Header {
	Header(*std::ifstream);
	~Header();
};

class InfoHeader{
	InfoHeader(*std::ifstream);
	~InfoHeader();
};

class ColorTable {
	ColorTable(*std::ifstream);
	~ColorTable();
};

class PixelData {
	PixelData(*std::ifstream);
	~PixelData()
};

int main(int argc, char* argv[]) {
	BMPFile file("input.bmp");


	return 0;
}
