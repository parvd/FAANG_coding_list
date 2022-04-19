
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

void rev(node **root){
	node *prev=null,*nex;
	node *current=*root;
	while(current!=null){
		nex=current->next;
		current->next=prev;
		prev=current;
		current=nex;
	}
	*root=prev;
}
int main()
{
	
	node *root=null;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
	//	cin>>x;
		push(i,&root);
	}	
	print(root);
	rev(&root);
	cout<<endl;
	print(root);	
}






