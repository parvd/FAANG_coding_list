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
void solve(vector<string> &log, int n, int m)
{
    vector<int> id(n, 0);
    vector<int> time(n, 0);
    vector<string> st(n, "");
    int j = 0;
    for (string s : log)
    {
        int pos = s.find(" ");
        id[j] = stoi(s.substr(0, pos));
        int pos1 = s.find(" ", pos + 1);
        time[j] = stoi(s.substr(pos, pos1));
        j++;
    }
    map<int, pair<int, int>> ans;
    for (int i = 0; i < j; i++)
    {
        //cout<<id[i]<<" "<<time[i]<<endl;
        if (ans.find(id[i]) != ans.end())
        {
            ans[id[i]] = {abs(ans[id[i]].first - time[i]), 1};
        }
        else
        {
            ans[id[i]] = {time[i], 0};
        }
    }
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        if (i->second.first <= m && i->second.second)
        {
            cout << i->first << endl;
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
    int n, m;
    cin >> n >> m;
    string a;
    vector<string> vec;
    for (int i = 0; i < n; i++)
    {
        getline(std::cin >> std::ws, a);
        vec.push_back(a);
    }
    solve(vec, n, m);
}
