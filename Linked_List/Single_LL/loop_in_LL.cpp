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
				break;
			}
        }  
        //cout<<"No Loop\n";
    }  
    if (slow_ptr != fast_ptr)
        {
		cout<<"No Loop\n";
		return ;
 		}
    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow_ptr = head;
    while (slow_ptr != fast_ptr) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }
    
    return ;
    
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
    
	head->next->next->next->next=head->next;
	detect_loop(head);
}






