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
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
void heapify(int a[],int n,int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l<n && a[l]>a[largest]) {
        largest = l;
    }
    if(r<n && a[r]>a[largest]) {
        largest = r;
    }
    if(largest != i){
        swap(a[i],a[largest]);
    }
    heapify(a,n,largest);
}
void heap(int a[],int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for(int i=n-1;i>=0;i++){
        swap(a[i],a[0]);
        heapify(a,i,0);
    }    
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        vector<int> vec;
        FOR(i, 0, n)
        {
            cin >> a[i];
        }
        heap(a,n);
        cout<<"A=";
        printArray(a,n);
    }
}
