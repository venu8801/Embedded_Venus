//delete selected node
//


void DeleteParticular_Queue(int num)
{
	if(front == NULL)
	{
		printf("Queue is empty\n");
		return;

	}
	else if(front->link = NULL)
	{
		if(front-data == num)
		{
			free(front);
			front = rear = NULL;
		}
	}
	struct node *prev, curr;
	prev = front;
	curr = front->link;
	while(curr->link != NULL)
	{
		if(curr->data == num)
		{
			prev->link = curr->link;
			if(curr == rear)
				rear = prev;
			free(curr);
		}

		curr = curr->link;
	}
}

