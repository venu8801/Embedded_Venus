#include "Stack_Header.h"
extern struct node *head;
void Swap_Links(int num1, int num2)
{
	struct node *curr1,*curr2,*prev1,*prev2,*temp;
	int pos1 = 0, pos2 = 0;
	if(num1 == num2)
	{
		printf("Duplicates exist\n");
		printf("--cannot perform swap\n");
		return;
	}
	if(head == NULL)
	{
		printf("Stack is empty\n");
		printf("--cannot perform swap\n");
		return;
	}
	if(head->link == NULL)
	{
		printf("Only one element is present\n");
		printf("--cannot perform swap\n");
		return;
	}

	curr1 = curr2 = head;

	while( curr1 != NULL)
	{
		pos1++;
		if(curr1->data == num1)
			break;
		prev1 = curr1; 
		curr1 = curr1->link;
	}

	while( curr2 != NULL)
	{
		pos2++;
		if(curr2->data == num2)
			break;
		prev2 = curr2; 
		curr2 = curr2->link;
	}

	if( (curr1 == NULL) || (curr2 == NULL))
	{
		printf("Element not found\n");
		return;
	}

	if(pos1 > pos2)
	{
		temp = curr1;
		curr1 = curr2;
		curr2 = temp;

		temp = prev1;
		prev1 = prev2;
		prev2 = temp;

	}

	//Non adjacent nodes

	if(curr1->link != curr2)
	{
		temp = curr1->link;
		curr1->link = curr2->link;
		curr2->link = temp;
		if( curr1 != head)
			prev1->link = curr2;
		else
			head = curr2;
		prev2->link = curr1;
		return;
	}		






	//adjacent nodes
	
	else
	{
		curr1->link = curr2->link;
		curr2->link = curr1;
		if(curr1 != head)
			prev1->link = curr2;
		else
			head = curr2;
		return;
	}		


}

