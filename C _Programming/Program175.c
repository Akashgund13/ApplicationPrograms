#include<stdio.h>

void Frequency(char *str)
{
    int iCountSmall = 0;
    int iCountCapital = 0;
    
    while(*str != '\0')
    {
        if((*str >= 'a') && (*str <= 'z'))
        {
            iCountSmall++;
        }

        else if((*str >= 'A') && (*str <= 'Z'))
        {
            iCountCapital++;
        }
        str++;
    }
    printf("Number of small characters are :%d\n", iCountSmall);
    printf("Number of capital characters are :%d\n", iCountCapital);
}

int main()
{
    char Arr[20];
    
    printf("Enter the string : \n");
    scanf("%[^'\n']s", Arr);

    Frequency(Arr);
    
    return 0;
}