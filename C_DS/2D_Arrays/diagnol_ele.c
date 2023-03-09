/* program to print diagnol elements in a matrix*/


void diagnol(int port, int r, int c, int (*ptr)[c]);
void display(int , int,int(*ptr)[] );
void read(int , int,  int(*ptr)[] );
#define R 3
#define C 3
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ptr[R][C];
	int portion; // upper portion or lower
	printf("matrix: %d x %d\n",R,C);
	printf("Enter matrix:\n");
	read( R, C, ptr);
	


	printf("------------\n");
	
	
	printf("Entered first matrix:\n");
	display( R, C, ptr);
	printf("Upper triangle or lower ?\n");
	printf("1---upper\n2---lower\n");
	scanf("%d",&portion);	
	diagnol(portion, R, C, ptr);
	
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
void diagnol(int port, int r, int c, int (*ptr)[c])
{
	int i,j,k;
	if(port == 1)
	{
		printf("upper diagnol\n");
		
		for(i = 0; i < r; i++)
		{
			j = 0; 
			for(k = 0; k < i; k++)
			{
				printf("  ");
				j++;
			}

			for(j; j < c; j++ )
			{
				printf("%d ",ptr[i][j]);
			}
			

			printf("\n");
		}
	}
	else if(port == 2)
	{
		printf("lower diagonol\n");
		j = 0;
		for(i = 0; i < r; i++ )
		{
			for(j = 0; j < c; j++)
			{
				if(j<=i)
					printf("%d ",ptr[i][j]);
				else
					printf("  ");
			}
			printf("\n");
		}
	}

}





















