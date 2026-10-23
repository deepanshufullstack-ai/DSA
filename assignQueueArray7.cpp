#include <iostream>
using namespace std;
class Queue
{
    int capacity;
    int front, rear;
    int *ptr;

public:
    Queue(int c)
    {
        if (c < 0)
        {
            c = -c;
        }
        capacity = c;
        front = -1;
        rear = -1;
        ptr = new int[capacity];
    }
    void insertNewElement(int element)
    {
        if ((front == 0 && rear == capacity - 1) || (front == rear + 1))
        {
            cout << "\nQueue is full";
        }
        else if (rear == -1)
        {
            rear = front = 0;
            ptr[rear] = element;
        }
        else if (rear == capacity - 1)
        {
            rear = 0;
            ptr[rear] = element;
        }
        else
        {
            rear++;
            ptr[rear] = element;
        }
    }
    void viewRear()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nQueue is empty";
            return;
        }

        cout << "\nRear: " << ptr[rear];
    }
        void viewFront()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nQueue is empty";
            return;
        }

        cout << "\nFront: " << ptr[front];
    }
    void deleteFront(){
        if(front==-1 && rear==-1){
            cout<<"\nQueue is empty";
            return;
        }

        if(front==rear){
            front=rear=-1;
        } else if(front==capacity-1){
            front=0;
        } else {
            front++;
        }
    }
        void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nQueue is empty";
            return;
        }

        cout << "\n";
        for (int i = front; i <= rear; i++)
        {
            cout << ptr[i] << " ";
        }
    }
    bool checkQueueOverflow(){
        if((front == 0 && rear == capacity - 1) || (front == rear + 1)){
            return true;
        } else {
            return false;
        }
    }
    bool checkQueueUnderflow(){
        if(front==-1){
            return true;
        } else {
            return false;
        }
    }
    ~Queue(){
        delete []ptr;
    }

};

int main()
{
    Queue q(5);
    q.display();
    q.insertNewElement(10);
    q.insertNewElement(20);
    q.insertNewElement(30);
    q.insertNewElement(40);
    q.insertNewElement(50);
    q.display();
    q.viewRear();
    q.viewFront();
    q.deleteFront();
    q.display();
    return 0;
}