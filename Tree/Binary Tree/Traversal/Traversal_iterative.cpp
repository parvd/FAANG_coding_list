// C program for different tree traversals 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
	Node(int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(struct Node* root) 
{ 
	stack<Node*> stk;
    stk.push(root);
 
    // create another stack to store post-order traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!stk.empty())
    {
        // we pop a node from the stack and push the data to output stack
        Node *curr = stk.top();
        stk.pop();
 
        out.push(curr->data);
 
        // push left and right child of popped node to the stack
        if (curr->left)
            stk.push(curr->left);
 
        if (curr->right)
            stk.push(curr->right);
    }
 
    // print post-order traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
} 

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 

	stack<Node*>st;
	Node * curr = node;
	while(!st.empty() || curr!=NULL){
		if(curr!=NULL){
			st.push(curr);
			curr=curr->left;
		}
		else{
			curr=st.top();
			st.pop();
			cout<<curr->data<<" ";
			curr=curr->right;
		}
	}
	
	
} 

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node *root) 
{ 
	if (root == NULL) 
		return; 

	stack<Node*>st;
	st.push(root);
	while(!st.empty()){
		Node *curr = st.top();
		st.pop();
		cout<<curr->data<<" ";
		
		if(curr->right)
		st.push(curr->right);
		
		if(curr->left)
		st.push(curr->left);
	}
} 

/* Driver program to test above functions*/
int main() 
{ 
	struct Node *root = new Node(1); 
	root->left			 = new Node(2); 
	root->right		 = new Node(3); 
	root->left->left	 = new Node(4); 
	root->left->right = new Node(5); 

	cout << "\nPreorder traversal of binary tree is \n"; 
	printPreorder(root); 

	cout << "\nInorder traversal of binary tree is \n"; 
	printInorder(root); 

	cout << "\nPostorder traversal of binary tree is \n"; 
	printPostorder(root); 

	return 0; 
} 

