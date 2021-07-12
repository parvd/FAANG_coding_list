//In c++
//by goku_11
//Write an efficient program to find the sum of contiguous subarray 
//within a one-dimensional array of numbers that has the largest sum. 
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
void solve(int a[],int n){
    int max_temp = 0;
    int s=0,m,e;
    int max_final = INT_MIN;
    FOR(i,0,n){
        max_temp+=a[i];
        if(max_final < max_temp){
            max_final = max_temp;
            s=m;
            e=i;
        }
        if(max_temp < 0){
            max_temp=0;
            m=i+1;
        }
    }
    cout<<"index="<<s<<"-"<<e<<" sum="<<max_final<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
        solve(a,n);
    }
}