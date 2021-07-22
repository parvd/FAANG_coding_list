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
bool solve(int a[], int n, int x)
{
    //code
    sort(a, a + n);
    int i = 0, j = 1, sum = 0;
    while (i <= j && j < n)
    {
        sum = a[j] - a[i];
        //cout<<sum<<" "<<i<<" - "<<j<<endl;
        cout << sum << " " << a[j] << "-" << a[i] << endl;
        if (sum > x)
        {
            i++;
        }
        else if (sum < x)
        {
            j++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
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
        int n, x;
        cin >> n >> x;
        int a[n];
        vector<int> vec;
        FOR(i, 0, n)
        {
            cin >> a[i];
        }
        bool y = solve(a, n, x);
        cout<<"ans="<<y<<endl;
    }
}