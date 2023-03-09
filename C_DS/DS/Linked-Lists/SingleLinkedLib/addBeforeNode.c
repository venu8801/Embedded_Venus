#include "Stack_Header.h"
extern struct node *head;
void addBeforeNode(int num, int val)
{

	struct node *prev, *curr;
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	if(head->data == num)
	{
		struct node *ptr = (struct node *)malloc(1 * sizeof(struct node));
		if(ptr == NULL)
		{
			printf("Failed to allocate memory\n");
			exit(1);
		}
		ptr->data = val;
		ptr->link = head;
		head = ptr;
		return;
	}
	prev = head;
	curr = head->link;

	while(curr != NULL)
	{
		if(curr->data == num)
		{
			struct node *ptr = (struct node *)malloc(1 * sizeof(struct node));
			if(ptr == NULL)
			{
				printf("failed to allocate memory\n");
				exit(1);
			}
			ptr->data = val;
			ptr->link = prev->link;
			prev->link = ptr;
			return;


		}

		prev = curr;
		curr = curr->link;
	}
	printf("Element not found\n");
}
