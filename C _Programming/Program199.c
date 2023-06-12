#include<stdio.h>
#include<stdbool.h>

bool stricmpX(char *str1, char *str2)        // Case Insensitive
{
    while((*str1 != '\0') && (*str2 != '\0'))
    {
        if(*str1 != *str2)             // Letters are different
        { 
            if((*str1 >= 'a') && (*str1 <= 'z'))        // First letter is small
            {
                if(*str1 != (*str2 + 32))
                {
                    break;
                }
            }
            else if((*str1 >= 'A') && (*str1 <= 'Z'))        // First letter is capital
            {
                if(*str1 != (*str2 - 32))
                {
                    break;
                }
            }
            else                    // Special symbol and digits
            {
                break;
            }
        }
        str1++;
        str2++;
    }
    
    if((*str1 == '\0') && (*str2 == '\0'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char Arr[20];
    char Brr[20];
    bool bRet = false;

    printf("Enter first string : \n");
    scanf("%[^'\n']s", Arr);

    printf("Enter second string : \n");
    scanf(" %[^'\n']s", Brr);

    bRet = stricmpX(Arr, Brr);        // strcmpX(100, 200);

    if(bRet == true)
    {
        printf("Both the strings are identical\n");
    }
    else
    {
        printf("Both the strings are different\n");
    }

    return 0;
}