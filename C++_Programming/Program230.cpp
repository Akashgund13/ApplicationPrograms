#include<iostream>
using namespace std;

void DisplayHexadecimal(int iNo)
{
    int iDigit = 0;

    cout<<"Hexadecimal conversion of : "<<iNo<<" is : "<<"\n";
    while(iNo != 0)
    {
        iDigit = iNo % 16;
        char Arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
        
        if(iDigit <= 9)
        {
            cout<<iDigit;
        }
        else
        {
            cout<<Arr[iDigit -10];
        }
        iNo = iNo / 16;
    }
    cout<<"\n";
}
int main()
{
    int iValue = 0;

    cout<<"Enter the number :"<<"\n";
    cin>>iValue;

    DisplayHexadecimal(iValue);

    return 0;
}
