#include<iostream>
using namespace std;

template <class T>           // Template header    T = Template variable/argument
T Addition(T No1, T No2)
{
    T Ans;
    Ans = No1 + No2;
    return Ans;
}

int main()
{
    int A = 10;
    int B = 11;
    int Ret = 0;
    Ret = Addition(A, B);
    cout<<"Addition is : "<<Ret<<"\n";

    double X = 90.7;
    double Y = 78.9;
    double Result = 0.0; 
    Result = Addition(X, Y);
    cout<<"Addition is : "<<Result<<"\n";

    float L = 90.7f;
    float M = 78.9f;
    float Resultf = 0.0f; 
    Resultf = Addition(L, M);
    cout<<"Addition is : "<<Resultf<<"\n";

    return 0;
}