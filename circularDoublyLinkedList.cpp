#include <iostream>
using namespace std;
// define a class CDL to implement circular doubly linked list data structure with member variable start pointer of type node
struct node
{
    node *prev;
    int item;
    node *next;
};
class CDLL
{
    node *start;

public:
    // define a constructor to intialize start pointer with null
    CDLL()
    {
        start = nullptr;
    }
    // define a method to insert a data into the list at the beginning
    void insertAtBeginning(int data)
    {
        node *n = new node;
        n->item = data;

        if (start == nullptr)
        {
            n->prev = n;
            n->next = n;
            start = n;
        }
        else
        {
            n->next = start;       // for new node
            n->prev = start->prev; // for new node
            start->prev->next = n; // for last node
            start->prev = n;       // for start node
            start = n;             // for the start pointer
        }
    }
    // define a method to insert a data into the list at the end
    void insertAtEnd(int data)
    {
        node *n = new node;
        n->item = data;
        if (start == nullptr)
        {
            n->prev = n;
            n->next = n;
            start = n;
        }
        else
        {
            n->next = start;       // for new node
            n->prev = start->prev; // for new node
            start->prev->next = n; // for last node
            start->prev = n;       // for start node
        }
    }
    // define a method to search a node with the give item
    node *searchNode(int data)
    {
        node *t;
        if (start == nullptr)
        {
            return nullptr;
        }
        else
        {
            t = start;
            do
            {
                if (t->item == data)
                {
                    return t;
                }
                t = t->next;
            } while (t->next != start);
            return nullptr;
        }
    }
    // define a method to insert a data into the list after the specified node of the list
    void insertAfterSpecificNode(node *temp, int data)
    {
        node *n = new node;
        n->item = data;
        if (temp == nullptr)
        {
            cout << "The node is not exist";
            return;
        }
        n->prev = temp;
        n->next = temp->next;
        temp->next->prev = n;
        temp->next = n;
    }
    // define a method to delete first node from the list
    void deleteFirst()
    {
        node *t;
        if (start != nullptr)
        {
            t = start;
            start->prev->next = start->next;
            start->next->prev = start->prev;
            if (start->next == start)
            {
                start = nullptr;
            }
            else
            {
                start = start->next;
            }
        }
        delete t;
    }
    // define a method to delete last node of the list
    void deleteLast()
    {
        node *t;
        if (start != nullptr)
        {
            t = start->prev;
            if (start == start->next)
            {
                delete start;
                start = nullptr;
            }
            else
            {
                t->prev->next = start;
                start->prev = t->prev;
            }
        }
        delete t;
    }
    // define a method to delete a specific node
    void deleteSpecificNode(int data)
    {
        node *temp = searchNode(data);
        if (temp != nullptr)
        {
            if (start == temp)
            {
                deleteFirst();
            }
            else
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
            }
        }
        delete temp;
    }
    // define a destructor to deallocated memory for all the nodes in the linked list
    ~CDLL()
    {
        while (start != nullptr)
        {
            deleteFirst();
        }
    }
};
int main()
{
    return 0;
}
