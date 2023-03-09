#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

 ;
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
	struct node *ptr, *start = NULL, *prev;
	for(i = 0; i < n; i++)
	{
		ptr = (struct node *)malloc(1 * sizeof(struct node));
		if(ptr == NULL)
		{
			printf("failed to allocate memory in heap\n");
			exit(1);
		}
		ptr->data = arr[i];
	
		if(start == NULL) // if this is the first node in the list
		{
			ptr->prev = NULL;
			start = ptr;

		}
		else
			ptr->prev = prev; 
			prev->next = ptr;
		prev = ptr;
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
			printf("10.Create list\n")
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
				default:
					printf("Invalid Option Selected\n");
					printf("---------\n");
					exit(2);
					break;
			}
		}
	}

