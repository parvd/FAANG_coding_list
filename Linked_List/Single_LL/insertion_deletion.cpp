
//In c++
//by goku_11
#include<bits/stdc++.h>
using namespace std;
 
struct node{
		int data;
		struct node *next;
	};
		
void push(int x,node **head){
	node *temp 	= new node();
	temp->data=x;
	temp->next = *head;
	*head=temp;
}
void push_front(int x,node **head){
	
	node *new_node=new node();
	new_node->data=x;
	new_node->next = NULL;   
    
    if (*head == NULL)   
    {   
        *head = new_node;   
        return;   
    }   
    node *temp = *head;
    while (temp->next != NULL)   
        temp = temp->next;   
    
    temp->next = new_node;   
}
void print(node *head){
	node *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
	node *root=NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		//cin>>x;
		push(i,&root);
	}	
	print(root);
	cout<<endl;	
}






