#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Linkedlist
{
public:
    Node *head;
    Linkedlist()
    {
        head = NULL;
    }

    bool isempty()
    {
        return (head == NULL);
    }

    void insertFirst(int newItem)
    {
        Node *newNode = new Node;
        newNode->data = newItem;

        if (isempty())
            newNode->next = NULL;
        else
            newNode->next = head;

        head = newNode;
        cout << "Inserted " << newItem << endl;
    }

    void display()
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    int counter()
    {
        int counter = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        cout << "Total nodes: " << counter << endl;
        return counter;
    }

    bool isFound(int item)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                cout << "Item " << item << " found!" << endl;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void insertBefore(int item, int newValue)
    {
        if (isempty())
        {
            insertFirst(newValue);
        }
        if (isFound(item))
        {

            Node *newNode = new Node();
            newNode->data = newValue;
            Node *temp = head;

            while (temp->next->data != item && temp != NULL)
            {

                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << newValue << " Before " << item << endl;
        }
    }
    void Append(int newValue)
    {
        Node *temp = head;
        Node *newNode = new Node;
        newNode->data = newValue;
        if (isempty())
        {
            insertFirst(newValue);
        }
        else
        {

            while (temp->next != NULL)
            {

                temp = temp->next;
            }
            newNode->next == NULL;
            temp->next = newNode;
        }
    }
    void Delete(int delVal)
    {
        if (isempty())
        {
            cout << "List is empty, no items to delete\n";
        }
        if (head->data == delVal)
        {
            Node *delPtr = head;

            head = head->next;
            delete delPtr;
        }
        else
        {
            Node *prev = NULL;
            Node *delPtr = head;

            while (delPtr->data != delVal)
            {
                prev = delPtr;
                delPtr = delPtr->next;
            }
            prev->next = delPtr->next;
            delete delPtr;
        }
    }
};

int main()
{
    Linkedlist list;
    list.insertFirst(30);
    list.insertFirst(10);
    list.Append(35);
    list.insertBefore(30, 20);
    list.Delete(10);
    list.display();
    list.counter();
    return 0;
}
