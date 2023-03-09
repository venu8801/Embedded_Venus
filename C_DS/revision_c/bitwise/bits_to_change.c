/* program to find count of no. of bits needed to be changed */
#include<stdio.h>
/* this function counts no. of digits need to be changed in a to make it b */
int find_count(unsigned int a, unsigned int b)
{
	int i, cnt = 0;
	for(i = 31; i >=0; i--)
	{
		if(  (a & (0x1 << i)) != (b & (0x1 << i)) )
			cnt++;


	}
	return cnt;

}
void main()
{
	unsigned int a , b;
	printf("Enter the numbers a,b: ");
	scanf("%d,%d",&a,&b);
	
	int cnt = find_count(a, b);
	printf("no. of bits needed to be changed: %d\n", cnt);




}
