#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    printf("Thread id from thread function is : %u\n", pthread_self());
    pthread_exit(NULL);
    return NULL;
}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID, NULL, ThreadProc, (int *)TID);

    if(ret != 0)
    {
        printf("Unable to create the thread\n");
        return -1;
    }

    printf("Thread id from the main function is : %u\n", TID);

    pthread_join(TID, NULL);

    printf("End of main thread\n");

    return 0;
}