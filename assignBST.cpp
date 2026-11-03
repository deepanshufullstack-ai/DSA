#include <iostream>
using namespace std;

struct node
{
    node *left;
    int item;
    node *right;
};

class BST
{
    node *root;

public:
    BST()
    {
        root = nullptr;
    }
    bool isEmpty()
    {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insert(int data)
    {
        node *n = new node;
        n->item = data;
        n->left = nullptr;
        n->right = nullptr;

        if (isEmpty())
        {
            root = n;
        }
        else
        {
            node *ptr = root;
            while (ptr->item != data)
            {
                if (data < ptr->item)
                {
                    if (ptr->left != nullptr)
                    {
                        ptr = ptr->left;
                    }
                    else
                    {
                        ptr->left = n;
                        break;
                    }
                }
                else
                {
                    if (ptr->right != nullptr)
                    {
                        ptr = ptr->right;
                    }
                    else
                    {
                        ptr->right = n;
                        break;
                    }
                }
            }
        }
    }
    void preOrder()
    {
        preOrderRec(root);
    }
    void preOrderRec(node *ptr)
    {
        if (ptr != nullptr)
        {
            cout << " " << ptr->item;
            preOrderRec(ptr->left);
            preOrderRec(ptr->right);
        }
    }
    void inOrder()
    {
        inOrderRec(root);
    }
    void inOrderRec(node *ptr)
    {
        if (ptr != nullptr)
        {
            inOrderRec(ptr->left);
            cout << " " << ptr->item;
            inOrderRec(ptr->right);
        }
    }
    void postOrder()
    {
        postOrderRec(root);
    }
    void postOrderRec(node *ptr)
    {
        if (ptr != nullptr)
        {
            postOrderRec(ptr->left);
            postOrderRec(ptr->right);
            cout << " " << ptr->item;
        }
    }
    node *search(int data)
    {
        node *ptr = root;
        while (ptr != nullptr)
        {
            if (ptr->item == data)
            {
                return ptr;
            }
            if (data < ptr->item)
            {
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
        return nullptr;
    }
    void deleteNode(int data)
    {
        root = deleteNodeRec(root, data);
    }

    // Find the smallest node
    node *findMin(node *ptr)
    {
        while (ptr->left != nullptr)
        {
            ptr = ptr->left;
        }
        return ptr;
    }

    // Recursive deletion
    node *deleteNodeRec(node *ptr, int data)
    {

        // Base condition
        if (ptr == nullptr)
        {
            return nullptr;
        }

        // Search in left subtree
        if (data < ptr->item)
        {
            ptr->left = deleteNodeRec(ptr->left, data);
        }

        // Search in right subtree
        else if (data > ptr->item)
        {
            ptr->right = deleteNodeRec(ptr->right, data);
        }

        // Node found
        else
        {

            // Case 1: No left child
            if (ptr->left == nullptr)
            {
                node *temp = ptr->right;
                delete ptr;
                return temp;
            }

            // Case 2: No right child
            else if (ptr->right == nullptr)
            {
                node *temp = ptr->left;
                delete ptr;
                return temp;
            }

            // Case 3: Two children
            node *temp = findMin(ptr->right);

            ptr->item = temp->item;

            ptr->right = deleteNodeRec(ptr->right, temp->item);
        }

        return ptr;
    }
};

int main()
{
    return 0;
}