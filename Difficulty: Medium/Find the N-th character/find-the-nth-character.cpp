//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string s0="01",s1="10";
    char nthCharacter(string s, int r, int n) {
        if(r==0) return s[n];
        int t=nthCharacter(s,r-1,n/2)-'0';
        return (t)?s1[n&1]:s0[n&1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends