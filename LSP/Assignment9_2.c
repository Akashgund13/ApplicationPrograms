#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int Ret1 = 0;
    int Ret2 = 0;
    int status1, status2;
    
    Ret1 = fork();
    if(Ret1 == 0)
    {
        execl("./Process1", "NULL", NULL);
    }
    wait(&status1);

    Ret2 = fork();
    if(Ret2 == 0)
    {
        execl("./Process2", "NULL", NULL);
    }

    wait(&status2);

    return 0;
}