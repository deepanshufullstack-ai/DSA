#include<iostream>
struct node{
    int item;
    int pno;
    node *next;
};
class PriorityQueue{
    private:
    node *start;
    public:
    PriorityQueue(){
        start=nullptr;
    }
    bool isEmpty(){
        return start==nullptr;
    }
    void insertNewItem(int data, int pno){
        node *n=new node;
        n->item=data;
        n->pno=pno;
        n->next=nullptr;

        if(isEmpty() || start->pno<pno){
            n->next=start;
            start=n;
        } else {
            node *t;
            t=start;
            while(t->next!=nullptr){
                if(t->next->pno<pno){
                    n->next=t->next;
                    break;
                }
                t=t->next;
            }
            t->next=n;
        }
    }
    void removeItem(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return;
        }
        node *t=start;
        start=start->next;
        delete t;
    }
    int getHighestPriorityItem(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return -1;
        }
        return start->item;
    }
    int getHighestPriorityNumber(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return -1;
        }
        return start->pno;
    }
    ~PriorityQueue(){
        while(!isEmpty()){
            removeItem();
        }
    }
};
int main(){
    return 0;
}