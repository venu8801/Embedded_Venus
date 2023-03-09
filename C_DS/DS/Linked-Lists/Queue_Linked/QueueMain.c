#include "QueueH.h"
struct node *front= NULL, *rear = NULL;
int main()
{
	int num, pos, count,val;
	char subopt;
	int opt;
	while(1)
	{
		printf("----------------------\n");
		printf("Select the option\n");
		printf("0.Exit\n1.Insert\n2.Delete\n3.Display\n4.Count\n5.Search\n6.Delete Entire Queue\n");
		printf("7.Create Queue\n");
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
				//add at last using rear
				insert_Queue(num);
				break;
			case 2:
				printf("----------------------\n");
				printf("Delete node at beginning\n");
				delete_Queue();
				break;
			case 3:
				printf("----------------------\n");
				printf("Displaying data from all existing nodes\n");
				display_Queue();
				break;
			case 4:
				printf("----------------------\n");
				printf("----count of all nodes\n");
				count = Nodecount_Queue();
				printf("No. of nodes: %d\n",count);
				break;
			case 5:
				printf("----------------------\n");
				printf("Search in nodes\n");
				printf("Enter the element to be searched: ");
				scanf("%d",&num);
				pos = Nodesearch_Queue(num);
				if(pos <= 0)
					printf("data not found in queue\n");
				else
					printf("Data found at pos: %d\n",pos);
				break;
			case 6:
				printf("----------------------\n");
				printf("Delete Entire queue\n");
				Delete_full_Queue();
				break;
			case 7:
				printf("----------------------\n");
				printf(" Create a queue\n");
				printf("Enter size of the list: ");
				scanf("%d",&num);
				int *ptr = (int *)malloc(1 * sizeof(int));
				if(ptr == NULL)
				{
					printf("failed to allocate memory for array\n");
					exit(1);
				}
				printf("Enter elements into list to be added to queue\n");
				for(i = 0; i < num; i++)
					scanf("%d",&ptr[i]);
					
				Create_Queue(ptr, num);
				break;
				
			
			
				

			default:
				printf("--");
				printf("Invalid option selected\n");
				exit(2);







		}
		printf("----------------------\n");
	}
}
