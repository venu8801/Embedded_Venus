// printing only the diagnol elements from a square matrix
#include<stdio.h>
void readMatrix2D(int R, int C,int (*ptr)[C]);
void DisplayMatrix(int R, int C, int (*ptr)[C]);
void main()
{
	int R,C;
	int i,j;
	printf("Enter Rows: ");
	scanf("%d",&R);
	printf("Enter Columns: ");
	scanf("%d",&C);

	int arr[R][C];
	readMatrix2D(R,C,arr);
	DisplayMatrix(R,C,arr);
	
	printf("_______\n");
	printf("Diagnol Elements L->R are: \n");

	for(i = 0; i < R; i++)
	{
		for(j = 0; j < C; j++)
		{
			if( i == j )
			{
				printf("%d ",arr[i][j]);
			}
		}
	}
	printf("\n");
	printf("Diagnol Elements R->L are: \n");
	for(i = 0; i < R; i++)
	{
		for(j = 0; j < C; j++)
		{
			if( i == C-j-1 )
			{
				printf("%d ",arr[i][j]);
			}
		}
	
	
	}
}
void readMatrix2D(int R, int C,int (*ptr)[C])
{
	printf("Enter elements into 2D matrix %d x %d\n", R, C);
	int i, j;
	for(i = 0; i < R; i++)
	{
		for(j = 0; j < C; j++)
		{
			scanf("%d",&ptr[i][j]);
		}
		printf("\n");
	}
}
void DisplayMatrix(int R, int C, int (*ptr)[C])
{
	printf("Entered elements inside matrix %d x %d\n",R,C);
	int i, j;
	for(i = 0; i < R; i++)
	{
		for(j = 0; j < C; j++)
		{
			printf("%d",ptr[i][j]);
		}
		printf("\n");
	}
	
}
