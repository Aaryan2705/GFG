//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int low = 1, high = n, ans = 0;
        
        while (low <= high) {
            long long int mid = (low + high) / 2;
            long long int sqr = mid * mid;
            
            if (sqr == n) {
                return mid;  // Exact square root found
            } else if (sqr < n) {
                ans = mid;  // Store the potential answer
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;  // Return the floor value
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends