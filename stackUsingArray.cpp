// LIFO (last in, first out)
#include<iostream>
using namespace std;
// define a class stack with capacity, top and ptr pointer as member variables implement stack using array
class Stack{
    private:
    int capacity;
    int top;
    int *ptr;
// define a paramterized constructor to initialize member variables
    public:
    Stack(int cap){
        if(cap<=0){
            cap=5;
        }
        capacity=cap;
        top=-1;
        ptr=new int[capacity];
    }
// define a method to check stack overflow
    bool isFull(){
        return top==capacity-1;
    }
// define a method to check stack underflow
    bool isEmpty(){
        return top==-1;
    }
// define a method to push a new element on the stack
    void push(int data){
        if(isFull()){
            cout<<"Stack is overflow";
        } else {
            top++;
            ptr[top]=data;
        }
    }
// define a method to peek top element of the stack
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty";
        } else {
            return ptr[top];
        }
    }
// define a method to pop the top element of the stack
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty";
            return;
        }

        top--;
    }
// define a method to reverse a stack
    void reverse(){
        int temp;
        for(int i=0; i<(top+1)/2; i++){
            temp=ptr[i];
            ptr[i]=ptr[top-i];
            ptr[top-i]=temp;
        }
    }
// define a solution to keep track of minimum value element in the stack
    void minValue(){
        if(isEmpty()){
            cout<<"Stack is empty";
            return;
        }

        int min=ptr[0];
        for(int i=0; i<=top; i++){
            if(ptr[i]<min){
                min=ptr[i];
            }
        }
        cout<<"Minimum value is: "<<min;
    }
// define a destructor to deallocates the memory
    ~Stack(){
        delete []ptr;
    }
};
int main(){
    return 0;
}