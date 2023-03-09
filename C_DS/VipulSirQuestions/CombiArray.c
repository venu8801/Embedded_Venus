/*program to find sum combinations of given number from an array
 * example:
 * arr{1,3,5,4,2} target = 7;
 */
#include<stdio.h>
void main()
{
	int n;
	/*printf("Enter the elements into the array\n");
	scanf("%d",&n);
	int arr[n];*/

	int arr[5] = {1,3,5,4,2};
	int target = 7;
	int i,j;
	int sum;
	for(i = 0; i < 5; i++)
	{
		sum = 0;
		for(j = 0; j < n; j++)
		{
			if(arr[i] == arr[j])
				continue;
			sum += arr[i];
			if(sum == target)
			{
				flag = 1;
				break;
			}

		}
		if(flag == 1)
		{
			printf(")

