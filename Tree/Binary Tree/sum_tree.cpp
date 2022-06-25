// C++ program to find maximum sum from a subset of
// nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct node
{
	int data;
	struct node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Declaration of methods
int sumOfGrandChildren(node* node);
int getMaxSum(node* node);
int getMaxSumUtil(node* node, map<struct node*, int>& mp);

// method returns maximum sum possible from subtrees rooted
// at grandChildrens of node 'node'
int sumOfGrandChildren(node* node, map<struct node*, int>& mp)
{
	int sum = 0;

	// call for children of left child only if it is not NULL
	if (node->left)
		sum += getMaxSumUtil(node->left->left, mp) +
			getMaxSumUtil(node->left->right, mp);

	// call for children of right child only if it is not NULL
	if (node->right)
		sum += getMaxSumUtil(node->right->left, mp) +
			getMaxSumUtil(node->right->right, mp);

	return sum;
}

// Utility method to return maximum sum rooted at node 'node'
int getMaxSumUtil(node* node, map<struct node*, int>& mp)
{
	if (node == NULL)
		return 0;

	// If node is already processed then return calculated
	// value from map
	if (mp.find(node) != mp.end())
		return mp[node];

	// take current node value and call for all grand children
	int incl = node->data + sumOfGrandChildren(node, mp);

	// don't take current node value and call for all children
	int excl = getMaxSumUtil(node->left, mp) +
			getMaxSumUtil(node->right, mp);

	// choose maximum from both above calls and store that in map
	mp[node] = max(incl, excl);

	return mp[node];
}

// Returns maximum sum from subset of nodes
// of binary tree under given constraints
int getMaxSum(node* node)
{
	if (node == NULL)
		return 0;
	map<struct node*, int> mp;
	return getMaxSumUtil(node, mp);
}

// Driver code to test above methods
int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	root->left->left = newNode(1);

	cout << getMaxSum(root) << endl;
	return 0;
}
