

#include"QueueH.h"
extern struct node *front, *rear;
// add into list using rear pointer
void insert_Queue(int num)
{
	struct node *ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(1);
	}
	ptr->data = num;
	ptr->link = NULL;
	if(rear != NULL)
	{
		rear->link = ptr;
		rear = ptr;
	}
	else
		front = rear = ptr;
		
}
