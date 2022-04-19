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
    int cnt=1,st=0;
    // for substring of length 2
    for(int i=0;i<n-1;i++){
        int j=i+1;
        if(s[i]==s[j]){
            dp[i][j]=1;
            cnt=2;
            st=i;
        }
    }
    for(int i=3;i<=n;i++){
        for(int j=0;j<n-i+1;j++){
            int k=j+i-1;
            if(s[j]==s[k] && dp[j+1][k-1]==1){
                dp[j][k]=1;  
                if(cnt<i){
                    cnt=i;
                    st=j;
                }
                              
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "Longest palindrome substring is: ";
    printSubStr(s, st, st + cnt - 1);
    cout<<s.substr(st,st + cnt);
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