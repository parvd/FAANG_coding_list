//In c++
//by goku_11
/*
 
*/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, n) FOR(i, 0, (int)n - 1)
#define pb push_back
#define mp make_pair
#define MS0(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, 1, sizeof(x))
#define SORT(a, n) sort(begin(a), begin(a) + n)
#define REV(a, n) reverse(begin(a), begin(a) + n)
#define ll long long int
#define llu unsigned long long int
#define pii pair<int, int>
#define MOD 1000000007
#define fi first
#define sec second
#define N NULL
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y, k;
        cin >> n >> x >> y >> k;
        set<ll>v,p;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            if(a>=x && a<=y){
                p.insert(a);
				//cout<<"aaaa\n";
            }
            else
                v.insert(a);
        }
        int j=p.size() , z=v.size();
        //cout<<j<<" "<<z<<endl;
        ll ans = n-j+z;
        ll ans2= y-x+1-j;
        ll r = min(min(ans,ans2),k);
        
        cout<<r+j+z<<endl;

    }
}