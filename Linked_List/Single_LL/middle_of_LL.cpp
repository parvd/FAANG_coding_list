/*
Given a linked list, write a function to find middle .

Example:

Input: 1->2->3->4->5->6->7->8->NULL
O=>5
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

void printMiddle(node *head)  
{  
     node *slow_ptr = head;  
     node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf("\nThe middle element is [%d]\n\n", slow_ptr->data);  
    }  
}
int main()
{
	node *root=null;
	int n,k;
	cin>>n;
	if(k>n)
	cout<<"NOT possible\n";	
	for(int i=0;i<n;i++){
		int x;
	//	cin>>x;
		push(i,&root);
	}	
	print(root);
	printMiddle	(root);
}






