#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int iRet = 0;
    int Bytes = 0;

    char Arr[50] = {'\0'};
    if(argc != 2)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file \n");
        return -1;
    }

    printf("Enter the bytes that you want to read\n");
    scanf("%d", &Bytes);

    iRet = read(fd, Arr, Bytes);

    printf("Data from the file is : %s\n", Arr);

    return 0;
}