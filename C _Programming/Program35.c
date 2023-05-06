#include<stdio.h>
#include<stdbool.h>

unsigned long int CalculatePower(int iBase, int iPower)
{
    int iCnt = 0;
    unsigned long int iResult = 1;

    if((iBase < 0) || (iPower < 0))
    {
        return 0;
    }

    for(iCnt = 1; iCnt <= iPower; iCnt++)
    {
        iResult = iResult * iBase;
    }
    return iResult;
}

int main()
{
    int iValue1 = 0, iValue2 = 0;
    unsigned long int iRet = 0;

    printf("Enter Base : \n");
    scanf("%d", &iValue1);

    printf("Enter power : \n");
    scanf("%d", &iValue2);

    iRet = CalculatePower(iValue1, iValue2);

    printf("Result is : %d\n", iRet);

    return 0;
}