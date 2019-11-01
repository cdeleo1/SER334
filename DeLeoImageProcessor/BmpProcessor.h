/**
 * BMP Headers IO - contains structures for the headers of a BMP file and 
 * functions to read and write them.
 * 
 * Completion time: 1.5 hours
 * 
 * @author Cristi DeLeo
 * @version 20191031
 */

#ifndef BMPPROCESSOR_H
#define BMPPROCESSOR_H

struct BMP_Header {
    char signature[2];          // ID field
    int size;                   // Size of the BMP file
    short reserved1;            // Application specific
    short reserved2;            // Application specific
    int offset_pixel_array;     // Offset where the pixel can be found
};

// DIB DATA STRUCTURE
// A bitmap image loaded into memory becomes a DIB data structure
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

/**
 * read BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination BMP header
 */
void readBMPHeader(FILE* file, struct BMP_Header* header);

/**
 * write BMP header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeBMPHeader function
 */
void writeBMPHeader(FILE* file, struct BMP_Header* header);

/**
 * read DIB header from a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: Pointer to the destination DIB header
 */
void readDIBHeader(FILE* file, struct DIB_Header* header);

/**
 * write DIB header of a file. Useful for converting files from PPM to BMP.
 *
 * @param  file: A pointer to the file being read or written
 * @param  header: The header made by makeDIBHeader function
 */
void writeDIBHeader(FILE* file, struct DIB_Header* header);

/**
 * make BMP header based on width and height. 
 * The purpose of this is to create a new BMPHeader struct using the information 
 * from a PPMHeader when converting from PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makeBMPHeader(struct BMP_Header* header, int width, int height);

/**
 * Makes new DIB header based on width and height. Useful for converting files from
PPM to BMP.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makeDIBHeader(struct DIB_Header* header, int width, int height);

/**
 * read Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void readPixelsBMP(FILE* file, struct Pixel** pArr, int width, int height);

/**
 * write Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void writePixelsBMP(FILE* file, struct Pixel** pArr, int width, int height);
Annotations

#endif /* BMPPROCESSOR_H */