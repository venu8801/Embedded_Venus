
void palindrome(int *arr, int l);
void ascending(int *arr, int l );
void descending(int *arr, int l );
void help(void);
void  binary(int*ptr, int l);
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char *argv[])
{
	//printf("%c\n",argv[1][0]);
	if(argc <= 2 || (argv[1][0] != '-'))

	{
		printf("Not enough arguements (or) missing \"-\" \n");
		printf("use -h flag to know\n");
		exit(-1);
	}
	if(argv[1][1] == 'h')
	{
		help();
		exit(-1);
	}

	int arr[argc - 2]; // integer array to store all int elements
	int i, j = 0, k = 0;
	int minus = 0;
	int sum = 0, ascii;
	for(i = 2; i < argc; i++)
	{
		j = 0;
		minus=0;
		if(argv[i][0] == '-')
		{
			minus = 1; // checking if it has negative sign or not
			j++; // if negative incrementing j to next value
		}	
		sum = 0;

		for(j ; argv[i][j] != '\0'; j++ )
		{
			//printf("%c\n",argv[i][j]);
			if(argv[i][j] >= '0' &&  argv[i][j] <= '9')
			{
				ascii = argv[i][j] - 48;
				sum = sum*10 + ascii;
				//	printf("sum =%d\n",sum);
			}
			else
			{
				printf("Not valid strings\n");
				exit(-1);
			}
		}
		//printf("sum =%d\n",sum);
		if(minus == 1)
			sum = -(sum);
		//printf("sum =%d\n",sum);

		arr[k] = sum;
		k++;


	}
	// printing array elements
	printf("Array elements: ");

	for(k = 0; k < argc - 2; k++)
	{
		printf("%d ", arr[k]);
	}
	printf("\n");
	char arg = argv[1][1];
	//printf("%c\n",arg);
	switch(arg)
	{
		case 'a':
			binary(arr, (argc - 2));
			break;
		case 'b':
			ascending(arr, (argc - 2));
			break;
		case 'c':
			descending(arr, (argc -2));
			break;
		case 'd':
			palindrome(arr, (argc - 2));
			break;

		default:
			printf("Not a valid flag\n");
			help();

	}




}
//-----------------------------------------------------------------------------------------------------------------------
void  binary(int*ptr, int l)
{
	int i, j;

	for(i = 0; i < l; i++)
	{
		printf("arr[%d] = %d: ",i,ptr[i] );
		for(j = 31; j >= 0; j--)
		{
			if( (( ptr[i]&(0x1 << j) ) == 0))
				printf("0");
			else
				printf("1");
		}
		printf("\n");

	}
}
//-----------------------------------------------------------------------------------------------------------------------

void help(void)
{

	printf("-------------------------\n");
	printf("usage--------------------\n");
	printf(" < executable > -< flag > < Strings > \n");
	printf("-Flag	purpose\n");
	printf("-a	binary conversion 32 bit\n");
	printf("-b 	descending order of elemenst\n");
	printf("-c	ascending order of elements\n");
	printf("-a	palindrome if any\n");
	printf("-h	help\n");

	printf("-------------------------\n");
}


//-----------------------------------------------------------------------------------------------------------------------

void ascending(int *arr, int l )
{
	int i,j;

	int temp;
	for(i = 0; i < l; i++)
	{
		for(j = i + 1; j < l; j++)
		{
			if(arr[i] < arr[i+1])
			{
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}

	}
	for(i = 0; i < l; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	
	}
}


//-----------------------------------------------------------------------------------------------------------------------

void descending(int *arr, int l )
{
	int i,j;
	int temp;
	for(i = 0; i < l; i++)
	{
		for(j = i + 1; j < l; j++)
		{
			if(arr[i] < arr[i+1])
			{
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}

	}
	for(i = 0; i < l; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");


	}
}
//-----------------------------------------------------------------------------------------------------------------------

void palindrome(int *arr, int l)
{
	int i;
	int temp,rev,rem;
	for(i = 0; i < l; i++)
	{	
		rev = 0;
		if(arr[i] < 0)
			arr[i] = -(arr[i]);
		printf("%d\n",arr[i]);
		temp = arr[i];
		while(temp > 0)
		{
			rem = temp % 10;
			rev  = rev*10 + rem ;
			temp = temp / 10;
		}
		printf("%d\n",temp);
		if(temp == arr[i])
		{
			printf("palindrome: %d\n",arr[i]);
		}
	}
}








