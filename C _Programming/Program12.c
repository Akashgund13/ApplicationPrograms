// Display "Jay Ganesh" 5 times on screen

#include<stdio.h>

void Display(int iNo)
{
    int iCnt = 0;

    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        printf("Jay Ganesh...\n");
    }
}

int main()
{
    int iValue = 0;

    printf("Please enter the frequency of Jay Ganesh statement : \n");
    scanf("%d", &iValue);

    Display(iValue);

    return 0;
}


