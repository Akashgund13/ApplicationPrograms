#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;                     // #
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;                     // #

    if(*Head == NULL)      // LL is empty
    {
        *Head = newn;
    }
    else            // LL contains at least one node
    {
        (*Head)->prev = newn;            // #
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;                     // #

    if(*Head == NULL)      // LL is empty
    {
        *Head = newn;
    }
    else            // LL contains at least one node
    {
        
    }
}

void InsertAtPos(PPNODE Head, int No, int ipos)
{}

void DeleteFirst(PPNODE Head)
{}

void DeleteLast(PPNODE Head)
{}

void DeleteAtPos(PPNODE Head, int ipos)
{}

void Display(PNODE Head)
{
    printf("Elements of Linked List are : \n");
    printf("NULL <=> ");
    while(Head != NULL)
    {
        printf("| %d |<=> ", Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
}

int Count(PNODE Head)
{

    return 0;
}

int main()
{
    PNODE First = NULL;

    return 0;
}