#include<iostream>
using namespace std;
class DA{
    private:
    int capacity;
    int lastIndex;
    int *ptr;
    protected:
    void doubleArray(){
        int *temp;
        temp=new int[capacity*2];
        for(int i=0; i<=lastIndex; i++){
            temp[i]=ptr[i];
        }
        delete []ptr;
        ptr=temp;
        capacity=capacity*2;
    }
    void halfArray(){
        int *temp;
        temp=new int[capacity/2];
        for(int i=0; i<=lastIndex; i++){
            temp[i]=ptr[i];
        }
        delete []ptr;
        ptr=temp;
        capacity=capacity/2;
    }
    public:
    A(int cap){
        if(cap<0){
            cap=5;
        }
        capacity=cap;
        lastIndex=-1;
        ptr=new int[capacity];
    }
    bool isEmpty(){
        return lastIndex==-1;
    }
    bool isFull(){
        lastIndex==capacity-1;
    }
    void append(int data){
        if(isFull()){
            doubleArray();
        }
        ptr[lastIndex+1]=data;
        lastIndex++;
    }
    void insert(int index, int data){
        if(index<0){
            return;
        }
        
        if(isFull()){
            doubleArray();
        }

        for(int i=lastIndex; i>=index; i--){
            ptr[i+1]=ptr[i];
        }

        ptr[index]=data;
        lastIndex++;
    }
    void edit(int index, int data){
        if(index<0){
            return;
        }

        ptr[index]=data;
    }
    void delete(int index){
        if(index<0){
            return;
        }

        for(int i=index; i<lastIndex; i++){
            ptr[i]=ptr[i+1];
        }

        lastIndex--;

        if(capacity>1 && lastIndex<capacity/2){
            halfArray();
        }
    }
    int get(int index){
        if(index<0){
            return -1;
        }
        return ptr[index];
    }
    int count(){
        return lastIndex+1;
    }
    int find(int data){
        for(int i=0; i<=lastIndex; i++){
            if(ptr[i]==data){
                return i;
            }
        }
        return -1;
    }
    Array(Array &arr){
        capacity=arr.capacity;
        lastIndex=arr.lastIndex;
        ptr=new int[capacity];
        for(int i=0; i<=lastIndex; i++){
            ptr[i]=arr.ptr[i]
        }
    }
    Array& operator=(Array &arr){
        delete []ptr;
        capacity=arr.capacity;
        lastIndex=arr.lastIndex;
        ptr=new int[capacity];
        for(int i=0; i<=lastIndex; i++){
            ptr[i]=arr.ptr[i];
        }
        return *this;
    }
    ~Array(){
        delete []ptr;
    }
}
int main(){
    return 0;
}