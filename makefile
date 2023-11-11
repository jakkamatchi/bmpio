objects = main.o BMPFile.o BMPHeader.o BMPInfoHeader.o BMPColorTable.o BMPPixelData.o utility.o

bmpio : $(objects)
	g++ -o bmpio $(objects)

main.o : BMPHeader.h BMPInfoHeader.h BMPColorTable.h BMPPixelData.h utility.h
BMPFile.o : BMPHeader.h BMPInfoHeader.h BMPColorTable.h BMPPixelData.h
BMPHeader.o : BMPHeader.h utility.h
BMPInfoHeader.o : BMPInfoHeader.h utility.h
BMPColorTable.o : BMPColorTable.h
BMPPixelData.o : BMPPixelData.h
utility.o : utility.h

.PHONY : clean
clean:
	rm bmpio $(objects)
