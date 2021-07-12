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

bool print_ltor(Node *,int );

bool print_rtol(Node *root,int level){
    if(root==nullptr){
        return 0;
    }

    if(level==1){
        cout<<root->data<< " ";
        return 1;
    }

    bool right = print_rtol(root->right,level-1);
    bool left = print_ltor(root->left,level-1);

    return left || right;
}

bool print_ltor(Node *root,int level){
    if(root==nullptr){
        return 0;
    }

    if(level==1){
        cout<<root->data<< " ";
        return 1;
    }
    bool left = print_ltor(root->left,level-1);
    bool right = print_rtol(root->right,level-1);

    return left || right;
}


void zigzag(Node *root){
    if(root==nullptr){
        return ;
    }

    int level=1;
    // T = o(n^2)
    while(print_ltor(root,level++) && print_rtol(root,level++));

}

void preorder(Node *root, int level, auto &map)
{
    // base case: empty tree
    if (root == nullptr)
        return;

    // insert current node and its level into the map

    // if level is odd insert at back, else insert at front
    if (level & 1)
        map[level].push_back(root->data);
    else
        map[level].push_front(root->data);

    // recur for left and right subtree by increasing level by 1
    preorder(root->left, level + 1, map);
    preorder(root->right, level + 1, map);
}

void zigzag_it(Node *root){
    if(root == nullptr)
        return ;
    unordered_map<int,list<int>>m;
    preorder(root,1,m);

    for(int i=0;i<m[i].size();i++){
        cout<< "level="<<i<< ":";
        for(auto j:m[i]){
            cout<<j<< " ";
        }
        cout<<endl;
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

    zigzag_it(root);
}
