/* stack implementation using single linked Stack*/
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node
{
	int data;
	struct node *link;
};


struct node *head = NULL;

void addAtlast(int num);
void deleteAll();
int Nodesearch(int num);
int Nodecount();
void display();
void delAtBeg();
void addatBeg(int num);
void deleteAtlast();
void addAfterNode(int num, int var);
void deleteParticularNode(int num);
void addBeforeNode(int num, int val);
void reverseStack();
void create_Stack(int s);
void Swap_data(int num1, int num2);
void Swap_Links(int num1, int num2);
void BubbleSortLinks();
void SelectionSortLinks();
int main()
{
	int num, pos, count,val;
	int opt;
	while(1)
	{
		printf("----------stack------------\n");
		printf("Select the option\n");
		printf("0.Exit\n1.PUSH\n2.POP\n3.Display\n4.Count\n5.Search\n6.Delete Entire Stack\n");
		printf("7.add after a node\n8.delete particular node\n9.Add before a Node\n10.Reverse Stack\n11.Create Stack\n12.Swap two nodes (data)\n13.Swap two nodes (links)\n14.Bubble Sort (Links)\n");
		printf("15.Selection Sort (Links)\n");
		scanf("%d",&opt);

		switch(opt)
		{
			case 0:
				printf("----------------------\n");
				printf("selected exit\n");
				exit(0);
			case 1:
				printf("----------------------\n");
				printf("PUSH\n");
				printf("Enter the data: ");
				scanf("%d",&num);
				addatBeg(num);
				break;
			case 2:
				printf("----------------------\n");
				printf("POP\n");
				delAtBeg();
				break;
			case 3:
				printf("----------------------\n");
				printf("Displaying data from all existing nodes\n");
				display();
				break;
			case 4:
				printf("----------------------\n");
				printf("----count of all nodes\n");
				count = Nodecount();
				printf("No. of nodes: %d\n",count);
				break;
			case 5:
				printf("----------------------\n");
				printf("Search in nodes\n");
				printf("Enter the element to be searched: ");
				scanf("%d",&num);
				pos = Nodesearch(num);
				if(pos <= 0)
					printf("data not found in Stack\n");
				else
					printf("Data found at pos: %d\n",pos);
				break;
			case 6:
				printf("----------------------\n");
				printf("Delete Entire Stack\n");
				deleteAll();
				break;
		
			case 7:
				printf("----------------------\n");
				printf("Enter node to be searched\n");
				scanf("%d",&num);
				printf("Enter data inside new node:\n");
				scanf("%d",&val);

				addAfterNode(num, val);
				break;
			case 8:
				printf("----------------------\n");
				printf("Enter node to be searched\n");
				scanf("%d",&num);

				deleteParticularNode(num);
				break;
			case 9:
				printf("----------------------\n");
				printf("Enter node to be searched\n");
				scanf("%d",&num);
				printf("Enter data inside new node:\n");
				scanf("%d",&val);
				addBeforeNode(num, val);
				break;
			case 10:
				printf("----------------------\n");
				printf("Reversing node\n");

				reverseStack();
				break;
			case 11:
				printf("----------------------\n");
				printf("Creating a Stack\n");
				printf("Enter size of the Stack: ");
				scanf("%d",&num);
				//create_Stack(num);
				break;
			case 12:
				printf("----------------------\n");
				printf("Swap data inside two nodes\n");
				printf("Swaps only data \n");
				printf("Enter node to be searched: ");
				scanf("%d",&num);
				printf("Enter node to be swapped with: ");
				scanf("%d",&val);
				Swap_data(num, val);
				break;
			case 13:
				printf("----------------------\n");
				printf("Swap data inside two nodes\n");
				printf("Swaps only data \n");
				printf("Enter node to be searched: ");
				scanf("%d",&num);
				printf("Enter node to be swapped with: ");
				scanf("%d",&val);
				Swap_Links(num, val);
				break;
			case 14:
				printf("----------------------\n");
				printf("Sorting a Stack\n");
				BubbleSortLinks();
				break;	
			case 15:
				printf("----------------------\n");
				printf("Sorting a Stack\n");
				SelectionSortLinks();
				break;		

			default:
				printf("Invalid option selected\n");
				exit(2);







		}
		printf("----------------------\n");
	}
}

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

void delAtBeg()
{
	struct node *tempPtr;

	if(head == NULL)
	{
		printf("Stack is empty cannot delete\n");
		return;
	}

	tempPtr = head;  // take backup of first node's address

	head = head->link; // store link part of first node which points to next node into head pointer
	// so now 2nd node becomes first node as head pointer is pointing to 2nd node


	free(tempPtr);// free the memory of first node which de-allocates the memory of first node
}





void display()
{
	struct node *tempPtr;


	if(head == NULL)
	{
		printf("Stack is empty cannot display\n");
		return;
	}
	printf("----------------\n");
	printf("data inside: ");


	tempPtr = head;  // updating tempPtr with head

	while( tempPtr != NULL)
	{
		printf("%d  ", tempPtr->data); // prints data pointed by tempPtr
		tempPtr = tempPtr->link; // updating tempPtr to point next node

	}
	printf("-------------------\n");

}

int Nodecount()
{
	struct node *tempPtr;

	int count = 0;

	if(head == NULL)
	{
		printf("Stack is empty\n");
		return 0;
	}

	tempPtr = head;

	while( tempPtr != NULL)
	{
		count++;
		tempPtr = tempPtr->link;
	}
	return count;
}

int Nodesearch(int num)
{
	struct node *tempPtr;

	if(head == NULL)
	{
		printf("Stack is empty\n");
		return 0;
	}

	int pos = 1;

	tempPtr = head;

	while(tempPtr != NULL)
	{
		if(tempPtr->data == num)
			return pos;

		tempPtr = tempPtr->link;
		pos++;

	}

	return 0;

}

void deleteAll()
{
	struct node *tempPtr1, *tempPtr2;

	if(head == NULL)
	{
		printf("Stack is empty\n");
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
void addAfterNode(int num, int var)
{
	struct node *ptr;
	struct node *tempPtr;

	if(head == NULL)
	{
		printf("Stack is empty----\n");
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

void deleteParticularNode(int num)
{

	struct node *curr, *prev;
	if(head == NULL)
	{
		printf("Stack is empty\n");
		exit(1);
	}
	if(head->data == num) // check if it is the first node or not
	{
		if(head->link == NULL)  // check if it is the only node present
		{
			free(head);
			head = NULL;
			return;
		}
		curr = head;
		head  = head->link;
		free(curr);
		return;
	}

	prev = head;
	curr = head->link;


	while(curr != NULL)
	{	
		if(curr->data == num)
		{
			prev->link = curr->link;
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->link;
	}
	printf("Element not found\n");

}

void addBeforeNode(int num, int val)
{

	struct node *prev, *curr;
	if(head == NULL)
	{
		printf("Stack is empty\n");
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
void BubbleSortLinks()
{
	if(head == NULL)
	{
		printf("List is empty, cannot perform swap\n");
		return;
	}
	if(head->link == NULL)
		return;
	
	
	
	struct node *p,*q, *e = NULL, *s, *r, *temp;
	
	for(e = NULL; head->link != e; e = q)
	{
		for(r = p = head; p->link != e; r = p, p = p->link)
		{
			q = p->link;
			if(p->data > q->data)
			{
				p->link = q->link;
				q->link = p;
				if(p!=head)
					r->link = q;
				else
					head = q;
					
				temp = p;
				p = q;
				q = temp;
			}
		}
	}			
}
void SelectionSortLinks()
{
	struct node *p,*q,*r,*s;
	struct node *temp;
	if(head == NULL)
	{
		printf("List is empty, cannot perform swap\n");
		return;
	}
	if(head->link == NULL)
		return;
	for(p = head;    p->link != NULL;   r = p, p = p->link)
	{	
		for(q = p->link; q != NULL; s = q, q = q->link)
		{
			if(p->data > q->data)
			{
				//checking if adjacent nodes or not
				if(p->link == q)
				{
					p->link = q->link;
					q->link = p;
					if(p == head)
						head = q;
					else
						r->link = q;
				}
				else
				{
					temp = p->link;
					p->link = q->link;
					q->link = temp;
					if(p != head)
						r->link = q;
					else
						head = q;
					s->link = p;
					
				}
				
				temp = p;
				p = q;
				q = temp;
				
			}
		}	
	}
}	

