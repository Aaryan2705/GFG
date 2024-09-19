//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        vector<string>v;
        string s;
        for(int i = 0; i<str.length(); i++){
            if(str[i] == '.'){
                v.push_back(s);
                s.erase();
            }
            else s+=str[i];
        }
        v.push_back(s);
        s.erase();
        for(int i = v.size()-1; i>=0; i--){
            s += v[i];
            if(i !=0 )s+='.';
        }
        return s;
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