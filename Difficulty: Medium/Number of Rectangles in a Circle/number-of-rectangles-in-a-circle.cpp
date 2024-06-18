//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        int count = 0;
        int max_side = 2 * r;  // The maximum side length to check is 2*r
        for (int a = 1; a <= max_side; ++a) {
            for (int b = 1; b <= max_side; ++b) {
                if (a * a + b * b <= 4 * r * r) {
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends