/*########################################################################################################################################
 *############################## PRIORITY QUEUE ########################################################################################
 * #code written by: Venu Gopal A
 * #e-mail: venu.ark.prasad@gmail.com
 *
 */


/*-----includes ---*/
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>



/*structure definition */
struct venusPQ
{
	struct venusPQ *vprev;
	int vdata;
	int vprty;
	struct venusPQ *vnext;
};

/*--------------- typedef --------------------*/ 

typedef struct venusPQ vpq;// type def for structure
vpq *PQ_head = NULL; // intializing head pointer for PQ

//-----------------------------------------------------//
//function prototypes
int Display_All();
int Insert_vPQ(int data, int prty);
void Display_Prty(int);
void DeleteAll();
void DeletePrty_Group(int);
void Delete_DataPrty(int data, int prty);
void Display_Queue_Debug();
void Create_Prty_Queue(int size);
void SelectionSort();
void Sorting_Priority(int prty);
int Insert_Priority(int data, int prty);
void Frequency();
void BubbleSort_Queue(int prty);
//-----------global variables------------------
int NodeCount = 0;

//main function start//
void main()
{
	int opt, subopt;
	int data, prty;
	int status;
	while(1)
	{
		printf("--------###--------------priority queue----------------###-------\n");
		printf("0.Exit\n1.Insert\n2.Display\n3.Delete\n4.Create Queue\n5.Sortings(data)\n6.Sortings (Priority)\n7.Frequency of nodes\n");
		printf("8.Bubble Sort\n");
		printf("select an option: ");
		__fpurge(stdin);
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:
				printf("--------exit--------\n");
				exit(2);
			case 1:
				printf("----------Insert-----------\n");
				printf("Enter data and priority level inside\n");
				printf("Enter in '/data:priority format only:'/ ");
				__fpurge(stdin);
				scanf("%d:%d",&data, &prty);
				//status = Insert_vPQ(data, prty);
				status = Insert_Priority(data, prty);
				if(status == 0)
					printf("Node added to Priority Queue\n");

				break;
			case 2:
				printf("-------Display----------\n");
				printf("1.Display All\n2.Display (Priority Based)\n");
				printf("Select Suboption: ");
				scanf("%d",&subopt);
				switch(subopt)
				{
					case 1:
						printf("--Display All--\n");
						NodeCount = Display_All();
						Display_Queue_Debug();
						break;
					case 2:
						printf("--Display based on priority--\n");
						printf("Enter priority: ");
						scanf("%d",&prty);
						printf("-----Displaying nodes with given priorities----\n");
						Display_Prty(prty);
						
						break;

					default:
						break;
				}
				break;
			case 3:
				printf("--------DELETION---------------\n");
				printf("1.Delete All\n2.Delete Priority Group\n3.Delete based on priority & data\n");
				printf("Option: ");
				scanf("%d",&subopt);
				switch(subopt)
				{
					case 1:
						printf("--------Delete all------------\n");
						DeleteAll();
						break;
					case 2:
						printf("--------Delete Priority Group------------\n");
						printf("Enter the priority num: ");
						scanf("%d",&prty);
						DeletePrty_Group(prty);
						break;
					case 3:
						printf("------------Delete Data & Priority-------------------------\n");
						printf("Enter data:priority ");
						scanf("%d:%d",&data,&prty);
						Delete_DataPrty(data, prty);
						break;
					default:
						printf("Invalid Option Selected\n");
				}
				break;
			case 4:
					printf("----------------Create Queue-------------------------\n");
					int size;
					printf("Enter the size: ");
					scanf("%d",&size);
					Create_Prty_Queue(size);
					break;
			case 5:
				printf("\t-----------Selection Sort based on data----------------\n");
				SelectionSort();
				break;
			case 6:
				printf("\t-----------Selection Sort based on priority----------------\n");
				printf("Enter priority to be sorted:");
				scanf("%d",&prty);
				Sorting_Priority(prty);
				break;
			case 7:
				printf("------------------Frequency of nodes-------------------------------\n");
				Frequency();
				break;
			case 8:
				printf("----------------------BUBBLE SORT PRIORITY---------------------\n");
				printf("Enter priority\n");
				scanf("%d",&prty);
				BubbleSort_Queue(prty);
				break;
			default:
				printf("Invalid Option Selected\n");
				


		}
	}
	
}
int Insert_vPQ(int data, int prty)
{
	vpq *ptr = (vpq *)malloc(1 * sizeof(vpq));
	vpq *tempPtr, *previous;
	if(ptr == NULL)
	{
		printf("Failed to allocate memory for new node\n");
		exit(1);
	}
	ptr->vdata = data;
	ptr->vprty = prty;

	if(PQ_head == NULL)
	{
		PQ_head = ptr;
		ptr->vprev = NULL;
		ptr->vnext = NULL;
		return 0;  // successfully added node 
	}
	/*if( (PQ_head->vnext == NULL))//contains only single node
	{
	  	if( prty < (PQ_head->vprty) )  // add before first the node as recieved priority level is lower
		{
			//add at begining
			PQ_head->vprev = ptr;
			ptr->vnext = PQ_head;
			ptr->vprev = NULL;
			PQ_head = ptr;
			return 0;
		}
		else if( (PQ_head->vprty) <= prty) //add after first node
		{
		
			PQ_head->vnext = ptr;
			ptr->vprev = PQ_head;
			ptr->vnext = NULL;
			return 0;
		}
		return 1;
	}*/
	//queue contains multiple nodes so traversing 
	tempPtr = PQ_head;
	while(tempPtr != NULL)
	{
		if( tempPtr->vprty == prty )
		{
		       	// finding last occurence of prty in queue
			 if(tempPtr->vnext == NULL)
			{	
				//add after a node
				tempPtr->vnext = ptr;
				ptr->vprev = tempPtr;
				ptr->vnext = NULL;
				return 0;
			}
			else if(tempPtr->vnext->vprty != prty)
                        {
                                // adding the node after the last occurence
                                ptr->vnext = tempPtr->vnext;

                                ptr->vprev = tempPtr;
                                //if(tempPtr->vnext != NULL)
                                tempPtr->vnext->vprev = ptr;
                               tempPtr->vnext = ptr;
                                return 0 ;
                        }
	
		}
		


		tempPtr = tempPtr->vnext;
	}
	// if priority not found in queue
	tempPtr = PQ_head;
	while(tempPtr != NULL)
	{
		if(prty > tempPtr->vprty)// if given priority is greater than add after last node in priority group
		{
			if(tempPtr->vnext == NULL)
			{
				tempPtr->vnext = ptr;
				ptr->vprev = tempPtr;
				ptr->vnext = NULL;
				return 0;
			}
			else if( !(prty > tempPtr->vnext->vprty) )
                        {
                                printf("Entered\n");
                                // adding the node after the last occurence
                                ptr->vnext = tempPtr->vnext;
                                
                                ptr->vprev = tempPtr;
                                //if(tempPtr->vnext != NULL)
                                        tempPtr->vnext->vprev = ptr;
                                        tempPtr->vnext = ptr;
                                return 0 ;
                        }
                }
                else
              	{
              	// if given priority is smallest among queue than it becomes first node				
			ptr->vprev = NULL;
			ptr->vnext = PQ_head;
			ptr->vnext->vprev = ptr;
			PQ_head = ptr;
			return 0;
	      	}
	      	tempPtr = tempPtr->vnext;
	}
	

}
int Insert_Priority(int data, int prty)
{
	vpq *ptr = (vpq *)malloc(1 * sizeof(vpq));
	vpq *tempPtr, *previous;
	if(ptr == NULL)
	{
		printf("Failed to allocate memory for new node\n");
		exit(1);
	}
	ptr->vdata = data;
	ptr->vprty = prty;

	if(PQ_head == NULL)
	{
		PQ_head = ptr;
		ptr->vprev = NULL;
		ptr->vnext = NULL;
		return 0;  // successfully added node 
	}
	tempPtr = PQ_head;
	while(tempPtr != NULL)
	{
		if(prty < tempPtr->vprty)//add before node
		{
			if(tempPtr != PQ_head)
				tempPtr->vprev->vnext = ptr;
			else
				PQ_head = ptr;
			ptr->vprev = tempPtr->vprev;
			ptr->vnext = tempPtr;
			tempPtr->vprev = ptr;
			return 0;
		}
		else if(prty >= tempPtr->vprty)//add after a node
		{
			if(tempPtr->vnext == NULL)
			{
				tempPtr->vnext = ptr;
				ptr->vprev = tempPtr;
				ptr->vnext = NULL;
				return 0;
			}
			else if(prty < tempPtr->vnext->vprty)
			{
				tempPtr->vnext->vprev = ptr;
				ptr->vnext = tempPtr->vnext;
				ptr->vprev = tempPtr;
				tempPtr->vnext = ptr;
				return 0;
			}
		}
		tempPtr = tempPtr->vnext;
	}
}
				



int Display_All()
{
	vpq *tempPtr;
	int count = 0;
	if(PQ_head == NULL)
	{
		printf("Queue is empty\n");
		return 0;
	}
	tempPtr = PQ_head;
	printf("Displaying all nodes in queue\n");
	printf("---   (Node Data --#priority level)   -----\n");
	while(tempPtr != NULL)
	{
		printf(" (%d --- %d)", tempPtr->vdata, tempPtr->vprty);

		tempPtr = tempPtr->vnext;
		count++;
	}
	printf("\n-----------------------------------------\n");
	return count;
}


void Display_Prty(int prty)
{
	vpq *tempPtr;
	int prtys = 0;
	if(PQ_head == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	tempPtr = PQ_head;
	printf("---Node Data ------#priority level-----\n");
	while(tempPtr != NULL)
	{
		if(tempPtr->vprty == prty)
		{
			printf("   %d               %d\n", tempPtr->vdata, tempPtr->vprty);
			prtys++;
		}
		tempPtr = tempPtr->vnext;
	}
	if(prtys == 0)
		printf("No Nodes found with given priority\n");
}
//display with addresses
void Display_Queue_Debug()
{
	vpq *temp;
	if(PQ_head == NULL)
	{
		printf("Queue is empty\n");
		return;
	}

	temp = PQ_head;
	printf("front: %-15p\n", PQ_head);
	while(temp != NULL)
	{
		printf("prev:%-15p node:%-15p  next:%-15p prty:%d  data:%d \n",temp->vprev, temp, temp->vnext, temp->vprty, temp->vdata);

		temp = temp->vnext;
	}
	//printf("rear: %-15p\n", rear);

}

void DeleteAll()
{
	vpq *temp;
	if(PQ_head == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp = PQ_head;
	while(PQ_head != NULL)
	{
		temp = PQ_head; 
		PQ_head = PQ_head->vnext;
		free(temp);
	}

}



void DeletePrty_Group(int prty)
{
	vpq *temp, *del;
	int ifDeleted = 0;
	if(PQ_head == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	/*if(PQ_head->vprty == prty)
	{
		if(PQ_head->vnext == NULL)
		{
			free(PQ_head);
			PQ_head == NULL;
			return;
		}
			


	}*/
			

	temp = PQ_head;
	while(temp != NULL)
	{
		if(temp->vprty == prty)
		{
			if(temp->vnext != NULL)
				temp->vnext->vprev = temp->vprev;
			if(temp != PQ_head)
				temp->vprev->vnext = temp->vnext;
			else
				PQ_head = temp->vnext;
			del = temp;
			temp = temp->vnext;
			free(del);
			ifDeleted = 1;
		}
		else
			temp = temp->vnext;		
		
	}
	if( ifDeleted == 0)
		printf("\tPriority group not found in queue\n");
	else
		printf("\tGiven Priority group deleted\n");


}

void Delete_DataPrty(int data, int prty)
{
	int ifDeleted = 0;

	vpq *temp, *del;
	temp = PQ_head;
	while(temp != NULL)
	{
		if( (temp->vprty == prty) && (temp->vdata == data) )
		{
			if(temp->vnext != NULL)
				temp->vnext->vprev = temp->vprev;
			if(temp != PQ_head)
				temp->vprev->vnext = temp->vnext;
			else
				PQ_head = temp->vnext;
		
			free(temp);
			ifDeleted = 1;
			break;
		}

		temp = temp->vnext;		
		
	}
	if( ifDeleted == 0)
		printf("priority and data not found in queue\n");
	else
		printf("--------given node deleted----\n");
}


void Create_Prty_Queue(int size)
{
	int i, data, prty;
	printf("Enter data and priority \n");
	printf(" 'data:priority' \n" );
	
	for(i = 0; i < size; i++)
	{
		scanf("%d:%d",&data,&prty);
		//calling insert function and passing the num to that function
		//int Insert_vPQ(int data, int prty)
		Insert_vPQ(data, prty);
		
	}
}
		
//Selection Sort sorting on data
void SelectionSort()
{
	if(PQ_head == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(PQ_head->vnext == NULL)
		return;
	vpq *p, *q, *temp;
	
	for(p = PQ_head; p->vnext != NULL; p = p->vnext)
	{
		for(q = p->vnext; q != NULL; q = q->vnext)
		{
			if(p->vdata > q->vdata)
			{
				if(p->vnext == q)
				{
					if(q->vnext != NULL)
						q->vnext->vprev = p;
					temp = p->vprev;
					if(p != PQ_head)
						p->vprev->vnext = q;
					p->vprev = q;
					p->vnext = q->vnext;
					q->vnext = p;
					if(p == PQ_head)
					{
						PQ_head = q;
					}
					q->vprev = temp;
				}
				else
				{
					if(p != PQ_head)
						p->vprev->vnext = q;
					if(q->vnext != NULL)
						q->vnext->vprev = p;
					temp = p->vnext;
					p->vnext = q->vnext;
					q->vnext = temp;

					temp->vprev = q;
					q->vprev->vnext = p;

					temp = p->vprev;
					p->vprev = q->vprev;
					q->vprev = temp;
					if(p == PQ_head)
						PQ_head = q;
				}
				temp = p;
				p = q;
				q = temp;		
			}
		}
	}
	
}	
void Frequency()
{
	if(PQ_head == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	int freq = 0, flag = 0, j;
	vpq *p, *q, *temp;
	temp = PQ_head;
	int prty_arr[100], i;
	for(i = 0,p = PQ_head; p != NULL; p = p->vnext)
	{
		freq = 1;
		prty_arr[i] = p->vprty;
		for(j = 0; j < NodeCount; j++)
		{
			if(p->vprty == prty_arr[j])
				flag = 1;
		}
		if(flag == 1)
			continue;
		for(q = p->vnext; q != NULL; q = q->vnext)
		{
			if(p->vprty == q->vprty)
			{
				freq++;
			}
		}
		printf(" priority: %d   freq: %d\n",p->vprty, freq);
		
	}
	
	
}

//sorting based on priority using selection sort
void Sorting_Priority(int prty)
{
	vpq *p, *q, *temp, *st = NULL, *e = NULL;
	if(PQ_head == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(PQ_head->vnext == NULL)
	{
		printf("Only single element is present\n");
		return;
	}
	
	// finding last occurence of priority
	temp = PQ_head;
	while(temp != NULL)
	{
		if( (prty == temp->vprty) && (st == NULL) )
		{
			st = temp;
			
		}
		if( (prty == temp->vprty)  )
		{
			if( (temp->vnext == NULL) || (prty != temp->vnext->vprty) )
				e = temp->vnext;
		}
		temp = temp->vnext;
		
	}
	
	printf("start:%-15p\n",st);
	printf("end:%-15p\n",e);
	
	for(p = st; (p != e) ; p = p->vnext)
	{
		for(q = p->vnext; (q != e); q = q->vnext )
		{
			printf("data:%d		prty:%d\n",p->vdata,p->vprty);
			if(p->vdata > q->vdata)
			{
				if(p->vnext == q) //adjacent nodes
				{
					if(q->vnext != NULL)
						q->vnext->vprev = p;
					temp = p->vprev;
					if(p != PQ_head)
						p->vprev->vnext = q;
					p->vprev = q;
					p->vnext = q->vnext;
					q->vnext = p;
					if(p == PQ_head)
					{
						PQ_head = q;
					}
					q->vprev = temp;
				}
				else// non ajacent nodes
				{
					if(p != PQ_head)
						p->vprev->vnext = q;
					if(q->vnext != NULL)
						q->vnext->vprev = p;
					temp = p->vnext;
					p->vnext = q->vnext;
					q->vnext = temp;

					temp->vprev = q;
					q->vprev->vnext = p;

					temp = p->vprev;
					p->vprev = q->vprev;
					q->vprev = temp;
					if(p == PQ_head)
						PQ_head = q;
				}
				temp = p;
				p = q;
				q = temp;		
			}
		}
	}
}	
	/*
	printf("start:%-15p\n",st);
	for(p = st; p->vprty == p->vnext->vprty; p = p->vnext)
	{
		for(q = p->vnext; q->vprty == q->vnext->vprty; q = q->vnext )
		{
			printf("data:%d		prty:%d\n",p->vprty,p->vdata);
			if(p->vdata > q->vdata)
			{
				if(p->vnext == q) //adjacent nodes
				{
					if(q->vnext != NULL)
						q->vnext->vprev = p;
					temp = p->vprev;
					if(p != PQ_head)
						p->vprev->vnext = q;
					p->vprev = q;
					p->vnext = q->vnext;
					q->vnext = p;
					if(p == PQ_head)
					{
						PQ_head = q;
					}
					q->vprev = temp;
				}
				else// non ajacent nodes
				{
					if(p != PQ_head)
						p->vprev->vnext = q;
					if(q->vnext != NULL)
						q->vnext->vprev = p;
					temp = p->vnext;
					p->vnext = q->vnext;
					q->vnext = temp;

					temp->vprev = q;
					q->vprev->vnext = p;

					temp = p->vprev;
					p->vprev = q->vprev;
					q->vprev = temp;
					if(p == PQ_head)
						PQ_head = q;
				}
				temp = p;
				p = q;
				q = temp;		
			}
		}
	}*/

		
	
void BubbleSort_Queue(int prty)
{
	printf("Given priority: %d\n",prty);
	if(PQ_head == NULL)
		return;
	if(PQ_head->vnext == NULL)
		return;
	vpq *p, *q, *temp, *e;

	for(p = PQ_head, e = NULL; PQ_head->vnext != e; e = q)
	{
		for( p = PQ_head ; p->vnext != e; p = p->vnext)
		{
			q = p->vnext;
			if(prty == p->vprty )
			{
				if(p->vdata > q->vdata)
				{



					printf("---\n");
					p->vnext = q->vnext;
					if(p != PQ_head)	
						p->vprev->vnext = q;
					else
						PQ_head  = q;
					q->vnext = p;
						p->vnext->vprev = p;
					temp = p->vprev;
					p->vprev = q;
					q->vprev = temp;


					temp = p;
					p = q;
					q = temp;
				}
			}
		}
	}
}	
	
	









































//--------------------------------------------------------------------------------------------------//
/*
		if(prty < tempPtr->vprty )
		{
			//add before node
			ptr->vnext = tempPtr;
			ptr->vprev = tempPtr->vprev;
			if(tempPtr != PQ_head)
			tempPtr->vprev->vnext = ptr;
			tempPtr->vprev = ptr;
			return 0;
		}
		if(tempPtr->vnext == NULL)
		{
			//add after node 
			//adding at last
			ptr->vnext = NULL;
			ptr->vprev = tempPtr;
			tempPtr->vnext = ptr;
			return 0;
		}

*/
			
	
