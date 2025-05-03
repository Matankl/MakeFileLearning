#include "StrList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//------------------------------------------------
// Node declaration
//------------------------------------------------

// Define the string node structure using typedef
typedef struct _StringNode {
    char *data;                // Pointer to the string data
    struct _StringNode *next;   // Pointer to the next node in the linked list
} StringNode;

//------------------------------------------------


//------------------------------------------------
// Node implementation
//------------------------------------------------

// Function to create a new string node
StringNode* createStringNode(const char *str ) {
    // Allocate memory for the node
    StringNode *newNode = (StringNode*)malloc(sizeof(StringNode));
    if (newNode == NULL) {
        return NULL;
    }
    
    // Allocate memory for the string data and copy the input string
    newNode-> data = strdup(str);

    
    // Initialize the next pointer to NULL
    newNode->next = NULL;
    
    return newNode;
}

// Function to free the memory allocated for a string node
void freeStringNode(StringNode *node) {
    free(node->data);   // Free the string data
    free(node);         // Free the node itself
}

// //clone the given node and return a pointer to the new node
// StringNode* cloneStringNode(StringNode* node){
//     StringNode* newNode = createStringNode(node->data);
//     return newNode;
// }


//------------------------------------------------



//------------------------------------------------
// List dclaration
//------------------------------------------------

// Define the string list structure using typedef
typedef struct _StrList {
    StringNode *head;   // Pointer to the first node in the list
    size_t size;        // Number of nodes in the list
} StrList;


//------------------------------------------------
// List implementation
//------------------------------------------------


// Function to allocate memory for a new string list
StrList* StrList_alloc(){
    StrList* p= (StrList*)malloc(sizeof(StrList));
    if ( p==NULL)
        return NULL;
    
    p->head= NULL;
    p->size= 0;
    return p;
}

// Function to free the memory allocated for a string list and its nodes
void StrList_free(StrList* StrList){
    if (StrList==NULL) return;
    StringNode* p1= StrList->head;
    StringNode* p2;
    while(p1) {
        p2= p1;
        p1= p1->next;
        freeStringNode(p2);
    }
    free(StrList);
}

// Function to return the number of elements in the string list
size_t StrList_size(const StrList* StrList){
    return StrList->size;
}

// Function to insert a new string node at the end of the string list
void StrList_insertLast(StrList* StrList, const char* data){
    StringNode* newNode = createStringNode(data);
    if (StrList->head == NULL) {
        StrList->head = newNode;
    } else {
        StringNode* p = StrList->head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }
    StrList->size++;
}

// Function to insert a new string node at a given index in the string list
void StrList_insertAt(StrList* StrList, const char* data,int index){
    StringNode* newNode = createStringNode(data);
    if (index == 0) {
        newNode->next = StrList->head;
        StrList->head = newNode;
    } else {
        StringNode* p = StrList->head;
        for (int i = 0; i < index - 1; i++) {
            if (p == NULL) {
                return;
            }
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    StrList->size++;
}

// Function to return the first string data in the string list
char* StrList_firstData(const StrList* StrList){
    if( StrList->head == NULL){
        return NULL;
    }
    return StrList->head->data;
}


//Prints the StrList to the standard output.
void StrList_print(const StrList* StrList){
    StringNode* p = StrList->head;
    while (p != NULL) {
        printf("%s", p->data);
        p = p->next;
        if (p != NULL)
            printf(" ");        
    }
    printf("\n");
}


// Prints the word at the given index to the standard output.
void StrList_printAt(const StrList* Strlist,int index){
    StringNode* p = Strlist->head;
    for (int i = 0; i < index; i++) {
        if (p == NULL) {
            return;
        }
        p = p->next;
    }
    printf("%s\n", p->data);
}


//Return the amount of chars in the list.
int StrList_printLen(const StrList* Strlist){
    int len = 0;
    StringNode* p = Strlist->head;
    while (p != NULL) {
        len += strlen(p->data);
        p = p->next;
    }
    return len;
}

// Return the number of times a the string exists in the list.
int StrList_count(StrList* StrList, const char* data){
    int count = 0;
    StringNode* p = StrList->head;
    while (p != NULL) {
        if (strcmp(p->data, data) == 0) {
            count++;
        }
        p = p->next;
    }
    return count;
}


//Given a string and a list, remove all the appearences of this string in the list.
void StrList_remove(StrList* StrList, const char* data){
    // 2 pointers to iterate through the list
    StringNode* p = StrList->head;
    StringNode* prev = NULL;

    while (p != NULL) {
        if (strcmp(p->data, data) == 0) {
            // If the head is the string to remove
            if (prev == NULL) {
                StrList->head = p->next;
            } else {
                prev->next = p->next;
            }
            StringNode* temp = p;
            p = p->next;
            freeStringNode(temp);
            StrList->size--;
        } else {
            prev = p;
            p = p->next;
        }
    }
}



//Given an index and a list, remove the string at that index.
void StrList_removeAt(StrList* StrList, int index){
    if (index == 0) {
        StringNode* temp = StrList->head;
        StrList->head = StrList->head->next;
        freeStringNode(temp);
        StrList->size--;
    } else {
        StringNode* p = StrList->head;
        for (int i = 0; i < index - 1; i++) {
            if (p == NULL) {
                return;
            }
            p = p->next;
        }
        if (p == NULL || p->next == NULL) {
            return;
        }
        StringNode* temp = p->next;
        p->next = p->next->next;
        freeStringNode(temp);
        StrList->size--;
    }
}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    StringNode* p1 = StrList1->head;
    StringNode* p2 = StrList2->head;
    while (p1 != NULL && p2 != NULL) {
        if (strcmp(p1->data, p2->data) != 0) {
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p1 == NULL && p2 == NULL) {
        return 1;
    }
    return 0;
}

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* StrListOG){
    StrList* newStrList = StrList_alloc();
    StringNode* p = StrListOG->head;
    while (p != NULL) {
        StrList_insertLast(newStrList, p->data);
        p = p->next;
    }
    return newStrList;
}


//Reverces the given StrList. 
void StrList_reverse( StrList* StrList){
    StringNode* prev = NULL;
    StringNode* current = StrList->head;
    StringNode* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    StrList->head = prev;
}


//Sort the given list in lexicographical order 
void StrList_sort( StrList* StrList){
    StringNode* p = StrList->head;
    StringNode* q = NULL;
    while (p != NULL) {
        q = p->next;
        while (q != NULL) {
            if (strcmp(p->data, q->data) > 0) {
                char* temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}


/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList){
    if (StrList->head == NULL || StrList->head->next == NULL) {
        return 1;
    }
    
    StringNode* p = StrList->head;
    
    while (p->next != NULL) {
        if (strcmp(p->data, p->next->data) > 0) {
            return 0;
        }
        p = p->next;
    }
    return 1;
}

/* ------------------- Additional Methods ------------------- */
 
 //Get data at index
 char* StrList_getData(StrList* StrList, int index){
    StringNode* p = StrList->head;
    for (int i = 0; i < index; i++) {
        if (p == NULL) {
            return NULL;
        }
        p = p->next;
    }
    return p->data;
}


//------------------------------------------------





/*

TODO: check declaration if it is correct (not twice declared - in StrList.h and here)
TODO: check if the include is correct
TODO: check if the insertAt function is implemented correctly (insert instead of or push at) 


*/

