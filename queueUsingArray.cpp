// FIFO (first in, first out)
#include<iostream>
using namespace std;
// define a class queue with capacity, front, rear and ptr pointer as member variables implement queue using array
class Queue{
    private:
    int capacity;
    int front;
    int rear;
    int *ptr;
// define a parameterized constructor to initialize member variables
    public:
    Queue(int cap){
        if(cap<=0){
            cap=5;
        }
        capacity=cap;
        front=-1;
        rear=-1;
        ptr=new int[capacity];
    }
// define a method to insert a new element at the rear in the queue
    void insert(int data){
        if((front==0 && rear==capacity-1) || front == rear+1 ){
            cout<<"Queue is overflow";
            return;
        } else if(rear==-1){
            front=rear=0;
            ptr[rear]=data;
        } else if(rear==capacity-1){
            rear=0;
            ptr[rear]=data;
        } else {
            rear++;
            ptr[rear]=data;
        }
    }
// define a method to check queue underflow 
    bool isEmpty(){
        return front==-1;
    }
// define a method to check queue overflow 
    bool isFull(){
        return front==0 && rear==capacity-1 || front==rear+1;
    }
// define a method to view rear element of the queue
    int getRear(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return -1;
        }
        return ptr[rear];
    }
// define a method to view front element of the queue
    int getFront(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return -1;
        }
        return ptr[front];
    }
// define a method to delete the front element of the queue
    void deleteFront(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return;
        } else if(front==rear){
            front=rear=-1;
        } else if(front==capacity-1){
            front=0;
        } else {
            front++;
        }
    }
// define a method to count number of elements present in the queue
    int count(){
        if(isEmpty()){
            return 0;
        } else if(rear>=front){
            return rear-front+1;
        } else {
            return capacity+rear-front+1;
        }
    }
// define a destructor to deallocates the memory
    ~Queue(){
        delete []ptr;
    }
};

int main(){
    return 0;
}