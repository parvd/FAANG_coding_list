#//In c++
// by goku_11
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

void solve(int a[], int n)
{
    vector<int> c(n, 1);
    int i = 0, j = 1;

    while (j < n)
    {
        while (i < j)
        {

            cout << a[i] << "<" << a[j] << endl;
            if (a[i] < a[j])
            {   
                c[j] = max(c[j], c[i] + 1);
                i++;
            }
            else{
                i++;
            }
        }
        j++;
        i=0;
    }

    FOR(i, 0, n)
    cout << c[i] << " ";
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(ans<c[i]) ans=c[i];
    }
    cout<< ans <<endl;
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
        solve(a, n);
    }
}
