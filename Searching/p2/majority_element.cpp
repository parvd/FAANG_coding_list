//In c++
//by goku_11
/*
 Given an array A of N elements. Find the majority element in the array. 
 A majority element in an array A of size N is an element that appears 
 more than N/2 times in the array.
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
int solve(int a[], int n)
{

    // your code here
    int mi = 0;
    int c = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[mi])
        {
            c--;
        }
        else
        {
            c++;
        }
        if (c == 0)
        {
            mi = i;
            c = 1;
        }
    }
    int v = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[mi] == a[i])
        {
            v++;
        }
    }
    if (v <= (n / 2))
        return -1;
    return a[mi];
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
        int n;
        cin >> n;
        int a[n];
        vector<int> vec;
        FOR(i, 0, n)
        {
            cin >> a[i];
        }
        int ans = solve(a, n);
        cout << "Answer =" << ans << endl;
    }
}