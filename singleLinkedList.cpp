#include<iostream>
using namespace std;
struct node{
    int item;
    node *next;
};
class SLL{
    private:
    node *start;
    public:
    SLL(){
        start=nullptr;
    }
    void insertAtStart(int data){
        node *n=new node;
        n->item=data;
        n->next=start;
        start=n;
    }
    void insertAtLast(int data){
        node *n=new node;
        n->item=data;
        n->next=nullptr;
        if(start==nullptr){
            start=n;
        } else {
            node *t=start;
            while(t->next!=nullptr){
                t=t->next;
            }
            t->next=n;
        }
    }
    node *search(int data){
        node *t=start;
        while(t!=nullptr){
            if(t->item==data){
                return t;
            }
        }
        return nullptr;
    }
    void insertAfter(node *ptr, int data){
        node *n=new node;
        n->item=data;
        
        if(ptr==nullptr){
            return;
        }

        n->next=ptr->next;
        ptr->next=n; 
    }
    void deleteFirst(){
        if(start!=nullptr){
            node *t;
            t=start;
            start=start->next;
            delete t;
        }
    }
    void deleteLast(){
        if(start!=nullptr){
            if(start->next==nullpr){
                delete start;
                start=nullptr;
            } else {
                node *t;
                t=start;
                while(t->next->next!=nullptr){
                    t=t->next;
                }
                delete t->next;
                t->next=nullptr;
            }
        }
    }
    void deleteNode(node *ptr){
        if(ptr==nullptr){
            return;
        }

        node *t;
        t=start;
        while(t->next!=ptr){
            t=t->next;
        }
        t->next=ptr->next;
        delete t;
    }
    ~SLL(){
        while(start!=nullptr){
            deleteFirst();
        }
    }
};
int main(){
    return 0;
}

























