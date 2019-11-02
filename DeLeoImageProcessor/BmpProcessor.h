/**
 * BMP Headers - contains structures for the headers of a BMP file and 
 * function declarations for reading from and writing to them.
 * 
 * Completion time: 1.5 hours
 * 
 * @author Cristi DeLeo
 * @version 20191031
 */

#ifndef BMPPROCESSOR_H
#define BMPPROCESSOR_H

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

#ifdef LOADBMP_IMPLEMENTATION
#	define LOADBMP_API
#else
#	define LOADBMP_API extern
#endif

// ---------------------------------------------------------------------
// INCLUDES
//#include "PixelProcessor.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ---------------------------------------------------------------------
// TYPEDEF DECLARATIONS
typedef struct BMP_Header BMP_Header;
//typedef struct DIB_Header* DIB_Header;

struct BMP_Header {
    char signature[2];          // ID field
    int size;                   // Size of the BMP file
    short reserved1;            // Application specific
    short reserved2;            // Application specific
    int offset_pixel_array;     // Offset where the pixel can be found
};

LOADBMP_API unsigned int loadBMPFile(
	const char *filename, unsigned char **imageData, 
        unsigned int *width, unsigned int *height, unsigned int components);

void readBMPHeader(FILE* file, BMP_Header* header);
void writeBMPHeader(FILE* file, BMP_Header* header);

LOADBMP_API unsigned int loadBMPFile(const char *filename, 
        unsigned char **imageData, unsigned int *width, 
        unsigned int *height, unsigned int components) {
    
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

    fclose(f);

    return LOADBMP_NO_ERROR;
}

/**
 * read BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination BMP header
 */
void readBMPHeader(FILE* file, BMP_Header* header) {

    if (!file)
        return LOADBMP_FILE_NOT_FOUND;

    fread(&header->signature, sizeof(char)*2, 1, file);
    fread(&header->size, sizeof(int), 1, file);
    fread(&header->reserved1, sizeof(short), 1, file);
    fread(&header->reserved2, sizeof(short), 1, file);
    fread(&header->offset_pixel_array, sizeof(int), 1, file);
    
    printf("signature: %c%c\n", header->signature[0], header->signature[1]);
    printf("size: %d\n", header->size);
    printf("reserved1: %d\n", header->reserved1);
    printf("reserved2: %d\n", header->reserved2);
    printf("offset_pixel_array: %d\n", header->offset_pixel_array);
    
    fclose(file);
}

/**
 * write BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being written
 * @param  header: The header made by makeBMPHeader function
 */
void writeBMPHeader(FILE* file, BMP_Header* header) {

    if (!file)
        return LOADBMP_FILE_NOT_FOUND;

    fwrite("BP", sizeof(char)*2, 1, file);
    fwrite(header->size, sizeof(int), 1, file);
    fwrite(0, sizeof(short), 1, file);
    fwrite(0, sizeof(short), 1, file);
    fwrite(header->offset_pixel_array, sizeof(int), 1, file);
    
    printf("signature: %c%c\n", header->signature[0], header->signature[1]);
    printf("size: %d\n", header->size);
    printf("reserved1: %d\n", header->reserved1);
    printf("reserved2: %d\n", header->reserved2);
    printf("offset_pixel_array: %d\n", header->offset_pixel_array);
    
    fclose(file);
}

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

#endif /* BMPPROCESSOR_H */