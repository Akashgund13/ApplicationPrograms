#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    printf("Inside thread1\n");
    pthread_exit(NULL);
}

void * ThreadProc2(void *ptr)
{
    printf("Inside thread2\n");
    pthread_exit(NULL);
}

void * ThreadProc3(void *ptr)
{
    printf("Inside thread3\n");
    pthread_exit(NULL);
}

void * ThreadProc4(void *ptr)
{
    printf("Inside thread4\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2, TID3, TID4;
    int ret = 0;

    ret = pthread_create(&TID1, NULL, ThreadProc1, NULL);
    if(ret != 0)
    {
        printf("Unable to create the thread\n");
        return -1;
    }
    printf("Thread1 id from the main function is : %u\n", TID1);
    
    ret = pthread_create(&TID2, NULL, ThreadProc2, NULL);
    if(ret != 0)
    {
        printf("Unable to create the thread\n");
        return -1;
    }
    printf("Thread2 id from the main function is : %u\n", TID2);
    
    ret = pthread_create(&TID3, NULL, ThreadProc3, NULL);
    if(ret != 0)
    {
        printf("Unable to create the thread\n");
        return -1;
    }
    printf("Thread3 id from the main function is : %u\n", TID3);
    
    ret = pthread_create(&TID4, NULL, ThreadProc4, NULL);
    if(ret != 0)
    {
        printf("Unable to create the thread\n");
        return -1;
    }
    printf("Thread4 id from the main function is : %u\n", TID4);

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);
    pthread_join(TID3, NULL);
    pthread_join(TID4, NULL);

    printf("End of main thread\n");

    return 0;
}