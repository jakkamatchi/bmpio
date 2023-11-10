#!/bin/bash

g++ -std=c++20 main.cpp BMPFile.cpp BMPHeader.cpp BMPInfoHeader.cpp BMPColorTable.cpp BMPPixelData.cpp -o bmpio 

