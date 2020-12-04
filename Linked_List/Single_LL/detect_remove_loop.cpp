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
	
void push(node **head,int d){
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

void removeloop(node *pt,node *head){
	int cnt=1;
	node *t1 = pt;
	node *t2 = pt;
	while(t1->next != t2){
		t1=t1->next;
		cnt++;
	}
	t1=head;
	t2=head;
	for(int i=0;i<cnt;i++){
		t2=t2->next;
	}
	//they meet starting of loop node
	while(t1!=t2){
		t1=t1->next;
		t2=t2->next;
	}
	
	//get t2 to end of loop node
	while(t2->next!=t1){
		t2=t2->next;
	}
	t2->next=NULL;
	
}

void detect_loop(node *head)  
{  
     node *slow_ptr = head;  
     node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
        	
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
            if(slow_ptr == fast_ptr){
				removeloop(slow_ptr,head);
			}
        }  
    }  
}
int main()
{
	node *head=null;
	int n;

	push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 4); 
    push(&head, 5); 
    push(&head, 6);
    push(&head, 7);
	head->next->next->next->next->next = head->next;
	detect_loop(head);
	print(head);
}






