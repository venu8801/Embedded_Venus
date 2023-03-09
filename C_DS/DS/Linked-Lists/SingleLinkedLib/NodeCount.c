#include "Stack_Header.h"
extern struct node *head;
int Nodecount()
{
	struct node *tempPtr;

	int count = 0;

	if(head == NULL)
	{
		printf("List is empty\n");
		return 0;
	}

	tempPtr = head;

	while( tempPtr != NULL)
	{
		count++;
		tempPtr = tempPtr->link;
	}
	return count;
}
