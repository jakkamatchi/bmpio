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
	Display(BMPFile&, std::ofstream&);
	~Display();

	int cursor_X = 0;
	int cursor_Y = 0;

	private:
	void Print_8_BPP(BMPFile&, std::ofstream&);
};

Display::Display(BMPFile& File, std::ofstream& log) {
	if (File.InfoHeader->BMPBitsPerPixel == 1) {
		
	}
	else if (File.InfoHeader->BMPBitsPerPixel == 4) {

	}
	else if (File.InfoHeader->BMPBitsPerPixel == 8) {
		Print_8_BPP(File, log);		
	}
	else if (File.InfoHeader->BMPBitsPerPixel == 16) {

	}
	else if (File.InfoHeader->BMPBitsPerPixel == 32) {

	}
}

Display::~Display() {

}


void Display::Print_8_BPP(BMPFile& File, std::ofstream& log) {
	std::ostringstream ss;	
	ss << termcolor::colorize;
	int c = 0;

	for (int i = File.InfoHeader->BMPImageSize; i > -1; i-- ) {		
		//std::cout << "read char no. " << i << ": " << (int)File.PixelData->VPixelData[i] << std::endl;
		char ct_ref = File.PixelData->VPixelData[i];
	
		uint8_t BLUE = File.ColorTable->BMPColorData[(int)ct_ref].BLUE;
		uint8_t GREEN = File.ColorTable->BMPColorData[(int)ct_ref].GREEN; 
		uint8_t RED = File.ColorTable->BMPColorData[(int)ct_ref].RED;
		
		//log << "\033[38;2;" << +RED << ";" << +GREEN << ";" << +BLUE << "m";
		//log << (int)BLUE << " " << (int)RED << " "  << (int)GREEN << "\n";	
	
		ss << "\033[38;2;" << +RED << ";" << +GREEN << ";" << +BLUE << "m" << "\u2588\u2588";
		if(c == File.InfoHeader->BMPWidth + 1) {
			ss << "\n";
			c = 0;
		}

		c++;

	}
	std::cout << ss.str();
}

int main(int argc, char* argv[]) {
	std::ofstream log;
	log.open("log.log", std::ios::out);

	BMPFile file(argv[1], log);
	
	Display display(file, log);

	return 0;
}
