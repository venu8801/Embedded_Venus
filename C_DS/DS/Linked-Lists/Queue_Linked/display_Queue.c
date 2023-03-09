#include"QueueH.h"
extern struct node *front, *rear;
void display_Queue()
{
	struct node *tempPtr;


	if(front == NULL)
	{
		printf("List is empty cannot display\n");
		return;
	}
	printf("----------------\n");
	printf("data inside: ");


	tempPtr = front;  // updating tempPtr with head

	while( tempPtr != NULL)
	{
		printf("%d  ", tempPtr->data); // prints data pointed by tempPtr
		tempPtr = tempPtr->link; // updating tempPtr to point next node

	}
	printf("-------------------\n");

}

