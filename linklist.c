#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"  

void deleteN(nodeType* head, int position)
{
   int index=1;
   //work in progress, this code just delete the head node.
   nodeType * temp = head;

   if(position == 1)
   {
       head = head -> next;
       free(temp);
       display(head); 
    }
   else
   {
        for(index=1;index<position;index++)
        {
            temp = head;
            head = head -> next;
            
            free(temp);
        }
       
//        for(index=1;index<position;index++)
//        {
//            temp ->next = head;
//            head = head -> next;
//        }
        
            temp->next = head->next;
        display(temp);
   }

    
    
}

void display(nodeType *head)
{
    if(head == NULL)
    {
        printf("NULL\r\n");
    }
    
    while(head != NULL)
    {
        printf("%d\r\n", head -> data);
        head= head-> next;
    }
}

void initList_insertFront_insertLast()
{
    nodeType *last,*head,*newNode;
        
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
    head->next= NULL;
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

void linkList_Derive_From_Data_delete_first_data()
{
	int arr[] ={5,3,7,4,8,9};
	
	nodeType*  myList = linkedlistCreate(arr,6);
    deleteN(myList,3);
    
}
void linkList_Derive_From_Data()
{
	int arr[] ={5,3,7,4,8,9};
	
	nodeType*  myList = linkedlistCreate(arr,6);
	display(myList);     
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
	temp->data = element;
	
	if (idx == 0)
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
    return 0;
}

void linklist_position_insert_pos_mentioned(void)
{
    nodeType *myLinklist = (nodeType* )malloc(sizeof(nodeType));
    myLinklist->data =10;
    myLinklist->next =NULL;

    linkedList_insert(myLinklist,1,12);
    linkedList_insert(myLinklist,2,13);
    display(myLinklist);

}

void linklist_setup(void)
{    
    char operation;
    printf("Link list MCU guide\r\n");
    scanf("%c", &operation);

    
    switch(operation)
    {
        case 'a':
            printf("link list init, insert head, insert last\r\n");
            initList_insertFront_insertLast();
            break;

        case 'b':
            printf("link list derive from data array\r\n");
            linkList_Derive_From_Data();
            break;
        
        case 'c':
            printf("link list insert with position mentioned\r\n");
            linklist_position_insert_pos_mentioned();
            break;


        default:
            printf("invalid input");
    }

    
}
