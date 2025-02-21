//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        for (char it : s) {
            if (it == '(' || it == '{' || it == '[') {
                st.push(it);
            } 
            else {
                if (st.empty()) return false;
                char top = st.top();
                if ((it == ')' && top == '(') || 
                    (it == '}' && top == '{') || 
                    (it == ']' && top == '[')) {
                    st.pop();
                } 
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends