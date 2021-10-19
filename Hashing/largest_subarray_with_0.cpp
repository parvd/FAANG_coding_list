/* A simple C++ program to find
largest subarray with 0 sum */
#include <bits/stdc++.h>
using namespace std;

// Returns length of the largest
// subarray with 0 sum
int maxLen(int arr[], int n)
{
	// Initialize result
	int max_len = 0;

	// Pick a starting point
	for (int i = 0; i < n; i++) {

		// Initialize currr_sum for
		// every starting point
		int curr_sum = 0;

		// try all subarrays starting with 'i'
		for (int j = i; j < n; j++) {
			curr_sum += arr[j];

			// If curr_sum becomes 0,
			// then update max_len
			// if required
			if (curr_sum == 0)
				max_len = max(max_len, j - i + 1);
		}
	}
	return max_len;
}

// Driver Code
int main()
{
	int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Length of the longest 0 sum subarray is "
		<< maxLen(arr, n);
	return 0;
}
