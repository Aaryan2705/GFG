//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        vector<string>v;
        string curr = "";
        for(auto ch:str){
            if(ch == '.'){
                v.push_back(curr);
                curr = "";
            }
            else{
                if(!isdigit(ch))return false;
                curr.push_back(ch);
            }
        }
        if(curr.size() > 0){
            v.push_back(curr);
        }
        if(v.size() !=4)return false;
        for(auto str:v){
            long long int x = 0;
            for(int i=0;i<str.size();i++){
                x = 10*x + (str[i]-'0');
            }
            if(x > 255){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends