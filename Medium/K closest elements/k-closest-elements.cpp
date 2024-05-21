//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int> result;
        
        // Remove the occurrences of x
        arr.erase(remove(arr.begin(), arr.end(), x), arr.end());
        n = arr.size(); // Update size after removal

        // Find the closest element to x using binary search
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        // Initialize two pointers
        int left = idx - 1;
        int right = idx;
        
        // Collect k closest elements
        while (k > 0 && (left >= 0 || right < n)) {
            if (left >= 0 && right < n) {
                if (abs(arr[left] - x) < abs(arr[right] - x) || 
                    (abs(arr[left] - x) == abs(arr[right] - x) && arr[left] > arr[right])) {
                    result.push_back(arr[left--]);
                } else {
                    result.push_back(arr[right++]);
                }
            } else if (left >= 0) {
                result.push_back(arr[left--]);
            } else if (right < n) {
                result.push_back(arr[right++]);
            }
            k--;
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends