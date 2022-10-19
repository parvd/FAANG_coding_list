// C++ Program to check whether an array
// can be fit into another array with given
// condition.
#include <bits/stdc++.h>
using namespace std;

// Returns true if the array A can be fit into
// array B, otherwise false
bool checkFittingArrays(vector<int>p, vector<int>c)
{
	// Sort both the arrays
    int n=p.size();int m = c.size();
    map<int ,int>up;
    map<int,int>uc;	
    for(int i=0;i<n;i++){
        up[p[i]]=i;
    }
    for(int i=0;i<m;i++){
        uc[c[i]]=i;
    }
	sort(c.begin(), c.end());
    vector<int>ans;
    for(int i=0;i<n;i++){
        int x = p[i];
        int indx = lower_bound(c.begin(), c.end(), x) - c.begin();
        int val = c[indx];
        if(uc.find(val)!=uc.end()){
            if(uc[val]==-1){
                ans.push_back(-1);
            }
            else{
            ans.push_back(uc[val]);
            uc[val]=-1;
        }
        }

    }

    for(auto a:ans){
        cout<<a<<" ";
    }

}

// Driver Code
int main()
{
	vector<int>A = { 1000,10,1,1 };
	vector<int>B = { 12,12,1,1 };
	int N = sizeof(A) / sizeof(A[0]);

}
