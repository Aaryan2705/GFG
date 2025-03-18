//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool helper(int idx, vector<int>& arr, float sum, vector<vector<int>> &dp)
    {
        if(sum == 0)
            return true;
        if(idx >= arr.size())
            return false;
        if(dp[idx][sum] != -1)
            return dp[idx][sum]; 
        bool ans = helper(idx + 1, arr, sum, dp);
        if(sum - arr[idx] >= 0)
            ans = ans | helper(idx + 1, arr, sum-arr[idx], dp);
        return dp[idx][sum]=ans;
    }
    bool equalPartition(vector<int>& arr) 
    {
        int sum = 0;
        
        for(int i = 0; i < arr.size(); i++)
            sum += arr[i];
        float half = (float)(sum);
        half = half/2;
        //cout << half;
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum+1,-1));
        return helper(0,arr,half,dp);
        // code here
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends