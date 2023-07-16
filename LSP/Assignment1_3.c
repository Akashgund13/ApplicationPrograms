#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Mode = 0;

    if(argc != 3)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    if(strcmp(argv[2] , "Read") == 0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2], "Write") == 0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDONLY;
    }

    fd = access(argv[1], Mode);

    if(fd == -1)
    {
        printf("File is not accessible\n");
    }
    else
    {
        printf("File is get accessed\n");
    }

    return 0;
}