/**
 * DeLeoImageProcessor.c implements main()
 * 
 * Completion time: 1.5 hours
 * 
 * @author Cristi DeLeo
 * @version 20191031
 */

// Errors
#define LOADBMP_NO_ERROR 0

#define LOADBMP_OUT_OF_MEMORY 1

#define LOADBMP_FILE_NOT_FOUND 2
#define LOADBMP_FILE_OPERATION 3

#define LOADBMP_INVALID_FILE_FORMAT 4

#define LOADBMP_INVALID_SIGNATURE 5
#define LOADBMP_INVALID_BITS_PER_PIXEL 6


// Components
#define LOADBMP_RGB  3
#define LOADBMP_RGBA 4

// ---------------------------------------------------------------------
// INCLUDES
// ---------------------------------------------------------------------
//#include "BmpProcessor.h"
//#include "PixelProcessor.h"
//#include "PpmProcessor.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    
    //BMP_Header bmp_header;  // BITMAPFILEHEADER
    //DIB_Header dib_header;  // BITMAPINFOHEADER

    unsigned char *pixels = NULL;
    
    const char *filename = "test2.bmp";
    unsigned char **imageData = &pixels;
    unsigned int *width = &width;
    unsigned int *height = &height;
    unsigned int components = LOADBMP_RGBA;
    unsigned int err;
    
    FILE *f = fopen(filename, "rb");

    if (!f)
	return LOADBMP_FILE_NOT_FOUND;

    unsigned char bmp_file_header[14];
    unsigned char bmp_info_header[40];
    unsigned char bmp_pad[3];

    unsigned int w, h;
    unsigned char *data = NULL;

    unsigned int x, y, i, padding;

    memset(bmp_file_header, 0, sizeof (bmp_file_header));
    memset(bmp_info_header, 0, sizeof (bmp_info_header));

    if (fread(bmp_file_header, sizeof (bmp_file_header), 1, f) == 0) {
        fclose(f);
        return LOADBMP_INVALID_FILE_FORMAT;
    }

    if (fread(bmp_info_header, sizeof (bmp_info_header), 1, f) == 0) {
        fclose(f);
        return LOADBMP_INVALID_FILE_FORMAT;
    }

    if ((bmp_file_header[0] != 'B') || (bmp_file_header[1] != 'M')) {
        fclose(f);
        return LOADBMP_INVALID_SIGNATURE;
    }

    if ((bmp_info_header[14] != 24) && (bmp_info_header[14] != 32)) {
        fclose(f);
        return LOADBMP_INVALID_BITS_PER_PIXEL;
    }

    w = (bmp_info_header[4] + (bmp_info_header[5] << 8)
            + (bmp_info_header[6] << 16) + (bmp_info_header[7] << 24));
    h = (bmp_info_header[8] + (bmp_info_header[9] << 8)
            + (bmp_info_header[10] << 16) + (bmp_info_header[11] << 24));

    if ((w > 0) && (h > 0)) {
        data = (unsigned char*) malloc(w * h * components);

        if (!data) {
            fclose(f);
            return LOADBMP_OUT_OF_MEMORY;
        }

        for (y = (h - 1); y != -1; y--) {
            for (x = 0; x < w; x++) {
                i = (x + y * w) * components;

                if (fread(data + i, 3, 1, f) == 0) {
                    free(data);

                    fclose(f);
                    return LOADBMP_INVALID_FILE_FORMAT;
                }

                data[i] ^= data[i + 2] ^= data[i] ^= data[i + 2]; // BGR -> RGB

                if (components == LOADBMP_RGBA)
                    data[i + 3] = 255;
            }

            padding = ((4 - (w * 3) % 4) % 4);

            if (fread(bmp_pad, 1, padding, f) != padding) {
                free(data);

                fclose(f);
                return LOADBMP_INVALID_FILE_FORMAT;
            }
        }
    }

    (*width) = w;
    (*height) = h;
    (*imageData) = data;
    
    printf("Closing file...");
    
    fclose(f);

    err = LOADBMP_NO_ERROR;

    if (err)
	printf("LoadBMP Load Error: %u\n", err);

    // Remember to free the pixel data when it isn't needed anymore.
    free(pixels);
    
    return 0;
    
}