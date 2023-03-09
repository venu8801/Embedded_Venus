#include "Stack_Header.h"
extern struct node *head;
int Nodesearch(int num)
{
	struct node *tempPtr;

	if(head == NULL)
	{
		printf("List is empty\n");
		return 0;
	}

	int pos = 1;

	tempPtr = head;

	while(tempPtr != NULL)
	{
		if(tempPtr->data == num)
			return pos;

		tempPtr = tempPtr->link;
		pos++;

	}

	return 0;

}

