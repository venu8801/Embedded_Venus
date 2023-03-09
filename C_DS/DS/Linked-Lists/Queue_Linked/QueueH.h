#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node
{
	int data;
	struct node *link;
};
void insert_Queue(int num);
void delete_Queue();
void Delete_full_Queue();
void Create_Queue(int *iptr, int n);
void display_Queue();
int Nodecount_Queue();
int Nodesearch_Queue(int num);
