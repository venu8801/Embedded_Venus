void read(int r, int c, int (*ptr)[c] );
void display(int r, int c, int (*ptr)[c] );
#define R 4
#define C 4
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ptr[R][C] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	


	printf("------------\n");
	
	
	printf("Entered matrix:\n");
	display( R, C, ptr);
	Spiral_MatrixPrint(R,C,ptr);
	
	}

void read(int r, int c, int (*ptr)[c] )
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

void display(int r, int c, int (*ptr)[c] )
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

