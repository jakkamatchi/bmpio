#include <fstream>

#include "BMPInfoHeader.h"
#include "utility.h"

const int OFFSET_SIZE = 0x0E;
const int OFFSET_WIDTH = 0x12;
const int OFFSET_HEIGHT = 0x16;
const int OFFSET_PLANES = 0x1A;

const int OFFSET_BITS_PER_PIXEL = 0x1C;
const int OFFSET_COMPRESSION = 0x1E;
const int OFFSET_IMAGE_SIZE = 0x22;
const int OFFSET_X_PPM = 0x26;

const int OFFSET_Y_PPM = 0x2A;
const int OFFSET_COLORS_USED = 0x2E;
const int OFFSET_IMPORTANT_COLORS = 0x32;

BMPInfoHeader::BMPInfoHeader(std::ifstream& input, std::ofstream& log) {
	char* size_input = new char[4];
	char* width_input = new char[4];
	char* height_input = new char[4];
	char* planes_input = new char[2];

	char* bits_per_pixel_input = new char[2];
	char* compression_input = new char[4];
	char* image_size_input = new char[4];
	char* x_ppm_input = new char[4];		//pixels per meter

	char* y_ppm_input = new char[4];		//pixels per meter
	char* colors_used_input = new char[4];
	char* important_colors_input = new char[4];

	input.seekg(OFFSET_SIZE, std::ios::beg);
	input.read(size_input, 4);

	input.seekg(OFFSET_WIDTH, std::ios::beg);
	input.read(width_input, 4);

	input.seekg(OFFSET_HEIGHT, std::ios::beg);
	input.read(height_input, 4);

	input.seekg(OFFSET_PLANES, std::ios::beg);
	input.read(planes_input, 2);

	input.seekg(OFFSET_BITS_PER_PIXEL, std::ios::beg);
	input.read(bits_per_pixel_input, 2);

	input.seekg(OFFSET_COMPRESSION, std::ios::beg);
	input.read(compression_input, 4);

	input.seekg(OFFSET_IMAGE_SIZE, std::ios::beg);
	input.read(image_size_input, 4);

	input.seekg(OFFSET_X_PPM, std::ios::beg);
	input.read(x_ppm_input, 4);

	input.seekg(OFFSET_Y_PPM, std::ios::beg);
	input.read(y_ppm_input, 4);

	input.seekg(OFFSET_COLORS_USED, std::ios::beg);
	input.read(colors_used_input, 4);

	input.seekg(OFFSET_IMPORTANT_COLORS, std::ios::beg);
	input.read(important_colors_input, 4);

	BMPSize = uint8_to_uint32(size_input);				
	log << "Size: " << BMPSize << std::endl;
	
	BMPWidth = uint8_to_uint32(width_input);
	log << "Width: " << BMPWidth << std::endl;
	
	BMPHeight = uint8_to_uint32(height_input);
	log << "Height: " << BMPHeight << std::endl;
	
	BMPPlanes = uint8_to_uint16(planes_input);
	log << "Planes: " << BMPPlanes << std::endl;

	BMPBitsPerPixel = uint8_to_uint16(bits_per_pixel_input);
	log << "Bits Per Pixel: " << BMPBitsPerPixel << std::endl;
	
	BMPCompression = uint8_to_uint32(compression_input);
	log << "Compression: " << BMPCompression << std::endl;

	BMPImageSize = uint8_to_uint32(image_size_input);
	log << "Image Size: " << BMPImageSize << std::endl;

	BMPXPixelsPerMeter = uint8_to_uint32(x_ppm_input);
	log << "X Pixels Per Meter: " << BMPXPixelsPerMeter << std::endl;

	BMPYPixelsPerMeter = uint8_to_uint32(y_ppm_input);
	log << "Y Pixels Per Meter: " << BMPYPixelsPerMeter << std::endl;

	BMPColorsUsed = uint8_to_uint32(colors_used_input);
	log << "Colors Used: " << BMPColorsUsed << std::endl;
	
	BMPImportantColors = uint8_to_uint32(important_colors_input);
	log << "Important Colors: " << BMPImportantColors << std::endl;

	delete[] size_input;
	delete[] width_input;
	delete[] height_input;
	delete[] planes_input;

	delete[] bits_per_pixel_input;
	delete[] compression_input;
	delete[] image_size_input;
	delete[] x_ppm_input;

	delete[] y_ppm_input;
	delete[] colors_used_input;
	delete[] important_colors_input;
}

BMPInfoHeader::~BMPInfoHeader() {

}
