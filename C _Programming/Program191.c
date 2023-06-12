#include<stdio.h>

// 1 : travel till end of dest
// 2 : copy the data from end of dest
// 3 : write '\0' at the end of dest

void strncatX(char *src, char *dest, int iLength)
{
    // 1 : travel till end of dest
    while(*dest != '\0')
    {
        dest++;
    }
    
    // 2 : copy the data from end of dest
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;

        iLength--;
        if(iLength == 0)
        {
            break;
        }
    }

    // 3 : write '\0' at the end of dest
    *dest = '\0';
}

int main()
{
    char Arr[20];
    char Brr[20] = "Demo";
    int iNo = 0;
    
    printf("Enter the string : \n");
    scanf("%[^'\n']s", Arr);

    printf("Enter the number of letters that you want to concat :\n");
    scanf("%d", &iNo);

    strncatX(Arr, Brr, iNo);

    printf("String after copy is : %s\n", Brr);
    
    return 0;
}