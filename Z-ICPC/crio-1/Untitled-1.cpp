//In c++
//by goku_11
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
void solve(vector<int>a, int n)
{
    sort(a.begin(),a.end());
    map<int,int>m;
    int cnt=0;
    // for(int i=0;i<n;i++)
    // m[a[i]]++;
    int i=1,j=0;
    while(i<n+1 && j<n){
        if(i<=a[j]){
            i++;
            j++;
            cnt++;        
        }
        else{
            j++;
        }
    }
    cout<<cnt<<endl;
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
        int n, k;
        cin >> n;
        int a;
        vector<int> vec;
        FOR(i, 0, n)
        {   
            cin>>a;
            vec.push_back(a);
        }
        solve(vec, n);
    }
}