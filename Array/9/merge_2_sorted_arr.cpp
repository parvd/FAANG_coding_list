//In c++
//by goku_11
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
void solve2(int a[], int b[], int m, int n) {
    cout<<"\n Solution 2\n";
	   for(int i=n-1;i>=0;i--){
	       int last = a[m-1],j;
	       for(j=m-2;j>=0 && a[j]>b[i] ;j--){
	           a[j+1]=a[j];
	       }
	       if(j!=m-2||last > b[i]){
	           a[j+1]=b[i];
	           b[i]=last;
	       }
	   }
       for(int i=0;i<m;i++)
	   cout<<a[i]<<" ";
	   for(int i=0;i<n;i++)
	   cout<<b[i]<<" ";
       cout<<endl;
	}
void solve(int a1[], int a2[], int n, int m)
{
    cout<<"\n Solution 1\n";
    int i = 0, j = 0;
    // cout<<n<<" "<<m<<endl;
    while (i < n && j < m)
    {
        if (a1[i] <= a2[j])
        {
            i++;
        }
        else
        {
            swap(a1[i], a2[j]);
            i++;
            while (a2[j + 1] < a2[j] && j < m - 1)
            {
                int temp = a2[j];
                int tempj = j + 1;
                while (a2[tempj] < temp && tempj < m)
                {
                    a2[tempj - 1] = a2[tempj];
                    tempj++;
                }
                a2[tempj - 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << a1[i] << " ";
    for (int i = 0; i < m; i++)
        cout << a2[i] << " ";
    cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[n];
        vector<int> vec;
        FOR(i, 0, n)
        {
            cin >> a[i];
        }
        FOR(i, 0, m)
        {
            cin >> b[i];
        }
        solve(a, b, n, m);
        solve2(a, b, n, m);
    }
}