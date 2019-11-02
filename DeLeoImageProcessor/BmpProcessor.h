/**
 * BMP Headers - contains structures for the headers of a BMP file and 
 * function declarations for reading from and writing to them.
 * 
 * Completion time: 1.5 hours
 * 
 * @author Cristi DeLeo
 * @version 20191031
 */

//#ifndef BMPPROCESSOR_H
//#define BMPPROCESSOR_H

// ---------------------------------------------------------------------
// INCLUDES
//#include "PixelProcessor.h"

//#include <stdlib.h>
//#include <stdio.h>

// ---------------------------------------------------------------------
// TYPEDEF DECLARATIONS
//typedef struct BMP_Header* BMP_Header;
//typedef struct DIB_Header* DIB_Header;

/**
 * read BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination BMP header
 */
//void readBMPHeader(FILE* file, struct BMP_Header header);

/**
 * write BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeBMPHeader function
 */
//void writeBMPHeader(FILE* file, struct aBMP_Header* header);

/**
 * read DIB header from a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination DIB header
 */
//void readDIBHeader(FILE* file, struct aDIB_Header* header);

/**
 * write DIB header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeDIBHeader function
 */
//void writeDIBHeader(FILE* file, struct aDIB_Header* header);

/**
 * make BMP header based on width and height. 
 * The purpose of this is to create a new BMPHeader struct using the information 
 * from a PPMHeader when converting from PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void makeBMPHeader(struct aBMP_Header* header, int width, int height);

/**
 * Makes new DIB header based on width and height. Useful for converting files from
PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void makeDIBHeader(struct aDIB_Header* header, int width, int height);

/**
 * read Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void readPixelsBMP(FILE* file, struct Pixel** pArr, int width, int height);

/**
 * write Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void writePixelsBMP(FILE* file, struct Pixel** pArr, int width, int height);

//#endif /* BMPPROCESSOR_H */