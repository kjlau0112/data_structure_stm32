#include "uart.h"
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
	
};

typedef struct node nodeType;


void linkedlist1()
{
    nodeType *last,*head,*newNode;
        
    //test_setup();
    printf("\r Linked List Feature:\r\n");
    head = (nodeType* )malloc(sizeof(nodeType));
    head->data = 9;
    head->next = last;
    
    // create a newNode  to insert at the begining.
    newNode = (nodeType* )malloc(sizeof(nodeType));
    newNode -> data = 27;
    newNode -> next = head;
    head = newNode;

    // create another new node to insert at the end.
    last = (nodeType* )malloc(sizeof(nodeType));
    last->data =100;
    last->next = NULL;
    
    head->next->next = last;
    
    //newNode->next = last;
    //head = newNode;
    while(head != NULL)
    {
        printf(" %d ", head-> data);
        head = head -> next;
    }
}


nodeType* linkedlistCreate(int *ptr, int arrLength)
{
		int index=1;
		nodeType *last,*head,*newNode;
		head = (nodeType*)malloc(sizeof(nodeType));
	
		head->data = ptr[0];
		//head->next= NULL;
		last = head;
	
		for(index=1;index<arrLength;index++)
		{
				newNode= (nodeType*)malloc(sizeof(nodeType));
				newNode ->data = ptr[index];
				last->next = newNode;
			  last = newNode;
		}
		
		return head;
}

void linkedlist2()
{
	int arr[] ={5,3,7,4,8,9};
	
	nodeType*  myList = linkedlistCreate(arr,6);
	
	while(myList != NULL)
	{
		printf(" %d ", myList-> data);
		myList = myList -> next;
	}
}



uint32_t linklist_length(nodeType* list)
{
	uint32_t length = 0;
	
	while(list!=NULL)
	{
		list = list->next;
		length++;
	}
	
	return length;
	
}


int8_t linkedList_insert(nodeType* list, uint32_t idx, int8_t element)
{
	nodeType* temp;
	if (idx >linklist_length(list))
	{
		printf("\r error:\r\n");
		return -1;
	}
	
	temp = (nodeType* )malloc(sizeof(nodeType));
	temp->data =element;
	
	if (idx ==0)
	{
			temp->next = list;
			list = temp;
	}
	else
	{
		for(int i = 0; i<idx-1;i++)
		{
				list= list->next;
		}
		temp->next =list->next;
		list->next = temp;
	}
}

int main()
{
	USART2_Init();
	linkedlist1();


}
