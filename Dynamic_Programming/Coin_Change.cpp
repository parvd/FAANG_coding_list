//In c++
//by goku_11
#include<bits/stdc++.h>
 
using namespace std;
 
#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long int 
#define llu unsigned long long int
#define pii pair<int,int>
#define MOD 1000000007

int mini(int x,int y){
    if(x>y)
    return y;
    return x;
}
void solve(vector<int>c,int n,int tot){
    if(tot==0){
        cout<<"nope\n";
        return;
    }
    int dp[n][tot+1];

    for(int i=0;i<n;i++){
        for(int j=0;j<=tot;j++){
            dp[i][j]=999;
        }
    }
    for(int i=0;i<n;i++)
    dp[i][0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=tot;j++){
            if(i==0 && c[i]>j){
            continue;
            }
            else if(i==0 && dp[i][j-c[i]]!=999){
                dp[i][j]=dp[i][j-c[i]]+1;
            }
            else {
                if(c[i]>j)
                dp[i][j]=dp[i-1][j];
                else if (c[i]<=j && i>0){
                dp[i][j]=mini(dp[i-1][j],dp[i][j-c[i]]+1);
                }

            }
    }
}
    for(int i=0;i<n;i++){
        for(int j=0;j<=tot;j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout<<dp[n-1][tot]<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.pb(x);
    }
    int val;
    cin>>val;
    solve(a,n,val);


    }
}
