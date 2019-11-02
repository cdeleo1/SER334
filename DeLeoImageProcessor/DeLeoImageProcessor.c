/**
 * DeLeoImageProcessor.c implements main()
 * 
 * Completion time: 1.5 hours
 * 
 * @author Cristi DeLeo
 * @version 20191031
 */

// ---------------------------------------------------------------------
// INCLUDES
// ---------------------------------------------------------------------
#include "BmpProcessor.h"
//#include "PixelProcessor.h"
//#include "PpmProcessor.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    BMP_Header* bmp_header;

    const char *filename = "test2.bmp";
    
    // BEGIN LOAD BMP FUNCTION
    unsigned char *pixels = NULL;
    unsigned int width, height;
    unsigned int err = loadBMPFile(filename, &pixels, &width, 
            &height, LOADBMP_RGBA);
    if (err)
        printf("LoadBMP Load Error: %u\n", err);
    free(pixels);
    // END LOAD BMP FUNCTION

    // BEGIN READ BMP FUNCTION
    FILE *f = fopen(filename, "rb");
    readBMPHeader(f, bmp_header);
    // END READ BMP FUNCTION
    
    return 0;
}