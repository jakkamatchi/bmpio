#ifndef __BMPHEADER_H_INCLUDED__
#define __BMPHEADER_H_INCLUDED__

#include <fstream>
#include <string>

class BMPHeader {
	public:
		BMPHeader(std::ifstream&);
		~BMPHeader();

		std::string BMPSignature;	//BMP Signature 'BM'
		uint32_t BMPFileSize;		//File size
		uint32_t DataOffset;		//Offset to start of PixelData
};

#endif 
