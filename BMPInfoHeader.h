#ifndef __BMPINFOHEADER_H_INCLUDED__
#define __BMPINFOHEADER_H_INCLUDED__

#include <iostream>
#include <fstream>

class BMPInfoHeader{
	public:
		BMPInfoHeader(std::ifstream&, std::ofstream&);
		BMPInfoHeader() { };
		~BMPInfoHeader();

		uint32_t BMPSize = 0;
		uint32_t BMPWidth = 0;
		uint32_t BMPHeight = 0;
		uint16_t BMPPlanes = 0;
		uint16_t BMPBitsPerPixel = 0;
		uint32_t BMPCompression = 0;
		uint32_t BMPImageSize = 0;
		uint32_t BMPXPixelsPerMeter = 0;
		uint32_t BMPYPixelsPerMeter = 0;
		uint32_t BMPColorsUsed = 0;
		uint32_t BMPImportantColors = 0;
};

#endif
