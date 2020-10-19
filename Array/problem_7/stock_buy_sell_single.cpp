//In c++
//by goku_11
#include<bits/stdc++.h>
 
using namespace std;

int i=0;
int mini=INT_MAX;
int p=0;
while(i<n){
	if(a[i]<mini){
		mini=a[i];
	}
//	cout<<"mini="<<mini<<endl;
//	cout<<"a[i]-mini"<<"="<<a[i]-mini<<endl;
	p=max(a[i]-mini,p);
//	cout<<"p="<<p<<endl;
	i++;
}
cout<<p<<endl;
}
	

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	solve(a,n);
} 
}





