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
    int iCount = 0;

    while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
}

int main()
{
    int iRet = 0;
    PNODE First = NULL;

    InsertFirst(&First, 101);
    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    iRet = Count(First);
    printf("Number of nodes are : %d\n", iRet);

    Display(First);

    return 0;
}