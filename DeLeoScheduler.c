/* 
 * Chunk-based decryption implementation
 * 
 * Completion time: 1.5 HOURS
 * 
 * @author Cristi DeLeo
 * @version 20191024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//MACROS: CONSTANTS

//DATA STRUCTURES
typedef enum { SER=0, EGR=1, CSE=2, EEE=3 } subjects;
typedef enum subjects Subject;

struct CourseNode {
    //subjects x = SER;
    int number;
    char teacher[1024];
    int creditHours;
    struct CourseNode* next;
};

//GLOBAL VARIABLES
struct CourseNode courseNode;
struct CourseNode* course_collection = NULL;

//FORWARD DECLARATIONS
void branching(char option);
struct CourseNode* add_CourseNode(struct CourseNode* new_node, struct CourseNode* front);
void remove_CourseNode();
void display(struct CourseNode* front);

//main entry point. Starts the program by displaying a welcome and beginning an 
//input loop that displays a menu and processes user input. Pressing q quits.      
int main() {
    char input_buffer;
    printf("\n\nWelcome to ASU Class Schedule\n");

    //menu and input loop
    do {
        printf("\nMenu Options\n");
        printf("------------------------------------------------------\n");
        printf("a: Add a class\n");
        printf("d: Drop a class\n");
        printf("s: Show your classes\n");
        printf("q: Quit\n");
        //printf("\nTotal Credits: %d\n\n", TODO);
        printf("Please enter a choice ---> ");
        scanf(" %c", &input_buffer);
        branching(input_buffer);
    } while (input_buffer != 'q');
    
    //Deallocate
    while(course_collection != NULL)
        remove_CourseNode();
    
    return 0;
}

//takes a character representing an inputs menu choice and calls the appropriate
//function to fulfill that choice. display an error message if the character is
//not recognized.
void branching(char option) {
    
    switch (option) {
        int courseNumber;
        case 'a':
            printf("Please enter a class number (0, 1, 2, 3): ");
            scanf("%d", &courseNumber);
            struct CourseNode* courseNode1 = (struct CourseNode*) 
                malloc(sizeof(struct CourseNode));
            courseNode1->creditHours = 3;
            courseNode1->number = courseNumber;
            strcpy(courseNode1->teacher, "Teacher Name");
            course_collection = add_CourseNode(courseNode1, course_collection);
            break;
        case 'd':
            remove_CourseNode();
            break;
        case 's':
            display(course_collection);
            break;
        case 'q':
            // main loop will take care of this.
            break;
        default:
            printf("\nError: Invalid Input.  Please try again...");
            break;
    }
}

struct CourseNode* add_CourseNode(struct CourseNode* new_node, struct CourseNode* front) {
    new_node->next = front;
    front = new_node;
    
    return front;
}

void remove_CourseNode() {
    if (course_collection != NULL) {
        struct CourseNode* temp = course_collection;
        
        course_collection = course_collection->next;
        free(temp);
        temp = NULL;
    }
}

void display(struct CourseNode* front) {
    struct CourseNode* iter = front;
    
    while(iter) {
        printf("Course Number: %d Credit Hours: %d Teacher: %s\n", 
                iter->number, iter->creditHours, iter->teacher);
        iter = iter->next;
    }
}