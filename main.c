#include "uart.h"
#include <stdlib.h>
#include "linklist.h"





int main()
{ 
	USART2_Init();
    printf("program starting\r\n");

//   linkList_Derive_From_Data_delete_first_data();
    
   
    while(1)
    {
        linklist_setup();
        printf("program restarting\r\n");
    }
}
