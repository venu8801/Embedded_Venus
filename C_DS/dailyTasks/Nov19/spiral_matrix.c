/*spiral matrix printing*/
void Spiral_MatrixPrint(int r, int c,int (*ptr)[c]);
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


void Spiral_MatrixPrint(int r, int c,int (*ptr)[c])
{
	int i;
	int j = 0;
	int k;
	printf("\n");
	int cnt=0;
	for(i = 0; i < r*c;i++ )
	{	
		//	printf("i = %d\n",i);
			if(cnt  < c )
			{	
				
				printf("%d ",ptr[0][j]);
				cnt++;	
				j++;		
			}
			else if(cnt == c )
			{
				j = c - 1;
				for(k = 1; k < r; k++  )
				{
					printf("%d ",ptr[k][j]);
					cnt++;
						
				}
			}
			else if(cnt == (r + c) - 2)
			{
			//	printf("i = %d\n",i);
			//	printf("k = %d\n",k);
				k = k - 1;
				for(j = k; j >= 0; j--)
				{
					printf("%d ",ptr[k][j]);
					cnt++;
				
				}
				printf("i = %d\n",i);

			} 	
			else if( cnt < c + 2*(c - 1)  )	
			{		
				k = k - 1; // k becomes 3 for 4x4 matrix
				//printf("# ");
				for(j = k - 1; j >= 0; j--)
				{
					printf("%d ",ptr[k][j]);
					cnt++;

				}
			}
			else if(cnt == ())
			
			else
				cnt++;
	}
}
				


































