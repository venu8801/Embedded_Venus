/* program to print small and capital characters from a string using
 * mutex locks and conditional variables*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cvar = PTHREAD_COND_INITIALIZER;

void *cap(void *);
void *small(void *);

void main()
{
	pthread_t t1, t2;
	char str[100];

	printf("Enter the string: ");
	scanf("%[^\n]s",str);
	printf("[m]: %s\n",str);

	pthread_create(&t1, NULL, small, (void *)str);
	pthread_create(&t2, NULL, cap, (void *)str);

	pthread_join(&t1, NULL);
	pthread_join(&t2,NULL);

}

//thread 1
void *cap(void *ptr)
{
	char *str = (char *)ptr;

	int i;

	printf("%s\n",str);
	for(i = 0; str[i] != '\0'; i++)
	{
	printf("%c\n",str[i]);

		pthread_mutex_lock(&mtx);
		if((str[i] >= 'a') && (str[i] <= 'z'))
		{
			printf("%c",str[i]);
			//pthread_cond_signal(&cvar);
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			pthread_cond_wait(&cvar,&mtx);

		}
		else
			printf("%c",str[i]);
		pthread_mutex_unlock(&mtx);
	}


}

//thread 2
void *small(void *ptr)
{
	char *str = (char *)ptr;

	int i;

	for(i = 0; str[i] != '\0'; i++)
	{

		pthread_mutex_lock(&mtx);
		if((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			printf("%c",str[i]);
			pthread_cond_signal(&cvar);
		}
		else if(str[i] >= 'a' && str[i] <= 'z')
		
//	else /*if(str[i] >= 'A' && str[i] <= 'Z') 
	{
			pthread_cond_wait(&cvar,&mtx);

		}
		else
			printf("%c",str[i]);
		pthread_mutex_unlock(&mtx);
	}

}
