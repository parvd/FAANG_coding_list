/*CPP program to find the minimum number 
of swaps required to sort an array 
Input: arr[] = { 3, 5, 2, 4, 6, 8}
Output: 3
Explanation: 
Swap 4 and 5 so array = 3, 4, 2, 5, 6, 8
Swap 2 and 3 so array = 2, 4, 3, 5, 6, 8
Swap 4 and 3 so array = 2, 3, 4, 5, 6, 8
So the array is sorted.
*/
#include<bits/stdc++.h> 
using namespace std; 

// Function to find minimum swaps to 
// sort an array 
void printin(vector<pair<int,int>> vec,int n ){
	for(int i=0;i<n;i++)
	cout<<vec[i].first<<" ";
	cout<<endl;
}
int findMinSwap(int arr[] , int n) 
{ 
	// Declare a vector of pair	 
	vector<pair<int,int>> vec(n); 
	
	for(int i=0;i<n;i++) 
	{ 
		vec[i].first=arr[i]; 
		vec[i].second=i; 
	} 

	// Sort the vector w.r.t the first 
	// element of pair 
	sort(vec.begin(),vec.end()); 

	int ans=0,c=0,j; 

	for(int i=0;i<n;i++) 
	{ 
		// If the element is already placed 
		// correct, then continue 
		cout<<"i="<<i<<endl;
		if(vec[i].second==i) 
			continue; 
		else
		{ 
			// swap with its respective index 
			swap(vec[i].first,vec[vec[i].second].first); 
			swap(vec[i].second,vec[vec[i].second].second); 
			printin(vec,n);
		} 
		
		// swap until the correct 
		// index matches 
		if(i!=vec[i].second) 
			--i; 
		
		// each swap makes one element 
		// move to its correct index, 
		// so increment answer 
		ans++; 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 3, 5, 2, 4, 6, 8}; 
	
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	cout<<findMinSwap(arr,n); 
	
	return 0; 
} 

