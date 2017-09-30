/*****
*
*	Define structures and function prototypes for your sorter
*
*
*
******/

//Suggestion: define a struct that mirrors a record (row) of the data set
#ifndef _SORTER_H_
#define _SORTER_H_

typedef struct _data { //THIS DATA STRUCT IS CURRENTLY BAD, PUT DATA IN NODE
char** fielddata; //2d array to contain string types
int* comma; //does the node have a comma in the field n? 0 = no, 1 = yes
//might want to make the data types a linked list also?
//or make a LL to keep track when creating, then place into array??
} data;

typedef struct _Node {
data ndata; //data in a node

//char** data; use this instead of a data struct
struct _Node* next;
}Node;

typedef struct _LL { //linked list that contains the nodes with the movies
Node* head;
Node* tail;
int count; //count of total nodes in list
int numfields; //count of the total fields in the csv
int sortingfield; //keeps track of the field to be sorted, where sortingfield = # field sorted
int sortingtype; //keeps track of what type is being sorted, 0 = string, 1 = int, 2 = float
int* types; //keeps track of types, 0 = string, 1 = long, 2 = float
char** fields; //keeps track of the name fields
}LL;

//Suggestion: prototype a mergesort function
LL* mergesortBegin(LL* dlist, char* field);
Node* mergeSort(LL* dlist, Node* head);
Node* split(Node* head);
Node* merge(LL* dlist, Node* left, Node* right);
#endif

