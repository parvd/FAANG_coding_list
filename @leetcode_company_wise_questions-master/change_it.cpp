#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string s;
ll n,pr[155],prio[155];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k;
    cin>>n;
    pr[0]=pr[1]=1;
    for(i=2;i*i<=150;i++)
    {
        for(j=i*i;j<=150;j+=i)
        {
            pr[j]=1;
        }
    }
    j=1;
    for(i=2;i<=150;i++)
    {
        if(pr[i]==0)
        {
            prio[i]=j;
            j++;
        }
    }
    for(i=150;i>=2;i--)
    {
        if(pr[i])
        {
            prio[i]=j;
            j++;
        }
    }
    cin>>s;
    vector<pair<ll,char> >v;
    assert(n>=1&&n<=100000);
    for(i=0;i<n;i++)
    {
        char c=s[i];
        assert((int)(c)>=33&&(int)(c)<=126&&c!=' ');
        v.push_back({prio[(int)c],c});
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
    cout<<v[i].second;
    return 0;
}


