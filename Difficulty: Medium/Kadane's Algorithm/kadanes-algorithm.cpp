//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(std::vector<int>& arr) {
        // Handle edge case: if the array is empty
        if (arr.empty()) return 0;

        // Initialize variables
        int max_current = arr[0];
        int max_global = arr[0];

        // Iterate over the array starting from the second element
        for (size_t i = 1; i < arr.size(); ++i) {
            // Update max_current to be the maximum of the current element itself
            // or the current element plus the previous max_current
            max_current = std::max(arr[i], max_current + arr[i]);
            // Update max_global if max_current is greater
            max_global = std::max(max_global, max_current);
        }

        // Return the result
        return max_global;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends