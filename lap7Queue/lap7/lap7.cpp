#include <iostream>
using namespace std;

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
void EnQueue(int value);
void DeQueue();
void Peek();
void Display();
int main()
{
    bool isDone=true;
    while(isDone)
    {
        int ChNum;
        cout << "\n\t\t[1]Enqueue\n\t\t[2]Dequeue\n\t\t[3]Peek\n\t\t[4]Display\n\t\t[5]Exit\n--> ";
        cin >> ChNum;
        switch (ChNum)
        {
        case 1:
        {
            int value;
            cout << "\nEnter the value : ";
            cin >> value;
            EnQueue(value);
            break;
        }
        case 2:
        {
            DeQueue();
            break;
        }
        case 3:
        {
            Peek();
            break;
        }
        case 4:
        {
            Display();
            break;
        }
        case 5:
        {
            isDone = false;
            break;
        }
        default:
        {
            cout << "\nwrong input !!!\ntry again ...\n";
            break;
        }
        }
    }
}
void EnQueue(int value) 
{
    if (rear != SIZE - 1)
    {
        if (rear == -1 && front == -1)
        {
            front++;
            queue[++rear] = value;
        }
        else
            queue[++rear] = value;
    }
    else
        cout << "\nThis Queue is Full !!! \n";
}
void DeQueue()
{
    if (front != -1 && rear != -1 && front <= rear)
        front++;

    else
        cout << "\nThis queue is empety\n";
}
void Peek()
{
    if (front != -1 && rear != -1 && front <= rear)
        cout << "\nFirst input is : " << queue[front]<<endl;

    else
        cout << "\nThis queue is empety\n";
}
void Display()
{
    if (front != -1 && rear != -1 && front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << "The ["<<i+1<<"th] element is : "<<queue[i]<<endl;
        }
    }
    else
        cout << "\nThis queue is empety\n";
}