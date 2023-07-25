#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int fd = 0;
    char Fname[30];
    int iRet = 0;

    char Arr[50] = {'\0'};

    printf("Enter the file name that you want to open : \n");
    scanf("%s", Fname);

    fd = open(Fname, O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    
    iRet = read(fd, Arr, 5);

    printf("%d bytes gets successfully fetched from the file \n", iRet);

    printf("Data from file is : \n");
    write(1, Arr, iRet);

    close(fd);

    return 0;
}