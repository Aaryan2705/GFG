//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumIndex;
        int sum = 0;
        int maxLength = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            // If subarray sum equals k
            if (sum == k) {
                maxLength = max(maxLength, i + 1);
            }
            
            // Check if (sum - k) exists in the map
            if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[sum - k]);
            }
            
            // Store the first occurrence of the prefix sum
            if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
                prefixSumIndex[sum] = i;
            }
        }
        
        return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends