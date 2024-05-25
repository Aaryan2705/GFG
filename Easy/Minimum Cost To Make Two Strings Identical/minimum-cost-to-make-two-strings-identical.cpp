//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        int n1 =x.size();
        int n2 =y.size();
        vector<vector<int>> dp(n1+ 1,vector<int> (n2 +1));
        dp[0][0] =0;
        for(int i =1;i<=n1;i++){
            for(int j =1;j<=n2;j++){
                if(x[i -1] == y[j -1]){
                    dp[i][j] = 1+ dp[i -1][j -1];
                }
                else{
                    dp[i][j] = max(dp[i -1][j],dp[i][j -1]);
                }
            }
        }
        
        int LCS =dp[n1][n2];
        return costX*(n1 - LCS) + costY*(n2 - LCS);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends