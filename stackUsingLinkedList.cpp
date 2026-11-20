#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class Stack
{
    node *top;

public:
    Stack()
    {
        top = nullptr;
    }
    void push(int data)
    {
        node *n = new node;
        n->item = data;
        n->next = top;
        top = n;
    }
    int peek()
    {
        if (top == nullptr)
        {
            cout << "stack is empty";
            return -1;
        }
        return top->item;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "stack is empty";
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    ~Stack()
    {
        while (top != nullptr)
        {
            pop();
        }
    }
};
int main()
{
    return 0;
}