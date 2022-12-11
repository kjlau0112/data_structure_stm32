#include "uart.h"
//#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
	
};

typedef struct node nodeType;
void display(nodeType *head);
uint32_t linklist_length(nodeType* list);
void deleteN(nodeType** head, int position);
void display(nodeType *head);
void initList_insertFront_insertLast(void);
nodeType* linkedlistCreate(int *ptr, int arrLength);
void linkList_Derive_From_Data_delete_first_data(void);
void linkList_Derive_From_Data(void);
uint32_t linklist_length(nodeType* list);
int8_t linkedList_insert(nodeType* list, uint32_t idx, int8_t element);
void linklist_setup(void);
