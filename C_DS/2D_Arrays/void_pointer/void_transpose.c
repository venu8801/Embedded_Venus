/* program to transpose a matrix*/

void m_transpose(int r, int c, void *, void *);
void display(int , int,void * );
void read(int , int, void * );
#define R 2
#define C 4
#include<stdio.h>
#include<stdlib.h>
int main()
{
	void *m1;
       m1 = malloc(R * C * sizeof(int));
       void *m2 = malloc(C * R * sizeof(int));
      
	
	printf("matrix: %d x %d\n",R,C);
	printf("Enter matrix:\n");
	read( R, C, m1);
	

	printf("------------\n");


	printf("Entered matrix:\n");
	display( R, C,m1);
	

	m_transpose(R,C,m1,m2);

	printf("matrix 3 after transpose\n");
	display(C,R,m2);
	
	free(m1);
	free(m2);
//	free(m3);
	return 0;

	
}
void read(  int r, int c, void *ptr )
{
	int i,j;

	for(i = 0; i < r; i++)
	{
		printf("row %d\n",i);
		for(j = 0; j < c; j++)
		{
			scanf("%d",&((int (*)[c])ptr)[i][j]);

		}
		printf("\n");
	}
}

void display(  int r, int c, void *ptr )
{
	int i,j;

	for(i = 0; i < r; i++)
	{
		//printf("row %d\n",i);
		for(j = 0; j < c; j++)
		{
			printf("%d ",((int (*)[c])ptr)[i][j]);

		}
		printf("\n");
	}
}
void m_transpose(int r, int c, void *ptr1, void *ptr2)
{
	int i,j;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			( (int (*)[r])ptr2)[j][i] = ( (int (*)[c])ptr1 )[i][j]; // 1st matrix's 1st column is 2nd matrix 1st row

		}

	}
	

}






























