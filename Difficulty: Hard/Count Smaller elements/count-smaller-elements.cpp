//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    vector<int> constructLowerArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        vector<int> sortedArr = arr;
        
        // Coordinate compression
        sort(sortedArr.begin(), sortedArr.end());
        for (int i = 0; i < n; ++i) {
            arr[i] = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin() + 1;
        }
        
        // Binary Indexed Tree (BIT) or Fenwick Tree
        vector<int> BIT(n + 1, 0);

        // Function to update the BIT
        auto updateBIT = [&](int index, int value) {
            while (index <= n) {
                BIT[index] += value;
                index += index & -index;
            }
        };

        // Function to get the sum from BIT
        auto queryBIT = [&](int index) -> int {
            int sum = 0;
            while (index > 0) {
                sum += BIT[index];
                index -= index & -index;
            }
            return sum;
        };

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = queryBIT(arr[i] - 1);
            updateBIT(arr[i], 1);
        }
        
        return ans;
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
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends