//------------------------------------circular double linked list------------------------------//
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

/*----------structure definition------------*/
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head = NULL;

void AddAtBeg(int num)
{
	struct node *ptr;
	ptr = (struct node*)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("failed to allocate memory in heap\n");
		exit(2);
	}
	ptr->data = num;
	if(head == NULL)
	{
		head = ptr;
		ptr->prev = head;
		ptr->next = head;
		return;
	}
	head->prev->next = ptr;
	ptr->prev = head->prev;
	head->prev = ptr;
	ptr->next = head;
	
	head = ptr;
}
void AddAtLast(int num)
{
	struct node *ptr;
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(2);
	}
	ptr->data = num;
	if(head == NULL)
	{
		head = ptr;
		ptr->prev = head;
		ptr->next = head;
		return;
	}
	head->prev->next = ptr;
	ptr->next = head;
	ptr->prev = head->prev;
	head->prev = ptr;
}

void DelAtBeg()
{
	if(head == NULL)
	{
		printf("Circular linked list is empty\n");
		return;
	}
	if(head->next == head)
	{
		free(head);
		head = NULL;
		return;
	}
	struct node *temp;
	head->prev->next = head->next;
	head->next->prev = head->prev;
	temp = head;
	head = head->next;
	free(temp);
}	
void DelAtLast()
{
	if(head == NULL)
	{
		printf("Circular linked list is empty\n");
		return;
	}
	if(head->next == head)
	{
		free(head);
		head = NULL;
		return;
	}
	struct node *temp;
	temp = head->prev;
	head->prev->prev->next = head;
	head->prev = head->prev->prev;
	free(temp);
}
void Display_Debug()
{
	if(head == NULL)
		return;
	struct node *temp;
	printf("------------------------------------------------\n");
	temp = head;
	printf("head:%-15p\n",head);
	do
	{
		printf("prev:%-15p   node:%15p  next:%-15p  data:%d\n",temp->prev, temp, temp->next, temp->data);
		temp = temp->next;
	}while(temp != head);
	printf("------------------------------------------------\n");
}	
void Display()
{
	struct node *temp;
	if(head == NULL)
	{
		printf("Circular linked list is empty\n");
		return;
	}
	temp = head;
	do
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}while(temp != head);
	printf("\n");
}
int search(int num)
{
	if(head == NULL)
	{
		printf("Circular DL list is empty\n");
		return -1;
	}
	struct node *temp;
	int pos = 0;
	temp = head;
	do
	{
		pos++;
		if(temp->data == num)
			return pos;
		temp = temp->next;
	}while(temp != head);
	return pos;
}

int Nodecount()
{
	if(head == NULL)
	{
		printf("Circular DL list is empty\n");
		return 0;
	}
	struct node *temp;
	int pos = 0;
	temp = head;
	do
	{
		pos++;
		temp = temp->next;
	}while(temp != head);
	return pos;
}
void CreateList_Circular(int *arr, int s)
{
	int i;
	struct node *ptr;
	for(i = 0; i < s; i++)
	{
		ptr = (struct node *)malloc(1 * sizeof(struct node));
		if(ptr == NULL)
		{
			printf("failed to allocate memory\n");
			exit(2);
		}
		ptr->data = arr[i];
		if(head == NULL)
		{
			head = ptr;
			ptr->prev = head;
			ptr->next = head;
			
		}
		else
		{
			head->prev->next = ptr;
			ptr->prev = head->prev;
			ptr->next = head;
			head->prev = ptr;
		}
	}
}
void DeleteAll_Circular()
{
	if(head == NULL)
	{
		printf("Circular DL list is empty\n");
		return;
	}
	if(head->next == head)
	{
		free(head);
		head = NULL;
		return;
	}
	struct node *temp, *Phead;
	Phead = head;
	do
	{
		temp = head;
		head = head->next;
		free(temp);

	}while(head != Phead);
	head = NULL;
}	
void Delete_Particular(int num)
{

	struct node *temp;
	if(head == NULL)
	{
		printf("Circular DL list is empty\n");
		return;
	}
	if(head->data == num)
	{
		if(head->next == head)
		{
			free(head);
			head = NULL;
			return;
		}
		head->prev->next = head->next;
		head->next->prev = head->prev;
		temp = head;
		head = head->next;
		free(temp);
		return;
	}
	temp = head->next;
	while(temp != head)
	{
		if(temp->data == num)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
			return;
		}
		temp = temp->next;
	}
	printf("Element not found so, not deleted\n");
}
void AddBeforeNode(int node, int num)
{
	struct node *ptr, *temp;
	if(head == NULL)
	{
		printf("Circular DL list is empty\n");
		return;
	}
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(3);
	}
	ptr->data = num;
	temp = head;
	do
	{
		if(temp->data == node)
		{
	
				temp->prev->next = ptr;
				ptr->prev = temp->prev;
				ptr->next = temp;
				temp->prev = ptr;
				return;
		}
		temp = temp->next;
	}while(temp != head);

	printf("Element not found\n");
}	

void swapNodes(int num1, int num2)
{	
	if(num1 == num2)
		return;
	if(head == NULL)
	{
		printf("D linked list is empty\n");
		return;
	}
	if(head->next == NULL)
		return;
	struct node *temp, *p, *q;
	int f1=0, f2=0,pos1=0,pos2=0;
	p = q = head;
	do
	{
		pos1++;
		if(p->data == num1)
		{
			f1 = 1;
			break;
		}
		p = p->next;
	}while(p != head);
	do
	{	pos2++;
		if(q->data == num2)
		{
			f2 = 1;
			break;
		}
		q = q->next;
	}while(q != head);
	if( (f1==0) || (f2==0) )
	{
		printf("Element(s) not found\n");
		return;
	}
	if(pos1>pos2)
	{
		temp = p;
		p = q;
		q = temp;
	}
	printf("p:%-15p 	q:%-15p\n",p,q);
	if(p->next == q)
	{	
		if(p == head)
		{
			head = q;
			p->prev->next = head;
		}
		else
			p->prev->next = q;
		if(q->next == head )
		{
			printf("t\n");
			head->prev = p; 
			//head->prev = q;
		}
		else
			q->next->prev = p;
		if( q->next != p )
		{
			//printf("CNDTION SACHI CHE!!!!!!!!!!!\n");
			q->prev = p->prev; 
			q->prev=p; 
			p->next = q->next;
		}
		else
		{
			//printf("else\n");
			head->prev = p;
		}
		q->next = p;
		p->prev = q;
		/*if(head->next->next==head)
			head->prev=head->next;
*/
	     	
		/*
		p->next = q->next;
		q->next = p;
		q->prev = p->prev;
		p->prev = q;
		q->prev->next = q;
		p->next->prev = p;
		if(p == head)
			head = q;*/
	}
	else
	{
		if(p == head)
		{
			head = q;
		}
		
		temp = p->next;
		p->next = q->next;
		q->next = temp;
		
		temp = p->prev;
		p->prev = q->prev;
		q->prev = temp;
		
		
	}
	
}
			
					



void main()
{
	int opt;
	int num, val;
	while(1)
	{
		printf("---------------------------Circular Double Linked List-------------------------------------------\n");
		printf("--options--\n");
		printf("0.exit\n1.Add at Begining\n2.Display\n3.Add at last\n4.Delete at Begining\n5.Delete at last\n6.Search\n7.Count\n");
		printf("8.Create List Circular\n9.Delete Entire List\n10.Delete Particular Node\n11.Add before node\n12.Swap Nodes(links)\n");
		printf("select an option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("-----------Add at Begining-----------------\n");
				printf("Enter the number inside node: ");
				scanf("%d",&num);
				AddAtBeg(num);
				break;
			case 2:
				printf("-----------Display-----------------\n");
				Display_Debug();
				Display();
				break;
			case 3:
				printf("-----------Add at Last-----------------\n");
				printf("Enter the number inside node: ");
				scanf("%d",&num);
				AddAtLast(num);
				break;
			case 4:
				printf("-----------Delete at Begining-----------------\n");
				DelAtBeg();
				break;
			case 5:
				printf("-----------Delete at last-----------------\n");
				DelAtLast();
				break;
			case 6:
				printf("-------------------Search-------------------------\n");
				printf("Enter the data to be searched: ");
				scanf("%d",&val);
				num = search(val);
				printf("Found at pos: %d\n",num);
				break;
			case 7:
				printf("----------------Count No. of Nodes---------------------\n");
				num = Nodecount();
				printf("No. of nodes currently active: %d\n",num);
				break;
			case 8:
				printf("----------------Create Circular List---------------------\n");
				printf("Enter size of list: ");
				scanf("%d",&num);
				int *ptr = (int *)malloc( num * sizeof(int));
				int i;
				if(ptr == NULL)
					exit(3);
				for(i = 0; i < num; i++)
				{
					__fpurge(stdin);
					scanf("%d",(ptr+i));
				}
				CreateList_Circular(ptr, num);
				break;
			case 9:
				printf("---------------------Delete Entire List-------------------------\n");
				DeleteAll_Circular();
				break;
			case 10:
				printf("---------------------Delete particular node-------------------------\n");
				printf("Enter the node to be deleted: ");
				scanf("%d",&num);
				Delete_Particular(num);
				break;
			case 11:
				printf("-----------------------Add before node--------------------------------------\n");
				printf("Enter node to be searched: ");
				scanf("%d",&num);
				printf("Enter node to be added\n");
				scanf("%d",&val);
				AddBeforeNode(num, val);
				break;
			case 12:
				printf("-----------------------swap two nodes--------------------------------------\n");
				printf("Enter node 1: ");
				scanf("%d",&num);
				printf("Enter node 2: ");
				scanf("%d",&val);
				swapNodes(num, val);
				break;
			default:
				printf("Invalid option selected\n");
				break;
		}
	}
}
