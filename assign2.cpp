#include <iostream>
#define OVERFLOW 1;
#define INVALIDINDEX 2;
using namespace std;

class DynArray
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

protected:
    void doubleArray()
    {
        int *temp;
        temp = new int[capacity * 2];
        for (int i = 0; i <= lastIndex; i++)
        {
            temp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = temp;
        capacity = capacity * 2;
    }
    void halfArray()
    {
        int *temp;
        temp = new int[capacity / 2];
        for (int i = 0; i <= lastIndex; i++)
        {
            temp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = temp;
        capacity = capacity / 2;
    }

public:
    DynArray(int cap)
    {
        if (cap <= 0)
        {
            cap = 10;
        }
        capacity = cap;
        lastIndex = -1;
        ptr = new int[capacity];
    }

    int currentCapacity()
    {
        return capacity;
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
            doubleArray();
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
            doubleArray();
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
        for (int i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
        if (capacity > 1 && lastIndex < capacity / 2)
        {
            halfArray();
        }
    }
    int getElementByIndex(int index)
    {
        if (index < 0)
        {
            throw INVALIDINDEX;
        }
        return ptr[index];
    }
    int countArrayElements()
    {
        return lastIndex + 1;
    }
    ~DynArray()
    {
        delete[] ptr;
    }
    int findElement(int element)
    {
        for (int i = 0; i < lastIndex; i++)
        {
            if (ptr[i] == element)
            {
                return i;
            }
            else
            {
                return -1;
            }
        }
    }
    void display()
    {
        cout << "\nThe lastIndex is: " << lastIndex;
    }
};
int main()
{
    DynArray a1(5);
    a1.appendElement(10);
    a1.appendElement(20);
    DynArray a2(10);
}