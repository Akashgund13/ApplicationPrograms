#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define BUFFERSIZE 1024

int main()
{
    char FileName[50];
    int fd = 0;
    char Arr[BUFFERSIZE];
    int iRet = 0, iCnt = 0, iCountCapital = 0, iCountSmall = 0, iCountDigit = 0;

    printf("Enter the file that you want to open : \n");
    scanf("%s", FileName);

    fd = open(FileName, O_RDONLY);

    while(1)
    {
        iRet = read(fd, Arr, sizeof(Arr));  // 10
        if(iRet == 0)
        {
            break;
        }

        for(iCnt = 0; iCnt < iRet; iCnt++)
        {
            if((Arr[iCnt] >= 'A') && (Arr[iCnt] <= 'Z'))
            {
                iCountCapital++;
            }
            else if((Arr[iCnt] >= 'a') && (Arr[iCnt] <= 'z'))
            {
                iCountSmall++;
            }
            else if((Arr[iCnt] >= '0') && (Arr[iCnt] <= '9'))
            {
                iCountDigit++;
            }
        }
    }

    printf("Number of capital case letters are : %d\n", iCountCapital);
    printf("Number of small case letters are : %d\n", iCountSmall);
    printf("Number of digits are : %d\n", iCountDigit);


    close(fd);
    
    return 0;
}