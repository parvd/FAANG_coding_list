//In c++
//by goku_11
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
void solve(int a[], int n, int x)
{
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    int ans = INT_MAX;
    pii p;
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        int d = abs(x - a[i]);
        cout << "d=" << d << " a=" << a[i] << endl;

        int l = lower_bound(a, a + n, d) - a;
        int u = upper_bound(a, a + n, d) - a;
        cout << "l=" << l << " u=" << u << endl;
        if (l - 1 > 0)
        {
            cout << "l-1=" << a[l - 1] << endl;
            if (abs(d - a[l-1]) <= ans)
            {
                ans = abs(d - a[l-1]);
                cout<<"ans="<<ans<<endl;             
                p.first = a[i], p.second = a[l-1];
            }
        }
        if (u + 1 < n - 1)
        {
            cout<<"u+1=" << a[u + 1] << endl;
            if (abs(d - a[u+1]) <= ans)
            {
                ans = abs(d - a[u+1]);
                p.first = a[i], p.second = a[u+1];
            }
        }
    }
    cout << ans << " " << p.first + p.second; //= a[u];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    int a[n];
    vector<int> vec;
    FOR(i, 0, n)
    {
        cin >> a[i];
    }
    solve(a, n, x);
}
