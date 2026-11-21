// #include <iostream>
// using namespace std;
// class Array
// {
//     int capacity;
//     int lastIndex;
//     int *ptr;

// public:
//     Array(int cap)
//     {
//         if (cap <= 0)
//         {
//             cap = 5;
//         }
//         capacity = cap;
//         lastIndex = -1;
//         ptr = new int[capacity];
//     }
//     bool isFull()
//     {
//         return lastIndex == capacity - 1;
//     }
//     bool isEmpty()
//     {
//         return lastIndex == -1;
//     }
//     void append(int data)
//     {
//         if (isFull())
//         {
//             cout << "Array is full" << endl;
//             return;
//         }

//         ptr[lastIndex + 1] = data;
//         lastIndex++;
//     }
//     void insertAtSpecificIndex(int index, int data)
//     {
//         if (index < 0)
//         {
//             cout << "Invalid index" << endl;
//             return;
//         }
//         if (isFull())
//         {
//             cout << "Array is full" << endl;
//             return;
//         }
//         for (int i = lastIndex; i >= index; i--)
//         {
//             ptr[i + 1] = ptr[i];
//         }
//         ptr[index] = data;
//         lastIndex++;
//     }
//     void edit(int index, int data)
//     {
//         if (index < 0)
//         {
//             cout << "Invalid index" << endl;
//             return;
//         }
//         ptr[index] = data;
//     }
//     void deleteAtSpecificIndex(int index)
//     {
//         if (index < 0)
//         {
//             cout << "Invalid index" << endl;
//             return;
//         }

//         for (int i = index; i < lastIndex; i++)
//         {
//             ptr[i] = ptr[i + 1];
//         }
//         lastIndex--;
//     }
//     int get(int index){
//         if (index < 0)
//         {
//             cout << "Invalid index" << endl;
//             return -1;
//         }
//         return ptr[index];
//     }
//     int count(){
//         return lastIndex+1;
//     }
//     int find(int data){
//         for(int i=0; i<=lastIndex; i++){
//             if(ptr[i]==data){
//                 return i;
//             }
//         }
//         return -1;
//     }
//     ~Array(){
//         delete []ptr;
//     }
// };
// int main()
// {
//     return 0;
// }


#include<iostream>
using namespace std;
class A{
    private:
    int capacity;
    int lastIndex;
    int *ptr;
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
            return;
        }
        ptr[lastIndex+1]=data;
        lastIndex++;
    }
    void insert(int index, int data){
        if(index<0){
            return;
        }
        
        if(isFull()){
            return;
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