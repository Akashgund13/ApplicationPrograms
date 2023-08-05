#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    printf("Inside thread\n");
}

int main()
{
    pthread_t TID;
    int Ret = 0;

    Ret = pthread_create(&TID, NULL, ThreadProc, NULL);

    if(Ret != 0)
    {
        printf("Unable to create the thread\n");
        return -1;
    }

    printf("Thread is created with ID : %u\n", TID);

    return 0;
}