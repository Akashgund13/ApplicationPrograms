#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}Node, *PNODE, **PPNODE;

class SinglyLL
{
    public:
        PNODE First;         // Characteristics
        int iCount;          // characteristics

        SinglyLL();          // Constructor

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int iCount();
        
};

int main()
{
    SinglyLL obj1();
    return 0;
}