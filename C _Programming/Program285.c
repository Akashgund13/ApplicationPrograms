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

void CheckPerfect(PNODE Head)
{
    int iNo = 0;
    int iSum = 0;
    int iCnt = 0;

    while(Head != NULL)
    {
        iNo = Head->data;

        for(iCnt = 1; iCnt <= (iNo/2); iCnt++)
        {
            if((iNo % iCnt) == 0)
            {
                iSum = iSum + iCnt;
            }
        }

        if(iSum == iNo)
        {
            printf("%d is a perfect number\n", iNo);

        }
        iSum = 0;
        Head = Head->next;        
    }

}

int main()
{
    int iRet = 0;
    PNODE First = NULL;

    InsertFirst(&First, 111);
    InsertFirst(&First, 28);
    InsertFirst(&First, 51);
    InsertFirst(&First, 496);
    InsertFirst(&First, 6);

    Display(First);

    CheckPerfect(First);

    return 0;
}
