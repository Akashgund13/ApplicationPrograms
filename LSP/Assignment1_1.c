#include<stdio.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    else 
    {
        printf("The file is successfully opened with FD %d\n", fd);
    }

    close(fd);

    return 0;
}