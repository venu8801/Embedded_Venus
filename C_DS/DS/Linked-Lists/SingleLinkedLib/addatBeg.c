#include "Stack_Header.h"
extern struct node *head;
void addatBeg(int num)
{
	struct node *ptr;
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Failed to allocate memory in heap\n");
		exit(1);
	}
	ptr->link = head; // update headpointers address into link part of newly added node so that it points next node (if any) or null

	ptr->data = num;  // add data inside newly created node

	head = ptr;
	// update newly added node's address into head pointer so that this newly added node should be pointed by head pointer
}
