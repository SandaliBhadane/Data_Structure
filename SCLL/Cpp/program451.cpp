////////////////////////////////////////////////////////////////////////////////////
//
//  File Name   :     program451.cpp
//  Description :     Singly Circular Linked List
//                  
//  Input       :         
//  Output      :        
//  Author      :     Gitanjali Patil
//  Date        :      23/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////

// Singly Circular

//SINGLYCLL
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *last;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:    
        SinglyCLL()
        {
            cout<<"Object of SinglyCLL gets created.\n";
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
            newn->last = NULL;

            if(first == NULL || last == NULL)
            {
                first = newn;
                last = newn;
            }
            else
            {
                newn-> next = first;
                first = newn;
            }
            last -> next = first;

            iCount++;

        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->last = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;
            }
            else 
            {
                last->next = newn;
                last = newn;
            }
            last -> next = first;

            iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            int iCnt = 0;

            if(pos<1 || pos > iCount+1)
            {
                cout<<"Inavlid Position\n";
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


                temp = first;
                for(iCnt = 1; iCnt <= pos-1 ; iCnt++)
                {
                    temp = temp-> next ;
                    iCnt++;
                }

                newn -> next = temp -> next;
                temp->next = newn;
                last->next = first;

                iCount++;
            }



        }

        void DeleteFirst()
        {
            PNODE temp = NULL;
            if(first == NULL &&  last == NULL)
            {
                cout<<"Linked List is Empty";
                return;
            }
            else if(first == last)
            {
                free(first);
                first = NULL;
                last = NULL;
            }
            else
            {
                temp = first;
                first = first->next;
                free(temp);
                last->next = first;
            }

            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;
            if(first == NULL &&  last == NULL)
            {
                cout<<"Linked List is Empty";
                return;
            }
            else if(first == last)
            {
                free(first);
                first = NULL;
                last = NULL;
            }
            else
            {
                temp = first;
                while(temp->next != last)
                {
                    temp = temp -> next;
                }
                free(last);
                last = temp;
                last->next = first;
            }

            iCount--;
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            int iCnt = 0;

            if(pos<1 || pos > iCount)
            {
                cout<<"Inavlid Position\n";
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
                for(iCnt = 1; iCnt <= pos-1 ; iCnt++)
                {
                    temp = temp-> next ;
                    iCnt++;
                }
                target = temp->next;
                temp->next = target->next;
                free(target);

                iCount--;

            }
        }

        void Display()
        {
            do
            {
                printf("|%d|->",first -> data);
                first = first -> next;
            } while (first != last -> next);

            printf("\n");
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    SinglyCLL obj;
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