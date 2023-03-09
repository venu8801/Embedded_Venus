#include<stdio.h>
int main()
{
	/* a double pointer can store address of a single pointer */
	// double pointer size depends upon machine architecture
	// to dereference a double pointer we should ** two stars
	int x = 10;

	int *ptr = &x; // single pointer with adress of variable x

	int **dptr = &ptr; // double pointer with address of ptr
// single pointer
	printf("single pointer\n");
	printf("adress inside ptr:%p\n",ptr);
	printf("address of ptr:%p\n",&ptr);
	printf("value:%d\n",*ptr);
// double pointer
	printf("double pointer\n");

	printf("adress inside dptr:%p\n",dptr); // prints single pointer's address

	
	printf("adress of dptr:%p\n",&dptr); // prints double pointer's base address
	
	
	printf("**(%p) = %p\n",&dptr,*dptr); // dereferencing double pointer *
	// prints value inside dptr that is address of single pointer
	
	
	printf(" *(%p) = %d\n",*dptr,**dptr); 
	
	// dereferencing  pointer base adress **
	// prints value inside x 





	return 0;
}
