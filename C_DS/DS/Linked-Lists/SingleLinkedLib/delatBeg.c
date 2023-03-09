#include "Stack_Header.h"
extern struct node *head;
void delAtBeg()
{
	struct node *tempPtr;

	if(head == NULL)
	{
		printf("list is empty cannot delete\n");
		return;
	}

	tempPtr = head;  // take backup of first node's address

	head = head->link; // store link part of first node which points to next node into head pointer
	// so now 2nd node becomes first node as head pointer is pointing to 2nd node


	free(tempPtr);// free the memory of first node which de-allocates the memory of first node
}
