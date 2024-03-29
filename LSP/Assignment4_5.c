#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{   
    int fd = 0;
    char Arr[20];
    int ret = 0;
    int size = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    lseek(fd, atoi(argv[2]), 0);
    ret = read(fd, Arr, 20);

    printf("Data from the file is :\n");
    write(1, Arr, ret);

    close(fd);
    
    return 0;
}