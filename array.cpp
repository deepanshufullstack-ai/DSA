#include <iostream>
using namespace std;
class Array
{
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array(int cap)
    {
        if (cap <= 0)
        {
            cap = 5;
        }
        capacity = cap;
        lastIndex = -1;
        ptr = new int[capacity];
    }
    bool isFull()
    {
        return lastIndex == capacity - 1;
    }
    bool isEmpty()
    {
        return lastIndex == -1;
    }
    void append(int data)
    {
        if (isFull())
        {
            cout << "Array is full" << endl;
            return;
        }

        ptr[lastIndex + 1] = data;
        lastIndex++;
    }
    void insertAtSpecificIndex(int index, int data)
    {
        if (index < 0)
        {
            cout << "Invalid index" << endl;
            return;
        }
        if (isFull())
        {
            cout << "Array is full" << endl;
            return;
        }
        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
    }
    void edit(int index, int data)
    {
        if (index < 0)
        {
            cout << "Invalid index" << endl;
            return;
        }
        ptr[index] = data;
    }
    void deleteAtSpecificIndex(int index)
    {
        if (index < 0)
        {
            cout << "Invalid index" << endl;
            return;
        }

        for (int i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
    }
    int get(int index){
        if (index < 0)
        {
            cout << "Invalid index" << endl;
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
    ~Array(){
        delete []ptr;
    }
};
int main()
{
    return 0;
}