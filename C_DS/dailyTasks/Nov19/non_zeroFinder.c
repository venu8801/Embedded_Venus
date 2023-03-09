

void display(int r, int c, int(*ptr)[]);
int read(int r, int c, int(*ptr)[]);
void count_non_zeroes(int r, int c, int (*ptr)[c],int (*out)[3]);
#include<stdio.h>
#include<stdlib.h>
#define R 5
#define C 5
void main()
{
	int (*ptr)[C];

	ptr = (int (*)[])malloc(R * C * sizeof(int));

	printf("---------\n");

	printf("Enter the elements into matrix\n");

	int rcount = read(R,C,ptr); // calling function to read elements into matrix

	printf("Displaying matrix elements:\n");

	display(R,C,ptr); // calling a function to display elements inside the matrix

	int output[rcount][3];


	count_non_zeroes(R, C, ptr, output);

	display(rcount,3,output);




}
int  read(int r, int c, int (*ptr)[c] )
{

	int i,j;
	int r_count = 0;
	printf("%d x %d matrix\n",r,c);
	printf("-------------------\n");
	for(i = 0; i < r; i++)
	{
		printf("row %d\n",i);
		for(j = 0; j < c; j++)
		{
			scanf("%d",&ptr[i][j]);
			if(ptr[i][j] != 0)
				r_count++;

		}
		printf("\n");
	}
	return r_count;
}

void display(int r, int c, int (*ptr)[c] )
{
	int i,j;

	printf("%d x %d matrix\n",r,c);
	printf("-------------------\n");
	for(i = 0; i < r; i++)
	{
		//printf("row %d\n",i);
		for(j = 0; j < c; j++)
		{
			printf("%d ",ptr[i][j]);

		}
		printf("\n");
	}
	printf("-------------------\n");
}


void count_non_zeroes(int r, int c, int (*ptr)[c], int(*out)[3])
{
	int i, j;
	int k = 0;
	printf("r:%d and c:%d\n",r,c);
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			//printf("ptr[i][j]:%d\n",ptr[i][j]);
			if(ptr[i][j] != 0)
			{
				//printf("--ptr[i][j]:%d\n",ptr[i][j]);
				out[k][0] = i;
				out[k][1] = j;
				out[k][2] = ptr[i][j];

				k++;
			}


		}
	}
}

















