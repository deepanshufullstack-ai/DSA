#include<iostream>
using namespace std;
struct node {
    int item;
    node *next;
};
class Queue{
    node *front, *rear;
    public:
    Queue(){
        front=rear=nullptr;
    }
    void insert(int data){
        node *n=new node;
        n->item=data;
        n->next=nullptr;

        if(rear==nullptr){
            front=rear=n;
        } else {
            rear->next=n;
            rear=n;
        }
    }
    int getFront(){
        if(front==nullptr){
            cout<<"Queue is empty";
            return -1;
        }
        return front->item;
    }
    int getRear(){
        if(rear==nullptr){
            cout<<"Queue is empty";
            return -1;
        }
        return rear->item;
    }
    void deleteFront(){
        if(front==nullptr){
            cout<<"Queue is empty";
            return;
        }
        node *temp=front;
        front=front->next;
        if(front==nullptr){
            rear=nullptr;
        }
        delete temp;
    }
    int count(){
        int c=0;
        node *temp=front;
        while(temp!=nullptr){
            c++;
            temp=temp->next;
        }
        return c;
    }
    ~Queue(){
        while(front!=nullptr){
            deleteFront();
        }
    }
};
int main(){
    return 0;
}