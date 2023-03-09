/* program to print mirror image of a 2D matrix
 */
#define R 4
#define C 4

#include<stdio.h>
void readMatrix2D( int (*)[]);
void displayMatrix2D( int (*)[]);
void mirror2D(int (*m)[C]);
void main()
{
	int m1[R][C];
	
	readMatrix2D( m1);
	
	displayMatrix2D(m1);
	
	mirror2D(m1);

	displayMatrix2D( m1);






}
void readMatrix2D( int(*m)[C] )
{

	printf("enter the elements into %d x %d matrix\n", R, C);
	int i, j;
	for(i = 0; i < R; i++)
	{
		for(j = 0; j < C; j++)
		{
			scanf("%d",&m[i][j]);
		}
	}


}
void displayMatrix2D( int(*m)[C] )
{

	printf("elements inside %d x %d matrix\n", R, C);
	int i, j;
	for(i = 0; i < R; i++)
	{
		for(j = 0; j < C; j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}


}
void mirror2D( int (*m)[C])
{
	
	printf("entered\n");

	int i , j , k;
	int temp;
	for(i = 0; i < R; i++)
	{
		for(j = 0; j < C/2; j++ )
		{
			//printf("j:%d\n",j);
			temp = m[i][j];
			m[i][j] = m[i][C-j-1];
			m[i][C-j-1] = temp;
		}
	}


}
