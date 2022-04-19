#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int key)
    {
        data = key;
        this->left = this->right = nullptr;
    }
};

void leftView(Node *root){
	
	if(root==nullptr){
		return;
	}
	
	list<Node*>q;
	q.pb(root);
	
	Node *curr = root;
	while(!q.empty()){
		int s = q.size();
		int i=0;
		
		while(i++ < s){
			curr = q.front();
			q.pop_front();
			
			if(i==1){
				cout<<curr->data<<" ";
			}
			if(curr->left){
				q.pb(curr->left);
			}
			if(curr->right){
				q.pb(curr->right);
			}
			
		}
	}
	
	
}

int main()
{
    Node* root = nullptr;
 
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    leftView(root);
 
    return 0;
}
