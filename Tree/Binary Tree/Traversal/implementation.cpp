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

void morris_inorder(Node *root) //lhr
{
	Node *cur = root;
	while (cur != NULL)
	{
		if (cur->left == NULL)
		{
			cout << cur->data << " ";
			//   inorder.push_back(cur -> data);
			cur = cur->right;
		}
		else
		{
			Node *prev = cur->left;
			while (prev->right != NULL && prev->right != cur)
			{
				prev = prev->right;
			}

			if (prev->right == NULL)
			{
				prev->right = cur;
				cur = cur->left;
			}
			else
			{
				cout << cur->data << " ";
				prev->right = NULL;				
				cur = cur->right;
			}
		}
	}
}

void morris_preorder(Node *root) //hlr
{
	Node *cur = root;
	while (cur != NULL)
	{

		if (cur->left == NULL)
		{
			cout << cur->data << " ";
			cur = cur->right;
		}
		else
		{
			Node *prev = cur->left;
			while (prev->right != NULL && prev->right != cur)
			{
				prev = prev->right;
			}

			if (prev->right == cur)
			{
				prev->right = NULL;
				cur = cur->right;
			}
			else
			{
				cout << cur->data << " ";
				prev->right = cur;
				cur=cur->left;
			}
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
	cout << endl;
	cout<<"Inorder=";
	inorder(root);
	cout << endl;
	cout<<"Post=";
	postorder(root);
	cout << endl;
	cout<<"Morris-inorder=";
	morris_inorder(root);
	cout << endl;
	cout<<"Morris-preorder=";
	morris_preorder(root);
	return 0;
}
