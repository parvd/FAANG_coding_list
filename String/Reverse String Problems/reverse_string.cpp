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
#define N NULL
void rev_1(string &str){
	int n=str.length();
	int j=0,k=0;
	for(int i=0;i<n;i++){
		if(!isalnum(str[i])||i==n-1){
			if(i<n-1){
				k=i-1;
			}
			else{
				k=i;
			}
			while(j<k){
				char temp=str[j];
				str[j]=str[k];
				str[k]=temp;
				k--;
				j++;
			}
			j=i+1;
		}
	}
	cout<<str<<endl;
}
void rev_2(string &str){
	int i=0,j=str.length()-1;
	while(i<j){
		swap(str[i],str[j]);
		i++;
		j--;
	}
	cout<<str<<endl;
}
void rev_parv(string &s){
	int n=s.length();
	int i=0,k=0,j=0;
	for(i=0;i<n;i++){
		if(s[i]==' ' || i==n-1){
			if(i==n-1)
			j+=1;
			while(k<j){
				//cout<<s[k]<<" "<<s[j]<<endl;
				swap(s[k],s[j]);
				k++;
				j--;
			}
			//cout<<k<<endl;
			k=i+1;
		}
		else{
			j=i;		
		}
	}
	cout<<s<<endl;
}
int main()
{
	string str="my name is robert jr aka ironman";
	string s2=str;
	rev_parv(s2);
	
	//getline(cin,str); // my name is robert jr aka ironman
	//cout<<str<<endl;
	//rev_1(str); //ym eman si trebor rj aka namnori
	rev_2(str);//ironman aka jr robert is name my
	//cout<<str<<endl;
}





