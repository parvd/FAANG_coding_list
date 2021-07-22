//In c++
//by goku_11

/* 
Given the array nums after the rotation and an integer target, 
return the index of target if it is in nums, or -1 if it is not in nums.
Q: Search in Rotated Sorted Array
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
int findPivot(vector<int> &arr, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (mid - 1 >= low && arr[mid] < arr[mid - 1])
        return mid - 1;
    else if (high >= mid + 1 && arr[mid + 1] < arr[mid])
        return mid;
    else if (arr[mid] < arr[low])
        return findPivot(arr, low, mid - 1);
    else
        return findPivot(arr, mid + 1, high);
}
int bs(vector<int> &arr, int low, int high, int target)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return bs(arr, low, mid - 1, target);
    else
        return bs(arr, mid + 1, high, target);
}
int search(vector<int> &arr, int target)
{
    if (arr.size() == 1)
        return target == arr[0] ? 0 : -1;
    int inx = findPivot(arr, 0, arr.size() - 1);
    int inx1 = bs(arr, 0, inx, target);
    int inx2 = bs(arr, inx + 1, arr.size() - 1, target);
    return inx1 == -1 ? inx2 : inx1;
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
            vec.push_back(a[i]);
        }
        int ans = search(vec, x);
        cout << ans << endl;
    }
}