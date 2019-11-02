/**
 * PpmProcessor.c contains function implementations for reading from 
 * and writing to PPM files.
 * 
 * Completion time: 1.5 hours
 * 
 * @author Cristi DeLeo
 * @version 20191031
 * 
 **/

// ---------------------------------------------------------------------
// INCLUDES
// ---------------------------------------------------------------------
//#include "PpmProcessor.h"

#include <stdlib.h>
#include <stdio.h>

// ---------------------------------------------------------------------
// STRUCT DECLARATION
// ---------------------------------------------------------------------
//struct PPM_Header {
//    char signature[2];  // ID field
//    int width;          // Width of the PPM file in ASCII (not binary)
//    int height;         // Height of the PPM file in ASCII (not binary)
//    int maxval;         // Maximum color value (must be > 0 and < 65536)
//};

/**
 * Read PPM header of a file
 * Useful for converting files from BMP to PPM.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination PPM header
 */
//void readPPMHeader(FILE* file, struct PPM_Header* header) {
    
//}

/**
 * write PPM header of a file. Useful for converting files from BMP to PPM.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makePPMHeader function
 */
//void writePPMHeader(FILE* file, struct PPM_Header* header) {
   
//}

/**
 * make PPM header based on width and height. Useful for converting 
 * files from BMP to PPM.
 *
 * @param  header: Pointer to the destination PPM header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void makePPMHeader(struct PPM_Header* header, int width, int height) {
    
//}

/**
 * read Pixels from PPM file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for 
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void readPixelsPPM(FILE* file, struct Pixel** pArr, int width, int height) {
    
//}

/**
 * write Pixels from PPM file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void writePixelsPPM(FILE* file, struct Pixel** pArr, int width, int height) {
    
//}