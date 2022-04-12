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
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif	
	ll t;
	cin>>t;
	while(t--)
	{
	int n,e;
	// cout<<"Total Nodes=\n";
	cin>>n;
	// cout<<"Total Edges=\n";
	cin>>e;
	vector<int>adj[n];
	cout<<n<<" "<<e<<endl;
	cout<<"--\n";
	for(int i=1;i<=e;i++){
	int u,v;
	cin>>u>>v;
	addedge(adj,u,v);			
	}	
	printGraph(adj,n);
	}	 	
}




