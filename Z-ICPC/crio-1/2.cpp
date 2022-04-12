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
int solve(string arr, int n)
{
    // if length of array is 1
    // answer will be 0 as we have
    // to split it into two
    // non-empty halves
    if (n == 1)
        return 0;
 
    // variables to store total sum,
    // current sum and count
    int tot_sum = 0, sum = 0, ans = 0;
 
    // finding total sum
 
    // checking if sum equals total_sum/2
    for (int i = 0; i < n - 1; i++) {
        if(arr[i]=='R') 
        sum += 1;

        if (sum == 2)
            ans++;
    }
 
    return ans;
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
        int n, k;
        cin >> n;
        int a;
        vector<int> vec;
        string s;
        FOR(i, 0, n)
        {   
            cin>>s;
            // vec.push_back(a);
        }
        int x=solve(s, n);
        cout<<x<<endl;
    }
}