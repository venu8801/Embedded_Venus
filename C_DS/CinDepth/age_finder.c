/* program to find age of a person */



#include<stdio.h>
#include<stdlib.h>
int main()
{
	int cyy,cmm,cdd;
	int yy,mm,dd;
	printf("Enter current date in dd/mm/yy format only\n");
	scanf("%2d/%2d/%4d",&cdd,&cmm,&cyy);
	if(cdd > 31 || cdd <= 0 )
	{
		printf("Invalid date\n");
		printf("---Exitting---");
		exit(0);
	}
	else if(cmm > 12 || cmm <= 0 )
	{
		printf("Invalid month\n");
		printf("---Exitting---");
		exit(0);
	}
	printf("Current date: %d/%d/%d\n",cdd,cmm,cyy);
	printf("Enter start  date in dd/mm/yy format only\n");
	scanf("%2d/%2d/%4d",&dd,&mm,&yy);
	if(cdd > 31 || cdd <= 0 )
	{
		printf("Invalid date\n");
		printf("---Exitting---");
		exit(0);
	}
	else if(cmm > 12 || cmm <= 0 )
	{
		printf("Invalid month\n");
		printf("---Exitting---");
		exit(0);
	}
	printf("Start date: %d/%d/%d\n",dd,mm,yy);


	

	
	return 0;
}
	
