//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int missingNumber(int n, vector<int>& arr) {
        // Calculate the sum of the first n natural numbers
        int totalSum = n * (n + 1) / 2;
        
        // Calculate the sum of the elements in the array
        int arraySum = 0;
        for (int i = 0; i < arr.size(); i++) {
            arraySum += arr[i];
        }
        
        // The missing number is the difference between the total sum and array sum
        return totalSum - arraySum;
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