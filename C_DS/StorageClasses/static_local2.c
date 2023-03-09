#include<stdio.h>
static int x;
int main()
{
	static int x =1; // static local var
	// this variable is stored with a suffix
	for(x; x <= 10; x++)
	{
		static int x = 10;// static local var
		// this variable is also stored with a suffix but different from above
		printf("%d\n",x);
		x++;
	}

}
/* two variables with same name cannot exist in same memory segment
 * so, compiler does naming decoration or data mangling */
