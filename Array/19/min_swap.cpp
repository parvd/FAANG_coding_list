//In c++
//by goku_11
/*Given an array of n positive integers and a number k. 
Find the minimum number of swaps required to bring all the numbers 
less than or equal to k together.*/
#include<bits/stdc++.h>
 
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb push_back
#define mp make_pair
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
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
return (a.second < b.second);
}
void solve(int *arr, int n, int k) {
    // Complet the function
    
    int nums=0;//window size
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            nums++;//counts <=k
        }
    }
    if(nums==0 || nums==n){//if all are <=k || all are >k then return zero
        cout<< 0<<endl;
    }
    
    int ans=n;
    int nums2=0;
    
    for(int j=0;j<nums;j++){//creating 1st window
        if(arr[j]>k)
            nums2++;//count numbers greater than k in 1st window
    }
    ans=min(ans,nums2);    
    
    int l=0,r=nums-1;//initial window size
    while(r<n-1){
        if(arr[l]>k)//excluding left most
            nums2--;
        l++;    
        r++;
        if(arr[r]>k)//including right most
            nums2++;
        
        ans=min(ans,nums2);    
    }
    cout<< ans<<endl;
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
int n,k;
cin>>n>>k;
int a[n];
vector<int>vec;
FOR(i,0,n){
cin>>a[i];
}
solve(a,n,k);
}
}