#include "Sorter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *file;

void mergeSortBegin(LL* dlist, char* field){ //takes in a data struct array and a field to sort by
  if((dlist->head == NULL) || (dlist->head == dlist->tail)){ //if no nodes or one nodes, already solved
    printf("There are no entries in the csv, cannot sort.");
   return;
  }
  int n = 0;
  int found = 0;
  for(n = 0;n < dlist->numfields; n++){ //determines the field to be sorted
   if(strcmp(field,dlist->fields[n]) == 0){ //note: 0 = string, 1 = int, 2 = float
    dlist->sortingfield = n; //determines the field to sort by 
    found = 1;
   }
  }
  if(found == 0){
   printf("Field not found. Please sort by one of the fields in the csv file.\n");
  }
  
  dlist->sortingtype =  dlist->types[dlist->sortingfield];
  dlist->head = mergeSort(dlist,dlist->head);
  
}

Node* mergeSort(LL* dlist, Node* head){//note: String's mergesort
  if((head == NULL) || (head->next == NULL)){
   return head; 
  }
  Node* temp = head;
  int n = 0;
  while(temp != NULL){
   if(strcmp(temp->ndata.fielddata[11], "xXx ") ==0){
//   printf("%s, %d", temp->ndata.fielddata[11],n);

  }
  temp = temp->next;
  n++;
  }
  
  Node* mid = split(head);

  head = mergeSort(dlist, head);
  mid = mergeSort(dlist, mid);
  
  head = merge(dlist,head,mid);

  return head;
  
}



Node* split(Node* head){ //given a head node, returns a pointer to the middle node
  if((head == NULL) || (head->next == NULL)){
   return NULL;
  }
 Node* temp = head->next;
 Node* prev = head;
while(temp != NULL){
   temp = temp->next;
   if(temp != NULL){
    prev = prev->next;
    temp = temp->next;
 }
}
Node* midpt = prev->next;
prev->next = NULL;
return midpt;
}


Node* merge(LL* dlist, Node* left, Node* right){
  if( left == NULL){
   return right; 
  }
  else if(right == NULL){
   return left; 
  }
  if(dlist->sortingtype == 0){ //if sorting a string
    
    //alphabetic sorting method
   
    char* leftstr = strdup(left->ndata.fielddata[dlist->sortingfield]);
    int n = 0;
    for(n = 0;n < strlen(leftstr);n++){
     leftstr[n] = tolower(leftstr[n]); 
    }
    char* rightstr = strdup(right->ndata.fielddata[dlist->sortingfield]);
    
    for(n = 0;n < strlen(rightstr);n++){
     rightstr[n] = tolower(rightstr[n]); 
    }

    
  //  char* leftstr = left->ndata.fielddata[dlist->sortingfield];
  //  char* rightstr = right->ndata.fielddata[dlist->sortingfield];
       
    int cmp = strcmp(leftstr,rightstr);
    Node* final = NULL;
    if(cmp <= 0){
     final = left;
     final->next = merge(dlist,left->next,right);
    }
    else{
      final = right;
      final->next = merge(dlist,left,right->next);
    }
    free(leftstr);
    free(rightstr);
    return final;
  }
  else if(dlist->sortingtype == 1){ //if sorting longs
    
    char** lendptr = NULL;
    char** rendptr = NULL;
    long leftlong = strtol(left->ndata.fielddata[dlist->sortingfield], lendptr,10);
    long rightlong = strtol(right->ndata.fielddata[dlist->sortingfield], rendptr,10);
    Node* final = NULL;
    if(leftlong <= rightlong){
     final = left;
     final->next = merge(dlist,left->next,right);
    }
    else{
      final = right;
      final->next = merge(dlist,left,right->next);
    }
    return final;
  }
  else{ //if sorting neither longs or strings, must be sorting floats
    char** lendptr = NULL;
    char** rendptr = NULL;
    float leftfl = strtof(left->ndata.fielddata[dlist->sortingfield], lendptr);
    float rightfl = strtof(right->ndata.fielddata[dlist->sortingfield], rendptr);
    Node* final = NULL;
    if(leftfl <= rightfl){
     final = left;
     final->next = merge(dlist,left->next,right);
    }
    else{
      final = right;
      final->next = merge(dlist,left,right->next);
    }
    return final;
    
  }
    
  
}