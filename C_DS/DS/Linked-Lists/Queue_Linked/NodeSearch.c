#include"QueueH.h"
extern struct node *front, *rear;
int Nodesearch_Queue(int num)
{
	struct node *tempPtr;

	if(front == NULL)
	{
		printf("Queue is empty\n");
		return 0;
	}

	int pos = 1;

	tempPtr = front;

	while(tempPtr != NULL)
	{
		if(tempPtr->data == num)
			return pos;

		tempPtr = tempPtr->link;
		pos++;

	}

	return 0;

}

