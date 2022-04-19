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
void solve(string s1,string s2){
    int n1 = s1.length(),n2=s2.length();
    int v1=0,v2=0;
    for(int i=0,j=0;i<n1 || j<n2;){

        while(i<n1 && s1[i]!= '.' ){
            v1 = v1 * 10 + (s1[i]-'0');
            i++;
        }
        while (j<n2 && s2[i]!= '.' )
        {
            v2 = v2 * 10 + (s2[i]-'0');
            j++;
        }
        if(v1>v2){
            cout<<"s1";
            return;
        }
        else{
            cout<<"s2";
            return;
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
        string s1,s2;
        cin>>s1>>s2;
        solve(s1,s2);
    }
}