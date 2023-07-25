#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));   

    newn -> data = no;                      
    newn -> next = NULL;                    

    if(*Head == NULL)                     
    {
        *Head = newn;                     
    }
    else
    {
        newn -> next = *Head;              
        *Head = newn;                     
    }
}

void Display(PNODE Head)
{
    printf("Elements of Linked List are : \n");

    while(Head != NULL)
    {
        printf("| %d | -> ", Head->data);
        Head = Head -> next;
    }
    printf("NULL\n");
}

void SumDigit(PNODE Head)
{
    int iNo = 0;
    int iSum = 0;
    int iDigit = 0;

    while(Head != NULL)
    {
        iNo = Head->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        printf("%d\n", iSum);

        iSum = 0;
        Head = Head->next;
    }

}

int main()
{
    int iRet = 0;
    PNODE First = NULL;

    InsertFirst(&First, 111);
    InsertFirst(&First, 101);
    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    Display(First);

    SumDigit(First);

    return 0;
}
