#include <fstream>

#include "BMPPixelData.h"
#include "BMPInfoHeader.h"
#include "BMPHeader.h"

BMPPixelData::BMPPixelData(std::ifstream& input, std::ofstream& log, BMPHeader& header, BMPInfoHeader& infoHeader, BMPColorTable& colorTable) {
	int PixelDataSize = infoHeader.BMPImageSize;
	char* t_VPixelData = new char[PixelDataSize];
	int PixelDataOffset = 0x36 + (infoHeader.BMPColorsUsed * 4);
	
	input.seekg(PixelDataOffset, std::ios::beg);
	input.read(t_VPixelData, PixelDataSize);

	for (int i = 0; i < PixelDataSize; i++) {
		VPixelData.push_back(t_VPixelData[i]);
		//std::cout << VPixelData[i] << " " << t_VPixelData[i] << std::endl;
	}

	std::cout << "finished redaing" << std::endl;
	delete[] t_VPixelData;
}

BMPPixelData::~BMPPixelData() {

}
