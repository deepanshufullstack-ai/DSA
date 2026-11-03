#include<iostream>
using namespace std;
class Array{
    int capacity;
    int lastIndex;
    int *ptr;
    public:
    Array(int cap){
        if(cap<=0){
            cap=10;
        }
        capacity=cap;
        lastIndex=-1;
        ptr=new int[capacity];
    }
    bool isEmpty(){
        return lastIndex==-1;
    }
    bool isFull(){
        return lastIndex==capacity-1;
    }
    void append(int data){
        if(isFull()){
            return;
        }
        ptr[lastIndex+1];
        lastIndex++;
    }
    void insert(int index, int data){
        if(index<0 || index>lastIndex){
            return;
        }

        if(isFull()){
            return;
        }

        for(int i=lastIndex; i>=index; i--){
            ptr[i+1]=ptr[i];
        }

        ptr[index]=data;
        lastIndex++;;
    }
    void edit(int index, int data){
        if(index<0 || index>lastIndex){
            return;
        }
        
        ptr[index]=data;
    }
    void deleteElement(int index){
        if(index<0 || index>lastIndex){
            return;
        }

        for(int i=index; i<=lastIndex; i++){
            ptr[i]=ptr[i+1];
        }

        lastIndex--;
    }
    int get(int index){
        if(index<0 || index>lastIndex){
            return 1;
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
    Array(){
        delete []ptr;
    }
};
int main(){
    return 0;
}