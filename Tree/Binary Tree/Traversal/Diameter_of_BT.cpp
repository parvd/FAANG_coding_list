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

int solve(Node *root, auto &d)
{
    if(root == nullptr)
        return 0;
    int left = solve(root->left,d);
    int right = solve(root->right,d);

    int ans = left+right+1;
    d=max(ans,d);

    return max(left,right) + 1;
}
int getDiameter(Node *root){
    int d=0;
    solve(root,d);
    return d;
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

    cout<<getDiameter(root);
}

