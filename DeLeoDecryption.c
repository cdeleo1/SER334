/* 
 * Chunk-based decryption implementation
 * 
 * Completion time: 1.5 HOURS
 * 
 * @author Cristi DeLeo
 * @version 20191024
 */

#include <stdio.h>
#include <string.h>

//Macros: constants
#define CHUNK_LENGTH (20+1) //Each chunk has twenty characters, we add 1 so
                            //there is space for the null terminator.
#define NUMBER_OF_CHUNKS 4  //The message is spread across 4 chunks.
#define DECRYPTION_SHIFT 5  //This is the ASCII table shift used for decryption.

//Forward declarations
void sort_chunks();
void decrypt_chunks();
void display_chunks();

char chunks[NUMBER_OF_CHUNKS][CHUNK_LENGTH];

int main() 
{
    //copy message into memory.
    strcpy(chunks[0], "2i1%fsi%fs%jstwrtzx%");
    strcpy(chunks[1], "1'H%nx%vznwp~1%kqf|j");
    strcpy(chunks[2], "4R3%Wnyhmnj%%%%%%%%%");
    strcpy(chunks[3], "3xzhhjxx3'%2%Ijssnx%");

    sort_chunks();
    decrypt_chunks();
    display_chunks();

    return 0; 
}

//given two strings, swaps their contents in memory.
void swap_strings(char* x, char* y) 
{
    //create a temporary holding place for the data so we don't lose it.
    char temp[CHUNK_LENGTH];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

// Sorts each string in the global variable chunks[][]
// The sort order is based on the first character of each string.
void sort_chunks() 
{
    char *chunk_ptr = 0;
    int j;
    
    for (int i = 0; i < NUMBER_OF_CHUNKS; i++) {
        
        int minIndex = i;
        chunk_ptr = chunks[i];
        
        for (j = i + 1; j < NUMBER_OF_CHUNKS; j++) {
            if (*chunk_ptr > chunks[j][0]) {
                chunk_ptr = chunks[j] ;
                minIndex = j;
            };
        }
        
        if (minIndex != i) {
            swap_strings(chunks[i], chunks[minIndex]);
        };
    }
}

//for each string in the global chunks variable, shifts the characters in it by
//DECRYPTION_SHIFT.
void decrypt_chunks() 
{
    char *chunk_ptr = 0;
    
    for (int i = 0; i < NUMBER_OF_CHUNKS; i++) {
        
        chunk_ptr = chunks[i];
        
        while (*chunk_ptr) {
            *chunk_ptr = *chunk_ptr - DECRYPTION_SHIFT;
            chunk_ptr++;
        }
    }
}

//displays the strings in the global chunks variable
void display_chunks() 
{
    char *chunk_ptr = 0;
    
    for (int i = 0; i < NUMBER_OF_CHUNKS; i++) {
        
        chunk_ptr = chunks[i];
        chunk_ptr++;
        
        while (*chunk_ptr) {
            printf("%c",*chunk_ptr);
            *chunk_ptr = *chunk_ptr + 1;
            chunk_ptr++;
        }
    }
}
