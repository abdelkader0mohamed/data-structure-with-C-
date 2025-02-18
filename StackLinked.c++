 

#include <iostream>

using namespace std;



class Node
{
public:
int data;
Node* next;
Node() 
{
    data = 0;
    next = NULL;
}

};



class Stack
{
    Node * top;
    public:
    Stack()
    {
        top = NULL;
    }
    void push(int item)
    {
        Node * newNode = new Node;
        newNode->data = item;
        if(isEmpty())
        {
            top = newNode;
        }
        else 
        {
            newNode->next = top;
            top = newNode;
        }
    }
    int pop()
    {

    }
    void display()
    {

    }
    bool isEmpty()
    {
        return (top == NULL);
    }
};











int main()
{

return 0;
}
















