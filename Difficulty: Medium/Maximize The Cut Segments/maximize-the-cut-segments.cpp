//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    // Function to find the maximum number of cuts.
    int solve(int n, int x, int y, int z, vector<int>& dp) {
        if(n == 0)
            return 0; // Base case: No length left to cut
        if(n < x && n < y && n < z)
            return -1e9; // Impossible to cut further

        if(dp[n] != -1)
            return dp[n]; // Return the result if already computed

        // Try all possible cuts and choose the maximum
        int xcut = 1 + solve(n - x, x, y, z, dp);
        int ycut = 1 + solve(n - y, x, y, z, dp);
        int zcut = 1 + solve(n - z, x, y, z, dp);
        
        // Store the result in dp array and return it
        return dp[n] = max(xcut, max(ycut, zcut));
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1); // Initialize dp array with -1
        int ans = solve(n, x, y, z, dp); // Solve the problem
        
        if(ans < 0)
            return 0; // If no cuts were possible, return 0
        else 
            return ans; // Otherwise, return the maximum cuts
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends