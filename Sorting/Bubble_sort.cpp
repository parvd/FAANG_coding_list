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

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int a[n];
	FOR(i,0,n-1){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]<a[i]){
				swap(a[j],a[i]);
			}
		}
	}
	FOR(i,0,n-1){
		cout<<a[i]<<" ";
	}	
	cout<<endl;
	} 		
}





