#include<iostream>
using namespace std;

typedef unsigned int UINT;

int OffBit(UINT iNo)
{
    UINT iMask = 0XFFFFFFBF;

    return (iNo & iMask);
}

int main()
{
    UINT iValue = 0;
    UINT iRet = 0;
    UINT iBit = 0;

    cout<<"Enter the number :"<<"\n";
    cin>>iValue;

    iRet = OffBit(iValue);
    cout<<"Result is : "<<iRet<<"\n";

    return 0;
}
