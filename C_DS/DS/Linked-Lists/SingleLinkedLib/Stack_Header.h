#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node
{
	int data;
	struct node *link;
};


void addAtlast(int num);
void deleteAll();
int Nodesearch(int num);
int Nodecount();
void display();
void delAtBeg();
void addatBeg(int num);
void deleteAtlast();
void addAfterNode(int num, int var);
void deleteParticularNode(int num);
void addBeforeNode(int num, int val);
void reverseStack();
void create_Stack(int s);
void Swap_data(int num1, int num2);
void Swap_Links(int num1, int num2);

