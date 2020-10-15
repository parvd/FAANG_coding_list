//In c++
//by goku_11
#include<bits/stdc++.h>
using namespace std;

void max_2th(int a[],int n){
	int first=INT_MIN , second=INT_MIN;
	for(int i=0;i<n;i++){
		if(n<2){
			cout<<"Invalid\n";
		}
		if(a[i]>first){
			second=first;
			first=a[i];
		}
		else if(a[i]>second && a[i]!=first){
			second=a[i];			
		}
	}
	if(second==INT_MIN){
		cout<<"Invalid\n";
	}
	else{
		cout<<"2nd largest="<<second<<endl;
	}
}

void min_2th(int a[],int n){
	int first=INT_MAX , second=INT_MAX;
	for(int i=0;i<n;i++){
		if(n<2){
			cout<<"Invalid\n";
		}
		if(a[i]<first){
			second=first;
			first=a[i];
		}
		else if(a[i]<second && a[i]!=first){
			second=a[i];			
		}
	}
	if(second==INT_MIN){
		cout<<"Invalid\n";
	}
	else{
		cout<<"2nd smallest="<<second<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<"Start input:\n";
	int a[n+1];
	for(int i=0;i<n;i++)
	cin>>a[i];

	cout<<"----using_single_traversal----\n";
	max_2th(a,n);
	min_2th(a,n);
	
}
