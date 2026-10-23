// #include <iostream>
// #define EMPTYSTACK 1;
// using namespace std;

// class Stack
// {
// private:
//     int capacity;
//     int top;
//     int *ptr;

// public:
//     Stack(int c)
//     {
//         if (capacity < 0)
//         {
//             capacity = 10;
//         }
//         capacity = c;
//         top = -1;
//         ptr = new int[capacity];
//     }
//     bool checkStckIsFullOrNot()
//     {
//         if (top == capacity - 1)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     void push(int data)
//     {
//         if (checkStckIsFullOrNot())
//         {
//             cout << "\nStack is overflow";
//         }
//         else
//         {
//             top++;
//             ptr[top] = data;
//         }
//     }
//     int peek()
//     {
//         if (top < 0)
//         {
//             throw EMPTYSTACK;
//         }
//         return ptr[top];
//     }
//     int pop()
//     {
//         if (top < 0)
//         {
//             throw EMPTYSTACK;
//         }
//         int x = ptr[top];
//         top--;
//         return x;
//     }
//     ~Stack()
//     {
//         delete[] ptr;
//     }
//     void reverseStack()
//     {
//         int i = 0;
//         int j = top;
//         while (i < j)
//         {
//             int temp = ptr[i];
//             ptr[i] = ptr[j];
//             ptr[j] = temp;

//             i++;
//             j--;
//         }
//     }
//     void findMinimum(){
//         int min=ptr[0];
//         for(int i=0; i<=top; i++){
//             if(ptr[i]<min){
//                 min=ptr[i];
//             }
//         }
//         cout<<"\nMin: "<<min;
//     }
//     void display()
//     {
//         for (int i = 0; i <= top; i++)
//         {
//             cout << ptr[i] << " ";
//         }
//     }
// };

// int main()
// {

//     try
//     {
//         Stack s1(5);
//         s1.push(45);
//         s1.push(30);
//         s1.push(40);
//         s1.push(50);
//         s1.push(60);

//         cout << "\n";
//         s1.display();

//         s1.pop();

//         cout << "\n";
//         s1.display();

//         s1.reverseStack();

//         cout << "\n";
//         s1.display();

//         s1.findMinimum();
//     }
//     catch (int e)
//     {
//         if (e == 1)
//         {
//             cout << "\nStack is empty";
//         }
//     }
//     return 0;
// }

#include<iostream>
using namespace std;
int main(){
    return 0;
}