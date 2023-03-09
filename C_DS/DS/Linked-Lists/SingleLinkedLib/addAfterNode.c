#include "Stack_Header.h"
extern struct node *head;
void addAfterNode(int num, int var)
{
	struct node *ptr;
	struct node *tempPtr;

	if(head == NULL)
	{
		printf("List is empty----\n");
		return;
	}


	tempPtr = head;

	while(tempPtr != NULL)
	{
		if(tempPtr->data == num)
		{
			ptr = (struct node *)malloc(1 * sizeof(struct node));
			printf("add: %p\n",ptr);
			if(ptr == NULL)
			{
				printf("failed to allocate memory in heap\n");
				exit(0);
			}

			ptr->data = var;
			ptr->link = tempPtr->link;
			tempPtr->link = ptr;
			return;
		}
		tempPtr = tempPtr -> link;
	}
}
