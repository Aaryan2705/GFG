//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:

    double solve(double b, int e) {

      double ans = 1;

      while (e) {

        if (e & 1) {

          ans = ans * b;

        }

        b = b * b;
        e = e >> 1;

      }
      return ans;
    }
  double power(double b, int e) {

    long long p = e;

    if (p < 0) {

      double ans = solve(b, -1 * p);

      return (1 / ans);

    }

    double ans = solve(b, p);
    return ans;

  }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends