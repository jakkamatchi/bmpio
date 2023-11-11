#include "utility.h"

uint32_t uint8_to_uint32(char* input){
	uint32_t ret;
	uint32_t temp1, temp2, temp3, temp4 = 0;
	
	temp1 = (uint32_t)input[3] << 24;
	temp2 = (uint32_t)input[2] << 16;
	temp3 = (uint32_t)input[1] << 8;
	temp4 = (uint32_t)input[0];
	ret = temp1  | temp2 | temp3 | temp4;
	
	return ret;
}

uint16_t uint8_to_uint16(char* input){
	uint16_t ret;
	uint16_t temp1, temp2 = 0;
	
	temp1 = (uint16_t)input[1] << 8;
	temp2 = (uint16_t)input[0];

	ret = temp1  | temp2;
	
	return ret;
}
