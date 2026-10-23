// #include <iostream>
// #define OVERFLOW 1;
// #define INVALIDINDEX 2;
// using namespace std;

// class DynArray
// {
// private:
//     int capacity;
//     int lastIndex;
//     int *ptr;

// protected:
//     void doubleArray()
//     {
//         int *temp;
//         temp = new int[capacity * 2];
//         for (int i = 0; i <= lastIndex; i++)
//         {
//             temp[i] = ptr[i];
//         }
//         delete[] ptr;
//         ptr = temp;
//         capacity = capacity * 2;
//     }
//     void halfArray()
//     {
//         int *temp;
//         temp = new int[capacity / 2];
//         for (int i = 0; i <= lastIndex; i++)
//         {
//             temp[i] = ptr[i];
//         }
//         delete[] ptr;
//         ptr = temp;
//         capacity = capacity / 2;
//     }

// public:
//     DynArray(int cap)
//     {
//         if (cap <= 0)
//         {
//             cap = 10;
//         }
//         capacity = cap;
//         lastIndex = -1;
//         ptr = new int[capacity];
//     }

//     int currentCapacity()
//     {
//         return capacity;
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
//             doubleArray();
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
//             doubleArray();
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
//         if (capacity > 1 && lastIndex < capacity / 2)
//         {
//             halfArray();
//         }
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
//     ~DynArray()
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
//     void display()
//     {
//         cout << "\nThe lastIndex is: " << lastIndex;
//     }
// };
// int main()
// {
//     DynArray a1(5);
//     a1.appendElement(10);
//     a1.appendElement(20);
//     DynArray a2(10);
// }

#include <iostream>
using namespace std;
class DynArray {
  int capacity;
  int lastIndex;
  int *ptr;

public:
  DynArray(int c) {
    if (c < 0) {
      c = -c;
    }
    capacity = c;
    lastIndex = -1;
    ptr = new int[capacity];
  }
  void doubleArray() {
    int *temp;
    temp = new int[capacity * 2];
    for (int i = 0; i <= lastIndex; i++) {
      temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    capacity = capacity * 2;
  }
  void halfArray() {
    int *temp;
    temp = new int[capacity / 2];
    for (int i = 0; i <= lastIndex; i++) {
      temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    capacity = capacity / 2;
  }
  int currentCapacity() { return capacity; }
  bool arrayEmptyOrNot() {
    if (lastIndex == -1) {
      return true;
    } else {
      return false;
    }
  }
  void appendNewElement(int element) {
    if (arrayIsFullOrNot()) {
      doubleArray();
    }
    ptr[lastIndex + 1] = element;
    lastIndex++;
  }
  void insertNewELementAtSpecificIndex(int element, int index) {
    if (index < 0) {
      cout << "\nInvalid index";
      return;
    }

    if (arrayIsFullOrNot()) {
      doubleArray();
    }

    for (int i = lastIndex; i >= index; i--) {
      ptr[i + 1] = ptr[i];
    }

    ptr[index] = element;
    lastIndex++;
  }
  void editElementAtSpecifiedIndex(int index, int element) {
    if (index < 0) {
      cout << "\nInvalid index";
      return;
    }

    ptr[index] = element;
  }
  void deleteElementAtSpecifiedIndex(int index) {
    if (index < 0) {
      cout << "\nInvalid index";
      return;
    }

    for (int i = index; i < lastIndex; i++) {
      ptr[i] = ptr[i + 1];
    }
    lastIndex--;
  }
  bool arrayIsFullOrNot() {
    if (lastIndex == capacity - 1) {
      return true;
    } else {
      return false;
    }
  }
  int getElement(int index) {
    if (index < 0) {
      cout << "\nInvalid index";
      return 0;
    }

    return ptr[index];
  }
  void countElement() {
    if (arrayEmptyOrNot()) {
      cout << "\nArray is empty";
      return;
    } else {
      int count = 0;
      for (int i = 0; i <= lastIndex; i++) {
        count++;
      }
      cout << "\n" << count << " total element present in the array";
    }
  }
  int findElement(int element) {
    if (arrayEmptyOrNot()) {
      cout << "\nArray is empty";
      return 0;
    }

    for (int i = 0; i <= lastIndex; i++) {
      if (ptr[i] == element) {
        return i;
      }
    }
    return -1;
  }
  void display() {
    cout << endl;
    for (int i = 0; i <= lastIndex; i++) {
      cout << ptr[i] << " ";
    }
  }
  ~DynArray() { delete[] ptr; }
};
int main() {
  DynArray d(5);
  d.appendNewElement(10);
  d.appendNewElement(20);
  d.appendNewElement(30);
  d.display();
  d.insertNewELementAtSpecificIndex(1, 0);
  d.display();
  d.editElementAtSpecifiedIndex(0, 10);
  d.display();
  d.deleteElementAtSpecifiedIndex(2);
  d.display();
  cout << "\n" << d.getElement(0);
  d.countElement();
  cout << "\n" << d.findElement(20);
  return 0;
}