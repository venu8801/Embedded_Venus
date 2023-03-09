/* polynomial equation addition using double linked list */

#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int pow;
	int coeff;
	struct node *next;
};
struct node *head1 = NULL; // for eq1
struct node *head2 = NULL; // for eq2

int insertNode(int pow, int coeff, char eq)
{
	struct node *ptr, *temp, *head;
	ptr = (struct node *)malloc(1 * sizeof(struct node));
	if(ptr == NULL)
	{
		printf("failed to allocate memory\n");
		exit(1);
	}
	ptr->pow = pow;
	ptr->coeff = coeff;
	if(eq == 1)
		head = head1;
	else
		head = head2;
	if(head == NULL)
	{
		head = ptr;
		ptr->prev = NULL;
		ptr->next = NULL;
		return 0;

	}
	temp = head;
	while(temp->next != NULL)
	{
		if(temp->pow == pow)
		{
			temp->coeff += coeff;
			return 0;
		}
		else if(temp->pow < pow)
		{

			//add before node
			if(temp != head)
				temp->prev->next = ptr;
			else
				head = ptr;
			ptr->prev = temp->prev;
			ptr->next = temp;
			temp->prev = ptr;
			return 0;

		}
		else
		{
			// add after node
			if(temp->next != NULL)
				temp->next->prev = ptr;
			ptr->next = temp->next;
			temp->next = ptr;
			ptr->prev = temp;
			return 0;
		}


		temp = temp->next

	}




}



void display_eq(int eq)
{
	struct node *temp, *head;
	if(eq == 1)
		head = head1;
	else
		head = head2;
	if(head == NULL)
	{
		printf("equation is empty\n");
		exit(1);
	}
	temp = head;
	while(temp != NULL)
	{
		printf("%dX^%d + ", temp->coeff, temp->pow);
		temp = temp->next;
	}

}


void main()
{
	
	
	
	
}
