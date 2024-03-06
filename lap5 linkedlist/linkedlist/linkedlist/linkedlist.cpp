#include <iostream>
using namespace std;
struct Node
{
    int Data;
    Node* Next;
};
Node* Head=NULL;
void Appened();
void Print();
void Insert();
void Delete();
int main()
{
    bool isDone=true;
    int i = 0;
    while (isDone)
    {
        int chNum;
        cout << "\n\n[1]Append\n[2]Insert\n[3]Delete\n[4]Print\n[5]Exit\n\n--> ";
        cin >> chNum;
        switch (chNum)
        {
        case 1:
        {
            Appened();
            i++;
            break;
        }
        case 2:
        {
            if(i>0)
                Insert();
            else
                cout << "\nThere is no element !!!\n";
            break;
        }
        case 3:
        {
            if (i > 0)
                Delete();
            else
                cout << "\nThere is no element !!!\n";
            break;
        }
        case 4:
        {
            Print();
            break;
        }
        case 5:
        {
            isDone = false;
            break;
        }
        default:
        {
            cout << "\nwrong input !!!\n";
            break;
        }
        }
    }
}
void Appened()
{
    int newValue;
    cout << "enter a new value : ";
    cin >> newValue;
    Node* newNode;
    newNode = new Node;
    newNode->Data = newValue;
    if (Head == NULL)
    {
        Head = newNode;
        newNode->Next = NULL;
    }
    else
    {
        Node* Temp;
        Temp = Head;
        while (Temp->Next!=NULL)
        {
            Temp = Temp->Next;
        }
        Temp->Next = newNode;
        newNode->Next = NULL;
    }
}
void Print()
{
    Node* walkerNodes=Head;
    if (Head == NULL)
        cout << "This List is Empty ...!\n";
    else
    {
        while (walkerNodes != NULL)
        {
            cout << walkerNodes->Data << "\t";
            walkerNodes = walkerNodes->Next;
        }
    }
}
void Insert()
{
    Node* previousNode=Head, * persentNode = Head, *newNode;
    int newvalue, searchedValue,Counter = 0;
    bool isFound=true;
    newNode = new Node;
    cout << "Enter the looking for value to insert before it : ";
    cin >> searchedValue;

    while (persentNode->Data != searchedValue)
    {
        previousNode = persentNode;
        persentNode = persentNode->Next;
        if (persentNode == NULL)
        {
            isFound = false;
            cout << "This Value is not fouded ...! \n";
            break;
        }
        Counter++;
    }
    // insert between 2 nodes
    if (isFound && Counter > 0)
    {
        cout << "Enter the new value : ";
        cin >> newvalue;
        newNode->Data = newvalue;
        previousNode->Next = newNode;
        newNode->Next = persentNode;
    }
    // insert between head & first node
    else if (isFound && Counter == 0)
    {
        cout << "Enter the new value : ";
        cin >> newvalue;
        newNode->Data = newvalue;
        newNode->Next = Head;
        Head = newNode;
    }
}
void Delete()
{
    Node* peresentNode=Head, * PreviousNode = Head;
    int deletedValue,Counter=0;
    cout << "Enter the value you want to delete it : ";
    cin >> deletedValue;
    while (peresentNode->Data!=deletedValue)
    {
        PreviousNode = peresentNode;
        peresentNode = peresentNode->Next;
        Counter++;
    }
    if (Counter > 0)
    {
        PreviousNode->Next= peresentNode->Next;
        free(peresentNode);
    }
    else if (Counter == 0)
    {
        Head = Head->Next;
        delete PreviousNode;
    }
}