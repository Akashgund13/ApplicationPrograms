#include<iostream>
using namespace std;

template <class T>
T Maximum(T Arr[], int Size)
{
    int iCnt = 0;
    T Max = Arr[0];

    for(iCnt = 0; iCnt < Size; iCnt++)
    {
        if(Arr[iCnt] > Max)
        {
            Max = Arr[iCnt];
        }
    }
    return Max;
}

int main()
{
    int Ret = 0;
    int A[] = {10, 20, 30, 40, 50};
    Ret = Maximum(A, 5);
    cout<<"Maximum is : "<<Ret<<"\n";

    double dRet = 0;
    double B[] = {10.78, 20.65, 30.34, 40.56, 50.67};
    dRet = Maximum(B, 5);
    cout<<"Maximum is : "<<dRet<<"\n";
    
    return 0;
}