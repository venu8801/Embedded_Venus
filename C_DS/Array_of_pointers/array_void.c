

void read(void **dptr, int np , int ne);
void display(void **dptr, int np, int ne);
#include<stdio.h>
#include<stdlib.h>
int main()
{
	void **dptr; // double pointer to store address returned by DMA calls for array of pointers

	dptr = malloc(2 * sizeof(int **)); // malloc returning address of array of pointers array of pointers for 2 integer pointers 2 * 8 = 16
	
	int i;
	for(i = 0; i < 2; i++)
	{
		dptr[i] =  malloc(3 * sizeof(int));  // creating an integer array of 12 bytes (to store 3 integer elements) 
		// type casted malloc value to int * so that it has base address of integer array

	}

	read(dptr, 2, 3); // as we dont have any name to these addresses to write data to them
	display(dptr, 2, 3);
}


void read(void **dptr, int np , int ne)
{
	int i,j;

	for(i = 0; i < np; i++)
	{
		printf("pointer array addresses:%p\n",((int **)dptr)[i]);

		for(j = 0; j < ne; j++)
		{
			printf("Enter elements inside integer arrays:");
				scanf("%d",&((int **)dptr)[i][j]);
		}
		printf("\n");
	}
}
void display(void **dptr, int np, int ne)
{
	int i,j;
	for(i = 0; i < np; i++)
	{
		for(j = 0; j < ne; j++)
		{
			printf("%p  and %d\n",&((int *)dptr[i])[j], ((int *)dptr[i])[j]);
		}
	}
}
