#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pid = 0, pid1 = 0, pid2 = 0;

    pid = fork();

    if(pid == 0)
    {
        sleep(3);
        printf("pid of child1 is %d and ppid is %d\n", getpid(), getppid());
    }
    else
    {
        pid1 = fork();

        if(pid1 == 0)
        {
            sleep(2);
            printf("pid of child2 is %d and ppid is %d\n", getpid(), getppid());
        }
        else
        {
            pid2 = fork();
            
            if(pid2 == 0)
            {
                printf("pid of child3 is %d and ppid is %d\n", getpid(), getppid());
            }
            else
            {
                sleep(3);
                printf("pid of parent is : %d\n", getpid());
            }
        }
    }

    return 0;
}