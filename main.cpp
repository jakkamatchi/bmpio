#include <iostream>
#include <fstream>
#include <string>

#include "BMPFile.h"
#include "BMPHeader.h"
#include "BMPInfoHeader.h"
#include "BMPColorTable.h"
#include "BMPPixelData.h"

int main(int argc, char* argv[]) {
	BMPFile file(argv[1]);

	return 0;
}
