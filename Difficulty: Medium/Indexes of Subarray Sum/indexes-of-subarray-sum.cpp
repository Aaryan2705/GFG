//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int start = 0, currSum = 0;

        for (int end = 0; end < arr.size(); end++) {
            currSum += arr[end];

            while (currSum > target && start < end) {
                currSum -= arr[start];
                start++;
            }

            if (currSum == target) {
                return {start + 1, end + 1}; // 1-based indexing
            }
        }

        return {-1}; // No subarray found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends