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
    PNODE temp = *Head;
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
        while(temp->next != NULL)              // type 2 cha while loop
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // #
    }
}

void InsertAtPos(PPNODE Head, int No, int ipos)
{}

void DeleteFirst(PPNODE Head)
{   
    if(*Head == NULL)                // LL is empty
    {
        return;
    }
    else if((*Head)->next == NULL)            // LL contains only one node
    {
        free(*Head);
        *Head = NULL;
    }
    else            // LL contains more than one node
    {
        *Head = (*Head)->next;
        free((*Head)->prev);        // #
        (*Head)->prev = NULL;       // #
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)                // LL is empty
    {
        return;
    }
    else if((*Head)->next == NULL)            // LL contains only one node
    {
        free(*Head);
        *Head = NULL;
    }
    else            // LL contains more than one node
    {
        while(temp->next->next != NULL)      // type 3 cha while loop
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;        
    }
}

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

    InsertLast(&First, 111);
    InsertLast(&First, 121);

    iRet = Count(First);
    printf("Number of nodes are : %d\n", iRet);
    Display(First);

    DeleteFirst(&First);
    DeleteLast(&First);

    iRet = Count(First);
    printf("Number of nodes are : %d\n", iRet);
    Display(First);

    return 0;
}