#include "Stack_Header.h"
extern struct node *head;
void reverseStack()
{
	struct node *curr, *prev, *nxt;

	if(head == NULL)
	{
		printf("Stack is empty\n");
		return;
	}

	if(head->link == NULL)
	{
		printf("Only one node is present\n");
		return;
	}
	prev = NULL;
	curr = head;

	while(curr != NULL)
	{
		nxt = curr->link;
		curr->link = prev;
		prev = curr;
		curr = nxt;

	}

	head = prev;
}
