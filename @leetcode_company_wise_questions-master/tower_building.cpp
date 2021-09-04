// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the
// smallest subarray with sum K
int subArraylen(int arr[], int n, int K)
{
	// Stores the frequency of
	// prefix sums in the array
	unordered_map<int, int> mp;

	mp[arr[0]] = 0;

	for (int i = 1; i < n; i++) {

		arr[i] = arr[i] + arr[i - 1];
		mp[arr[i]] = i;
	}

	// Initialize len as INT_MAX
	int len = INT_MAX;

	for (int i = 0; i < n; i++) {

		// If sum of array till i-th
		// index is less than K
		if (arr[i] < K)

			// No possible subarray
			// exists till i-th index
			continue;

		else {

			// Find the exceeded value
			int x = arr[i] - K;

			// If exceeded value is zero
			if (x == 0)
				len = min(len, i);

			if (mp.find(x) == mp.end())
				continue;
			else {
				len = min(len, i - mp[x]);
			}
		}
	}

	return len;
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 4, 3, 2, 4, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int K = 7;

	int len = subArraylen(arr, n, K);

	if (len == INT_MAX) {
		cout << "-1";
	}
	else {
		cout << len << endl;
	}

	return 0;
}
