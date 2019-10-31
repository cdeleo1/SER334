#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//////////////////////////////////////////////////////////////////////
//Include Files
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
//Type Definitions
typedef struct list list;

//////////////////////////////////////////////////////////////////////
//Function Declarations
//borrowed from docs.oracle.com/javase/9/docs/api/java/util/LinkedList.html

//purpose: creates a new list and returns it.
//return: error value (zero for success, non-zero for error)
list* list_create();


//purpose: destroys a list.
//return: n/a
void list_destroy(list** lst);


//purpose: appends the specified element to the end of this list.
//return: n/a
void list_add(list* lst, void* element);


//purpose: Returns the element at the specified position in this list.
//return: element
void* list_get(list* lst, int idx);


//purpose: Returns the index of the first occurrence of the  element, or -1
//         if this list does not contain the element.
//return: index or -1 if not found
int list_indexOf(list* lst, void* ele);


//purpose: replaces the element at the specified position in this
//         list with the specified element.
//return value: n/a
void list_set(list* lst, int idx, void* element);


//purpose: returns the size of the size.
//return: number of elements in the stack
int list_size(list* lst);

#endif