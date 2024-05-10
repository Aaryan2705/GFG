//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> ans; // Global variable to store the result
    
    // Recursive helper function to find combinations
    void help(int idx, int sum, vector<int> &arr, int n, vector<int> &temp) {
        if (sum == 0) { // Base case: if sum becomes zero, add the current combination to the result
            ans.push_back(temp);
            return;
        }
        if (idx == n) return; // Base case: if index reaches end of array, return
        
        for (int i = idx; i < n; ++i) {
            if (i != idx && arr[i] == arr[i - 1]) continue; // Skip duplicates
            if (arr[i] <= sum) {
                temp.push_back(arr[i]); // Add current element to the combination
                help(i + 1, sum - arr[i], arr, n, temp); // Recursive call with updated index and sum
                temp.pop_back(); // Backtrack by removing the last element
            }
        }
    }
    
    // Function to find combinations that sum up to target value
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
        sort(arr.begin(), arr.end()); // Sort the input array
        vector<int> temp; // Temporary vector to store current combination
        help(0, k, arr, n, temp); // Call helper function to find combinations
        return ans; // Return the result
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends