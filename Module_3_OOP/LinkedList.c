//////////////////////////////////////////////////////////////////////
//Include Files
#include "LinkedList.h"


//////////////////////////////////////////////////////////////////////
//Type Definitions

typedef struct node node;

struct node {
    void* element;
    struct node* next;
};

struct list {
    struct node* head;
    int size;
};

//////////////////////////////////////////////////////////////////////
//Function Declarations

list* list_create() {
    list* new_list = (list*)malloc(sizeof(list));
    
    if(new_list == NULL) {
        printf("Error: list not created");
        exit(1);
    } else {
        new_list->head = NULL;
        new_list->size = 0;
        
        return new_list;
    }
}

void list_destroy(list** lst) {
    node* iter = (*lst)->head; // pointer to the head of the list
    
    while (iter != NULL) {
        node* n = iter->next;
        free(iter); 
        iter = n;
    }
    
    // Free list
    free(*lst);
    
    // Prevent dangling pointer
    *lst = NULL;
}

void list_add(list* lst, void* element) {
    node* new_node = (node*)malloc(sizeof(node));
    
    // Set up node
    new_node->element = element;
    new_node->next = lst->head;
    
    // Attach node
    lst->head = new_node;
    lst->size++;
}

void* list_get(list* lst, int idx) {
    node* iter = lst->head;
    void* data = iter->element;
    
    for (int i = 0; i < idx; i++) {
        iter = lst->head->next;
    }
    
    data = iter->element;
    
    return data;
}

int list_indexOf(list* lst, void* ele) {
    list* copy_list = (list*)malloc(sizeof(lst));
    copy_list = lst;
    int eleFound = 0;
    
    node* n = copy_list->head;
    int idx = 0;
    
    while (n->element != ele && idx < lst->size) {
        if (n->element == ele) {
            eleFound = 1;
        }
        
        n = copy_list->head->next;
        idx++;
    }
    
    list_destroy(&copy_list);
    
    if (eleFound == 0) {
        printf("Error: element not in list\n");
        exit(1);
    } else {
        return idx;
    }
}

void list_set(list* lst, int idx, void* element) {
    node* iter = lst->head;
    
    if(idx >= lst->size) {
        printf("Error: invalid index\n");
    } else {
        for (int i = 0; i < idx; i++) {
            iter = iter->next;
        }

        iter->element = element;
    }
}

int list_size(list* lst) {
    return lst->size;
}