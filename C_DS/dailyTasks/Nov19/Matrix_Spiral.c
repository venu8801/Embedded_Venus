#include<stdio.h>
#define R 6
#define C 6
void display(int r, int c, int (*ptr)[c] );
void spiral(int (*a)[C],int i,int j,int r,int c){
	int k,l;
	printf("\t");
	if(((r-i)<=0)&&((c-j)<=0)) // if the element is last and single element
	{	if(((r-i)==0)&&((c-j)==0))
		 printf("%d ",a[i][j]);
		 printf("\n");
		return;
	}
	for(k=i;k<=c;k++) // first outer row
		printf("%d ",a[i][k]);
	for(k=i+1;k<=r;k++)// right most column printing
		printf("%d ",a[k][c]);
	for(k=c-1;k>=i;k--) // last row of the matrix
		printf("%d ",a[r][k]);
	for(k=r-1;k>i;k--)// left most column
		printf("%d ",a[k][i]);
		
	printf("\t");
	spiral(a,i+1,j+1,r-1,c-1);// recursing through inner matrix
}
void main(){
	int arr[R][C],i,j,k=1;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++,k++)
		{
		 	arr[i][j]=k;
		}
	}
	display(R,C,arr);		 
	
	spiral(arr,0,0,R-1,C-1);
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
