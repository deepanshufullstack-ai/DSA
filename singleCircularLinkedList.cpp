#include<iostream>
using namespace std;
struct node{
    int item;
    node *next;
};
class SCLL{
    private:
    node *last;
    public:
    SCLL(){
        last=nullptr;
    }
    void insertAtStart(int data){
        node *n=new node;
        n->item=data;
        if(last==nullptr){
            n->next=n;
            last=n;
        } else {
            n->next=last->next;
            last->next=n;
        }
    }
    void insertAtLast(int data){
        node *n=new node;
        n->item=data;
        if(last==nullptr){
            n->next=n;
            last=n;
        } else {
            n->next=last->next;
            last->next=n;
            last=n;
        }
    }
    node *search(int data){
        node *t;
        if(last==nullptr){
            return nullptr;
        } else {
            t=last->next;
            do{
            if(t->item=data){
                return data;
            }
            }while(t!=last->next);
    
            return nullptr
        }
    }
    void insertAfter(node *temp, int data){
        if(temp==nullptr){
            return; 
        }

        if(temp==last){
            insertAtLast();
        } else {
            node *n=new node;
            n->item=data;
            n->next=temp->next;
            temp->next=n;
        }
    }
    void deleteFirst(){
        node *t;
        if(last!=nullptr){
            if(last->next==last){
                delete last;
                last=nullptr;
            } else {
                t=last->next;
                last->next=t->next;
                delete t;
            }
        }
    }
    void deleteLast(){
        node *t;
        if(last!=nullptr){
            if(last->next==last){
                delete last;
                last=nullptr;
            } else {
                t=last->next;
                while(t->next!=last){
                    t=t->next;
                }
                t->next=last->next;
                delete last;
                last=t;
                
            }
        }
    }
    void deleteNode(int data){
        node *temp=search(data);
        if(temp==nullptr){
            return;
        }

        node *t=last->next;
        while(t->next!=temp){
            t=t->next;
        }
        t->next=temp->next;
        delete temp;
    }
    ~SCLL(){
        while(last!=nullptr){
            deleteFirst();
        }
    }
};
int main(){
    return 0;
}



