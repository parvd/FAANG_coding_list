//In c++
//by goku_11
#include<bits/stdc++.h>
 
using namespace std;
 
#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb push_back
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
//undirected graph
void addedge(vector<int>adj [],int u,int v){
	adj[u].push_back(v);
	adj[v].pb(u);
}

//recursive dfs
void dfsutil(int u,vector<int>adj[],vector<bool> &visited){
	cout<<u<<" ";
	visited[u]=true;
	for(int v:adj[u]){
		if(!visited[v]){
			visited[v]=true;
			dfsutil(v,adj,visited);
		}
	}
	
}

//iterative dfs
void dfsutil_i(stack<int>&stk,vector<int>adj[],vector<bool>&visited){
	while(!stk.empty()){
	int x=stk.top();
	stk.pop();
	cout<<x<<" ";
	for(int u:adj[x]){
		if(!visited[u]){
			stk.push(u);
			visited[u]=true;
			}
		}
	}
}
void dfs(vector<int>adj[],int n){
	vector<bool>visited(n,0);
	stack<int>stk;
	for(int i=0;i<n;i++){
		if(!visited[i]){
		stk.push(i);
		visited[i]=true;
		dfsutil(i,adj,visited);
		}
	}	
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	int n,e;
	cout<<"Total Nodes=\n";
	cin>>n;
	cout<<"Total Edges=\n";
	cin>>e;
	vector<int>adj[n];
	for(int i=1;i<=e;i++){
	int u,v;
	cin>>u>>v;
	addedge(adj,u,v);		
	}
	dfs(adj,n);
	}	 	
}

/*
1
2 
1
3 
1 
4
2 
5 
2 
6
5
9
5 
10
4
7
4
8
7
11
7
12

*/



