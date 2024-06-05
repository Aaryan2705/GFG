//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Calculate the sum of both arrays
        int sumA = 0, sumB = 0;
        for (int i = 0; i < n; i++) sumA += a[i];
        for (int i = 0; i < m; i++) sumB += b[i];

        // Calculate the target difference
        int targetDiff = sumA - sumB;

        // If the target difference is odd, we cannot balance the sums by swapping
        if (targetDiff % 2 != 0) return -1;

        // The target difference should be halved
        targetDiff /= 2;

        // Sort both arrays
        sort(a, a + n);
        sort(b, b + m);

        // Use two pointers to find a valid swap
        int i = 0, j = 0;
        while (i < n && j < m) {
            int currentDiff = a[i] - b[j];
            if (currentDiff == targetDiff) {
                return 1; // Found a pair to swap
            } else if (currentDiff < targetDiff) {
                i++;
            } else {
                j++;
            }
        }

        return -1; // No pair found
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends