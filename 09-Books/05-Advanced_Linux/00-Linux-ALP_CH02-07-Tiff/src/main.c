/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <tiffio.h>

int main(int argc, char *argv[]) {

	TIFF* tiff;
	tiff= TIFFOpen(argv[1], "r");
	TIFFClose(tiff);
	return EXIT_SUCCESS;
}
