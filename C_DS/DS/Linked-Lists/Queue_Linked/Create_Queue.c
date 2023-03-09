// create queue
#include"QueueH.h"
extern struct node *front, *rear;
void Create_Queue(int *iptr, int n)
{
	int i;
	struct node *ptr;
	for(i = 0; i < n; i++)
	{
		ptr = (struct node *)malloc(1 * sizeof(struct node));
		if(ptr = NULL)
		{
			printf("failed to allocate memory\n");
			exit(1);
		}
		ptr->data = iptr[i];
	       	ptr->link = NULL;
		if(rear == NULL)
			front = rear = ptr;
		else
			rear->link = ptr;
		rear = ptr;
		
	}
	
}
