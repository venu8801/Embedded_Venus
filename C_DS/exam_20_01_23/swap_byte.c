/* program to swap nibble of a number
 * ex: num = 0x12345678
 * output num = 0x56781234*/
#include<stdio.h>
unsigned int swap_nibble(unsigned int num)
{
	num = num & (~ ( (0xffff << 16)|(0xffff << 0)) ) | ( (num & (0xffff << 16) ) >> 16 ) | ((num & (0xffff) )<< 16);
	return num;


}
void main()
{
	unsigned int num = 0x11223344;

	printf("output: 0x%x\n",swap_nibble(num));
	



}
