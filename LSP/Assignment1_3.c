#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int Mode = 0;

    if(argc != 3)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    if(strcmp(argv[2] , "Read") == 0)
    {
        Mode = R_OK;
    }
    else if(strcmp(argv[2], "Write") == 0)
    {
        Mode = W_OK;
    }
    else if(strcmp(argv[2], "Execute") == 0)
    {
        Mode = X_OK;
    }

    if(access(argv[1], Mode) < 0)
    {
        printf("Unable to access %s file in %s mode\n", argv[1], argv[2]);
    }
    else
    {
        printf("You can access %s file in %s mode\n", argv[1], argv[2]);
    }

    return 0;
}