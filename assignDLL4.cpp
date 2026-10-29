#include<iostream>
using namespace std;
struct node {
    node *prev;
    int data;
    node *next;
};

class DLL {
  node *start;
    public:
    DLL(){
        start=nullptr;
    }
    void insertAtStart(int element){
        node *n=new node;
        n->prev=nullptr;
        n->data=element;
        n->next=start;

        if(start!=nullptr){
            start->prev=n;
        }

        start=n;
    }
    void insertAtLast(int element){
        node *n=new node;
        n->data=element;
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
            t->next=n;
            n->prev=t;
        }
    }
    node *search(int element){
        node *t;
        t=start;
        while(t->next!=nullptr){
            if(t->data==element){
                return t;
            }
            t=t->next;
        }
        return t;
    }
    void insertAfterSpecificNode(node *item, int element){
       if(item==nullptr){
           return;
       }

        node *n=new node;
        n->data=element;
        n->next=item->next;
        n->prev=item;

        item->next=n; 
    }
    void deleteFirst(){
        if(start!=nullptr){
            if(start->next==nullptr){
                delete start;
                start=nullptr;
            } else {
                node *t=start;
                t->next->prev=nullptr;
                start=t->next;
                delete t;
            }
        }
    }
    void deleteLast(){
        if(start!=nullptr){
            if(start->next==nullptr){
                delete start;
                start=nullptr;
            } else {
                node *t=start;
                while(t->next->next!=nullptr){
                    t=t->next;
                }
                delete t->next;
                t->next=nullptr;
            }
        }
    }
    void deleteNode(node *temp){
    if(temp==nullptr){
        return;
    }

    if(temp==start){
        deleteFirst();
        return;
    }

    temp->prev->next=temp->next;

    if(temp->next!=nullptr){
        temp->next->prev=temp->prev;
    }

    delete temp;
    }
};
int main(){
    return 0;
}













