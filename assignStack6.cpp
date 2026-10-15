#include<iostream>
#define EMPTYSTACK 1;
using namespace std;

struct node {
    int item;
    node *next;
};

class Stack {
    private:
    node *top;
    public:
    Stack(){
        top=nullptr;
    }
    void push(int data){
        node *n=new node;
        n->item=data;
        n->next=top;
        top=n;
    }
    int peek(){
        if(top==nullptr){
            throw EMPTYSTACK;
        }
        return top->item;
    }
    int pop(){
        int data;

        node *t;

        if(top==nullptr){
            throw EMPTYSTACK;
        }

        t=top;
        top=top->next;

        data=t->item;

        delete t;

        return data;
    }
    ~Stack(){
        while(top){
            pop();
        }
    }
};

int main(){
    Stack s1;
    return 0;
}