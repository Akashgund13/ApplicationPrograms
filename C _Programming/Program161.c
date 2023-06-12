#include<stdio.h>

int strlenX(char *str)         // str is just a character pointer
{
    int iCount = 0;

    while(*str != '\0')
    {
        iCount++;
        str++;
    }
    return iCount;
}

int main()
{
    char Arr[20];
    int iRet = 0;

    printf("Enter string :\n");
    scanf("%[^'\n']s", Arr);

    iRet = strlenX(Arr);  // strlenX(100);

    printf("Length of string is : %d\n", iRet);
    
    return 0;
}