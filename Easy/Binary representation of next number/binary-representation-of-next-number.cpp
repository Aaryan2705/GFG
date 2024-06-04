//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        int j = s.size() - 1;
        
        while (j >= 0) {
            if (s[j] == '0') {
                s[j] = '1';
                break;
            } else {
                s[j] = '0';
                j--;
            }
        }
        
        if (j < 0) {
            s = '1' + s;
        }
        
        j = 0;
        
        while (j < s.size() && s[j] == '0') {
            j++;
        }
        
        return s.substr(j);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends