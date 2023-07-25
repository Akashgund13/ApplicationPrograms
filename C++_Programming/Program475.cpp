#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
};

ArrayX :: ArrayX(int iNo)
{
    cout<<"Inside constructor to allocate memory"<<"\n";
    this->iSize = iNo;
    this->Arr = new int[iSize];
}

ArrayX :: ~ArrayX()
{
    cout<<"Inside destructor to deallocate memory"<<"\n";
    delete []Arr;
}

void ArrayX :: Accept()
{
    cout<<"Inside Accept method"<<"\n";

    cout<<"Enter the elements :"<<"\n";

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

void ArrayX :: Display()
{
    cout<<"Inside Display method"<<"\n";

    cout<<"Elements from tha array are :"<<"\n";

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}


int main()
{
    cout<<"Inside main"<<"\n";

    int iValue = 0;

    cout<<"Enter the size of an array :"<<"\n";
    cin>>iValue;

    ArrayX obj(iValue);

    obj.Accept();
    obj.Display();

    cout<<"End of main"<<"\n";
    
    return 0;
}