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

void pushfront(int data, node **root)
{
    node *temp = new node();
    temp->data = data;
    temp->next = null;
    if (*root == NULL)
    {
        *root = temp;
    }
    else
    {
        node *curr = *root;
        while (curr->next != null)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void print(node *root)
{
    node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node* merge(node *r1, node *r2){
    
    if(r1==null) return r2;

    if(r2==null) return r1;

    if(r1->data > r2->data)
    swap(r1,r2);

    node* res = r1;
    while(r1 != NULL && r2 != NULL) {
 
            node* temp = NULL;

            while(r1 != NULL && r1->data <= r2->data) {

                temp = r1;//storing last sorted node  
                r1 = r1->next;
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = r2;
            std::swap(r1,r2);
        }
    return res;

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
        node *root1 = null, *root2 = null;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            pushfront(x, &root1);
        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin>>x;
            pushfront(x, &root2);
        }
        print(root1);
        cout << endl;
        print(root2);
        cout << endl;
        node *ans = merge(root1,root2);
        print(ans);
        cout << endl;
    }
}