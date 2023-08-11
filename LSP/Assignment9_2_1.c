#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char Buffer[512];
    int iCnt = 0, Ret = 0, i = 0, fd = 0;

    fd = open("Demo.txt", O_RDONLY);

    while((Ret = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        for(i = 0; i < Ret; i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCnt++;
            }
        }
    }

    printf("number of capital letters from Demo.txt file are : %d\n", iCnt);

    close(fd);

    return 0;
}