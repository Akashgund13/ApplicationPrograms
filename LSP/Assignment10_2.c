#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    int iCnt = 0;

    printf("Inside thread 1\n");

    for(iCnt = 1; iCnt <= 500; iCnt++)
    {
        printf("%d\n", iCnt);
    }
}

void * ThreadProc2(void *ptr)
{
    int iCnt = 0;

    printf("Inside thread 2\n");

    for(iCnt = 500; iCnt >= 1; iCnt--)
    {
        printf("%d\n", iCnt);
    }
}

int main()
{
    pthread_t TID1, TID2;
    int Ret1 = 0, Ret2 = 0;

    Ret1 = pthread_create(&TID1, NULL, ThreadProc1, NULL);

    if(Ret1 != 0)
    {
        printf("Unable to create the thread\n");
        return -1;
    }

    printf("Thread2 is created with ID : %u\n", TID1);

    Ret2 = pthread_create(&TID2, NULL, ThreadProc2, NULL);

    if(Ret2 != 0)
    {
        printf("Unable to create the thread\n");
        return -1;
    }

    printf("Thread2 is created with ID : %u\n", TID2);

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    printf("End of main thread\n");

    return 0;
}