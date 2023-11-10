#ifndef __BMPINFOHEADER_H_INCLUDED__
#define __BMPINFOHEADER_H_INCLUDED__

#include <iostream>
#include <fstream>

class BMPInfoHeader{
	public:
		BMPInfoHeader(std::ifstream&);
		~BMPInfoHeader();

		uint32_t BMPSize;
		uint32_t BMPWidth;
		uint32_t BMPHeight;
		uint16_t BMPPlanes;
		uint16_t BMPBitsPerPixel;
		uint32_t BMPCompression;
		uint32_t BMPImageSize;
		uint32_t BMPXPixelsPerMeter;
		uint32_t BMPYPIxelsPerMeter;
		uint32_t BMPColorsUsed;
		uint32_t BMPImportantColors;
};

#endif
