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


void inorder(struct Node* node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

bool balance(Node *root,int *h)
{
    if(root == nullptr)
    {
       *h=0;
        return 1;

    }

    int l =0,r=0,lh=0,rh=0;

    l = balance(root->left,&lh);
    r= balance(root->right,&rh);

    *h = max(lh,rh)+1;

    if(abs(lh-rh)>2)
        return 0;
    else{
        return l && r;
    }


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
    int h=0;
    cout<<balance(root,&h);
}



