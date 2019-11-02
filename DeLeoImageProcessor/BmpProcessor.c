/**
 * BmpProcessor.c contains function implementations for reading from 
 * and writing to BMP files.
 * 
 * Completion time: 1.5 hours
 * 
 * @author Cristi DeLeo
 * @version 20191031
 */

// ---------------------------------------------------------------------
// INCLUDES
// ---------------------------------------------------------------------
/*#include "BmpProcessor.h"
#include "PixelProcessor.h"
#include "PpmProcessor.h"

#include <stdlib.h>
#include <stdio.h>

// ---------------------------------------------------------------------
// STRUCT DECLARATIONS

struct BMP_Header {
    char signature[2];          // ID field
    int size;                   // Size of the BMP file
    short reserved1;            // Application specific
    short reserved2;            // Application specific
    int offset_pixel_array;     // Offset where the pixel can be found
};

struct DIB_Header {
    int size;                   // Size of this header
    int width;                  // Width of bitmap image (in pixels)
    int height;                 // Height of bitmap image (in pixels)
    short planes;               // Number of color planes (must be 1)
    short bits;                 // Number of bits per pixel
    int compression;            // Compression method being used
    int imageSize;              // Size of the raw bitmap data
    int x_resolution;           // Horizontal resolution of the image
    int y_resolution;           // Vertical resolution of the image
    int number_of_colors;       // Number of colors in the color table
    int important_color_count;  // Number of important colors used
};
*/
// ---------------------------------------------------------------------
// HELPER FUNCTIONS

/**
 * read BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination BMP header
 */
/*void readBMPHeader(FILE* file, struct aBMP_Header* header) {
    
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
*/
/**
 * write BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeBMPHeader function
 */
//void writeBMPHeader(FILE* file, struct aBMP_Header* header) {
    
//}

/**
 * read DIB header from a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination DIB header
 * 
 */
/*void readDIBHeader(FILE* file, struct aDIB_Header* header) {
    fread(&header->size, sizeof(int), 1, file);
    fread(&header->width, sizeof(int), 1, file);
    fread(&header->height, sizeof(int), 1, file);
    fread(&header->planes, sizeof(short), 1, file);
    fread(&header->bits, sizeof(short), 1, file);
    fread(&header->compression, sizeof(int), 1, file);
    fread(&header->imageSize, sizeof(int), 1, file);
    fread(&header->x_resolution, sizeof(int), 1, file);
    fread(&header->y_resolution, sizeof(int), 1, file);
    fread(&header->number_of_colors, sizeof(int), 1, file);
    fread(&header->important_color_count, sizeof(int), 1, file);
    
    printf("size: %d\n", header->size);
    printf("width: %d\n", header->width);
    printf("height: %d\n", header->height);
    printf("planes: %d\n", header->planes);
    printf("bits: %d\n", header->bits);
    printf("compression: %d\n", header->compression);
    printf("imageSize: %d\n", header->imageSize);
    printf("x_resolution: %d\n", header->x_resolution);
    printf("y_resolution: %d\n", header->y_resolution);
    printf("number_of_colors: %d\n", header->number_of_colors);
    printf("important_color_count: %d\n", header->important_color_count);
}
*/
/**
 * write DIB header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeDIBHeader function
 */
//void writeDIBHeader(FILE* file, struct aDIB_Header* header) {
    
//}

/**
 * make BMP header based on width and height. 
 * The purpose of this is to create a new BMPHeader struct using the information 
 * from a PPMHeader when converting from PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void makeBMPHeader(struct aBMP_Header* header, int width, int height) {
    //struct DIB_Header dib_header = &header;
    
    //dib_header->width = width;
    //dib_header->height = height;
//}

/**
 * Makes new DIB header based on width and height. Useful for converting files from
PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void makeDIBHeader(struct aDIB_Header* header, int width, int height) {
    
//}

/**
 * read Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void readPixelsBMP(FILE* file, struct Pixel** pArr, int width, int height) {
    
//}

/**
 * write Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void writePixelsBMP(FILE* file, struct Pixel** pArr, int width, int height) {
    
//}