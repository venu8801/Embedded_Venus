#include "Stack_Header.h"
#include<stdio.h>
#include<stdlib.h>
struct node *head = NULL;
int main()
{
	int num, pos, count,val;
	int opt;
	while(1)
	{
		printf("----------stack------------\n");
		printf("Select the option\n");
		printf("0.Exit\n1.PUSH\n2.POP\n3.Display\n4.Count\n5.Search\n6.Delete Entire Stack\n");
		printf("7.add after a node\n8.delete particular node\n9.Add before a Node\n10.Reverse Stack\n11.Create Stack\n12.Swap two nodes (data)\n13.Swap two nodes (links)\n");
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
				

			default:
				printf("Invalid option selected\n");
				exit(2);







		}
		printf("----------------------\n");
	}
}

