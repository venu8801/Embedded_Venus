// delete duplicates in queue
#include"QueueH.h"
extern struct node *front, *rear;
void DeleteDup_Queue()
{
	if(front == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	else if(front == rear)
	{
		printf("Only one node is present\n");
		return;
	}
	
	struct node *p, *q, *s;
	for(p = front; p != NULL; p = p->link)
	{
		for(s = p,q = p->link; q->link != NULL;s = q,  q = q->link)
		{
			if(p->data == q->data)
			{
				s->link = q->link;
				if(q == rear)
					rear = s;
				free(q);
			}
			q = s; // very imp because we have de-allocated queue so we cant traverse with q we need to update q
		}
	}
}


