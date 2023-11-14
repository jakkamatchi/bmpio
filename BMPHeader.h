#ifndef __BMPHEADER_H_INCLUDED__
#define __BMPHEADER_H_INCLUDED__

#include <fstream>
#include <string>

class BMPHeader {
	public:
		BMPHeader(std::ifstream&, std::ofstream&);
		//BMPHeader(const BMPHeader& h) : BMPFileSize(h.BMPFileSize),
		//				BMPDataOffset(h.BMPDataOffset) { };
		BMPHeader() { };
		~BMPHeader();

		std::string BMPSignature;		//BMP Signature 'BM'
		uint32_t BMPFileSize = 0;		//File size
		uint32_t BMPDataOffset = 0;		//Offset to start of PixelData
};

#endif 
