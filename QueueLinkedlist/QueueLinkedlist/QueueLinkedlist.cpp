#include <iostream>
using namespace std;

typedef int DT;

struct Node
{
    DT Data;
    Node* Next;
};

class QueueLL
{
public:
	QueueLL()
    {}
	~QueueLL()
    {}
    void EnQueue()
    {
        DT newValue;
        Node* newNode;
        newNode = new Node;
        cout << "\nEnter the value : ";
        cin >> newValue;
        newNode->Data = newValue;
        if (Front == NULL && Rear == NULL)
        {
            Front = Rear = newNode;
            newNode->Next = NULL;
        }
        else
        {
            Rear->Next = newNode;
            Rear = newNode;
            newNode->Next = NULL;
        }
    }
    void DeQueue()
    {
        if (Front == NULL)
            cout << "\nThis Queue is empty !!!";
        else if (Front == Rear)
            Front = Rear = NULL;
        else
            Front = Front->Next;
    }
    void Display()
    {
        Node* temp = Front;
        if (Front != NULL)
            while (temp != NULL)
            {
                cout << "\n-> " << temp->Data;
                temp = temp->Next;
            }
        else
            cout << "\nThis Queue is empty !!!";
    }
    void Peek()
    {
        if (Front == NULL)
            cout << "\nThis Queue is empty !!!";
        else
            cout << "\nThe Oldest input is : "<<Front->Data;
    }
private:
    Node* Front=NULL;Node *Rear=NULL;
    
};

int main()
{
    QueueLL QLL;
    bool isDone = false;
    while (!isDone)
    {
        int ChNum;
        cout << "\n\n\t\t[1]ADD\n\t\t[2]Delete\n\t\t[3]Print\n\t\t[4]Peek\n\t\t[5]Exit\n--> ";
        cin >> ChNum;
        switch (ChNum)
        {
        case 1:
        {
            int j;
            cout << "\nHow many element you will ADD ? \n--> ";
            cin >> j;
            for (int i = 0; i <j; i++)
                QLL.EnQueue();
            break;
        }case 2:
        {
            QLL.DeQueue();
            break;
        }case 3:
        {
            QLL.Display();
            break;
        }case 4:
        {
            QLL.Peek();
            break;
        }case 5:
        {
            isDone = true;
            break;
        }
        default:
        {
            cout << "\n wrong input !!!} >_<";
            break; 
        }
        }
    }
}