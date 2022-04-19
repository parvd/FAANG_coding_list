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
#define null NULL

struct node
{
    int data;
    struct node *next;
};

void push(int data, node **root)
{
    node *temp = new node();
    temp->data = data;
    temp->next = *root;
    *root = temp;
}

void print(node *root)
{
    node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
void remove_loop(node *root,node *slow){
    node *p1=root,*p2=root;
    int k=1; //number of nodes in loop
    while(p1->next!=p2){
        p1=p1->next;
        k++;
    }
    p1=root;
    p2=root;
    for(int i=0;i<k;i++){
        p2=p2->next;
    }
    while(p1!=p2){
        p1=p1->next;
        p2=p2->next;
    }
    while(p2->next!=p1){
        p2=p2->next;
    }
    p2->next=null;
}
void check_loop(node *root)
{
    node *slow = root, *fast = root;

    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast){
            cout<<"loop\n";
            remove_loop(root,slow);
            break;
        }
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        node *root = null;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            //	cin>>x;
            push(i, &root);
        }
        
        root->next->next->next->next = root;
        check_loop(root);
        print(root);
    }
}