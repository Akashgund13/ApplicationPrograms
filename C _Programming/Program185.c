#include<stdio.h>

void strcpycapitalX(char *src, char *dest)
{
    while(*src != '\0')
    {
        if((*src >= 'A') && (*src <= 'Z'))
        {
            *dest = *src;
            dest++;
        }
        src++;
    }
    *dest = '\0';
}

int main()
{
    char Arr[20];
    char Brr[20];
    
    printf("Enter the string : \n");
    scanf("%[^'\n']s", Arr);

    strcpycapitalX(Arr, Brr);

    printf("String after copy is : %s\n", Brr);
    
    return 0;
}