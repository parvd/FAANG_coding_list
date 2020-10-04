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
#define fi first
#define sec second

int main()
{
ll t;
cin>>t;
while(t--)
{
int n;
cin>>n;
int a[n];
FOR(i,0,n-1)
cin>>a[i];
int mini,j;
for(int i=1;i<n;i++){
mini=a[i];
j=i-1;
while(mini < a[j] && j>=0){
a[j+1]=a[j];
j--;
}
a[j+1]=mini;
}
FOR(i,0,n-1)
cout<<a[i]<<" ";
cout<<endl;
} 	
}





