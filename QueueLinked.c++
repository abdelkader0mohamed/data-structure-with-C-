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













class  Queue
{
public:
    Node* front;
    Node* rear;
    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void Enqueue(int item)
    {
        Node* newNode = new Node;
        newNode->data = item;
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            newNode->next = NULL;

        }
    }

    void Display()
    {
        Node* temp = front;

        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << "-------------------" << endl;
    }

    int Dequeue()
    {
        int item = -1;
        if (isEmpty())
        {
            cout << "There is no item to dequeue\n";
        }
        else if (front == rear)
        {
            item = front->data;
            delete front;
            front = rear = NULL;
        }
        else
        {
            item = front->data;
            Node* delptr = front;
            front = front->next;
            delete delptr;
        }
        return item;

    }

    int getFront()
    {
        return front->data;
    }

    int getRear()
    {
        return rear->data;
    }

    int count()
    {
        int counter = 0;

        Node* temp = front;

        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool isFound(int item)
    {
        Node* temp = front;
        
        while (temp != NULL)
        {
            if (temp->data == item)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void Clear()
    {
        while (!isEmpty())
        {
            Dequeue();
        }
    }

};




















int main()
{
    Queue qu;
    qu.Enqueue(10);
    qu.Enqueue(20);
    qu.Enqueue(30);

    cout << qu.Dequeue() << endl;

    qu.Display();
}















