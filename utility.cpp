#include "utility.h"
#include <iostream>

const uint32_t AND32_0 = 0b11111111000000000000000000000000;
const uint32_t AND32_1 = 0b00000000111111110000000000000000;
const uint32_t AND32_2 = 0b00000000000000001111111100000000;
const uint32_t AND32_3 = 0b00000000000000000000000011111111;

const uint16_t AND16_0 = 0b1111111100000000;
const uint16_t AND16_1 = 0b0000000011111111;

uint32_t uint8_to_uint32(char* input){
	uint32_t ret = 0;
	uint32_t temp1, temp2, temp3, temp4 = 0;

	//Using & solves unsigned / signed misbehaviour
	temp1 = ((uint32_t)input[3] << 24) & AND32_0;
	temp2 = ((uint32_t)input[2] << 16) & AND32_1;
	temp3 = ((uint32_t)input[1] << 8) & AND32_2;
	temp4 = ((uint32_t)input[0]) & AND32_3;
	
	ret = temp1  | temp2 | temp3 | temp4;
	
	return ret;
}

uint16_t uint8_to_uint16(char* input){
	uint16_t ret;
	uint16_t temp1, temp2 = 0;
	
	temp1 = ((uint16_t)input[1] << 8) & AND16_0;
	temp2 = ((uint16_t)input[0]) & AND16_1;

	ret = temp1  | temp2;
	
	return ret;
}
