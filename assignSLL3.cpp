// #include <iostream>
// using namespace std;

// struct node
// {
//     int item;
//     node *next;
// };

// class SLL
// {
// private:
//     node *start;

// public:
//     SLL()
//     {
//         start = nullptr;
//     }
//     void insertAtTheBeginning(int data)
//     {
//         node *n = new node;
//         n->item = data;
//         n->next = start;
//         start = n;
//     }
//     void insertAtTheLast(int data)
//     {
//         node *n = new node;
//         n->item = data;
//         n->next = nullptr;

//         node *t;

//         if (start == nullptr)
//         {
//             start = n;
//         }
//         else
//         {
//             t = start;
//             while (t->next != nullptr)
//             {
//                 t = t->next;
//             }
//             t->next = n;
//         }
//     }
//     node *search(int data)
//     {
//         node *t;
//         t = start;
//         while (t != nullptr)
//         {
//             if (t->item == data)
//             {
//                 return t;
//             }
//             t = t->next;
//         }
//         return nullptr;
//     }
//     void insertAfterSpecifiedNode(node *temp, int data)
//     {
//         if (temp == nullptr)
//         {
//             cout << "The given node cannot be nullptr" << endl;
//             return;
//         }
//         node *n = new node;
//         n->item = data;
//         n->next = temp->next;
//         temp->next = n;
//     }
//     void deleteFirst(){
//         if (start != nullptr)
//         {
//             node *temp = start;
//             start = start->next;
//             delete temp;
//         }
//     }
//     void deleteLast(){
//         if (start == nullptr)
//         {
//             return;
//         }
//         if (start->next == nullptr)
//         {
//             delete start;
//             start = nullptr;
//             return;
//         }
//         node *t = start;
//         while (t->next->next != nullptr)
//         {
//             t = t->next;
//         }
//         delete t->next;
//         t->next = nullptr;
//     }
//     void deleteNode(node *temp){
//         if (temp == nullptr)
//         {
//             cout << "The given node cannot be nullptr" << endl;
//             return;
//         }
//         if (temp == start)
//         {
//             start = start->next;
//             delete temp;
//             return;
//         }
//         node *t = start;
//         while (t->next != nullptr && t->next != temp)
//         {
//             t = t->next;
//         }
//         if (t->next == nullptr)
//         {
//             cout << "The given node is not found in the list" << endl;
//             return;
//         }
//         t->next = temp->next;
//         delete temp;
//     }
//     ~SLL(){
//         while(start != nullptr)
//         {
//             deleteFirst();
//         }
//     }
//     void display()
//     {
//         node *t;
//         t = start;
//         while (t != nullptr)
//         {
//             cout << t->item << "->";
//             t = t->next;
//         }
//     }
// };

// int main()
// {
//     SLL s;
//     s.insertAtTheBeginning(10);
//     s.insertAtTheLast(20);
//     s.insertAtTheLast(30);

//     cout<<"\nBefore insertion: ";
//     s.display();

//     node *temp = s.search(20);

//     s.insertAfterSpecifiedNode(temp, 25);

//     cout<<"\nAfter insertion: ";
//     s.display();

//     s.deleteFirst();
//     cout<<"\nAfter deleting the first node: ";
//     s.display();

//     s.deleteLast();
//     cout<<"\nAfter deleting the last node: ";
//     s.display();

//     return 0;
// }
