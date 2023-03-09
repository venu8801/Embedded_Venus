#include<stdio.h>
int main()
{
	int x[3] = {10,20,30};

	int y[3] = {40,50,60};

	int *ptr[2] = {x,y}; // declaring and defining adresses to pointers inside arrays
	int i,j;
	
		printf("%p----%p\n",&ptr[2],ptr[2]);
	return 0;
}


