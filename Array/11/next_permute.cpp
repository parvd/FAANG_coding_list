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
void solve(int a[], int n)
{
    string s;
    int i;
    for (i = n - 1; i >= 1; i--)
    {
        if (a[i - 1] < a[i])
        {
            break;
        }
    }
    if (i == 0)
    {
        sort(a, a + n);
        return;
    }

    int k = i - 1;
    int x = a[k];
    int small = i;
    for (int j = k + 2; j < n; j++)
    {
        if (a[small] > a[j] && x < a[j])
        {
            small = j;
        }
    }
    swap(a[k], a[small]);
    sort(a + i, a + n);
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
        int n;
        cin >> n;
        int a[n];
        vector<int> vec;
        FOR(i, 0, n)
        {
            cin >> a[i];
        }
        solve(a, n);
        FOR(i, 0, n)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}