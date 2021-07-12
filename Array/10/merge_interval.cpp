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
vector<vector<int>> solve(vector<vector<int>> &in)
{
    vector<pair<int, int>> v;
    int n = in.size();
    int m = in[0].size();
    sort(in.begin(), in.end());
    for (int i = 0; i < n; i++)
    {
        v.push_back({in[i][0], in[i][1]});
    }
    stack<pair<int, int>> st;
    st.push({v[0].first, v[0].second});
    pair<int, int> temp;

    for (int i = 1; i < n; i++)
    {
        temp = st.top();
        if (temp.second < v[i].first)
        {
            st.push({v[i].first, v[i].second});
        }
        else if (temp.second < v[i].second)
        {
            temp.second = v[i].second;
            st.pop();
            st.push(temp);
        }
    }
    in.clear();

    int i = 0;
    while (!st.empty())
    {
        vector<int> a;
        temp = st.top();
        a.push_back(temp.first);
        a.push_back(temp.second);
        st.pop();
        in.push_back(a);
        i++;
    }
    reverse(in.begin(), in.end());
    return in;
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
        vector<vector<int>> vec;
        FOR(i, 0, n)
        {
            int x, y;
            vector<int> temp;
            cin >> x >> y;
            temp.push_back(x);
            temp.push_back(y);
            vec.push_back(temp);
        }
        vector<vector<int>> in = solve(vec);
        for (int i = 0; i < in.size(); i++)
        {
            cout << in[i][0] << " " << in[i][1] << endl;
        }
    }
}