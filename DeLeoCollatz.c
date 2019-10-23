/* 
 * Determines if a particular positive integer satisfies the collatz conjecture.
 * 
 * Completion time:
 * 
 * @author Cristi DeLeo
 * @version 20191023
 */
#include <stdio.h>

int termination(int n);

int termination(int n) {
    int count = 0;
    
    while (n != 1) {
        if (n%2 == 0) {
            n = n/2;
        } else {
            n = (3 * n) + 1;
        };
        count = count + 1;
    }
    
    return count;
}

int main(void) 
{
    int n = 0;
    
    while (n <= 0) {
        printf("\nPlease enter a positive integer: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("\n  ERROR: INPUT MUST BE > 0\n");
        }
    }

    printf("\nNumber of iterations performed: %d\n", termination(n));
    
    return (0);
}

