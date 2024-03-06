// Binary search tree 

#include <iostream>
using namespace std;
typedef int primData ;
struct Node
{
    primData Data;
    Node* Left;
    Node* Right;
};

Node* Root = NULL ;
void Insert();
//rLR
void PreOrder(Node*P);
//LrR
void InOrder(Node* P);
//LRr
void PostOrder(Node* P);

void TheSmallestNum(Node* P);

void TheBigestNum(Node* P);

int totalNodes(Node* tree);

int totalExternalNodes(Node* tree);

int totalInternalNodes(Node* tree);

int Height(Node* tree);
//struct Node* Search(Node* P, primData searchedEelement);
int main()
{
    //30 20 35 19 25 34 36
    Insert();
    Insert();
    Insert();
    Insert();
    Insert();
    Insert();
    Insert();
    PreOrder(Root);
    InOrder(Root);
    PostOrder(Root);
    TheSmallestNum(Root);
    TheBigestNum(Root);
/*    primData searchedEelement;
    cout << "\nWhat is the element : ";
    cin >> searchedEelement;
    cout<<Search(Root, searchedEelement);   */ 
}
void Insert()
{
    primData newData;
    Node* newNode=new Node;
    cout << "\nEnter the new element : ";
    cin >> newData;
    newNode->Data = newData;
    if (Root == NULL)
    {
        Root=newNode; newNode->Left = NULL; newNode->Right = NULL;
    }
    
    else
    {
        Node* Temp=Root;
        Node* parentNode = new Node;
        while (Temp != NULL)
        {
            parentNode = Temp;
            if (newData > Temp->Data)
                Temp = Temp->Right;
            else
                Temp = Temp->Left;
        }
        if (newData > parentNode->Data)
            parentNode->Right = newNode;
        else
            parentNode->Left = newNode;
        newNode->Left = NULL; newNode->Right = NULL;
    }
}
void PreOrder(Node*P)
{
    if (P != NULL)
    {
        cout << P->Data << "\t";
        PreOrder(P->Left);
        PreOrder(P->Right);
    }
}void InOrder(Node*P)
{
    if (P != NULL)
    {
        InOrder(P->Left);
        cout << P->Data << "\t";
        InOrder(P->Right);
    }
}void PostOrder(Node*P)
{
    if (P != NULL)
    {
        PostOrder(P->Left);
        PostOrder(P->Right);
        cout << P->Data << "\t"; 
    }
}
void TheSmallestNum(Node* P)
{
    if (P->Left != NULL)
        TheSmallestNum(P->Left);
    else 
        cout << "\nThe smallest num in tree is : "<<P->Data;
}
void TheBigestNum(Node* P)
{
    if (P->Right != NULL)
        TheBigestNum(P->Right);
    else
        cout << "\nThe Bigest num in tree is : " << P->Data;
}
int totalNodes(Node* tree)
{
    if (tree == NULL)
        return 0;
    else
        return(totalNodes(tree->Left) + totalNodes(tree->Right) + 1);
}

int totalExternalNodes(Node* tree)
{
    if (tree == NULL)
        return 0;
    else if ((tree->Left == NULL) && (tree->Right == NULL))
        return 1;
    else
        return (totalExternalNodes(tree->Left) +
            totalExternalNodes(tree->Right));
}

int totalInternalNodes(Node* tree)
{
    if ((tree == NULL) || ((tree->Left == NULL) && (tree->Right == NULL)))
        return 0;
    else
        return (totalInternalNodes(tree->Left)
            + totalInternalNodes(tree->Right) + 1);
}
int Height(Node* tree)
{
    int leftheight, rightheight;
    if (tree == NULL)
        return 0;
    else
    {
        leftheight = Height(tree->Left);
        rightheight = Height(tree->Right);
        if (leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}
struct Node* deleteElement(Node* tree, int val)
{
    Node* cur, * parent, * suc, * psuc, * ptr;
    if (tree->Left == NULL)
    {
        cout << "\n The tree is empty ";
        return(tree);
    }
    parent = tree;
    cur = tree->Left;
    while (cur != NULL && val != cur->Data)
    {
        parent = cur;
        cur = (val < cur->Data) ? cur->Left : cur->Right;
    }
    if (cur == NULL)
    {
        cout << "\n The value to be deleted is not present in the tree";
        return(tree);
    }
    if (cur->Left == NULL)
        ptr = cur->Right;
    else if (cur->Right == NULL)

        ptr = cur->Left;
    else
    {
        // Find the in–order successor and its parent
        psuc = cur;
        cur = cur->Left;
        while (suc->Left != NULL)
        {
            psuc = suc;
            suc = suc->Left;
        }
        if (cur == psuc)
        {
            // Situation 1
            suc->Left = cur->Right;
        }
        else
        {
            // Situation 2
            suc->Left = cur->Left;
            psuc->Left = suc->Right;
            suc->Right = cur->Right;
        }
        ptr = suc;
    }
    // Attach ptr to the parent node
    if (parent->Left == cur)
        parent->Left = ptr;
    else
        parent->Right = ptr;
    free(cur);
    return tree;
}
