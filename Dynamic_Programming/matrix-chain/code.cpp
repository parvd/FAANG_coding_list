// See the Cormen book for details of the
// following algorithm
#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
void printParenthesis(int i, int j, int n, vector<vector<int>> bracket,char& name)
{
    // If only one matrix left in current segment
    if (i == j) {
        cout << name++;
        return;
    }
 
    cout << "(";
 
    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    // Note that "*((bracket+i*n)+j)" is similar to
    // bracket[i][j]
    printParenthesis(i, bracket[i][j], n, bracket, name);
 
    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(bracket[i][j] + 1, j, n, bracket, name);
    cout << ")";
}
int MatrixChainOrder(int p[], int n)
{
	vector<vector<int>> bracket(n,vector<int>(n,0));
	/* For simplicity of the program, one
	extra row and one extra column are
	allocated in m[][]. 0th row and 0th
	column of m[][] are not used */
	int m[n][n];

	int i, j, k, L, q;

	/* m[i, j] = Minimum number of scalar
	multiplications needed to compute the
	matrix A[i]A[i+1]...A[j] = A[i..j] where
	dimension of A[i] is p[i-1] x p[i] */

	// cost is zero when multiplying
	// one matrix.
	for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length.
	for (L = 2; L < n; L++)
	{
		cout<<"L="<<L<<endl;
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			cout<<"i="<<i<<"j="<<j<<endl;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				// q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				cout<<"k="<<k<<"q="<<q<<endl;
				cout<<m[i][k]<<" "<<m[k + 1][j]<<" "<<p[i - 1]<<" "<<p[k]<<" "<<p[j]<<endl;
				if (q < m[i][j]){
					m[i][j] = q;
					bracket[i][j] = k;
				}					
			}
		}
	}
	char name = 'A';
 
    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n - 1, n, bracket, name);
    cout << "nOptimal Cost is : " << m[1][n - 1];
    for (i=1; i<n; i++)
	{
		for (j = 1; j < n ; j++)
		{
			cout<<m[i][j]<<"\t";
		}
        cout<<endl;
	}


	return m[1][n - 1];
}

// Driver Code
int main()
{
	int arr[] = { 40,20,30,10,30};
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, size);

	getchar();
	return 0;
}

// This code is contributed
// by Akanksha Rai
