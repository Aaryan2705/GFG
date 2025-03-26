//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool helper(int i,string s,set<string>st,vector<int> &dp){
        if(i == s.length()){
            return true;
        }
        if(dp[i] != -1)
            return dp[i];
            
        string temp ="";
        for(int j=i; j<s.length(); j++){
            temp += s[j];
            if(st.find(temp) != st.end()){
                if(helper(j+1,s,st,dp)){
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }

    int wordBreak(string s, vector<string> &dictionary) {
        vector<int> dp(s.size(),-1);
        set<string>st(dictionary.begin(),dictionary.end());
        
        return helper(0,s,st,dp);
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends