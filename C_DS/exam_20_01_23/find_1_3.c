/* program to add 1st and 2nd node 
 * */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void add_1_3(struct node *head)
{
	if(head == NULL)
	{
		printf("null recieved list is empty\n");
		return;
	}
	struct node *temp, *ptr;
	int pos = 0, sum = 0;
	temp = head;
	while(temp->link != NULL)
	{
		pos++;
		if(pos == 1 || pos == 3)
		{
			sum += temp->data;
		}
		temp = temp->link;
			

	}
	if(pos <= 2)
	{
		printf("threre are not enough nodes\n");
		return;
	}
	printf("sum of 1st and 3rd node: %d\n",sum );




}
struct node* create_list(struct node *head, int *arr, int n)
{	
	int i;
	struct node *ptr, *temp;
	for(i = 0; i < n; i++)
	{
		ptr = (struct node *)malloc(1 * sizeof(struct node));
		if(ptr == NULL)
		{
			printf("failed to allocate memory in heap\n");
			exit(1);
		}
		ptr->data = arr[i];
		printf("ptr->data: %d\n",ptr->data);
		ptr->link = NULL;
		if(head == NULL)
		{
			head = ptr;
			printf("head: %p\n",head);
		}
		else
		{
			temp = head;
			while(temp->link != NULL)
			{	
				temp = temp->link;
			}
			temp->link = ptr;
		}
	}
	return head;
}

void display(struct node *head)
{
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}
	struct node *temp;
	temp = head;
	while(temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->link;
	}


}
void main()
{
	int i;
	int arr[5];
	struct node *head = NULL;
	for(i= 0; i < 5; i++)
	{
		printf("enter %d element: ", i);
		scanf("%d",&arr[i]);
	}
	head = create_list(head, arr, 5);
			printf("head: %p\n",head);
	
	display(head);
	add_1_3(head);


	

}
