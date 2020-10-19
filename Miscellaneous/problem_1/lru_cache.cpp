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

class lru{
	
	list<int>dq;
	unordered_map<int,list<int>::iterator>mp;
	int csize;
	public:
		
		lru(int size){
			csize=size;
		}
		void insert(int data){
			
			if(mp.find(data)!=mp.end()){
				dq.erase(mp[data]);
			}
			else{
				if(dq.size()==csize){
					int last = dq.back();
					dq.pop_back();
					mp.erase(last);
				}
				
			}
			dq.push_front(data);
			mp[data]=dq.begin();
		}
		
		void display(){
			for(auto i=dq.begin();i!=dq.end();i++){
				cout<<*i<<" ";
			}
			cout<<endl;
		}
};
int main(){
	lru s(4);
	s.insert(9);
	s.insert(8);
	s.insert(7);
	s.insert(6);
	s.insert(5);
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(5);
	s.display();
}




