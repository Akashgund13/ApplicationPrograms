#include<stdio.h>
#include<pthread.h>

#define _OPEN_THREADS

void *ThreadProc(void *arg)
{
    printf("Inside Thread\n");
    pthread_exit(NULL);
}

int main()
{
    int Ret, stat;
    pthread_attr_t attr;
    pthread_t Tid;

    Ret = pthread_attr_init(&attr);

    if(Ret == -1)
    {
        perror("error in pthread_attr_init");
        exit(1);
    }

    Ret = pthread_create(&Tid, &attr, ThreadProc, NULL);

    if(Ret == -1)
    {
        perror("error in pthread_create");
        exit(2);
    }

    Ret = pthread_join(Tid, (void *)&stat);
    exit(0);
}