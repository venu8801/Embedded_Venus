
/* program for matrix addition*/

void matrix_add(int r, int c, int(*ptr1)[c], int(*ptr2)[c], int(*ptr3)[c]);
void display(int , int,int(*ptr)[] );
void read(int , int,  int(*ptr)[] );
#define R 2
#define C 4
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int (*m1)[];
       m1 = (int(*)[])malloc(R * C * sizeof(int));
       int (*m2)[] = (int(*)[])malloc(R * C * sizeof(int));
       int (*m3)[] = (int(*)[])malloc(R * C * sizeof(int));
	
	printf("matrix: %d x %d\n",R,C);
	printf("Enter first matrix:\n");
	read( R, C, m1);
	printf("Enter second matrix:\n");
	read( R, C, m2);


	printf("------------\n");


	printf("Entered first matrix:\n");
	display( R, C,m1);
	printf("Entered second matrix:\n");
	display( R, C, m2);
	
	matrix_add(R,C,m1,m2,m3); // matrix addition


	printf("matrix 3 after adding\n");
	display(R,C,m3);
	
	free(m1);
	free(m2);
	free(m3);
	return 0;

	
}
void read(  int r, int c, int (*ptr)[c] )
{
	int i,j;

	for(i = 0; i < r; i++)
	{
		printf("row %d\n",i);
		for(j = 0; j < c; j++)
		{
			scanf("%d",&ptr[i][j]);

		}
		printf("\n");
	}
}

void display(  int r, int c, int (*ptr)[c] )
{
	int i,j;

	for(i = 0; i < r; i++)
	{
		//printf("row %d\n",i);
		for(j = 0; j < c; j++)
		{
			printf("%d ",ptr[i][j]);

		}
		printf("\n");
	}
}

void matrix_add(int r, int c, int(*ptr1)[c], int(*ptr2)[c], int(*ptr3)[c])
{
	int i, j;

	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			 ptr3[i][j] = ptr1[i][j] + ptr2[i][j];
		}
	}

}
