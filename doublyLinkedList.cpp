#include<iostream>
using namespace std;
struct node{
    node *prev;
    int item;
    node *next;
};
class DLL{
    private:
    node *start;
    public:
    DLL(){
        start=nullptr;
    }
    void insertAtStart(int data){
        node *n=new node;
        n->item=data;
        n->prev=nullptr;
        n->next=start;
        if(start!=nullptr){
            start->prev=n;
        }
    }
    void insertAtLast(int data){
        node *n=new node;
        n->item=data;
        n->next=nullptr;

        if(start==nullptr){
            n->prev=nullptr;
            start=n;
        } else {
            node *t;
            t=start;
            while(t->next!=nullptr){
                t=t->next;
            }
            n->prev=t;
            t->next=n;
        }
    }
    node *search(int data){
        node *t;
        t=start;
        while(t->next!=nullptr){
            if(t->item==data){
                return t;
            }
            t=t->next;
        }
        return nullptr;
    }
    void insertAfter(node *temp, int data){
        if(temp==nullptr){
            return;
        }
        
        node *n=new node;
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
    }
    void deleteFirst(){
        if(start->next==nullptr){
            delete start;
            start=nullptr;
        } else {
            node *t;
            t=start;
            start->next->prev=nullptr;
            delete t;
        }
    }
    void deleteLast(){
        if(start->next==nullptr){
            delete start;
            start=nullptr;
        } else {
            node *t;
            t=start;
            while(t->next!=nullptr){
                t=t->next;
            }
            t->prev->next=nullptr;
            delete t;
        }
    }
    void deleteNode(int data){
        node *t=search(data);
        if(t==nullptr){
            return;
        }

        t->next->prev=t->prev;
        t->prev->next=t->next;
        delete t;
    }
    ~DLL(){
        while(start!=nullptr){
            deleteStart();
        }
    }
}
int main(){
    return 0;
}




















