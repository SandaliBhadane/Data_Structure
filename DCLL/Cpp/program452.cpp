////////////////////////////////////////////////////////////////////////////////////
//
//  File Name   :     program452.cpp
//  Description :     Doubly Circular Linked List
//                  
//  Input       :         
//  Output      :        
//  Author      :     Sandali Sunil Bhadane
//  Date        :      23/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////

// Doubly Circular

//DOUBLYCLL
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DOUBLYCLL
{
    private:
    PNODE first;
    PNODE last;
    int iCount;

public:    
DOUBLYCLL()
{
    cout<<"Object of DOUBLYCLL gets created.\n";
    first = NULL;
    last = NULL;
    iCount = 0;
}

void InsertFirst(int no)
{
PNODE newn = NULL;

newn = new NODE;

newn->data = no;
newn->next = NULL;
newn->prev = NULL;

if(first == NULL && last == NULL)
{
    first = newn;
    last = newn;
}
else
{
    newn->next = first;
    first->prev = newn;
    first = newn;
    
    last->next = first;

}
iCount++;
}

void InsertLast(int no)
{
PNODE newn = NULL;

newn = new NODE;

newn->data = no;
newn->next = NULL;
newn->prev = NULL;

if(first == NULL && last == NULL) // LL is empty
{
    first = newn;
    last = newn;
}
else    // LL contains one or more
{
    last->next = newn;
    newn->prev = last;
    last = newn;
}

last->next = first;
first->prev = last;

iCount++;
}

void InsertAtPos(int no, int pos)
{
PNODE temp = NULL;
PNODE newn = NULL;
int iCnt = 0;


if(pos < 1 || pos > iCount+1)
{
    printf("Invalid position\n");
    return;
}

if(pos == 1)
{
    InsertFirst(no);
}
else if(pos == iCount+1)
{
    InsertLast(no);
}
else
{
    newn = new NODE;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    temp = first;

    for(iCnt = 1; iCnt < pos-1; iCnt++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    newn->next->prev = newn;

    temp->next = newn;
    newn->prev = temp;

    iCount++;
}
}

void DeleteFirst()
{
if(first == NULL && last == NULL) // LL is empty
{
    return;
}
else if(first == last)    // LL contains 1 node
{
    delete(first);
    first = NULL;
    last = NULL;
}
else
{
    first = first ->next;
    delete(first->prev);

    last->next = first;
    first->prev = last;
}
iCount--;
}

void DeleteLast()
{
if(first == NULL && last == NULL) // LL is empty
{
    return;
}
else if(first == last)    // LL contains 1 node
{
    delete(first);
    first = NULL;
    last = NULL;
}
else
{
    last = (last)->prev;
    delete(last->next);
    
    (last)->next = first;
    (first)->prev = last;
}    
iCount--;
}

void DeleteAtPos(int pos)
{
PNODE temp = NULL;
int iCnt = 0;

if(pos < 1 || pos > iCount)
{
    printf("Invalid position\n");
    return;
}

if(pos == 1)
{
    DeleteFirst();
}
else if(pos == iCount)
{
    DeleteLast();
}
else
{
    temp = first;

    for(iCnt = 1; iCnt < pos-1; iCnt++)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;
    delete(temp->next->prev);
    temp->next->prev = temp;
    iCount--;
}
}

void Display()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        printf("Linked List is empty\n");
        return;
    }

    printf(" <=> ");
    
    do
    {
        printf("| %d | <=> ",first->data);
        first = first -> next;
    }while(first != last->next);
    
    printf("\n");
}

int Count()
{
    return iCount;
}
};

int main()
{
    DOUBLYCLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(21,3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}
