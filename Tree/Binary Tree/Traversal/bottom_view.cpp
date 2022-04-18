// In c++
// by goku_11
/*

*/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, n) FOR(i, 0, (int)n - 1)
#define pb push_back
#define mp make_pair
#define MS0(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, 1, sizeof(x))
#define SORT(a, n) sort(begin(a), begin(a) + n)
#define REV(a, n) reverse(begin(a), begin(a) + n)
#define ll long long int
#define llu unsigned long long int
#define pii pair<int, int>
#define MOD 1000000007
#define fi first
#define sec second
#define N NULL
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
void bottomview_util(Node *root,int dist,int level,auto &m){
	if(!root){
		return;
	}
	if(m.find(dist)==m.end()){
		m[dist] = {root->data,level};
	}
	else{
		if(level>=m[dist].second){
			m[dist].second=level;
			m[dist].first=root->data;
		}
	}
	bottomview_util(root->left,dist-1,level+1,m);
    bottomview_util(root->right,dist+1,level+1,m);
}
void bottomview(Node *root){

	map<int,pair<int,int>> m; //  < h-dist, pair<data,level> >
    bottomview_util(root, 0,0,m); // {root, dist, level ,m}

    for(auto it:m )
        cout<<it.second.first<< " ";

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

	bottomview(root);

}