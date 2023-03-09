/* message queue server side code */
#include<sys/msg.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#define KEY 0x1998860
#define MSG_TYPE 1
struct msg
{
	long msgtype;
	long pid;
	char buff[200];
}M;
void main()
{
	char rbuff[100];
	int msqid;
	while(1)
	{

		
		msqid = msgget(KEY, IPC_CREAT | 0660);
		if(msqid < 0)
		{
			/* on failure of msgget() */
			printf("failed to get message queue ID\n");
			exit(1);
		}
		printf("waiting for message--\n");
		int msg_ret = msgrcv(msqid, &M, sizeof(struct msg), MSG_TYPE, 0);
		if(msg_ret < 0)
		{
			printf("failure of msgrcv");
			exit(2);
		}
		printf("[c]: %s\n",M.buff);
		printf("[s] : ");
		__fpurge(stdin);
		scanf("%[^\n]",M.buff);
		if(strcmp(M.buff,"//exit")==0)
			exit(0);

		msqid = msgsnd(msqid, &M, 200, 0);

	}
	//rbuff[msg_ret] = '\0';
	//printf("rbuff: %s\n",M.buff);


}

