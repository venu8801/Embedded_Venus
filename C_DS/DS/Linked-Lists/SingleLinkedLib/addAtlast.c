#include "Stack_Header.h"
extern struct node *head;
void addAtlast(int num)
{
	struct node *tempPtr1, *tempPtr2;

	tempPtr1 = head;
	if(tempPtr1 == NULL)
	{
		tempPtr1 =  (struct node*)malloc(1 * sizeof(struct node));
		if(tempPtr1 == NULL)
		{
			printf("failed to allocate\n");
			exit(9);
		}

		tempPtr1->data = num;
		tempPtr1->link = NULL;
		head = tempPtr1;
	}
	else
	{
		while(1)
		{
			if(tempPtr1->link == NULL)
			{
				tempPtr2 = (struct node*)malloc(1 * sizeof(struct node));
				if(tempPtr2 == NULL)
				{
					printf("failed to allocate memory at last\n");
					exit(2);
				}
				tempPtr2->data = num;
				tempPtr2->link = NULL;

				break;
			}


			tempPtr1 = tempPtr1->link;
		}
		tempPtr1->link = tempPtr2;
	}
}
