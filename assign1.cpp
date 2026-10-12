#include <iostream>
#define OVERFLOW 1;
#define INVALIDINDEX 2;
using namespace std;
class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array(int cap)
    {
        if (cap <= 0)
        {
            cap = 10;
        }
        capacity = cap;
        lastIndex = -1;
        ptr = new int[cap];
    }
    void displayLastIndex()
    {
        cout << "\nLastIndex: " << lastIndex;
    }
    bool checkArrayEmptyOrNot()
    {
        if (lastIndex == capacity - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void appendElement(int element)
    {
        if (checkArrayEmptyOrNot())
        {
            throw OVERFLOW;
        }
        else
        {
            ptr[lastIndex + 1] = element;
            lastIndex++;
        }
    }
    void insertElement(int index, int element)
    {
        if (index < 0)
        {
            throw INVALIDINDEX;
        }

        if (checkArrayEmptyOrNot())
        {
            throw OVERFLOW;
        }

        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = element;
        lastIndex++;
    }
    void editElement(int index, int element)
    {
        if (index < 0)
        {
            throw INVALIDINDEX;
        }

        ptr[index] = element;
    }
    void deleteElement(int index)
    {
        if (index < 0)
        {
            throw INVALIDINDEX;
        }
        for(int i=index; i<lastIndex; i++){
            ptr[i]=ptr[i+1];
        }
        lastIndex--;
    }
    int getElementByIndex(int index){
        if(index<0){
            throw INVALIDINDEX;
        }
        return ptr[index];
    }
    int countArrayElements(){
        return lastIndex+1;
    }
    ~Array(){
        delete []ptr;
    }
    int findElement(int element){
        for(int i=0; i<lastIndex; i++){
            if(ptr[i]==element){
                return i;
            } else {
                return -1;
            }
        }
    }
};
int main()
{
    Array a1(10);

    bool value = a1.checkArrayEmptyOrNot();

    if (value)
    {
        cout << "\nArray is overflow";
    }
    else
    {
        cout << "\nArray is an empty";
    }

    try
    {
        a1.appendElement(1);
        a1.appendElement(2);
        a1.appendElement(3);
        a1.displayLastIndex();
        a1.insertElement(0, 10);
        a1.displayLastIndex();
        a1.deleteElement(3);
        a1.displayLastIndex();
        cout<<"\nValue is: "<<a1.getElementByIndex(0);
        cout<<"\nElement count is: "<<a1.countArrayElements();
        int val=a1.findElement(10);
        if(val==-1){
            cout<<"\nElement not found";
        } else {
            cout<<"\nElement found at index: "<<val;
        }

        
    }
    catch (int e)
    {
        if (e == 1)
        {
            cout << "\nArray is overflow";
        }

        if (e == 2)
        {
            cout << "\nInvalid index";
        }
    }

    return 0;
}