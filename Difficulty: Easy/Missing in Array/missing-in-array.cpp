//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int missingNumber(int n, vector<int>& arr) {
        int total_sum = (n * (n + 1)) / 2;
        int array_sum = 0;
        for (int i = 0; i < n - 1; i++) {
            array_sum += arr[i];
        }
        // The missing number is the difference between the total sum and the array sum
        return total_sum - array_sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends