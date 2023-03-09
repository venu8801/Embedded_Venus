//reversing Queue

#include"QueueH.h"
extern struct node *front, *rear;
void Reverse_Queue(int *iptr, int num)
{
	if(front == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	else if(front == rear)
	{
		printf("Only one element is present\n");
		return;
	}

	struct node *curr, *prev, *next;

	*prev = front;
	*curr = front->link;

	while(curr != NULL)
	{
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}

	rear = front;
	front = prev;
}
