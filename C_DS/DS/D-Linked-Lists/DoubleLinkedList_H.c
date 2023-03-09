#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>


struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *head = NULL;

void Display_DoubleLinked()
{
	if(head == NULL)
	{
		printf("The Double Linked List is empty\n");
		return;
	}
	struct node *temp;
	temp = head;
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}

}

void AddAtBeg(int num)
{
	struct node *ptr;
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Failed to allocate memory in heap\n");
		exit(3);
	}
	ptr->data = num;
	ptr->prev = NULL;
	if(head == NULL)
		ptr->next = NULL;
	else
	{	
		ptr->next = head;
		head->prev = ptr;  // ptr->next->prev can also be used
	}
	head = ptr;

}


void DelAtBeg()
{
	if(head == NULL)
	{
		printf("List is empty\n");
		printf("cannot delete\n");
		return;
	}
	struct node *temp;
	temp = head;
	head = temp->next;
	temp->prev = NULL;
	free(temp);
	printf("----Element deleted----\n");

}

void AddAtLast(int num)
{

	struct node *ptr, *temp;
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Failed to allocate memory in heap\n");
		exit(2);
	}
	ptr->next = NULL;
	ptr->data = num;
	if(head == NULL)
	{
		ptr->next = NULL;
		head = ptr;

		return;
	}
	temp = head;

	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = ptr;
	ptr->prev = temp;

}

void DelAtLast()
{

	if(head == NULL)
	{
		printf("The Double Linked List is empty\n");
		return;
	}

	struct node *temp;
	temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	if(head->next != NULL)
		temp->prev->next = NULL;
	else
		head = NULL;
	free(temp);

}



void AddAfterNode(int num, int val)
{
	if(head == NULL)
	{
		printf("DLinkedList is empty\n");
		return;
	}
	struct node *ptr, *temp; 
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("failed to allocate memory\n");
		exit(2);

	}
	ptr->data = val;

	/*	if(head->data == num)
		{
		if(head->next == NULL)
		{
		ptr->prev = head;
		head->next = ptr;
		ptr->next = NULL;
		return;
		}
		temp = head;

		}
		*/

	temp = head;

	while(temp->next != NULL)
	{
		if(temp->data == num)
		{
			ptr->prev = temp;
			ptr->next = temp->next;
			temp->next = ptr;
			if(temp->next != NULL)
				temp->next->prev = ptr;

			return;
		}

		temp = temp->next;
	}
	if(temp->data == num)
	{
		ptr->prev = temp;
		ptr->next = temp->next;
		temp->next = ptr;

		return;
	}
	printf("Element not found in list\n");
}
void Delete_Dlist()
{
	//deletes entire Double linked list
	if(head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	struct node *temp;
	while(head != NULL)
	{
		temp = head;
		free(temp);
		head = head->next;
	}
	printf("############ All nodes deleted #################\n");

}

void AddBeforeNode(int num, int val)
{
	if(head == NULL)
	{
		printf("The list is empty\n");
		return;
	}

	struct node *temp, *ptr;
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("failed to allocate memory\n");
		exit(4);
	}
	ptr->data = val;
	temp = head;
	while(temp != NULL)
	{
		if(temp->data == num)
		{
			if(temp == head)
			{
				ptr->prev = NULL;
				ptr->next = head;
				head->prev = ptr;
				head = ptr;

				return;
			}

			ptr->prev = temp->prev;
			ptr->next = temp;
			temp->prev = ptr;
			ptr->prev->next = ptr;


			return;
		}
		temp = temp->next;
	}
	printf("element not found inside nodes\n");
}

int  CountNodes()
{	
	int count = 0;
	struct node *temp = head;
	if(temp == NULL)
		return 0;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;

}

void CreateList(int *arr, int n)
{
	int i;
	struct node *ptr, *start = NULL, *Previous, *temp;
	for(i = 0; i < n; i++)
	{
		ptr = (struct node *)malloc(1 * sizeof(struct node));
		if(ptr == NULL)
		{
			printf("failed to allocate memory in heap\n");
			exit(1);
		}
		ptr->data = arr[i];
		ptr->next = NULL;
		if(start == NULL) // if this is the first node in the list
		{
			ptr->prev = NULL;
			start = ptr;
			Previous = ptr;
		}
		else
		{
			ptr->prev = Previous; 
			Previous->next = ptr;
			Previous = ptr;
		}
		//Previous = ptr;
	}
	printf("address of last: %p\n", ptr->next);
	if(head == NULL)
	{
		head = start;
		return;
	}
	temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = start;
	start->prev = temp;
}	
void Reverse_DL()
{
	if(head == NULL)
	{
		printf("The list is empty\n");
		printf("Cannot reverse\n");
		return;
	}
	struct node *curr, *nxt, *temp;
	curr = head;
	while(curr != NULL)
	{
		nxt = curr->next;
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		if(curr->prev == NULL)
			head = curr;

		curr = nxt;
	}
}

void DeleteDuplicate_DL()
{

	if(head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	struct node *temp, *p, *q;

	for(p = head; p != NULL; p = p->next)
	{
		for(q = p->next; q != NULL; q = q->next)
		{
			if(p->data == q->data)
			{
				q->prev->next = q->next;
				if(q->next != NULL)
					q->next->prev = q->prev;
				temp = q;
				q = q->prev; //
				free(temp);
			}
		}
	}
}
void SelectionSort()
{
	// traversal is always from left to right in selection sort
	if(head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	if(head->next == NULL)
		return;
	struct node *p, *q, *temp;
	for(p = head; p->next != NULL; p = p->next)
	{
		for(q = p->next; q != NULL; q = q->next)
		{


			if(p->data > q->data)
			{

				if(p->next == q)// if adjacent nodes
				{
					if(q->next != NULL)
						q->next->prev = p;
					temp = p->prev;
					if(p != head)
						p->prev->next = q;
					p->prev = q;
					p->next = q->next;
					q->next = p;
					if(p == head)
					{
						head = q;
					}
					q->prev = temp;
				}

				else// non adjacent nodes
				{
					p->next->prev = q;
					if(q->next != NULL)
						q->next->prev = p;
					if(p != head)
						p->prev->next = q;
					q->prev->next = p;
					if(p == head)
						head = q;


					temp = p->next;
					p->next = q->next;
					q->next = temp;
					temp = p->prev;
					p->prev = q->prev;
					q->prev = temp;

				}


				temp = p;
				p = q;
				q = temp;
			}
		}
		//----------//

	}
	//----------------//
}

void SwapNodes_Data(int s1, int s2)
{
	if(head == NULL)
	{
		printf("the list is empthy\n");
		return;
	}
	if(head->next == NULL)
	{
		printf("Only one element is present\n");
		return;
	}
	struct node *p, *q;
	int temp;
	p = q = head;
	while(p != NULL)
	{
		if(p->data == s1)
			break;
		p = p->next;
	}
	while(q != NULL)
	{
		if(q->data == s2)
			break;
		q = q->next;
	}
	if((p== NULL) || (q == NULL))
	{
		printf("Element(s) not found\n");
		printf("Cannot swap\n");
		return;
	}
	temp = p->data;;
	p->data = q->data;
	q->data = temp;
}

void SwapNodes_Links(int s1, int s2)
{
	struct node *temp, *p, *q;
	int pos1 = 0, pos2 = 0;
	if(head == NULL)
	{
		printf("the list is empthy\n");
		return;
	}
	if(head->next == NULL)
	{
		printf("Only one element is present\n");
		return;
	}

	p = q = head;
	while(p != NULL)
	{

		if(p->data == s1)
			break;
		p = p->next;
		pos1++;
	}
	while(q != NULL)
	{
		if(q->data == s2)
			break;
		q = q->next;
		pos2++;
	}
	if((p== NULL) || (q == NULL))
	{
		printf("Element(s) not found\n");
		printf("Cannot swap\n");
		return;
	}
	if(pos1 > pos2)
	{
		temp = p;
		p = q;
		q = temp;
	} 
	if(p->next == q)
	{
		if(q->next != NULL)
			q->next->prev = p;
		temp = p->prev;
		if(p != head)
			p->prev->next = q;
		p->prev = q;
		p->next = q->next;
		q->next = p;
		if(p == head)
		{
			head = q;
		}
		q->prev = temp;
	}
	else
	{
		if(p != head)
			p->prev->next = q;
		if(q->next != NULL)
			q->next->prev = p;
		temp = p->next;
		p->next = q->next;
		q->next = temp;

		temp->prev = q;
		q->prev->next = p;

		temp = p->prev;
		p->prev = q->prev;
		q->prev = temp;
		if(p == head)
			head = q;
	}	
}
void DeleteParticular(int num)
{
	struct node *temp;

	if(head == NULL)
	{
		printf("the list is empthy\n");
		return;
	}
	if(head->data == num)
	{
		if(head->next == NULL);
		{
			free(head);
			head = NULL;
			return;
		}
		temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
		return;
	}

	temp = head;
	while(temp != NULL)
	{
		if(temp->data == num)
		{
			temp->prev->next = temp->next;
			if(temp->next != NULL)
				temp->next->prev = temp->prev;	
			free(temp);
			return;
		}
		temp = temp->next;
	}
	printf("Element not found inside linked list\n");
}

int Search(int num)
{
	struct node *temp;
	int pos = 0;
	if(head == NULL)
	{
		printf("the list is empthy\n");
		return -1;
	}
	temp = head;
	while(temp != NULL)
	{	
		pos++;
		if(temp->data == num)
			return pos;
		temp = temp->next;
	}
	return -1;
}
void main()
{
	int opt, num, val;
	while(1)
	{
		printf("Select an option\n");
		printf("-1.Clear Screen\n 0.Exit\n1.Add at begining\n2.Delete at begining\n3.Display\n");
		printf("4.Add at last\n5.Delete at last\n6.Add After a Node\n");
		printf("7.Delete all nodes\n8.Add Before Node\n9.Count no. of nodes\n");
		printf("10.Create list\n11.Reverse\n12.Delete Duplicates\n13.Selection Sort(Links)\n");
		printf("14.Swap Nodes(by data)\n15.Delete particular node\n16.Swap Nodes(by links)\n17.Search\n");
		__fpurge(stdin);
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				printf("-----Selected exit-----\n");
				exit(0);
			case 1:
				printf("-----Add at Begining-----\n");
				printf("Enter number inside node: ");
				scanf("%d",&num);
				AddAtBeg(num);
				break;
			case 2:
				printf("-----Selected Delete at Begining-----\n");
				DelAtBeg();
				break;
			case 3:

				printf("-----Selected Display-----\n");

				Display_DoubleLinked();
				printf("\n");
				break;
			case 4:
				printf("-----Add at last-----\n");
				printf("Enter number inside node: ");
				scanf("%d",&num);
				AddAtLast(num);
				break;
			case 5:
				printf("-----Delete at last-----\n");
				DelAtLast();
				break;
			case 6:
				printf("-----Add after a node-----\n");
				printf("data to be searched: ");
				scanf("%d",&num);
				printf("data to added inside node: ");
				scanf("%d",&val);
				AddAfterNode(num, val);
				break;
			case 7:
				printf("----------delete all nodes--------\n");
				Delete_Dlist();
				break;
			case 8:
				printf("----------Add Before Node--------------\n");
				printf("data to be searched: ");
				scanf("%d",&num);
				printf("data to added inside node: ");
				scanf("%d",&val);
				AddBeforeNode(num, val);
				break;
			case 9:
				printf("------------Count no. of nodes------------\n");
				int count = CountNodes();
				printf("No. of nodes currently active: %d\n",count);
				break;
			case -1:
				printf("System clear\n");
				system("clear");
				break;	
			case 10:
				printf("--------create a list----------\n");
				int i, n;
				printf("Enter the size: ");
				scanf("%d",&n);
				int *ptr = (int *)malloc(n * sizeof(int));
				if(ptr == NULL)
					printf("Failed to allocate memory\n"), exit(2);

				for(i = 0; i < n; i++)
				{
					__fpurge(stdin);
					scanf("%d",&ptr[i]);
				}
				CreateList(ptr, n);
				break;
			case 11:
				printf("----------Reverse D-Linked List------------\n");
				Reverse_DL();
				break;
			case 12:
				printf("--------------Delete Duplicates-----------------\n");
				DeleteDuplicate_DL();
				break;
			case 13:
				printf("---------------Selection Sort-----------------------\n");
				SelectionSort();
				break;
			case 14:
				printf("--------------------Swap nodes by data--------------------\n");
				printf("Enter nodes to be changed\n");
				printf("data1: ");
				scanf("%d",&num);
				printf("data2: ");
				scanf("%d",&val);

				SwapNodes_Data(num, val);
				break;
			case 15:
				printf("---------------Delete Particular Node-------------------\n");
				printf("Enter the node to delete:");
				scanf("%d",&num);
				DeleteParticular(num);
				break;
			case 16:
				printf("--------------------Swap nodes by links--------------------\n");
				printf("Enter nodes to be changed\n");
				printf("data1: ");
				scanf("%d",&num);
				printf("data2: ");
				scanf("%d",&val);

				SwapNodes_Links(num, val);
				break;
			case 17:
				printf("--------------------Search------------------------------------\n");
				printf("Enter the num to search inside DoubleLinkedList\n");
				printf("Enter the num: ");
				scanf("%d",&num);
				val = Search(num);
				if(val >= 1)
					printf("The Position: %d\n",val);
				else
					printf("Element not found\n");
				break;
			default:
				printf("Invalid Option Selected\n");
				printf("---------\n");
				exit(2);
				break;
		}
	}
}

