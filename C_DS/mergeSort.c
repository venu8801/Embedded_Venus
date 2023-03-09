#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node
{
	int data;
	struct node *link;
};
void Display(struct node *ptr);
struct node * create_Merge( struct node *ptr,int *iptr, int n);
void MergeSort(struct node *p1, struct node *p2);
	
struct node *head1 = NULL,*head2 = NULL,*head3 = NULL;



int main()
{	
	int N1,N2;
	printf("Enter the size of 1st linked list: ");
	__fpurge(stdin);

	scanf("%d",&N1);
	printf("Enter elements inside 1st list\n");
	int *ptr = (int *)malloc(N1 * sizeof(int));
	if(ptr == NULL)
	{
		printf("Failed to allocate memory in heap\n");
		exit(2);
	}
	int i;
	for (i = 0; i < N1; i++)
	{
		scanf("%d",&ptr[i]);
	}
	 head1 = create_Merge(head1, ptr, N1);
	 
	/*-----------------------------------------------*/
	
	__fpurge(stdin);
	printf("Enter the size of  2nd linked list: ");
	scanf("%d",&N2);
	printf("Enter elements inside 2nd list\n");
	ptr = (int *)malloc(N2 * sizeof(int));
	if(ptr == NULL)
	{
		printf("Failed to allocate memory in heap\n");
		exit(2);
	}
	
	for (i = 0; i < N2; i++)
	{
		scanf("%d",&ptr[i]);
	}
	head2 = create_Merge(head2, ptr, N2);
		/*-----------------------------------------------*/
		printf("----------\n");
	Display(head1);
	printf("----------\n");
	Display(head2);
	MergeSort(head1,head2);
	printf("\n");
		printf("----------\n");
	printf("After merge sort:\n");
	printf("---------------\n");

	Display(head3);
			
}
void Display(struct node *ptr)
{
	struct node *temp;
	temp = ptr;
	printf("displaying elements inside\n");
	while (temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}	
	
struct node * create_Merge( struct node *ptr, int *iptr, int n)
{
		int i;
		struct node *start = NULL, *temp, *prev ;
		for (i = 0; i < n; i++)
		{
			struct node *Nptr = (struct node *)malloc(1 * sizeof(struct node));
			if (Nptr == NULL)
			{
				printf("Failed to allocate memory in heap\n");
				exit(1);
			}
			
			Nptr->data = iptr[i];
			Nptr->link = NULL;
			
			if(start == NULL)
				start = Nptr;
			else
				prev->link = Nptr;
			prev = Nptr;

			
		}
		if(ptr == NULL)
		{
			ptr = start;
			return ptr;
		}
		temp = ptr;
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = start;	
}	
	
void MergeSort(struct node *p1, struct node *p2)	
{
	struct node *ptr, *start = NULL, *prev;

	for(    ; (p1 != NULL) && (p2 != NULL) ; )
	{
	
		ptr = (struct node *)malloc(1 * sizeof(struct node));	
			if(ptr == NULL)
			{
				printf("Failed to allocate memory in heap\n");
				exit(1);
			}
			
		if(p1->data == p2->data)
		{
			
			ptr->data = p1->data;
			ptr->link = NULL;
			if(start == NULL)
				start = ptr;
			else
				prev->link = ptr;
			prev = ptr;
			p1 = p1->link;
			p2 = p2->link;
		}
		else if(p1->data < p2->data)
		{
			
			ptr->data = p1->data;
			ptr->link = NULL;
			if(start == NULL)
				start = ptr;
			else
				prev->link = ptr;
			prev = ptr;
			p1 = p1->link;
		}
		else
		{
			
			ptr->data = p2->data;
			ptr->link = NULL;
			if(start == NULL)
				start = ptr;
			else
				prev->link = ptr;
			prev = ptr;
			p2 = p2->link;
		}
	}
		// add remaining elements(if any) to the newlist from list1
		for(p1 ; p1 != NULL; p1 = p1->link)
		{
			ptr = (struct node *)malloc(1 * sizeof(struct node));	
			if(ptr == NULL)
			{
				printf("Failed to allocate memory in heap\n");
				exit(1);
			}
			ptr->data = p1->data;
			ptr->link = NULL;
			
			prev->link = ptr;	
			prev = ptr;
			
			
		}
		// adding remaining elements (if any) to new list from list2				
		for(p2 ; p2 != NULL; p2 = p2->link)
		{
			ptr = (struct node *)malloc(1 * sizeof(struct node));	
			if(ptr == NULL)
			{
				printf("Failed to allocate memory in heap\n");
				exit(1);
			}
			ptr->data = p2->data;
			ptr->link = NULL;
			
			prev->link = ptr;	
			prev = ptr;
			
		}
	head3 = start;
}
		
	
	
	
	
	
	
	
	
	
	
	
