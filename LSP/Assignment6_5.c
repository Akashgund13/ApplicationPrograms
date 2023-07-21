#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{   
    int fd = 0;
    char Arr[20];
    int ret = 0;
    int Offset = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    
    fd = open(argv[1], O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("Enter the offset number : \n");
    scanf("%d", &Offset);

    lseek(fd, atoi(argv[1]), Offset);
    ret = read(fd, Arr, 20);

    truncate(argv[1], Offset);

    close(fd);
    
    return 0;
}