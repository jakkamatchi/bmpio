#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "BMPFile.h"
#include "BMPHeader.h"
#include "BMPInfoHeader.h"
#include "BMPColorTable.h"
#include "BMPPixelData.h"
#include "termcolor.h"

//#define R 150
//#define G 50
//#define B 100

class Display {
	public:
	Display(BMPFile&);
	~Display();

	int cursor_X = 0;
	int cursor_Y = 0;

	void PrintData(BMPFile&);
};

Display::Display(BMPFile& File) {
	if (File.InfoHeader->BMPBitsPerPixel == 1) {
		
	}
	else if (File.InfoHeader->BMPBitsPerPixel == 4) {

	}
	else if (File.InfoHeader->BMPBitsPerPixel == 8) {
		
	}
	else if (File.InfoHeader->BMPBitsPerPixel == 16) {

	}
	else if (File.InfoHeader->BMPBitsPerPixel == 32) {

	}
}

Display::~Display() {

}

void Display::PrintData(BMPFile& File) {
	for (int i = 0; i < File.InfoHeader->BMPImageSize; i++ ) {		
		std::cout << "read char no. " << i << ": " << (int)File.PixelData->VPixelData[i] << std::endl;
		char ct_ref = File.PixelData->VPixelData[i];
	
		uint8_t BLUE = File.ColorTable->BMPColorData[(int)ct_ref].BLUE;
		uint8_t GREEN = File.ColorTable->BMPColorData[(int)ct_ref].GREEN; 
		uint8_t RED = File.ColorTable->BMPColorData[(int)ct_ref].RED;
		
		uint8_t R = 1;
		uint8_t G = 2;
		uint8_t B = 3;
		
		std::ostringstream ss;		
		ss << termcolor::colorize;
		
		ss << "\033[38;2;" << +RED << ";" << +GREEN << ";" << +BLUE << "m";
		ss << (int)BLUE << " "  << (int)RED << " "  << (int)GREEN << std::endl;	
		//ss << termcolor::color<uint8_t i>;// << "@";
		std::cout << ss.str();
	}
}

int main(int argc, char* argv[]) {
	BMPFile file(argv[1]);

	std::cout << "file read" << std::endl;
	std::cout << file.InfoHeader->BMPImageSize;
	std::cout << "sig";
	
	Display display(file);
	display.PrintData(file);

	return 0;
}
