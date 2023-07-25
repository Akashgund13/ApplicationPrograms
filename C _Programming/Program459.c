#include<stdio.h>

void DisplayI(int iNo)
{
    int iCnt = 1;

    while(iCnt <= iNo)
    {
        printf("*\t");
        iCnt++;
    }
    printf("\n");
}

void DisplayR(int iNo)
{
    int iCnt = 1;

    if(iCnt <= iNo)
    {
        printf("*\t");
        iCnt++;
        DisplayR(iNo);    // Recursive call
    }
    printf("\n");
}



int main()
{
    int iValue = 0;

    printf("Enter the number : \n");
    scanf("%d", &iValue);

    DisplayR(iValue);

    return 0;
}