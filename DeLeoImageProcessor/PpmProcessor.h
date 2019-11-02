/**
 * PPM Header - contains structures for the headers of a PPM file and 
 * functions to read and write them.
 * 
 * Completion time: 1.5 hours
 * 
 * @author Cristi DeLeo
 * @version 20191031
 **/

//#ifndef PPMPROCESSOR_H
//#define PPMPROCESSOR_H

// ---------------------------------------------------------------------
// INCLUDES
// ---------------------------------------------------------------------
//#include <stdlib.h>
//#include <stdio.h>

// ---------------------------------------------------------------------
// TYPEDEF DECLARATION
// ---------------------------------------------------------------------
//typedef struct PPM_Header* PPM_Header;

/**
 * read PPM header of a file. Useful for converting files from BMP to PPM.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination PPM header
 */
//void readPPMHeader(FILE* file, struct PPM_Header* header);
/**
 * write PPM header of a file. Useful for converting files from BMP to PPM.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makePPMHeader function
 */
//void writePPMHeader(FILE* file, struct PPM_Header* header);

/**
 * make PPM header based on width and height. Useful for converting files from BMP 
 * to PPM.
 *
 * @param  header: Pointer to the destination PPM header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void makePPMHeader(struct PPM_Header* header, int width, int height);

/**
 * read Pixels from PPM file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for 
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void readPixelsPPM(FILE* file, struct Pixel** pArr, int width, int height);

/**
 * write Pixels from PPM file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void writePixelsPPM(FILE* file, struct Pixel** pArr, int width, int height);

//#endif /* PPMPROCESSOR_H */