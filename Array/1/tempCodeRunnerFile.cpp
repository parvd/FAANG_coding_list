//In c++
//by goku_11
#include<bits/stdc++.h>

using namespace std;

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
int main()
{
ll t;
cin>>t;
while(t--)
{
vector<pair<int,int> >af,br;
int maxdist = INT_MIN;
cin>>maxdist;
int nf,nr;
cin>>nf>>nr;
for(int i=0;i<nf;i++){
    int a,b;
    cin>>a>>b;
    af.push_back({a,b});
}
for(int i=0;i<nr;i++){
    int a,b;
    cin>>a>>b;
    br.push_back({a,b});
}

for(int i=0;i<nf;i++){
    cout<<af[i].fi<<" "<<af[i].sec;
}
for(int i=0;i<nr;i++){
    cout<<br[i].fi<<" "<<br[i].sec;
}

}
}
