#include<stdio.h>

void Display(int iNo)
{
    int iCnt = 0;

    if(iNo < 0)            // Updator
    {
        iNo = -iNo;
    }
    
    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        printf("%d\n", iCnt);
    }
}
int main()
{
    int iValue = 0;

    printf("Enter the number : \n");
    scanf("%d", &iValue);

    Display(iValue);
    
    return 0;
}