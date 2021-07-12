//In c++
//by goku_11
/* Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify 
the height of each tower either by increasing or decreasing them by K only once. After modifying, 
height should be a non-negative integer. Find out what could be the possible minimum difference 
of the height of shortest and longest towers after you have modified each tower. */

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
void getMinDiff(int arr[], int n, int k)
{
    // code here
    sort(arr, arr + n);

    int x = arr[n - 1] - arr[0];
    int mini, maxi;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < k)
        {
            continue;
        }
        maxi = max(arr[i] + k, arr[n - 1] - k);
        mini = min(arr[0] + k, arr[i + 1] - k);
        x = min(maxi - mini, x);
    }
    //cout<<maxi<<" "<<mini<<endl;
    cout<< x;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<int> vec;
    FOR(i, 0, n)
    {
        cin >> a[i];
    }
    getMinDiff(a, n, k);
}
