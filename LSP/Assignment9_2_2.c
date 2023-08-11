#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char Buffer[512];
    int iCnt = 0, Ret = 0, i = 0, fd = 0;

    fd = open("Hello.txt", O_RDONLY);

    while((Ret = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        for(i = 0; i < Ret; i++)
        {
            if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }

    printf("number of small letters from Hello.txt file are : %d\n", iCnt);

    close(fd);
    
    return 0;
}