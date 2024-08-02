//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int editDistance(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        
        // Create a 2D DP array
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Initialize base cases
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i; // Cost of deleting all characters from str1
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j; // Cost of inserting all characters into an empty str1
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // Characters are the same, no extra cost
                } else {
                    dp[i][j] = min({dp[i - 1][j] + 1,   // Delete
                                    dp[i][j - 1] + 1,   // Insert
                                    dp[i - 1][j - 1] + 1}); // Replace
                }
            }
        }
        
        return dp[m][n]; // Minimum operations to convert str1 to str2
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends