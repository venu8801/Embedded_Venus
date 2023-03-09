#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>


struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *front = NULL, *rear = NULL;
//Delete operation in queue double linked queue
// del at beg
void Delete_Queue()
{
	if(front == NULL) // queue is empty
	{
		printf("queue is empty\n");
		printf("cannot delete\n");
		return;
	}
	if(front == rear) // queue contains only one node
	{
		free(front);
		front = rear = NULL;
		return;
	}
	//queue contains multiple nodes
	struct node *temp;
	temp = front;
	front = front->next;
	front->prev = NULL;
	free(temp);
	printf("----Element deleted----\n");

}
//queue double linked queue
//add at last
void Insert_Queue(int num)
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
	if(rear == NULL)
	{
		ptr->next = NULL;
		ptr->prev = NULL;
		front = rear = ptr;
		return;
	}

	rear->next = ptr;
	ptr->prev = rear;
	rear = ptr;	

}
//display entire queue
void Display_Queue_Debug()
{
	if(front == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	struct node *temp;
	temp = front;
	printf("front: %-15p\n", front);
	while(temp != NULL)
	{
		printf("prev:%-15p node:%-15p  next:%-15p data:%d \n",temp->prev, temp, temp->next, temp->data);

		temp = temp->next;
	}
	printf("rear: %-15p\n", rear);

}
void Display_Queue()
{
	if(front == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	struct node *temp;
	temp = front;
	printf("front: %-15p\n", front);
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\nrear: %-15p\n", rear);

}


void Delete_allQueue()
{
	//deletes entire Double linked queue
	if(front == NULL)
	{
		printf("The Queue is empty, cannot delete\n");
		return;
	}
	struct node *temp;
	while(front != NULL)
	{
		temp = front;
		front = front->next;
		free(temp);
	}
	rear = NULL;
	printf("############ All nodes deleted #################\n");

}




int  CountNodes()
{	
	int count = 0;
	struct node *temp = front;
	if(front == NULL)
		return 0;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;

}

void Reverse_DL_Queue()
{
	if(front == NULL) // if queue is empty
	{
		printf("The queue is empty\n");
		printf("Cannot reverse\n");
		return;
	}
	if(front == rear) // if only one node exists
	{
		printf("\tOnly one node exists\n");
		return;
	}
	struct node *curr, *nxt, *temp;
	curr = front;
	while(curr != NULL)
	{
		nxt = curr->next;
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = nxt;
	}
	temp = front;
	front = rear;
	rear = temp;
}

//deletes duplicates in queue
void DeleteDuplicate_DL_Queue()
{

	if(front == NULL)//if queue is empty
	{
		printf("The queue is empty\n");
		return;
	}
	if(front == rear)//if only one node exists
	{
		printf("\t only one node exists\n");
		return;
	}
	struct node *temp, *p, *q;

	for(p = front; p != NULL; p = p->next)
	{
		for(q = p->next; q != NULL; q = q->next)
		{
			if(p->data == q->data)
			{
				q->prev->next = q->next;
				if(q->next != NULL)
					q->next->prev = q->prev;
				else // if it is last node update the rear pointer
					rear = q->prev;
				temp = q;
				q = q->prev; 
				free(temp);
			}
		}
	}
}

//deletes a particular node in queue
void DeleteParticular_Queue(int num)
{
	struct node *temp;

	if(front == NULL)
	{
		printf("the queue is empthy\n");
		return;
	}
	//if it is first node
	if(front->data == num)
	{
		if(front->next == NULL); //if it is single node
		{
			free(front);
			front = rear = NULL;
			return;
		}
		//first node but contains multiple nodes
		temp = front;
		front = front->next;
		front->prev = NULL;
		free(temp);
		return;
	}

	temp = front;
	while(temp != NULL)
	{
		if(temp->data == num)
		{
			temp->prev->next = temp->next;
			if(temp != rear)
				temp->next->prev = temp->prev;
			else// if last node update rear with prev node of last node
				rear = temp->prev;	
			free(temp);
			return;
		}
		temp = temp->next;
	}
	printf("Element not found inside linked queue\n");
}


int Search(int num)
{
	struct node *temp;
	int pos = 0;
	if(front == NULL)
	{
		printf("the queue is empthy\n");
		return -1;
	}
	temp = front;
	while(temp != NULL)
	{	
		pos++;
		if(temp->data == num)
			return pos;
		temp = temp->next;
	}
	return -1;
}
//creates a queue adds to existing queue if present
void Create_Queue(int *arr, int n)
{
	int i;
	struct node *ptr, *prev;
	for(i = 0; i < n; i++)
	{	
		ptr = (struct node *)malloc(1 * sizeof(struct node));
		if(ptr == NULL)
		{
			printf("failed to allocate memory\n");
			exit(2);
		}
		ptr->data = arr[i];
		ptr->next = NULL;
		if(rear == NULL)
		{
			front = rear = ptr;
			ptr->prev = NULL;
		}
		else
		{
			ptr->prev = rear;
			rear->next = ptr;
			rear = ptr;
		}

	}
}
//swap nodes by links in queue
void SwapNodes_Queue(int s1, int s2)
{
	printf("Entered function\n");
	if(s1 == s2)
		return;
	if(front == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(front ==  rear)
		return;
	struct node *temp, *p, *q;
	int pos1= 0, pos2 = 0;
	p = q = front;
	while(p != NULL)
	{
		pos1++;
		if(p->data == s1)
			break;
		p = p->next;
	}
	while(q != NULL)
	{
		pos2++;
		if(q->data == s2)
			break;
		q = q->next;
	}

	if( (p == NULL) || (q == NULL) )
	{
		printf("Element(s) not found in the queue\n");
		return;
	}
	if(pos1 > pos2)
	{
		temp = p;
		p = q;
		q = temp;
	}
	if(p->next == q) //adjacent nodes
	{
		printf("---\n");
		p->next = q->next;
		if(p != front)	
			p->prev->next = q;
		else
			front  = q;
		q->next = p;
		if(q != rear)
			p->next->prev = p;
		else
			rear = p;
		temp = p->prev;
		p->prev = q;
		q->prev = temp;

	}
	else// non adjacent nodes
	{
		printf("---\n");
		temp = p->prev;
		p->prev = q->prev;
		q->prev = temp;

		temp = p->next;
		p->next = q->next;
		q->next = temp;

		if(p != front)
			q->prev->next = q;
		else 
			front = q;
		if(q != rear)
			p->next->prev = p;
		else
			rear = p;


		q->next->prev = q;

		p->prev->next = p;

	}
}



void SelectionSort()
{
	// traversal is always from left to right in selection sort
	if(front == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	if(front == rear)
		return;
	struct node *p, *q, *temp;
	for(p = front; p->next != NULL; p = p->next)
	{
		for(q = p->next; q != NULL; q = q->next)
		{


			if(p->data > q->data)
			{

				if(p->next == q) //adjacent nodes
				{
					printf("---\n");
					p->next = q->next;
					if(p != front)	
						p->prev->next = q;
					else
						front  = q;
					q->next = p;
					if(q != rear)
						p->next->prev = p;
					else
						rear = p;
					temp = p->prev;
					p->prev = q;
					q->prev = temp;

				}
				else// non adjacent nodes
				{
					printf("---\n");
					temp = p->prev;
					p->prev = q->prev;
					q->prev = temp;

					temp = p->next;
					p->next = q->next;
					q->next = temp;

					if(p != front)
						q->prev->next = q;
					else 
						front = q;
					if(q != rear)
						p->next->prev = p;
					else
						rear = p;


					q->next->prev = q;

					p->prev->next = p;

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
void BubbleSort_Queue()
{
	if(front == NULL)
		return;
	if(front == rear)
		return;
	struct node *p, *q, *temp, *e;

	for(p = front, e = NULL; front->next != e; e = q)
	{
		for( p = front ; p->next != e; p = p->next)
		{
			q = p->next;
			if(p->data > q->data)
			{



				printf("---\n");
				p->next = q->next;
				if(p != front)	
					p->prev->next = q;
				else
					front  = q;
				q->next = p;
				if(q != rear)
					p->next->prev = p;
				else
					rear = p;
				temp = p->prev;
				p->prev = q;
				q->prev = temp;


				temp = p;
				p = q;
				q = temp;
			}
		
		}
	}
}
void main()	
{
	int opt, num, val;
	while(1)
	{	printf("---------------------------------Queue------------------------------------\n");
		printf("Select an option\n");
		printf("-1.Clear Screen\n 0.Exit\n1.Insert\n2.Delete\n3.Display\n");
		printf("4.Delete Entire Queue\n5.Count no. of nodes\n");
		printf("6.Create Queue\n7.Reverse\n8.Delete Duplicates\n9.Delete Particular\n10.Search\n11.Swap Nodes (exchange by Links)\n");
		printf("12.Selection Sort(links)\n13.Bubble Sort (links)");
		__fpurge(stdin);
		scanf("%d",&opt);
		switch(opt)
		{
			case -1:
				printf("System clear\n");
				system("clear");
				break;
			case 0:
				printf("-----Selected exit-----\n");
				exit(0);
			case 1:
				printf("-----Insert-----\n");
				printf("Enter number inside node: ");
				__fpurge(stdin);
				scanf("%d",&num);
				Insert_Queue(num);
				break;
			case 2:
				printf("-----Selected Delete-----\n");
				Delete_Queue();
				break;
			case 3:

				printf("-----Selected Display-----\n");

				Display_Queue();
				printf("\n");
				break;
			case 4:
				printf("----------delete all nodes--------\n");
				Delete_allQueue();
				break;
			case 5:
				printf("------------Count no. of nodes------------\n");
				int count = CountNodes();
				printf("No. of nodes currently active: %d\n",count);
				break;

			case 6:
				printf("--------create Queue----------\n");
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
				Create_Queue(ptr, n);
				break;
			case 7:
				printf("----------Reverse D-Linked List------------\n");
				Reverse_DL_Queue();
				break;
			case 8:
				printf("--------------Delete Duplicates-----------------\n");
				DeleteDuplicate_DL_Queue();
				break;
			case 9:
				printf("---------------Delete Particular Node-------------------\n");
				printf("Enter the node to delete:");
				scanf("%d",&num);
				DeleteParticular_Queue(num);
				break;
			case 10:
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

			case 11:
				printf("--------------------Swap nodes by links--------------------\n");
				printf("Enter nodes to be changed\n");
				printf("Node-data1: ");
				scanf("%d",&num);
				printf("Node-data2: ");
				scanf("%d",&val);

				SwapNodes_Queue(num, val);
				break;

			case 12:
				printf("---------------Selection Sort-----------------------\n");
				SelectionSort();
				break;
			case 13:
				printf("---------------Bubble Sort-----------------------\n");
				BubbleSort_Queue();
				break;
				/*case 14:
				  printf("--------------------Swap nodes by data--------------------\n");
				  printf("Enter nodes to be changed\n");
				  printf("data1: ");
				  scanf("%d",&num);
				  printf("data2: ");
				  scanf("%d",&val);

				  SwapNodes_Data(num, val);
				  break;

				  case 16:
				  printf("--------------------Swap nodes by links--------------------\n");
				  printf("Enter nodes to be changed\n");
				  printf("data1: ");
				  scanf("%d",&num);
				  printf("data2: ");
				  scanf("%d",&val);

				  SwapNodes_Links(num, val);
				  break;*/

			default:
				printf("Invalid Option Selected\n");
				printf("---------\n");
				exit(2);
				break;
		}
	}
}

