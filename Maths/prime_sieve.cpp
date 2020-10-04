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
void prime(int a,int b){

    bool arr[b+1];
    if(a==0)
    a++;
    if(a==1)
    a++;
    memset(arr,true,sizeof(arr));
    for(int i=2;ii<=b;i++){
        if(arr[i]){
            for(int j=ii;j<=b;j+=i){
                arr[j]=false;;
        }
    }
    for(int i=a;i<=b;i++)
    if(arr[i])
    cout<<i<<" ";

    cout<<endl;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    int a,b;
    cin>>a>>b;
    prime(a,b);
}
