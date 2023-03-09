//---------------------circular single linked list----------------------------------//

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
	while(temp->link != head)
		temp = temp->link;
	temp->link = head->link;
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

void Display()
{
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
	do
	{
		printf("%d ",temp->data);
		temp = temp->link;
	}while(temp != head);

}

void DeleteCircular()
{
	
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
	do
	{
		head = head->link;
		free(temp);
	}while(head->link != temp);
	head = NULL;
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
				break;
			/*case 4:
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
				
			*/
			default:
				printf("--");
				printf("Invalid option selected\n");
				exit(2);







		}
		printf("----------------------\n");
	}
}

