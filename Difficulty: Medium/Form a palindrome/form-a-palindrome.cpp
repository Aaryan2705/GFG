//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Every single character is a palindrome of length 1
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Fill the DP table
        for(int cl = 2; cl <= n; cl++) {
            for(int i = 0; i < n - cl + 1; i++) {
                int j = i + cl - 1;
                if(str[i] == str[j] && cl == 2) {
                    dp[i][j] = 2;
                } else if(str[i] == str[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        
        // The length of the longest palindromic subsequence is dp[0][n-1]
        int lps = dp[0][n-1];
        
        // Minimum insertions needed is the difference between
        // the string length and the length of the LPS
        return (n - lps);
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends