#include "BMPFile.h"

BMPFile::BMPFile(std::string filename) {
	input.open(filename, ios::in|ios::binary|ios::ate);

	BMPHeader(*input);
}

BMPFile::~BMPFile() {

}

