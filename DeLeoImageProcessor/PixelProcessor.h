/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PixelProcessor.h
 * Author: cristi
 *
 * Created on October 31, 2019, 8:50 PM
 */

#ifndef PIXELPROCESSOR_H
#define PIXELPROCESSOR_H

struct Pixel {
    //TODO:Finish struct
};
/**
 * Shift color of Pixel array. The dimension of the array is width * height. The 
 * shift value of RGB is 
 * rShift, gShift，bShift. Useful for color shift.
 *
 * @param  pArr: Pixel array of the image that this header is for
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 * @param  rShift: the shift value of color r shift
 * @param  gShift: the shift value of color g shift 
 * @param  bShift: the shift value of color b shift 
 */
void colorShiftPixels(struct Pixel** pArr, int width, int height, int rShift, int
        gShift, int bShift);
Annotations

#endif /* PIXELPROCESSOR_H */

