#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}Node, *PNODE, **PPNODE;

class SinglyLL
{
    private:
        PNODE First;         // Characteristics
        int iCount;          // characteristics

    public:
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

// Implementations of all behaviours

int main()
{
    SinglyLL obj1();
    return 0;
}