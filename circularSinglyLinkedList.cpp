#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
// define a class SCLL to implement circular linked list data structure with member variable last pointer of type node
class SCLL
{
    node *last;

public:
    // define a constructor to initialize last pointer with NULL
    SCLL()
    {
        last = nullptr;
    }
    // define a method to insert a data into the list at the beginning
    void insertAtStart(int data)
    {
        node *n = new node;
        n->item = data;

        if (last == nullptr)
        {
            n->next = n;
            last = n;
        }
        else
        {
            n->next = last->next;
            last->next = n;
        }
    }
    // define a method to insert a data into the list at the end
    void insertAtEnd(int data)
    {
        node *n = new node;
        n->item = data;

        if (last == nullptr)
        {
            n->next = n;
            last = n;
        }
        else
        {
            n->next = last->next;
            last->next = n;
            last = n;
        }
    }
    // define a method to search a node with the given item
    node *searchNode(int data)
    {
        node *t;
        if (last == nullptr)
        {
            return nullptr;
        }
        t = last->next;
        do
        {
            if (t->item == data)
            {
                return t;
            }
            t = t->next;
        } while (t != last->next);
        return nullptr;
    }
    // define a method to insert a data into the list after the specified node of the list
    void insertAfterSpecific(node *temp, int data)
    {
        node *n = new node;
        n->item = data;

        if (temp == nullptr)
        {
            cout << "Invalid address of node";
            return;
        }
        else
        {
            if (temp == last)
            {
                insertAtEnd(data);
            }
            else
            {
                n->next = temp->next;
                temp->next = n;
            }
        }
    }
    // define a method to delete first node from the list
    void deleteFirst()
    {
        node *t;
        if (last == nullptr)
        {
            cout << "List is empty";
            return;
        }
        else
        {
            if (last == last->next)
            {
                delete last;
                last = nullptr;
            }
            else
            {
                t = last->next;
                last->next = t->next;
                delete t;
            }
        }
    }
    // define a method to delete last node from the list
    void deleteLast()
    {
        node *t;
        if (last == nullptr)
        {
            cout << "List is empty";
            return;
        }
        else
        {
            t = last->next;
            while (t->next != last)
            {
                t = t->next;
            }
            t->next = last->next;
            delete last;
            last = t;
        }
    }
    // define a method to delete specific node from the list
    void deleteSpecificNode(int data)
    {
        node *temp = searchNode(data);
        if (temp == nullptr)
        {
            cout << "Invalid node";
            return;
        }
        else
        {
            if (temp == last)
            {
                deleteLast();
            }
            else
            {
                node *t = last->next;
                while (t->next != temp)
                {
                    t = t->next;
                }
                t->next = temp->next;
                delete temp;
            }
        }
    }
    // define a destructor to deallocates memory for all the nodes in the list
    ~SCLL()
    {
        while (last != nullptr)
        {
            deleteLast();
        }
    }
};
int main()
{
    return 0;
}