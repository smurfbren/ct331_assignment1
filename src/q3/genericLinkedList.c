#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef void ()

typedef struct genericlistElement{
  void* data;
  size_t size;
  printFunction print;
  struct listElementStruct* next;
} genericlistElement;

genericlistElement* createEl(void* data, size_t size, printfunction p){
  genericlistElement* e = malloc(sizeof(genericlistElement));
  if(e == NULL){
    
    return NULL; 
  }
  void* dataPointer = malloc(size);
  if(dataPointer == NULL){
    
    free(e); 
    return NULL; 
  }
  memmove(dataPointer, data, size);
  e->data = dataPointer;
  e->size = size;
  e->print =p;
  e->next = NULL;
  
  return e;
}


void traverse(genericlistElement* start){
  genericlistElement* current = start;
  while(current != NULL){
    current->print(current->data);
    current = current->next;
  }
}

genericlistElement* insertAfter(genericlistElement* el, char* data, size_t size,printfunction p){
  listElement* newEl = createEl(data, size,p);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(genericlistElement* after){
  genericlistElement* delete = after->next;
  genericlistElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

int length(genericlistElement* list){
genericlistElement* tracker = list;
int counter =0;
while(tracker != NULL){
counter++;
tracker = tracker->next;
}
return counter;
}

void push(genericlistElement** list, void* data, size_t size,printfunction p){
genericlistElement* new = createEl(data, size, p);
new->next = *list;
*list = new;
}

genericlistElement* pop(genericlistElement** list){
genericlistElement* head = *list;

if(head){
*list = head->next;
head->next=NULL;
}
return head;
}

void enqueue(genericlistElement** list, void* data, size_t size, printfunction p){
genericlistElement* new = createEl(data, size, p);
new->next=*list;
*list=new;
}

genericlistElement* dequeue(genericlistElement* list){

genericlistElement *tail =NULL;  
genericlistElement *cursor = list;  


while(cursor->next != NULL){  
tail = cursor;
cursor = cursor->next;
}
if(tail != NULL)
tail->next =NULL; 

if(cursor == list)  
list = NULL;

free(cursor);

return list;
}