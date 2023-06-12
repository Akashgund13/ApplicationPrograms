#include<stdio.h>

void strcpytoggleX(char *src, char *dest)
{
    int Gap = 'a' - 'A';

    while(*src != '\0')
    {
        if((*src >= 'A') && (*src <= 'Z'))
        {
            *dest = *src + Gap;
        }
        else if((*src >= 'a') && (*src <= 'z'))
        {
            *dest = *src - Gap;
        }
        else
        {
            *dest = *src;
        }
        dest++;
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

    strcpytoggleX(Arr, Brr);

    printf("String after copy is : %s\n", Brr);
    
    return 0;
}