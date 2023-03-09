/*program to understand static keyword applied to a local varaible*/

void display();
#include<stdio.h>
int main()
{
	display();
	display();
	display();
	display();
}
void display()
{
	static int x = 10;// this statement only gets executed one time 
	// memory for x is allocated in data segment not in
	// stackframe of display() function
	x++;
	printf("%d\n",x);
}
