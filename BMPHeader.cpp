#include <iostream>
#include <fstream>
#include <bitset>

#include "BMPHeader.h"
#include "utility.h"

const int OFFSET_SIGNATURE = 0x00;
const int OFFSET_FILE_SIZE = 0x02;
const int OFFSET_DATA_OFFSET = 0x0A;

BMPHeader::BMPHeader(std::ifstream& input, std::ofstream& log) {
	char* signature_input = new char[2];
	char* file_size_input = new char[4];
	char* data_offset_input = new char[4];
	
	//Reading Signature Values
	input.seekg(OFFSET_SIGNATURE, std::ios::beg);
	input.read(signature_input, 2);
	
	//Reading File Size Data
	input.seekg(OFFSET_FILE_SIZE, std::ios::beg);
	input.read(file_size_input, 4);

	//Reading Pixel Data Offset Value
	input.seekg(OFFSET_DATA_OFFSET, std::ios::beg);
	input.read(data_offset_input, 4);

	//Parsing inputs
	BMPSignature.append(1, signature_input[0]);
       	BMPSignature.append(1, signature_input[1]);
	delete[] signature_input;
	
	BMPFileSize = 0;
	BMPFileSize = uint8_to_uint32(file_size_input);
	delete[] file_size_input;

	BMPDataOffset = 0;
	BMPDataOffset = uint8_to_uint32(data_offset_input);	
	delete[] data_offset_input;

	log << "Signature: " << BMPSignature << std::endl;	
	log << "FileSize: " << BMPFileSize << std::endl;
	log << "DataOffset: " << BMPDataOffset << std::endl;
}

BMPHeader::~BMPHeader() {

}
