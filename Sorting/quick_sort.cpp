// In c++
// by goku_11
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

int conquer(int a[],int st,int ed){
    int pt=a[ed];
    int idx=st;
    for(int i=st;i<ed;i++){
        if(a[i]<=pt){
            swap(a[i],a[idx]);
            idx++;
        }
    }
    swap(a[idx],a[ed]);
    return idx;

}
void divide(int a[],int st,int ed){
    if(st>=ed){
        return;
    }
    int pt=conquer(a,st,ed);
    divide(a,st,pt-1);
    divide(a,pt+1,ed);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        vector<int> vec;
        FOR(i, 0, n)
        {
            cin >> a[i];            
        }
        divide(a,0,n-1);
        FOR(i, 0, n)
        {
            cout<< a[i]<<" ";            
        }
    }
}