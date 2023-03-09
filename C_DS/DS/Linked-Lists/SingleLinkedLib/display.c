#include "Stack_Header.h"
extern struct node *head;
void display()
{
	struct node *tempPtr;


	if(head == NULL)
	{
		printf("List is empty cannot display\n");
		return;
	}
	printf("----------------\n");
	printf("data inside: ");


	tempPtr = head;  // updating tempPtr with head

	while( tempPtr != NULL)
	{
		printf("%d  ", tempPtr->data); // prints data pointed by tempPtr
		tempPtr = tempPtr->link; // updating tempPtr to point next node

	}
	printf("-------------------\n");

}

