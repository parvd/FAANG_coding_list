//In c++
//by goku_11
#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, n) FOR(i, 0, (int)n - 1)
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
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

struct Pair
{
    int min, max;
};

struct Pair answer(int a[], int n)
{
    Pair ans;
    int i = 1;
    if (n % 2 == 0)
    {
        //even
        ans.max = a[0];
        ans.min = a[1];
        if (ans.max < ans.min)
        {
            int t = ans.max;
            ans.max = ans.min;
            ans.min = t;
        }

        i = 2;
    }
    else
    {

        ans.max = a[0];
        ans.min = a[0];
        i=1;
    }

    while (i < n - 1)
    {

        if (a[i] > a[i + 1])
        {
            if ( ans.max < a[i] )
            {
                ans.max = a[i];
            }
            if (a[i + 1] < ans.min)
            {
                ans.min = a[i + 1];
            }
        }
        else
        {
            if (ans.max < a[i + 1])
            {
                ans.max = a[i + 1];
            }
            if (ans.min > a[i])
            {
                ans.min = a[i];
            }
        }
        cout<<ans.max << " "<<ans.min<<"\n";
        i++;
    }

    return ans;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Pair ans = answer(a, n);
    cout << ans.max << " " << ans.min;
}
