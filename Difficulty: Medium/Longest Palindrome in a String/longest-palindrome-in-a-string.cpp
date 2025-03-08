//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool palindrome(string &s){
        int start = 0;
        int end = s.length()-1;
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string &s) {
        // code here
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                if(s[i]==s[j]){
                    string temp = s.substr(i,j-i+1);
                    if(palindrome(temp)){
                        //cout<<temp<<endl;
                        if(ans.length()<temp.length()){
                            ans = temp;
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends