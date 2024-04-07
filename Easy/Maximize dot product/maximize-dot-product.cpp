//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int dp[1001][1001];
	int func(int i, int j, int &n, int &m, int a[], int b[]){
	    if(j == m) return 0;
	    if(i == n) return -1e7;
	    if(dp[i][j] != -1) return dp[i][j]; 
	    return dp[i][j] = max((a[i] * b[j]) + func(i+1, j+1, n, m, a, b), func(i+1, j, n, m, a, b));
	}
	int maxDotProduct(int n, int m, int a[], int b[]) {
	    memset(dp, -1, sizeof(dp));
	    return func(0, 0, n, m, a, b);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends