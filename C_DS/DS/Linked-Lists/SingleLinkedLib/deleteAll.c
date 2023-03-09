#include "Stack_Header.h"
extern struct node *head;
void deleteAll()
{
	struct node *tempPtr1, *tempPtr2;

	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	tempPtr1 = head;

	while(tempPtr1 != NULL)
	{
		if(tempPtr1 == NULL)
			return;
		tempPtr2 = tempPtr1->link;
		free(tempPtr1);
		tempPtr1 = tempPtr2;

	}
	head = NULL;
}
