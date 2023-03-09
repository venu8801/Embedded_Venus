/*single linked list*/
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
void reverseList();
void create_list(int s);
void Swap_data(int num1, int num2);
void Swap_Links(int num1, int num2);
void SelectionSort();
void SelectionSortLinks();
void BubbleSortData();
void BubbleSortLinks();

int main()
{
	int num, pos, count,val;
	char subopt;
	int opt;
	while(1)
	{
		printf("----------------------\n");
		printf("Select the option\n");
		printf("0.Exit\n1.Add at Beginning\n2.Delete at Beginning\n3.Display\n4.Count\n5.Search\n6.Delete Entire List\n7.Add at last\n8.Delete at last\n");
		printf("9.add after a node\n10.delete particular node\n11.Add before a Node\n12.Reverse List\n13.Create a list\n14.Swap two nodes (data)\n15.Swap two nodes (links)\n16.Sortings\n");
		__fpurge(stdin);
		scanf("%d",&opt);

		switch(opt)
		{
			case 0:
				printf("----------------------\n");
				printf("selected exit\n");
				exit(0);
			case 1:
				printf("----------------------\n");
				printf("Add at the beginning of the node\n");
				printf("Enter the data: ");
				scanf("%d",&num);
				addatBeg(num);
				break;
			case 2:
				printf("----------------------\n");
				printf("Delete node at beginning\n");
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
					printf("data not found in list\n");
				else
					printf("Data found at pos: %d\n",pos);
				break;
			case 6:
				printf("----------------------\n");
				printf("Delete Entire List\n");
				deleteAll();
				break;
			case 7:
				printf("----------------------\n");
				printf("Enter the num to add at last: ");
				scanf("%d",&num);
				addAtlast(num);
				break;
			case 8:
				printf("----------------------\n");
				deleteAtlast();
				break;
			case 9:
				printf("----------------------\n");
				printf("Enter node to be searched\n");
				scanf("%d",&num);
				printf("Enter data inside new node:\n");
				scanf("%d",&val);

				addAfterNode(num, val);
				break;
			case 10:
				printf("----------------------\n");
				printf("Enter node to be searched\n");
				scanf("%d",&num);

				deleteParticularNode(num);
				break;
			case 11:
				printf("----------------------\n");
				printf("Enter node to be searched\n");
				scanf("%d",&num);
				printf("Enter data inside new node:\n");
				scanf("%d",&val);
				addBeforeNode(num, val);
				break;
			case 12:
				printf("----------------------\n");
				printf("Reversing node\n");

				reverseList();
				break;
			case 13:
				printf("----------------------\n");
				printf("Creating a list\n");
				printf("Enter size of the list: ");
				scanf("%d",&num);
				create_list(num);
				break;
			case 14:
				printf("----------------------\n");
				printf("Swap data inside two nodes\n");
				printf("Swaps only data \n");
				printf("Enter node to be searched: ");
				scanf("%d",&num);
				printf("Enter node to be swapped with: ");
				scanf("%d",&val);
				Swap_data(num, val);
				break;
			case 15:
				printf("----------------------\n");
				printf("Swap data inside two nodes\n");
				printf("Swaps only data \n");
				printf("Enter node to be searched: ");
				scanf("%d",&num);
				printf("Enter node to be swapped with: ");
				scanf("%d",&val);
				Swap_Links(num, val);
				break;
			case 16:
				printf("------Sortings-----------\n");
				printf("Please Select type of sorting\n");
				printf("a.Selection Sort(exchange by data)\nb.Selection Sort(exchange by links)\nc.Bubble Sort(exchange by data)\nd.Bubble Sort(exchange by links)\ne.Merge Sort\n");
				__fpurge(stdin);
				scanf("%c",&subopt);
				switch(subopt)
				{
					case 'a':
						printf("Selection Sort (Exchange by data)\n");
						SelectionSort();
						break;
					case 'b':
						printf("Selection Sort (Exchange by links)\n");
						SelectionSortLinks();
						break;
					case 'c':
						printf("Bubble Sort (Exchange by data)\n");
						BubbleSortData();
						break;
					case 'd':
						printf("Bubble Sort (Exchange by links)\n");
						BubbleSortLinks();
						break;				
						
					default:
						printf("Invalid Option Selected\n");
						exit(0);
						
				}
				break;
				

			default:
				printf("--");
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
		printf("list is empty cannot delete\n");
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
		printf("List is empty cannot display\n");
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
		printf("List is empty\n");
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
		printf("List is empty\n");
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


void deleteAtlast()
{
	struct node *prev, *curr;

	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link == NULL)
	{
		free(head);
		head = NULL;
		printf("element deleted\n");
		return;
	}
	prev = head;
	curr = head->link;

	while( curr->link != NULL)
	{	
		prev = curr;
		curr = curr->link;
	}
	free(curr);
	prev->link = NULL;
	printf("last element deleted\n");
}



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

void deleteParticularNode(int num)
{

	struct node *curr, *prev;
	if(head == NULL)
	{
		printf("List is empty\n");
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

void reverseList()
{
	struct node *curr, *prev, *nxt;

	if(head == NULL)
	{
		printf("list is empty\n");
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

void create_list(int s)
{
	int i;
	struct node *ptr, *start = NULL, *prev , *temp;

	for(i = 0; i < s; i++)
	{
		ptr = (struct node *)malloc(1 * sizeof(struct node));
		if(ptr == NULL)
		{
			printf("Failed to allocate\n");
			return;
		}
		printf("Enter data inside node: ");
		scanf("%d",&(ptr->data));
		if(start == NULL)
			start = ptr;
		else
			prev->link = ptr;
		ptr->link = NULL;
		prev = ptr;
	}

	if(head == NULL)
	{
		head = start;
		return;
	}
	temp = head;
	while(temp-> link != NULL)
	{
		temp = temp->link;
	}
	temp->link = start;


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
		printf("List is empty\n");
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
		printf("List is empty\n");
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
//selection sort
// exchange by data
void SelectionSort()
{
	int temp;
	struct node *p, *q;
	if(head == NULL)
	{
		printf("List is empty, cannot perform swap\n");
		return;
	}
	if(head->link == NULL)
		return;
	for(p = head; p->link != NULL; p = p->link)
	{
		for(q = p->link; q != NULL; q = q->link)
		{
			if(p->data > q->data)
			{
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}
//selection sort
//exchange by links	
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
//bubble sort 
// exchange by data
void BubbleSortData()
{
	if(head == NULL)
	{
		printf("List is empty, cannot perform swap\n");
		return;
	}
	if(head->link == NULL)
		return;
	
	
	
	struct node *p,*q, *e = NULL, *s;
	int temp;
	
	for(e = NULL, p = head; p->link != NULL; e = s->link, p = p->link)
	{
		
		
		for(q = head ; q->link != e ; s = q, q = q->link )
		{
			
			if(q->data > q->link->data)
			{
				temp = q->data;
				q->data = q->link->data;
				q->link->data = temp;
			}
				
			
		
		
		}
	}
}	
//Bubble Sort Bylinks
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
	




















