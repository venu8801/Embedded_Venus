/* program to replace a byte in num
 * ex: num = 0x12345678 replace 34 with 77 in num*/
#include<stdio.h>
void main()
{
	unsigned int num = 0x12345678;

	//num = ( num & (~(0xff << 16))  ) | (num | (0x77 << 16));
	num = num | (0x43 << 16);
	printf("num: 0x%x\n", num);


}
