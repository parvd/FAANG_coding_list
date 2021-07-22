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
void fourSum(vector<int> &a, int x)
{
    // Your code goes here

    int n = a.size();

    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && a[i - 1] == a[i])
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && a[j - 1] == a[j])
                continue;

            int k = j + 1, r = n - 1;
            while (k < r)
            {
                int sum = a[i] + a[j] + a[k] + a[r];
                if (sum == x)
                {
                    cout << "i=" << a[i] << "j=" << a[j] << "k=" << a[k] << "r=" << a[r] << endl;
                    k++;
                    r--;
                    while (k < r && a[k] == a[k - 1])
                        k++;
                    while (k < r && a[r] == a[r + 1])
                        r--;
                }
                else if (sum < x)
                {
                    k++;
                }
                else
                {
                    r--;
                }
            }
        }
    }
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
            vec.pb(a[i]);
        }
        fourSum(vec, x);
        cout<<endl;
    }
}
