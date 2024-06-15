//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        vector<long long>dp1(10,1);
        for(int i=2;i<=n;i++){
            vector<long long>dp2(10,0);
            dp2[0]=dp1[0]+dp1[8];
            dp2[1]=dp1[1]+dp1[2]+dp1[4];
            dp2[2]=dp1[1]+dp1[2]+dp1[3]+dp1[5];
            dp2[3]=dp1[2]+dp1[3]+dp1[6];
            dp2[4]=dp1[1]+dp1[4]+dp1[5]+dp1[7];
            dp2[5]=dp1[2]+dp1[4]+dp1[5]+dp1[6]+dp1[8];
            dp2[6]=dp1[3]+dp1[5]+dp1[6]+dp1[9];
            dp2[7]=dp1[4]+dp1[7]+dp1[8];
            dp2[8]=dp1[0]+dp1[5]+dp1[7]+dp1[8]+dp1[9];
            dp2[9]=dp1[6]+dp1[8]+dp1[9];
            dp1=dp2;
        }
        long long ans=accumulate(dp1.begin(),dp1.end(),0ll);
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
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends