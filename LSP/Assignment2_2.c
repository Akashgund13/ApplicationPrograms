#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Ret = 0;

    char Arr[50];

    if(argc != 2)
    {
        printf("Insufficient number of arguments\n");
        return -1;
    }

    printf("Enter the data that you want to write into the file\n");
    scanf("%[^'\n']s", Arr);

    fd = open(argv[1], O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open the file \n");
        return -1;
    }

    Ret = write(fd, Arr, strlen(Arr));

    printf("%d bytes gets successfully written in the file \n", Ret);

    close(fd);

    return 0;
}