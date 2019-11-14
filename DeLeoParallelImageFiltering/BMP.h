/*
 * A simple header for Bitmap images.
 *
 * Completion time: 
 * 
 * @author Cristi DeLeo
 * @version 2019.11.13
 * 
 */

#ifndef BMP_H
#define BMP_H

#include <stdio.h>

#ifndef UINT
        #define UINT    unsigned long int
#endif

#ifndef USHORT
        #define USHORT  unsigned short
#endif

#ifndef UCHAR
        #define UCHAR   unsigned char
#endif

/* ERROR  CODES */
typedef enum {
    BMP_OK = 0,
    BMP_ERROR,
    BMP_OUT_OF_MEMORY,
    BMP_IO_ERROR,
    BMP_FILE_NOT_FOUND,
    BMP_FILE_NOT_SUPPORTED,
    BMP_FILE_INVALID,
    BMP_INVALID_ARGUMENT,
    BMP_TYPE_MISMATCH,
    BMP_ERROR_NUM
} BMP_STATUS;

/* BITMAP IMAGE */
typedef struct BMP BMP;

/* CONSTRUCTOR / DESTRUCTOR */
BMP* BMP_Create(UINT width, UINT height, USHORT depth);
void BMP_Free(BMP* bmp);

/* IO */
BMP* BMP_ReadFile(const char* filename);
void BMP_WriteFile(BMP* bmp, const char* filename);

/* META INFO */
UINT BMP_GetWidth(BMP* bmp);
UINT BMP_GetHeight(BMP* bmp);
USHORT BMP_GetDepth(BMP* bmp);
UCHAR BMP_GetBytesPerPixel(BMP* bmp);
UINT BMP_GetBytesPerRow(BMP* bmp);
UCHAR* BMP_GetData(BMP* bmp);

/* PIXEL ACCESS */
void BMP_GetPixelRGB( BMP* bmp, UINT x, UINT y, UCHAR* r, UCHAR* g, UCHAR* b );
void BMP_SetPixelRGB( BMP* bmp, UINT x, UINT y, UCHAR r, UCHAR g, UCHAR b );
void BMP_GetPixelIndex( BMP* bmp, UINT x, UINT y, UCHAR* val );
void BMP_SetPixelIndex( BMP* bmp, UINT x, UINT y, UCHAR val );

/* PALETTE HANDLING */
void BMP_GetPaletteColor( BMP* bmp, UCHAR index, UCHAR* r, UCHAR* g, UCHAR* b );
void BMP_SetPaletteColor( BMP* bmp, UCHAR index, UCHAR r, UCHAR g, UCHAR b );

/* ERROR HANDLING */
BMP_STATUS BMP_GetError();
const char* BMP_GetErrorDescription();

#define BMP_CHECK_ERROR( output_file, return_value ) \
	if ( BMP_GetError() != BMP_OK )	\
	{\
		fprintf( ( output_file ), "BMP error: %s\n", BMP_GetErrorDescription() );\
		return( return_value );	\
	}

#endif /* BMP_H */