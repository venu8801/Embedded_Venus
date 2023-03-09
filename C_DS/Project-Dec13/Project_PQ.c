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
void Display_All(void);
int Insert_vPQ(int data, int prty);
void Display_Prty(int);
void DeleteAll();
void DeletePrty_Group(int);
void Delete_DataPrty(int data, int prty);
void Display_Queue_Debug();


//main function start//
void main()
{
	int opt, subopt;
	int data, prty;
	int status;
	while(1)
	{
		printf("--------###--------------priority queue----------------###-------\n");
		printf("0.Exit\n1.Insert\n2.Display\n3.Delete\n");
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
				status = Insert_vPQ(data, prty);
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
						Display_All();
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
	if( (PQ_head->vnext == NULL))//contains only single node
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
	}
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
                                tempPtr->vnext = ptr;
                                ptr->vprev = tempPtr;
                                //if(tempPtr->vnext != NULL)
                                        tempPtr->vnext->vprev = ptr;
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
                                tempPtr->vnext = ptr;
                                ptr->vprev = tempPtr;
                                //if(tempPtr->vnext != NULL)
                                        tempPtr->vnext->vprev = ptr;
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

void Display_All()
{
	vpq *tempPtr;
	if(PQ_head == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	tempPtr = PQ_head;
	printf("Displaying all nodes in queue\n");
	printf("---   (Node Data --#priority level)   -----\n");
	while(tempPtr != NULL)
	{
		printf(" (%d --- %d)", tempPtr->vdata, tempPtr->vprty);

		tempPtr = tempPtr->vnext;
	}
	printf("\n-----------------------------------------\n");
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











/* while( (prty > tempPtr->vprty) && (tempPtr != NULL) )
                        {
                                printf("Entered\n");
                                tempPtr = tempPtr->vnext;
                                // adding the node after the last occurence
                                ptr->vnext = tempPtr->vnext;
                                tempPtr->vnext = ptr;
                                ptr->vprev = tempPtr;
                                //if(tempPtr->vnext != NULL)
                                        tempPtr->vnext->vprev = ptr;
                                return 0 ;
                         } */
