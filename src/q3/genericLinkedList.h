#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct genericlistElementStruct listElement;

genericlistElement* createEl(void* data, size_t size, printFunction p);

void traverse(listElement* start);
genericlistElement* insertAfter(listElement* after, char* data, size_t size);
void deleteAfter(genericlistElement* after);
int length(genericlistElement* list);
void push(genericlistElement** list, void* data, size_t size);
void enqueue(genericlistElement** list, void* data, size_t size);
genericlistElement* pop(genericlistElement** list);
genericlistElement* dequeue(genericlistElement* list);



#endif