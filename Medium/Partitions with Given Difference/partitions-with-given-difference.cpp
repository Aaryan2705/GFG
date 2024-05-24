//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int mod = 1e9+7;
        // Calculating our search space
        int range = 0;
        for(int i=0;i<n;i++) range += arr[i]%mod;
        // if sum is odd and sum is negative then return 0
        if(range-d < 0 || ((d+range) % 2)) return 0;
        // calculating the sum for our valid answer
        int sum = ((range+d)/2);
        // our cache for storing the answer for sub-problems
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        // Initialization - same as subsetsum
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) dp[i][j] = 0; // if array is empty
                if(j==0) dp[i][j] = 1; // if sum is 0 but we can return empty set to thats why 1
            }
        }
        // calculating samea as subset sum
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1] <= j){
                    // valid input so we can take this
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j])%mod;
                }
                else{
                    // invalid input so cant take this
                    dp[i][j] = dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][sum]%mod; // this will be answer
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends