/*using void pointer only*/
// matrix multiplication
void mul_matrix(int r1, int r2, int c1, int c2, void *a, void *b, void *c  );
void display(int , int, void* );
void read(int , int, void *);
#define R 2
#define C 2
#include<stdio.h>
#include<stdlib.h>
int main()
{
	// declaring 3 void pointers
	void *m1 = malloc(R * C * sizeof(int));
	void *m2 = malloc(R * C * sizeof(int));
	void *m3 = malloc(R * C * sizeof(int));

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

	mul_matrix(R,C,R,C,m1,m2,m3); // matrix addition


	printf("matrix 3 after multiplication\n");
	display(R,C,m3);

	free(m1);
	free(m2);
	free(m3);
	return 0;


}
void read(int r, int c, void *ptr )
{
	int i,j;

	for(i = 0; i < r; i++)
	{
		printf("row %d\n",i);
		for(j = 0; j < c; j++)
		{
			scanf("%d", & ((int (*)[c])ptr)[i][j]);

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

void mul_matrix(int r1, int r2, int c1, int c2, void *a, void *b, void *c  )
{
	int i,j,k;
	for(i = 0; i < r1; i++)  // first matrix row times
	{
		for(j = 0; j < c2; j++) // second matrix column times
i		{
			for(k = 0; k < r2; k++) // second matrix row times
			{
				( (int (*)[r1]) c )[i][j] += ( (int (*)[c1])a)[i][k] * ((int (*)[c2])b)[k][j];
			}
		}
	}
}









































