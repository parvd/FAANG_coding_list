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

ll solve(vector<int>a,ll org){
	
	vector<ll>s;
	ll n=a.size();
	ll m=pow(10,n);
	s.push_back(m-1);
	s.push_back(m+1);
	
	if(n%2==0){
		int size=n/2;
		string str[3]={""};
		for(int i=0;i<size;i++)
		str[0]+=to_string(a[i]);
		
		ll p=stoi(str[0]);
		int p1=p+1,p2=p-1;
		str[1]=to_string(p1);
		str[2]=to_string(p2);
		
		for(int i=0;i<3;i++){
			string res="";
			res+=str[i];
			reverse(str[i].begin(),str[i].end());
			res+=str[i];
			//cout<<res<<"\n";
			ll z=stoi(res);
			s.push_back(z);
		}
	}
	else{
		int size=n/2;
		string str[3]={""};
		string mid=to_string(a[size]);
		string midm=to_string(a[size]-1);
		string midp=to_string(a[size]+1);
		cout<<mid<<" "<<midm<<" "<<midp<<endl;
		for(int i=0;i<=size-1;i++)
		str[0]+=to_string(a[i]);
		
		ll p=stoi(str[0]);
		int p1=p+1,p2=p-1;
		str[1]=to_string(p1);
		str[2]=to_string(p2);
		
		
		for(int i=0;i<3;i++){
			string res="";
			string resm="";
			string resp="";
			res+=str[i];
			resm+=str[i];
			resp+=str[i];
			
			res+=mid;
			resm+=midm;
			resp+=midp;
			
			reverse(str[i].begin(),str[i].end());
			res+=str[i];
			resm+=str[i];
			resp+=str[i];
			cout<<res<<" "<<resm<<" "<<resp<<"\n";
			ll z=stoi(res);
			s.push_back(z);
			z=stoi(resm);
			s.push_back(z);
			z=stoi(resp);
			s.push_back(z);
		}
	
	}
	ll ans;
	ll min=INT_MAX;
	for(int i=0;i<s.size();i++)
	{
		//cout<<s[i]<<"\n";
		//cout<<"min="<<min<<endl;
		if(abs(org-s[i])<min && abs(org-s[i])!=0 ){
			//cout<<"f\n";
			ans=s[i];
			min=abs(org-s[i]);
		}
	}
	//cout<<ans<<endl;
	return  ans;
		
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll m=n;
		vector<int>a;
		while(n>0){
			int x=n%10;
			a.pb(x);
			n/=10;
		}
		reverse(a.begin(),a.end());
		ll y=solve(a,m);
		cout<<y<<endl;
	}
}




