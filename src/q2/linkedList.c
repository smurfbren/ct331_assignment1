#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;


listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
   
    return NULL; 
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    
    free(e); 
    return NULL; 
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}



int length(listElement* list) {
    if (list == NULL) {
        return 0;
    } else {
        return 1 + length(list->next);
    }
}

void push(listElement** list, char* data, size_t size) {
  
    if (list == NULL) {
        return;
    }

    listElement* newHead = createEl(data, size);

    newHead->next = *list;
    *list = newHead;
}


listElement* pop(listElement** list) {
    
    if (list == NULL || *list == NULL) {
        return NULL;
    }
    listElement* oldHead = *list;
    *list = oldHead->next; 
    oldHead->next = NULL; 
    return oldHead;
}


void enqueue(listElement** list, char* data, size_t size) {
    push(list, data, size);
}


listElement* dequeue(listElement** list) {
 
    if (list == NULL || *list == NULL) {
        return NULL;
    }
  
    listElement* tail = *list;
    
    listElement* nTail = NULL;
    while (tail->next != NULL) {
        nTail = tail;
        tail = tail->next;
    }

    if (nTail == NULL) {
        
        *list = NULL;
    } else {
        
        nTail->next = NULL;
    }

    return tail;
}