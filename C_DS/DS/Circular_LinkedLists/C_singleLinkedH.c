//---------------------circular single linked list----------------------------------//
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head = NULL;




void AddAtBeg(int num)
{
	struct node *temp;
	struct node *ptr;
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(1);
	}
	ptr->data = num;
	if(head == NULL)
	{
		head = ptr->link = ptr;
		return;
	}
	temp = head;
	while(temp->link != head)
		temp = temp->link;
	temp->link = ptr;
	ptr->link = head;
	head = ptr;
}
void AddAtLast(int num)
{

	struct node *ptr, *temp;
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("failed to allocate memory\n");
		exit(2);
	}
	ptr->data = num;
	if(head == NULL)
	{
		head = ptr->link = ptr;
		return;
	}
	temp = head;
	while(temp->link != head)
		temp = temp->link;
	temp->link = ptr;
	ptr->link = head;
}
void DelAtBeg()
{
	//circular single linked list 
	struct node *temp;
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link == head)
	{
		free(head);
		head = NULL;
		return;
	}
	temp = head;
	while(temp->link != head) //traversing list till last node
		temp = temp->link;

	temp->link = head->link; //updating last node with 2nd node's address
	temp = head;
	head = head->link;
	free(temp);

}

void DelAtLast()
{
	struct node *curr, *prev;
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link == head)
	{
		free(head);
		head = NULL;
		return;
	}
	prev = head;
	curr = head->link;
	while(curr->link != head)
	{
		prev = curr;
		curr = curr->link;
	}

	prev->link = head;
	free(curr);
}
void Display_Debug()
{
	struct node *temp;
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	temp = head;
	printf(" head: %-15p\n",temp);
	do
	{
		printf("temp: %-15p  temp->link:%-15p   temp->data: %d \n",temp, temp->link,temp->data);
		temp = temp->link;
	}while(temp != head);

}

void Display()
{
	struct node *temp;
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	temp = head;
	do
	{
		printf("%d ",temp->data);
		temp = temp->link;
	}while(temp != head);
	printf("\n");
}

void DeleteCircular()//deletes entire list 
{

	struct node *temp, *end;
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link == head)
	{
		free(head);
		head = NULL;
		return;
	}
	end = head;//taking backup of head
	do
	{
		temp = head;
		head = head->link;
		free(temp);
	}while(head != end);
	head = NULL;
}
int Nodecount()
{
	int count = 0;
	struct node *temp;
	if(head == NULL)
	{
		printf("List is empty\n");
		return 0;
	}

	temp = head;
	do
	{
		count++;
		temp = temp->link;
	}while(temp != head);
	return count;
}
int searchNodes(int num)
{
	int pos = 0;
	struct node *temp;
	if(head == NULL)
	{
		printf("List is empty\n");
		return 0;
	}

	temp = head;
	do
	{
		pos++;	
		if(num == temp->data)
			return pos;

		temp = temp->link;
	}while(temp != head);
	return -1;
}
void AddAfterNode(int node, int data)
{

	if(head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(2);
	}
	ptr->data = data;
	temp = head;
	do
	{
		if(temp->data == node)
		{
			ptr->link = temp->link;
			temp->link = ptr;
			return;
		}
		temp = temp->link;
	}while(temp != head);
	printf("Element not found\n");
}

void DeleteParticular(int num)
{
	struct node *prev, *curr, *temp, *temp2;
	if(head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	if(head->data == num)
	{
		if(head->link == head)
		{
			free(head);
			head = NULL;
			return;
		}
		temp= temp2 = head;
		head = head->link;
		while(temp2->link != temp)
			temp2 = temp2->link;
		temp2->link = head;
		free(temp);
		return;

	}


	prev = head;
	curr = head->link;
	do
	{
		if(curr->data == num)
		{

			prev->link = curr->link;
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->link;
	}while(curr != head);

	printf("element not found\n");
}
void AddBeforeNode(int node, int num)
{

	if(head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	struct node *ptr, *prev, *curr, *temp;
	ptr = malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("failed to allocate\n");
		return;
	}
	ptr->data = num;


	if(head->data == node)
	{
		if(head->link == head)
		{
			head->link = ptr;
			ptr->link = head;
			head = ptr;
			return;
		}
		temp  = head;
		while(temp->link != head)
			temp = temp->link;
		ptr->link = head;
		temp->link = ptr;
		head = ptr;
		return;
	}
	prev = head;
	curr = head->link;
	do
	{
		if(curr->data == node)
		{
			ptr->link = prev->link;
			prev->link = ptr;
			return;
		}
		prev = curr;
		curr = curr->link;
	}while(curr != head);
	printf("Element not found\n");


}

void ReverseCircular()
{
	if(head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	if(head->link == head)
		return;
	struct node *curr, *prev, *next;
	curr = head;
	prev = NULL;
	do
	{
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
		printf("curr->data: %d\n",curr->data);

	}while(curr != head);
	printf("curr->data: %d\n",curr->data);

	head->link = prev;
	head = prev;


}
void CreateList(int *arr, int n)
{
	struct node *ptr,*prev;
	int i;
	for(i = 0; i < n; i++)
	{
		ptr = (struct node *)malloc(1 * sizeof(struct node));
		if(ptr == NULL)
		{
			printf("failed to allocate\n");
			exit(2);
		}
		ptr->data = arr[i];
		if(head == NULL)
		{

			head = ptr;
			ptr->link = head;

		}
		else
		{
			ptr->link = prev->link;
			prev->link = ptr;
		}
		prev = ptr;

	}
}
void SwapNodesLinks(int n1, int n2)
{
	if(n1 == n2)
		return;
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link == head)
	{
		printf("List contains only single element\n");
		return;
	}
	struct node *temp, *p, *q, *r, *s, *last;
	int pos1 = 0, pos2 = 0;
	int f1 = 0, f2 = 0;
	p = q = head;
	do
	{
		pos1++;
		if(p->data == n1)
		{
			printf("p->data: %d\n",p->data);
			f1 = 1;
			break;
		}
		r = p;
		p = p->link;
	}while(p != head);
	do
	{
		pos2++;
		if(q->data == n2)
		{
			printf("q->data: %d\n",q->data);
			f2 = 1;
			break;
		}
		s = q;
		q = q->link;
	}while(q != head);
	//to find last node
	last = head;
	//while(last->link != head)
	//last = last->link;
	if( (f1 == 0) || (f2 == 0) )
	{
		printf("Element(s) not found\n");
		return;
	}
	if(pos1 > pos2)
	{
		temp = p;
		p = q;
		q = temp;
		temp = r;
		r = s;
		s = temp;
	}

	printf("p->data: %d\n",p->data);
	printf("q->data: %d\n",q->data);
	if(p->link == q)
	{	//adjacent nodes

		p->link = q->link;
		q->link = p;
		if(p == head)
		{

			head = q;
			temp = last;
			while(temp->link != last)
				temp = temp->link;
			temp->link = head;
		}
		else 
			r->link = q;
	}
	else
	{
		temp = p->link;
		p->link = q->link;
		q->link = temp;
		s->link = p;
		if(p == head)
		{
			temp = head;
			while(temp->link != head)
				temp = temp->link;
			temp->link = q;
			head = q;
		}
		else
			r->link = q;
	}


}
void SelectionSortLinks()
{
	struct node *p,*q,*r,*s;
	struct node *temp, *last = head;
	if(head == NULL)
	{
		printf("List is empty, cannot perform swap\n");
		return;
	}
	if(head->link == head)
		return;
	for(p = head;    p->link != head;   r = p, p = p->link)
	{	
		for(q = p->link; q != head; s = q, q = q->link)
		{
			if(p->data > q->data)
			{
				//checking if adjacent nodes or not
				if(p->link == q)
				{	//adjacent nodes

					p->link = q->link;
					q->link = p;
					if(p == head)
					{

						head = q;
						temp = last;
						while(temp->link != last)
							temp = temp->link;
						temp->link = head;
					}
					else 
						r->link = q;
				}
				else
				{
					temp = p->link;
					p->link = q->link;
					q->link = temp;
					s->link = p;
					if(p == head)
					{
						temp = head;
						while(temp->link != head)
							temp = temp->link;
						temp->link = q;
						head = q;
					}
					else
						r->link = q;
				}


				temp = p;
				p = q;
				q = temp;

			}
		}	
	}
}
void BubbleSortLinks()
{
	if(head == NULL)
	{
		printf("List is empty, cannot perform swap\n");
		return;
	}
	if(head->link == head)
		return;



	struct node *p,*q, *e = head, *s, *r, *temp, *last = head;

	for(e = head; head->link != e; e = p)
	{
		for(r = p = head; p->link != e; r = p, p = p->link)
		{
			q = p->link;
			if(p->data > q->data)
			{
				//checking if adjacent nodes or not
				//adjacent nodes
					//adjacent nodes
				printf("---entered---\n");
					p->link = q->link;
					q->link = p;
					if(p == head)
					{

						temp = head;
						while(temp->link != head)
							temp = temp->link;
						temp->link = q;
						head = q;
						e = head;
						//last = temp->link;
					}
					else 
						r->link = q;
			        temp = p;
				p = q;
				q = temp;		
				
			}

				
				//printf("p->data = %d\n",p->data);
				//sleep(3);


				//------------//
						
		}
	}
}

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
		printf("9.add after a node\n10.delete particular node\n11.Add before a Node\n12.Reverse List\n13.Create a list\n14.Swap two nodes (links)\n15.Sortings\n");
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
				AddAtBeg(num);
				break;
			case 2:
				printf("----------------------\n");
				printf("Delete node at beginning\n");
				DelAtBeg();
				break;
			case 3:
				printf("----------------------\n");
				printf("Displaying data from all existing nodes\n");
				Display();
				printf("\n------------------------\n");
				Display_Debug();
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
				pos = searchNodes(num);
				if(pos <= 0)
					printf("data not found in list\n");
				else
					printf("Data found at pos: %d\n",pos);
				break;
			case 6:
				printf("----------------------\n");
				printf("Delete Entire List\n");
				DeleteCircular();
				break;
			case 7:
				printf("----------------------\n");
				printf("Enter the num to add at last: ");
				scanf("%d",&num);
				AddAtLast(num);
				break;
			case 8:
				printf("----------------------\n");
				DelAtLast();
				break;
			case 9:
				printf("----------------------\n");
				printf("Enter node to be searched\n");
				scanf("%d",&num);
				printf("Enter data inside new node:\n");
				scanf("%d",&val);

				AddAfterNode(num, val);
				break;
			case 10:
				printf("----------------------\n");
				printf("Enter node to be searched\n");
				scanf("%d",&num);

				DeleteParticular(num);
				break;
			case 11:
				printf("----------------------\n");
				printf("Enter node to be searched\n");
				__fpurge(stdin);
				scanf("%d",&num);
				printf("Enter data inside new node:\n");
				__fpurge(stdin);
				scanf("%d",&val);
				AddBeforeNode(num, val);
				break;
			case 12:
				printf("----------------------\n");
				printf("Reversing node\n");

				ReverseCircular();
				break;
			case 13:
				printf("----------------------\n");
				printf("Creating a list\n");
				printf("Enter size of the list: ");
				scanf("%d",&num);
				int *arr = (int *)malloc(num * sizeof(int));
				if(arr == NULL)
				{
					printf("failed to allocate\n");
					exit(4);
				}
				int i;
				printf("Enter elements inside list\n");
				for(i = 0; i < num; i++)
				{
					scanf("%d",(arr+i));
				}
				CreateList(arr,num);
				break;
			case 14:
				printf("----------------------\n");
				printf("Swap links of  two nodes\n");
				printf("Enter node to be searched: ");
				scanf("%d",&num);
				printf("Enter node to be swapped with: ");
				scanf("%d",&val);
				SwapNodesLinks(num, val);
				break;/*
					 case 15:
					 printf("----------------------\n");
					 printf("Swap data inside two nodes\n");
					 printf("Swaps only data \n");
					 printf("Enter node to be searched: ");
					 scanf("%d",&num);
					 printf("Enter node to be swapped with: ");
					 scanf("%d",&val);
					 Swap_Links(num, val);
					 break;*/
			case 15:
				printf("------Sortings-----------\n");
				printf("Please Select type of sorting\n");
				printf("a.Selection Sort(exchange by links)\nb.Bubble Sort(exchange by links)\n");
				__fpurge(stdin);
				scanf("%c",&subopt);
				switch(subopt)
				{
					case 'a':
						printf("Selection Sort (Exchange by links)\n");
						SelectionSortLinks();
						break;
					case 'b':
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


