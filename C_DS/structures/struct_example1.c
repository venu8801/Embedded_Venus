/* accessing a structure using a structure pointer
 * to access a structure using a structure pointer we need a pointer  of same type*/
#include<stdio.h>
#include<stdio_ext.h>
struct loan
{
	char loan[32];
	int loanAmount;
};

struct bank
{
	char accHolder[32];
	char typeAcc;
	int bal;
	struct loan *l1; // pointer for struct loan variable
};

void read(struct bank *ptr1);
void display(struct bank *ptr1);
int main()
{
	struct bank c1; // customer c1
	struct bank *ptr1 = &c1;
	struct loan b1;
	c1.l1 = &b1;
	read(ptr1);
	printf("---------------\n");
	display(ptr1);
	return 0;
}
void read(struct bank *ptr1)
{
	printf("Account holder name: ");
	__fpurge(stdin);
	scanf("%[^\n]",ptr1->accHolder);
	printf("Enter type of Account: ");
	__fpurge(stdin);
	scanf("%c",&ptr1->typeAcc);
	printf("Enter balance amount in account:");
	__fpurge(stdin);
	scanf("%d",&ptr1->bal);
	printf("Enter loan type:");
	__fpurge(stdin);
	scanf("%s",ptr1->l1->loan);
	printf("Enter loan amount:");
	__fpurge(stdin);
	scanf("%d",&ptr1->l1->loanAmount);
}
void display(struct bank *ptr1)
{
	printf("A/C Holder Name: %s\n",ptr1->accHolder);
	printf("Type of account: %c\n",ptr1->typeAcc);
	printf("Bal Amount: %d\n",ptr1->bal);
	printf("Loan type: %s\n",ptr1->l1->loan);
	printf("Loan amount:%d\n",ptr1->l1->loanAmount);
}

	
