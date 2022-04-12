
#include <bits/stdc++.h>
using namespace std;

int lrs(int x,string s1){
		    // Code here
        int dp[1000][1000];
        memset( dp, 0, sizeof(dp) );
        int i,j;
        for( i=1;i<=x;i++){
            for( j=1;j<=x;j++){
                if((s1[i-1]==s1[j-1]) && (i!=j)){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
		}
		return dp[x][x];
	}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        string s1, s2;
        cin >> x ;
         cin >> s1 ; // >> s2;
        cout << lrs(x, s1) << endl;
    }
}