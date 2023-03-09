/* conditional compilation */

#include<stdio.h>
#define BALAJI 56

void main()
{
	int i = 0;
	//printf("i = %d\n", i);
	//printf("i = %d\n", BALAJI);
	
	#if BALAJI > 56 
	//int BALAJI = 90;
	printf("i = %d\n", BALAJI);
	#elif BALAJI = 56
	printf("no balaji macro\n");
#else
	printf("else\n");
	#endif
	
}
