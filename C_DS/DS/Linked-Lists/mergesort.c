//merge sort using linked lists
struct node
{
	int data;
	struct node *link;
};
struct node *head1, *head2, *head3;


struct node * create_Mlist(struct node *ptr, int *iptr, int n)
{
	struct node *temp, *start = NULL, *prev;
	int i;
	for(i = 0; i < n; i++)
	{	
		struct node *Nptr = (struct node *)malloc(1 * sizeof(struct node));
		if(Nptr == NULL)
		{
			printf("Failed to allocate memory in heap\n");
			exit(3);
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
			ptr = Nptr;
			return;
		

			temp = ptr;
			while(temp->link != NULL)
			{
				temp = temp->link;
			}
			temp->link = start;
}	

void Merge_sort( struct node *p1, struct node *p2)
{
	struct node *temp
	for()
