// In c++
// by goku_11
#include <bits/stdc++.h>

using namespace std;

#define sp system("pause")
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, n) FOR(i, 0, (int)n - 1)
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
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

void merge(int a[], int l, int m, int h)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=h-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	L[i]=a[l+i];
	for(j=0;j<n2;j++)
	R[j]=a[m+1+j];
	
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			a[k]=L[i];
			i++;
		}
		else if(L[i] >= R[j]){
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=R[j];
		j++;
		k++;
	}
}

void partition(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		partition(a, low, mid);
		partition(a, mid + 1, high);
		merge(a, low, mid, high);
	}
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
		FOR(i, 0, n - 1)
		cin >> a[i];

		FOR(i, 0, n - 1)
		cout<< a[i]<<" ";
		cout<<endl;
		partition(a, 0, n - 1);

		FOR(i, 0, n - 1)
		cout << a[i] << " ";
		cout << endl;
	}
}
