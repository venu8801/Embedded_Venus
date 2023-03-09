#include<stdio.h>
void main()
{
	unsigned int num = 0x12345678;

	num = (num & (~((0xFFFF << 16)|(0xFFFF << 0)) ) ) |  ( num & ((0xFFFF) << 16)) >> 16 | ( (num & (0xFFFF << 0))  << 16);

	printf("ox%x\n",num);

}
