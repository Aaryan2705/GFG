//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string reverseWords(string str) {
        reverse(str.begin(), str.end());       // Reverse the entire string
        int start = 0;
        for (int i = 0; i <= str.size(); i++) {
            if (i == str.size() || str[i] == '.') {
                reverse(str.begin() + start, str.begin() + i); // Reverse individual words
                start = i + 1;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends