//In c++
//by goku_11
#include<bits/stdc++.h>
 
using namespace std;
 
#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define N NULL
void distinct(string str){
	int n=str.length();
	bool check[255];
	int cnt=0,maxi=0;
	memset(check,false,sizeof(check));
	
	for(int i=0;i<n-1;i++){
		check[str[i]]=true;
		cnt=1;
		for(int j=i+1;j<n;j++){
			if(!check[str[j]]){
				cnt++;
				check[str[j]]=true;
			}
			else{
				break;
			}
		}
		maxi=max(cnt,maxi);
		cnt=0;
		memset(check,false,sizeof(check));
	}
	
	cout<<maxi<<endl;
}
void optimize(string str){
	int n=str.length();
	cout<<n<<endl;
	vector<int>a(256,-1);
	int cnt=0,maxi=0;
	for(int i=0;i<n;i++){
		cnt=max(cnt,1+a[str[i]]);
		maxi=max(i-cnt+1,maxi);
		a[str[i]]=i;
		
	}
	cout<<maxi<<endl;
	
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	string n;
	cin>>n;
	//distinct(n);
	optimize(n);
	} 	
}
