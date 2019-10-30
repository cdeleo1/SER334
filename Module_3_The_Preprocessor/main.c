/* 
 * File:   main.c
 * Author: cristi
 *
 * Created on October 30, 2019, 2:40 PM
 */

// BEGIN MODULE 3 EXERCISE QUESTION 1
// Macro called PI with precision of two decimal places
#define PI 3.14

// Macro called AREA_OF_SPHERE that takes in value radius
// and computes the surface area of a sphere
#define AREA_OF_SPHERE(r) ((4*PI)*(r*r))

// Macro called VOLUME_OF_CONE that takes in values radius
// and height, and computes the volume of a cone
#define VOLUME_OF_CONE(r, h) ((PI*(r*r)*h)/3)
// END MODULE 3 EXERCISE QUESTION 1

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // BEGIN MODULE 3 EXERCISE QUESTION 1
    int radius = 3;
    int height = 5;
    float area = AREA_OF_SPHERE(radius);
    float volume = VOLUME_OF_CONE(radius, height);
    
    printf("area = %f", area);
    printf("volume = %f", volume);
    // END MODULE 3 EXERCISE QUESTION 1
    
    return (EXIT_SUCCESS);
}

