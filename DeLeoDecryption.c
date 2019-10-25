/* 
 * Chunk-based decryption implementation
 * 
 * Completion time: 0.5 HOURS
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

    //the format of a chunk is a single number indicating its order in overall
    //message followed by twenty encrypted characters.
    //reorder chunks in message by sorting them based on the first digital
    //they contain. looking above, one can see they are currently in the order
    //2, 1, 4, 3 but should be ordered 1, 2, 3, 4.
    sort_chunks();

    //shift the characters in the message to produce the original characters.
    //decrypt_chunks();

    //display the decrypted message.
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
    //TODO: Implement decrypt_chunks(). Loop over each string in the array
    //      and shift the characters in it by subtracting DECRYPTION_SHIFT value
    //      from them. Use pointer arithmetic to access individual characters
    //      but
    //      array access to the strings. Remember that C-style strings have a
    //      null
    //      terminator at the end. Do not apply the shift to the terminator.
    //      (Hint: to avoid doing double pointer arithmatic, save a char* 
    //      pointer
    //      to the active chunk[?] in the outer loop but before the inner 
    //      loop.
    //      Then the inner loop is only concerned with a single array of
    //      characters rather than an array of strings.)
}

//displays the strings in the global chunks variable
void display_chunks() 
{
    char *chunk_ptr = 0;
    
    for (int i = 0; i < NUMBER_OF_CHUNKS; i++) {
        
        chunk_ptr = chunks[i];
        
        while (*chunk_ptr) {
            printf("%c",*chunk_ptr);
            *chunk_ptr = *chunk_ptr + 1;
            chunk_ptr++;
        }
    }
}
