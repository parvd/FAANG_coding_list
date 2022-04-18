#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

void preorder(Node *root) // h,l,r
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(Node *root) // l,h,r
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
void postorder(Node *root) //
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}

void zigzag(Node *root){
    if(!root)
    return;

    stack<Node*>cur;
    stack<Node*>next;

    cur.push(root);
    bool ltor = true; // set this value for left to right (true) / right to left (false)
    while(!cur.empty()){        
        Node *temp = cur.top();
        cur.pop();
        if(temp){
            cout<<temp->data<<" ";
            if(ltor){
                if(temp->left)
                next.push(temp->left);
                if(temp->right)
                next.push(temp->right);
            }
            else{
                if(temp->right)
                next.push(temp->right);
                if(temp->left)
                next.push(temp->left);
            }
        }
        if(cur.empty()){
            ltor = ! ltor;
            swap(cur,next);
        }  
    }
    
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout<<"Preorder=";
	preorder(root);
    cout<<endl;
    zigzag(root);

}
