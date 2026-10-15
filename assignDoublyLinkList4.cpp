#include <iostream>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};

class DoublyLinkedList
{
private:
    node *start;

public:
    DoublyLinkedList()
    {
        start = nullptr;
    }
    void insertAtStart(int data)
    {
        node *n = new node; // create a new node
        n->item = data;     // assign data to the new node
        n->prev = nullptr;  // set previous pointer to nullptr
        n->next = start;    // set next pointer to the current start node
        if (start != nullptr)
        {                    // if the list is not empty
            start->prev = n; // set the previous pointer of the current start node to the new node
        }
        start = n; // update the start pointer to the new node
    }
    void insertAtEnd(int data)
    {
        node *n = new node; // create a new node
        node *t;
        n->item = data;       // assign data to the new node
        n->next = nullptr;    // set next pointer to nullptr
        if (start == nullptr) // if the list is empty
        {
            n->prev = nullptr; // set previous pointer to nullptr
            start = n;         // update the start pointer to the new node
        }
        else
        {
            t = start;                 // create a temporary pointer to traverse the list
            while (t->next != nullptr) // traverse until the end of the list
            {
                t = t->next; // move to the next node
            }
            t->next = n; // set the next pointer of the last node to the new node
            n->prev = t; // set the previous pointer of the new node to the last node
        }
    }
    node *search(int data)
    {
        node *t;
        t = start;
        while (t != nullptr)
        {
            if (t->item == data)
            {
                return t;
            }
            t = t->next;
        }
        return nullptr;
    }
    void insertAfterTheSpecifiedNode()
    {
    }
    void deleteFirstNode(){
        node *t;
        if(start!=nullptr){
            if(start->next==nullptr){
                delete start;
                start=nullptr;   
            } else {
                t=start;
                t->next->prev=nullptr;
                start=t->next;
                delete t;
            }
        }
    }
    void deleteLastNode(){
        node *t;
        if(start!=nullptr){
            if(start->next==nullptr){
                delete start;
                start=nullptr;
            } else {
                t=start;
                while(t->next->next!=nullptr){
                    t=t->next;
                }
                delete t->next;
                t->next=nullptr;
            }
        }
    }
    void deleteNode(){
        
    }
    void display()
    {
        node *temp = start; // create a temporary pointer to traverse the list
        while (temp != nullptr)
        {                              // traverse until the end of the list
            cout << temp->item << " "; // print the item of the current node
            temp = temp->next;         // move to the next node
        }
        cout << endl; // print a new line after displaying all items
    }
};

int main()
{
    DoublyLinkedList list;
    list.insertAtStart(10);
    list.display();
    list.insertAtStart(20);
    list.display();
    node *searchNode = list.search(20);
    return 0;
}