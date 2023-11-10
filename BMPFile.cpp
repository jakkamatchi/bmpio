#include <fstream>
#include <iostream>

#include "BMPFile.h"

BMPFile::BMPFile(std::string filename) {
	input.open(filename, std::ios::in|std::ios::binary|std::ios::ate);

	BMPHeader(*input);
}

BMPFile::~BMPFile() {

}

