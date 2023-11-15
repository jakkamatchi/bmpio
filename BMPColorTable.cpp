#include <fstream>

#include "BMPColorTable.h"

const int OFFSET_COLOR_TABLE = 0x36;

BMPColorTable::BMPColorTable(std::ifstream& input, std::ofstream& log, BMPHeader& header, BMPInfoHeader& info_header) {
	int colorDataSize = header.BMPDataOffset - OFFSET_COLOR_TABLE;
	int numEntries = colorDataSize / 4;

	std::cout << "Color Data Size: " << colorDataSize << "Color Data Entries: " << numEntries;

	int byteRead = OFFSET_COLOR_TABLE;
	char* color_entry_input = new char[4];

	BMPColor ColorEntry;
	ColorEntry.RED = 0;
	ColorEntry.GREEN = 0;
	ColorEntry.BLUE = 0;

	for (int i = 0; i < numEntries; i++) {
		input.seekg(byteRead, std::ios::beg);
		input.read(color_entry_input, 4);
		
		ColorEntry.BLUE = color_entry_input[0];
		ColorEntry.GREEN = color_entry_input[1];
		ColorEntry.RED = color_entry_input[2];
		
		BMPColorData.push_back(ColorEntry);
		//std::cout << "R:" << static_cast<int>(BMPColorData[i].RED) << " G:" << (int)BMPColorData[i].GREEN << " B:" << static_cast<int>(BMPColorData[i].BLUE) << std::endl; 
		byteRead += 4;
	}

	std::cout << "COLOR TABLE DONE" << std::endl;	
	delete[] color_entry_input;	
}

BMPColorTable::~BMPColorTable() {

}
