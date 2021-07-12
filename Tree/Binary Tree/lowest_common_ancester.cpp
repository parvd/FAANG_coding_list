#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int data){
        this->data=data;
        left=right=nullptr;
    }
};


Node *lca(Node *root,int n1,int n2)
{
    if(root == nullptr)
        return nullptr;

    if(root->data == n1 || root->data == n2 ){
        return root;
    }

    Node *left=lca(root->left,n1,n2);
    Node *right = lca(root->right,n1,n2);

    if(left == nullptr && right == nullptr)
        return nullptr;

    if(left!=nullptr && right!=nullptr)
        return root;

    return left?left:right;
}

int main(){

    Node* root = nullptr;

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    int n1=8,n2=5;
    //cin>>n1>>n2;  T=o(n)
    cout<<lca(root,n1,n2)->data;
}




