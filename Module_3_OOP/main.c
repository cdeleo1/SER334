#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
	list* lst;
	lst = list_create();

	list_add(lst, 10);
	list_add(lst, 15);
	list_add(lst, 20);

	printf("@1: %d\n", list_get(lst, 1));
	printf("Size: %d\n", list_size(lst));
        
	list_set(lst, 1, 99);
	printf("@1: %d\n", list_get(lst, 1));

	list_set(lst, 10, 72);
	printf("72 is @: %d\n", list_indexOf(lst, 72));
	printf("Size: %d\n", list_size(lst));
        
	list_destroy(&lst);
	return 0;
}