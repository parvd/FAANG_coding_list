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
int solve(vector<int>a,int n,int sum){
	bool t[n+1][sum+1];
	memset(t,false,sizeof(t));	
	for(int i=0;i<n;i++)
	t[i][0]=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(a[i]<=sum){
				t[i][j]= t[i-1][j] ||t[i][j-a[i]];
			}
			else
			t[i][j]=t[i-1][j];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	
	int i=n,j=sum;
	while(i>=0&&j>0){
		//<<endl;
		if(t[i][j]){
			//cout<<i<<" "<<j<<endl; 
			if(t[i-1][j]){
				i--;
			}
			else{
				cout<<"A="<<a[i]<<"\n";
				j=j-a[i];
				i--;
			}
		}
		
	}
	
	
	
	if(t[n][sum])
	return 1;
	
	return 0;
	
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	int n,sum;
	cin>>n;
	vector<int>a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.pb(x);
	}
	cin>>sum;
	bool y=solve(a,n,sum);
	y?cout<<"yes\n":cout<<"no \n";
	} 
	
	
}





