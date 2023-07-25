#include<iostream>
using namespace std;

typedef unsigned int UINT;

int ToggleBit(UINT iNo, int iPos)
{
    UINT iMask = 0X00000001;
    UINT iResult = 0;

    iMask = iMask << (iPos -1);

    iResult = iNo ^ iMask;
    
    return iResult;
}

int main()
{
    UINT iValue = 0;
    UINT iRet = 0;
    UINT iBit = 0;

    cout<<"Enter the number :"<<"\n";
    cin>>iValue;

    cout<<"Enter the bit position"<<"\n";
    cin>>iBit;

    iRet = ToggleBit(iValue, iBit);
    cout<<"Result is : "<<iRet<<"\n";

    return 0;
}
