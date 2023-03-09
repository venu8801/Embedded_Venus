/* project server side code */
/* written by  Venu Gopal A 
 * 	*/

#include<stdio_ext.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
void main()
{

	int opt;

	int servSock, clientSock;
	struct sockaddr_in serv, client;

	memset(&serv, 0, sizeof(serv));


	servSock = socket()



}


int init_db() // function which initializes database 
{
	// directory to maintain database
	int ret;

	ret = mkdir("/home/venus/bank_db", 0700)
	if(ret < 0)
	{
		printf("failed to create database directory\n");
		return -1;
	}
	ret = chdir("/home/venus/bank_db"); //changes current directory to database
	if(ret < 0)
	{
		printf("failed to create database directory\n");
		return -1;
	}
	
	return 0;

}





