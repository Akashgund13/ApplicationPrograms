#include<iostream>
using namespace std;

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        void BubbleSortEfficient();
        void SelectionSort();
};

template <class T>
ArrayX<T> :: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements :"<<"\n";
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX<T> :: Display()
{
    cout<<"Elements from tha array are :"<<"\n";

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
        cout<<"Data after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void ArrayX<T> :: SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

int main()
{
    int iValue = 0;

    cout<<"Enter the size of an array :"<<"\n";
    cin>>iValue;
    
    ArrayX<int> *obj = new ArrayX<int>(iValue);       

    obj->Accept();
    obj->Display();

    obj->SelectionSort();

    cout<<"Data after sorting is : \n";
    obj->Display();

    delete obj;
    
    return 0;
}