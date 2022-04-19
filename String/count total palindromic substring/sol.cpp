// In c++
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
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
void solve(string s)
{
    // cout<<"tes\n";
    int n = s.length();
    int cnt = 0;
    int mid, left, right;
    for (int i = 0; i < n; i++)
    {
        mid = i;
        left = mid - 1;
        right = mid + 1;
        cnt++;
        // for odd length;
        while (left >= 0 && right < n)
        {
            if (s[left] == s[right])
            {
                left--;
                right++;
                cnt++;
            }
            else
            {
                break;
            }
        }
        // for even length  aabbaa
        if (mid < n - 1 && s[i] == s[i + 1])
        {
            cnt++;
            left = mid - 1;
            right = mid + 2;
            while (left >= 0 && right < n)
            {
                if (s[left] == s[right])
                {
                    left--;
                    right++;
                    cnt++;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout<<cnt<<endl;
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
        string s;
        cin >> s;
        solve(s);
    }
}