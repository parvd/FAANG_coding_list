/*
Given a linked list, write a function to reverse every k nodes (where k is an input to the function).

Input: 1->2->3->4->5->6->7->8->NULL, K = 3
Output: 3->2->1->6->5->4->8->7->NULL

Input: 1->2->3->4->5->6->7->8->NULL, K = 5
Output: 5->4->3->2->1->8->7->6->NULL
*/


//In c++
//by goku_11
#include<bits/stdc++.h>
using namespace std;
#define null NULL
 
struct node{
		int data;
		struct node *next;
	};
	
void push(int d,node **head){
	node *temp= new node();
	temp->data=d;
	temp->next=(*head);
	*head=temp;
}
void print(node *root){
	node *temp=root;
	while(temp!=null){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void rev(node **root,int k){
	int cnt=1;
	node *temp= *root;
	while(cnt<k){
		temp=temp->next;
		cnt++;
	}
	node *join_next = temp->next;
	temp->next = NULL;
	node *prev=null,*next;
	node *curr = *root;
	while(curr != NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	
	*root = prev;
	curr=prev;
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=join_next;
	
}
int main()
{
	node *root=null;
	int n,k;
	cin>>n>>k;
	if(k>n)
	cout<<"NOT possible\n";	
	for(int i=0;i<n;i++){
		int x;
	//	cin>>x;
		push(i,&root);
	}	
	print(root);
	rev(&root,k);
	cout<<endl;
	print(root);	
}






