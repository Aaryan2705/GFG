//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fn(vector<int> &a, int i, int k,vector<int> &dp){
        if(i==a.size()-1){
            return abs(a[a.size()-1]-a[i]);
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        for(int j=1; j<=k; j++){
            int dest=i+j;
            if(dest<=(a.size()-1)){
                ans=min(ans,((abs(a[dest]-a[i]))+fn(a,dest,k,dp)));
            }
        }
        return dp[i]=ans;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector<int> dp(arr.size()+1,-1);
        return fn(arr,0,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends