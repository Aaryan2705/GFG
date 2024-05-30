//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        string bin = "";
        int m = n;
        while(m > 1)
        {
            bin += to_string(m % 2);
            m /= 2;
        }
        bin += to_string(m);
        int cnt = 8 - bin.length();
        for(int i = 0; i < cnt; i++)
        {
            bin += '0';
        }
        reverse(bin.begin(), bin.end());
        string swappedBin = bin.substr(4) + bin.substr(0, 4);
        int ans = 0, mul = 1;
        for(int i = 7; i >= 0; i--)
        {
            ans += (swappedBin[i] - '0') * mul;
            mul *= 2;
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
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends