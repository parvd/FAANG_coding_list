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

void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}
 

void solve(string s){
    int n=s.length();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<n-i+1;j++){
            int k=i+j-1;
            if(s[k]==s[j]){
                dp[j][k]=2+dp[j+1][k-1];
            }
            else{
                dp[j][k] = max(dp[j+1][k],dp[j][k-1]);
            }
        }
    }    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[0][n-1];
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
        string s;
        cin>>s;
        solve(s);
        cout<<"\n---\n";
    }
}