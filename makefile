objects = main.o BMPFile.o BMPHeader.o BMPInfoHeader.o BMPColorTable.o BMPPixelData.o utility.o
libs = -lncurses
args = -std=c++20
cc = g++

bmpio : $(objects)
	$(cc) $(args) $(objects) $(libs) -o bmpio

main.o : BMPHeader.h BMPInfoHeader.h BMPColorTable.h BMPPixelData.h utility.h termcolor.h
BMPFile.o : BMPHeader.h BMPInfoHeader.h BMPColorTable.h BMPPixelData.h
BMPHeader.o : BMPHeader.h utility.h
BMPInfoHeader.o : BMPInfoHeader.h utility.h
BMPColorTable.o : BMPColorTable.h
BMPPixelData.o : BMPPixelData.h
utility.o : utility.h

.PHONY : clean
clean:
	rm bmpio $(objects)
