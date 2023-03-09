// deletes full queue
#include"QueueH.h"
extern struct node *front, *rear;
void Delete_full_Queue()
{
	struct node *temp;
	if(front == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	else if(front == rear) // if only one element is present in the queue
	{
		free(front);
		front = rear = NULL;
		return;
	}
	temp = front;
	while(front != NULL)
	{
		temp = front;
		front = front->link;
		free(temp);
	}
	rear = NULL;
}
