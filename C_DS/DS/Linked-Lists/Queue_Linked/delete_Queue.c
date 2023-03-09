// delete operation in queue using front pointer
#include"QueueH.h"
extern struct node *front, *rear;
void delete_Queue()
{
	struct node *temp;
	if(front == NULL)
	{
		printf("Queue is empty cannot delete\n");
		return;
	}
	
	else if(front->link = NULL)
	{
		free(front);
		front = rear = NULL;
		return;
	}
	temp = front;
	front = temp->link;
	free(temp);

}
