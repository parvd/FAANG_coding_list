#include<bits/stdc++.h>
using namespace std;
#define ll long long int


// find power of something with mod https://www.codechef.com/status/CQ2RMMTS
ll P(ll x, ll n, ll mod){
	if(n==0){
		return 1;
	}
	ll ans = 1;
	while(n>0){
		if(n%2==1){
			ans = (ans*x)%mod;
			n = n-1;
		}
		else{
			x = (x*x)%mod;
			n = n/2;
		}
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll final = 1e10;
        ll ans = 0;
        int cnt  = __builtin_popcount(n);
        while(n<final){
            n++;
            int cnt1 = __builtin_popcount(n);
            if(cnt1==cnt){
                ans = n;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}