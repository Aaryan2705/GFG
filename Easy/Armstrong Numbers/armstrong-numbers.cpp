//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:

    string armstrongNumber(int n){

        // code here

        int x = 0;

        int store = n;

        while(n>0){

            int divi = n%10;

            x=x+(divi*divi*divi);

            n=n/10;

        }

        if(x==store){

            return "Yes";

        }

        return "No";

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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends