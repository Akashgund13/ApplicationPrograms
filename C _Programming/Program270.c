#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE Head, int No)
{}

void InsertLast(PPNODE Head, int No)
{}

void InsertAtPos(PPNODE Head, int No, int ipos)
{}

void DeleteFirst(PPNODE Head)
{}

void DeleteLast(PPNODE Head)
{}

void DeleteAtPos(PPNODE Head, int ipos)
{}

void Display(PNODE Head)
{}

int Count(PNODE Head)
{

    return 0;
}

int main()
{
    PNODE First = NULL;
       
    return 0;
}