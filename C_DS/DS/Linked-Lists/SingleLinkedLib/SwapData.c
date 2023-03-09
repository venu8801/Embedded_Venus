#include "Stack_Header.h"
extern struct node *head;
void Swap_data(int num1, int num2)
{
	struct node *ptr1, *ptr2;
	int tempData;
	if(num1 == num2)
	{
		printf("Duplicates exist\n");
		printf("--cannot perform swap\n");
		return;
	}
	if(head == NULL)
	{
		printf(" is empty\n");
		return;
	}
	if(head->link == NULL)
	{
		printf("Only one element is present\n");
		return;
	}
	ptr1 = ptr2 = head;
	while(ptr1 != NULL)
	{
		if(ptr1->data == num1)
			break;
		ptr1 = ptr1->link;
	}

	while(ptr2 != NULL)
	{
		if(ptr2->data == num2)			
			break;

		ptr2 = ptr2->link;
	}

	if( (ptr1 == NULL) || (ptr2 == NULL))
	{
		printf("Element not found\n");
		return;
	}

	tempData = ptr1->data;

	ptr1->data = ptr2->data;

	ptr2->data = tempData;

}
