//In c++
//by goku_11
/*
 Given an array representing n positions along a straight line. Find k (where k <= n) 
 elements from the array such that the minimum distance between any two (consecutive points among the k points) 
 is maximized.
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
bool isFeasible(int mid, int arr[], int n, int k)
{
    // Place first element at arr[0] position
    int pos = arr[0];

    // Initialize count of elements placed.
    int elements = 1;

    // Try placing k elements with minimum
    // distance mid.
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            // Place next element if its
            // distance from the previously
            // placed element is greater
            // than current mid
            pos = arr[i];
            elements++;

            // Return if all elements are placed
            // successfully
            if (elements == k)
                return true;
        }
    }
    return 0;
}

// Returns largest minimum distance for k elements
// in arr[0..n-1]. If elements can't be placed,
// returns -1.
int largestMinDist(int arr[], int n, int k)
{
    // Sort the positions
    sort(arr, arr + n);

    // Initialize result.
    int res = -1;

    // Consider the maximum possible distance
    //here we are using right value as highest distance difference,
    //so we remove some extra checks
    int left = 1, right = arr[n - 1] - arr[0];

    // left is initialized with 1 and not with arr[0]
    // because, minimum distance between each element
    // can be one and not arr[0]. consider this example:
    // arr[] = {9,12} and you have to place 2 element
    // then left = arr[0] will force the function to
    // look the answer between range arr[0] to arr[n-1],
    // i.e 9 to 12, but the answer is 3 so It is required
    // that you initialize the left with 1

    // Do binary search for largest minimum distance
    while (left < right)
    {
        int mid = (left + right) / 2;

        // If it is possible to place k elements
        // with minimum distance mid, search for
        // higher distance.
        if (isFeasible(mid, arr, n, k))
        {
            // Change value of variable max to mid iff
            // all elements can be successfully placed
            res = max(res, mid);
            left = mid + 1;
        }

        // If not possible to place k elements, search
        // for lower distance
        else
            right = mid;
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
        int n,c;
        cin >> n>>c;
        int a[n];
        vector<int> vec;
        FOR(i, 0, n)
        {
            cin >> a[i];
        }
        cout<<"ans="<<largestMinDist(a,n,c)<<endl;
    }
}