/* 
 * Computes the total volume for a number of cylinders.
 * 
 * Completion time: 0.5 HOURS
 * 
 * @author Cristi DeLeo
 * @version 20191023
 */

////////////////////////////////////////////////////////////////////////////////
//INCLUDES
#include <stdio.h>

int main(void)
{
    int i = 0, numCyl = 0;
    float height = 0, radius = 0, volume = 0;
    
    printf("Enter the number of cylinders (as an integer): ");
    scanf("%d", &numCyl);
    
    for (i = 0; i < numCyl; i++) {
        printf("\nCylinder %i\n", i + 1);
        printf("    Enter the height (decimals allowed): ");
        scanf("%f", &height);
        printf("    Enter the radius (decimals allowed): ");
        scanf("%f", &radius);
        
        volume = 0.5 * (height * radius);
        
        printf("    Volume of Cylinder %i = %f\n", i + 1, volume);       
    }

    return 0;
}

