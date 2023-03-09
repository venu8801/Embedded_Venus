#include "Stack_Header.h"
extern struct node *head;
void deleteAtlast()
{
	struct node *prev, *curr;

	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link == NULL)
	{
		free(head);
		head = NULL;
		printf("element deleted\n");
		return;
	}
	prev = head;
	curr = head->link;

	while( curr->link != NULL)
	{	
		prev = curr;
		curr = curr->link;
	}
	free(curr);
	prev->link = NULL;
	printf("last element deleted\n");
}

