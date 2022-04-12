#include<bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int cnt=0;
        int dp[1000][1000];
        memset( dp, 0, sizeof(dp) );
        int i,j;
        for( i=1;i<=x;i++){
            for( j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[x][y];
    }

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        string s1,s2;
        cin>>x>>y;
        cin>>s1>>s2;
        cout<<lcs(x,y,s1,s2)<<endl;
    }
}