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

void mirror_tree(Node *root)
{
    if(root ==nullptr)
        return ;

    mirror_tree(root->left);
    mirror_tree(root->right);

    Node *temp;

    temp = root->left;
    root->left = root->right;
    root->right = temp;
}
void inorder(struct Node* node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
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

    inorder(root);
    mirror_tree(root);
    cout<<endl;
    inorder(root);
}


