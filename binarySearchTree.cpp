#include<iostream>
struct node {
    node *left;
    int item;
    node *right;
};
class BST {
    private:
    node *root;
    protected:
    void preOrderRec(node *ptr){
        if(ptr!=nullptr){
            cout<<" "<<ptr->item;
            preOrderRec(ptr->left);
            preOrderRec(ptr->right);
        }
    }
    void inOrderRec(node *ptr){
        if(ptr!=nullptr){
            inOrderRec(ptr->left);
            cout<<" "<<ptr->item;
            inOrderRec(ptr->right);
        }
    }
    void postOrderRec(node *ptr){
        if(ptr!=nullptr){
            postOrderRec(ptr->left);
            postOrderRec(ptr->right);
            cout<<" "<<ptr->item;
        }
    }
    public:
    BST(){
        root=nullptr;
    }
    bool isEmpty(){
        return root==nullptr;
    }
    void insertNewElement(int data){
        node *ptr;
        
        node *n=new node;
        n->item=data;
        n->left=nullptr;
        n->right=nullptr;

        if(isEmpty()){
            root=n;
        } else {
            ptr=root;
            while(ptr->item!=data){
                if(data < ptr->item){
                    // left subtree
                    if(ptr->left!=nullptr){
                        ptr=ptr->left;
                    } else {
                        ptr->left=n;
                        break
                    }
                } else {
                    // right subtree
                    if(ptr->right!=nullptr){
                        ptr=ptr->right;
                    } else {
                        ptr->right=n;
                        break;
                    }
                }
            }
            if(ptr->item==data){
                delete n;
            }
        }
        
    }
    void preOrder(){
        preOrderRec(root);
    }
    void inOrder(){
        inOrderRec(root);
    }
    void postOrder(){
        postOrderRec(root);
    }
    node *searchNode(int data){
        node *ptr=root;
        while(ptr!=nullptr){
            if(ptr->item==data){
                return ptr;
            } 

            if(data<ptr->item){
                ptr=ptr->left;
            } else {
                ptr=ptr->right;
            }
        }
    }
    // delete method is very confusing that why i can't create a method
};
int main(){
    return 0;
}






















