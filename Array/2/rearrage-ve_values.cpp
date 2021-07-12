// Move all negative numbers to beginning and positive to end with constant extra space
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
{ //in-place arrange i.e orders can change
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            if (i != j)
            {
                swap(a[i], a[j]);
            }
            j++;
        }
    }
    FOR(i, 0, n)
    {
        cout << a[i] << " ";
    }
}
void reverse(int a[], int i, int j)
{
    int l = i, r = j;
    while (l < r)
    {
        swap(a[l], a[r]);
        l++;
        r--;
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i = l;     // Initial index of 1st subarray
    int j = m + 1; // Initial index of IInd

    while (i <= m && arr[i] < 0)
        i++;

    // arr[i..m] is positive

    while (j <= r && arr[j] < 0)
        j++;

    // arr[j..r] is positive

    // reverse positive part of
    // left sub-array (arr[i..m])
    reverse(arr, i, m);
    reverse(arr, m + 1, j - 1);
    reverse(arr, i, j - 1);
}

void solve2(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        solve2(arr, l, m);
        solve2(arr, m + 1, r);
        merge(arr, l, m, r);
    }
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
        solve2(a, 0, n);
        FOR(i, 0, n)
        {
            cout << a[i] << " ";
        }
    }
}