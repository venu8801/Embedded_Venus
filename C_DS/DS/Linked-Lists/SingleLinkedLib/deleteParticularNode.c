#include "Stack_Header.h"
extern struct node *head;
void deleteParticularNode(int num)
{

	struct node *curr, *prev;
	if(head == NULL)
	{
		printf("List is empty\n");
		exit(1);
	}
	if(head->data == num) // check if it is the first node or not
	{
		if(head->link == NULL)  // check if it is the only node present
		{
			free(head);
			head = NULL;
			return;
		}
		curr = head;
		head  = head->link;
		free(curr);
		return;
	}

	prev = head;
	curr = head->link;


	while(curr != NULL)
	{	
		if(curr->data == num)
		{
			prev->link = curr->link;
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->link;
	}
	printf("Element not found\n");

}

