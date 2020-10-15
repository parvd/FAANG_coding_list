//In c++
//by goku_11
#include<bits/stdc++.h>
using namespace std;
void rev(int a[],int n){
	int en=n-1;
	for(int i=0;i<n/2;i++){
		swap(a[i],a[en]);
		en--;
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<"\n"
}
void rev_str(string a,int n){
	int en=n-1;
	for(int i=0;i<n/2;i++){
		swap(a[i],a[en]);
		en--;
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int a[100];// input as array
		string str; //input as string
		cout<<"start array input\n";
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		rev(a,n);
		cout<<"start string input\n";
		cin>>str;
		rev_str(str,str.length());
	} 	
}
