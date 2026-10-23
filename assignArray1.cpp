// #include <iostream>
// #define OVERFLOW 1;
// #define INVALIDINDEX 2;
// using namespace std;
// class Array
// {
// private:
//     int capacity;
//     int lastIndex;
//     int *ptr;

// public:
//     Array(int cap)
//     {
//         if (cap <= 0)
//         {
//             cap = 10;
//         }
//         capacity = cap;
//         lastIndex = -1;
//         ptr = new int[cap];
//     }
//     Array(Array &arr)
//     {
//         capacity = arr.capacity;
//         lastIndex = arr.lastIndex;
//         ptr = new int[capacity];
//         for (int i = 0; i < lastIndex; i++)
//         {
//             ptr[i] = arr.ptr[i];
//         }
//     }
//     Array &Array::operator=(Array &arr)
//     {
//         if(this == &arr){
//             return *this;
//         }

//         delete[] ptr;

//         capacity = arr.capacity;
//         lastIndex = arr.lastIndex;

//         ptr = new int[capacity];
//         for (int i = 0; i < lastIndex; i++)
//         {
//             ptr[i] = arr.ptr[i];
//         }
//         return *this;
//     }
//     void displayLastIndex()
//     {
//         cout << "\nLastIndex: " << lastIndex;
//     }
//     bool checkArrayEmptyOrNot()
//     {
//         if (lastIndex == capacity - 1)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     void appendElement(int element)
//     {
//         if (checkArrayEmptyOrNot())
//         {
//             throw OVERFLOW;
//         }
//         else
//         {
//             ptr[lastIndex + 1] = element;
//             lastIndex++;
//         }
//     }
//     void insertElement(int index, int element)
//     {
//         if (index < 0)
//         {
//             throw INVALIDINDEX;
//         }

//         if (checkArrayEmptyOrNot())
//         {
//             throw OVERFLOW;
//         }

//         for (int i = lastIndex; i >= index; i--)
//         {
//             ptr[i + 1] = ptr[i];
//         }
//         ptr[index] = element;
//         lastIndex++;
//     }
//     void editElement(int index, int element)
//     {
//         if (index < 0)
//         {
//             throw INVALIDINDEX;
//         }

//         ptr[index] = element;
//     }
//     void deleteElement(int index)
//     {
//         if (index < 0)
//         {
//             throw INVALIDINDEX;
//         }
//         for (int i = index; i < lastIndex; i++)
//         {
//             ptr[i] = ptr[i + 1];
//         }
//         lastIndex--;
//     }
//     int getElementByIndex(int index)
//     {
//         if (index < 0)
//         {
//             throw INVALIDINDEX;
//         }
//         return ptr[index];
//     }
//     int countArrayElements()
//     {
//         return lastIndex + 1;
//     }
//     ~Array()
//     {
//         delete[] ptr;
//     }
//     int findElement(int element)
//     {
//         for (int i = 0; i < lastIndex; i++)
//         {
//             if (ptr[i] == element)
//             {
//                 return i;
//             }
//             else
//             {
//                 return -1;
//             }
//         }
//     }
// };
// int main()
// {
//     Array a1(10);

//     bool value = a1.checkArrayEmptyOrNot();

//     if (value)
//     {
//         cout << "\nArray is overflow";
//     }
//     else
//     {
//         cout << "\nArray is an empty";
//     }

//     try
//     {
//         a1.appendElement(1);
//         a1.appendElement(2);
//         a1.appendElement(3);
//         a1.displayLastIndex();
//         a1.insertElement(0, 10);
//         a1.displayLastIndex();
//         a1.deleteElement(3);
//         a1.displayLastIndex();
//         cout << "\nValue is: " << a1.getElementByIndex(0);
//         cout << "\nElement count is: " << a1.countArrayElements();
//         int val = a1.findElement(10);
//         if (val == -1)
//         {
//             cout << "\nElement not found";
//         }
//         else
//         {
//             cout << "\nElement found at index: " << val;
//         }
//     }
//     catch (int e)
//     {
//         if (e == 1)
//         {
//             cout << "\nArray is overflow";
//         }

//         if (e == 2)
//         {
//             cout << "\nInvalid index";
//         }
//     }

//     Array a2(20);
//     a1 = a2;
//     a2.displayLastIndex();

//     return 0;
// }

#include <iostream>
using namespace std;
class Array
{
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array(int c)
    {
        if (c < 0)
        {
            c = -c;
        }
        capacity = c;
        lastIndex = -1;
        ptr = new int[capacity];
    }
    bool arrayIsEmptyOrNot()
    {
        if (lastIndex == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void appendNewElement(int element)
    {
        if(lastIndex==capacity-1){
            cout<<"\nArray is full";
        } else {
            ptr[lastIndex+1]=element;
            lastIndex++;
        }
    }
    void insertElementAtSpecificIndex(int element, int index)
    {
        if (index < 0)
        {
            cout << "\nInvalid index";
        }

        if (lastIndex == capacity - 1)
        {
            cout << "\nArray is full";
        }

        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = element;
        lastIndex++;
    }
    void editElementAtSpecificIndex(int element, int index)
    {
        if (index < 0)
        {
            cout << "\nInvalid index";
        }

        ptr[index] = element;
    }
    void deleteElementAtSpecificIndex(int index)
    {
        if (index < 0)
        {
            cout << "\nInvalid index";
        }

        for (int i = index; i <= lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
    }
    bool arrayIsFullOrNot(){
        if(lastIndex == capacity - 1){
            return true;
        } else {
            return false;
        }
    }
    int getElementAtSpecificIndex(int index){
        if(index<0){
            cout<<"\nInvalid index";
        }
        
        return ptr[index];
    }
    void countNumberOfElement(){
        if(arrayIsEmptyOrNot()){
            cout<<"\nArray is empty";
        } else {
            int count=0;
            for(int i=0; i<=lastIndex; i++){
                count++;
            }
            cout<<"\n"<<count<<" total number of element present in the array";
        }
    } 
    void display()
    {
        cout << endl;
        for (int i = 0; i <= lastIndex; i++)
        {
            cout << ptr[i] << " ";
        }
    }
    int findElement(int element){
        if(arrayIsEmptyOrNot()){
            cout<<"\nArray is empty";
        } else {
            for(int i=0; i<=lastIndex; i++){
                if(ptr[i]==element){
                    return i;
                }
            }
            return -1;
        }
    }
    ~Array(){
        delete []ptr;
    }
};
int main()
{
    Array a(5);
    a.appendNewElement(10);
    a.appendNewElement(20);
    a.appendNewElement(30);
    a.appendNewElement(40);
    a.display();
    a.insertElementAtSpecificIndex(50,4);
    a.display();
    a.editElementAtSpecificIndex(1, 0);
    a.display();
    a.deleteElementAtSpecificIndex(4);
    a.display();
    cout<<"\n"<<a.getElementAtSpecificIndex(0);
    a.countNumberOfElement();
    cout<<"\n"<<a.findElement(20);
    return 0;
}