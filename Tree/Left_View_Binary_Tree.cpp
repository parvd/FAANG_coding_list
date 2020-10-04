#include<bits/stdc++.h>
using namespace std;

struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp = new node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->key); 
        inorder(root->right); 
    } 
} 
   
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 

void leftViewUtil(node* root, int level, int* max_level) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // If this is the first node of its level 
    if (*max_level < level) { 
       // cout << root->key << "\t"; 
        *max_level = level; 
    } 
  
    // Recur for left and right subtrees 
    leftViewUtil(root->left, level + 1, max_level); 
    leftViewUtil(root->right, level + 1, max_level); 
} 
  
// A wrapper over leftViewUtil() 
void leftView(node* root) 
{ 
    int max_level = 0; 
    leftViewUtil(root, 1, &max_level); 
    cout<<max_level;
} 
// Driver Program to test above functions 
int main() 
{ 
    int t;
   cin>>t;
   while(t--){
    int n,v;
    cin>>n>>v;
    struct node *root = NULL; 
    root = insert(root, v); 
    for(int i=0;i<n-1;i++){
        int val;
        cin>>val;
        insert(root, val); 
    }
   
    // print inoder traversal of the BST 
  //  inorder(root); 
   leftView(root);
   cout<<endl;
    } 
} 
