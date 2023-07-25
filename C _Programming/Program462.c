#include<stdio.h>

void DisplayI(int iNo)
{
    int iCnt = 1;

    while(iCnt <= iNo)
    {
        printf("%d\t", iCnt);
        iCnt++;
    }
}

int main()
{
    int iValue = 0;

    printf("Enter the number : \n");
    scanf("%d", &iValue);

    DisplayI(iValue);

    return 0;
}