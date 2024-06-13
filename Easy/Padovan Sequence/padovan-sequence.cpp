//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n)
    {
       //code here
       if(n<=2)
       {
           return 1;
       }
       int n1=1;
       int n2=1;
       int n3=1;
       int ans=0;
       int mod=1000000007;
       for(int i=3;i<=n;i++)
       {
           ans=(n1+n2)%mod;
           n1=n2;
           n2=n3;
           n3=ans;
       }
       return ans;
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends