/**
 * PixelProcessor.c contains a structure that represents a single pixel 
 * (24-bit pixel struct) and the functions to read and write them in 
 * both BMP and PPM.
 *
 * Completion time: 1.5
 *
 * @author Cristi DeLeo
 * @version YYYYMMDD
 *
 **/

// ---------------------------------------------------------------------
// INCLUDES
// ---------------------------------------------------------------------
//#include "PixelProcessor.h"

//#include <stdlib.h>
//#include <stdio.h>

// ---------------------------------------------------------------------
// STRUCT DECLARATION
// ---------------------------------------------------------------------
//struct Pixel {
//    int pixel_array[3];
//};

/**
 * Shift color of Pixel array. The dimension of the array is width * 
 * height. The shift value of RGB is rShift, gShift，bShift. Useful for 
 * color shift.
 *
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 * @param  rShift: the shift value of color r shift
 * @param  gShift: the shift value of color g shift 
 * @param  bShift: the shift value of color b shift 
 */
//void colorShiftPixels(struct Pixel** pArr, int width, int height, 
//        int rShift, int gShift, int bShift) {
    
//}