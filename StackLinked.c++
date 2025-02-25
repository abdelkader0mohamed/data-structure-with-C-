 

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
    void display()
    {
        Node * temp = top;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        delete temp;
    }
    bool isEmpty()
    {
        return (top == NULL);
    }
    int pop()
    {
        int value = top->data;
        Node * delptr = top;
        top = top->next;
        delete delptr;
        return value;
    }
    int peek()
    {
        return top->data;
    }
    int count()
    {
        Node * temp = top;
        int num = 0;
        while(temp!=NULL)
        {
            num++;
            temp = temp->next;
        }
        delete temp;
        return num;
    }
    bool isFound(int item)
    {
        Node * temp = top;
        while(temp != NULL)
        {
            if(item == temp->data)
            {
                delete temp;
                return true;
            }
            temp = temp->next;
        }
        delete temp;
        return false;
    }
    bool isFull()
    {
        Node * ptr = new Node();
        if(ptr == NULL)
        {
            cout << "The Stack is Full\n";
            return true;
        }
        cout << "There is a space\n";
        return false;
    }
};











int main()
{
    Stack s;
    int item = 0;
    for(int i = 0; i <= 3; i++)
    {
        cout << "Enter the item to push in the stack \n";
        cin >> item;
        s.push(item);
    }
    s.display();
    cout << s.pop() << endl;
    s.display();
    cout << s.count() << endl;
    cout << s.isFound(10) << endl;
return 0;
}
















