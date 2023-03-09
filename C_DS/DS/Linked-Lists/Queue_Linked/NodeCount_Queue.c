#include"QueueH.h"
extern struct node *front, *rear;
int Nodecount_Queue()
{
	struct node *tempPtr;

	int count = 0;

	if(front == NULL)
	{
		printf("List is empty\n");
		return 0;
	}

	tempPtr = front;

	while( tempPtr != NULL)
	{
		count++;
		tempPtr = tempPtr->link;
	}
	return count;
}
