//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> sh;
        map<string,char> op = {
            {"+",'+'}, {"-",'-'},
            {"*",'*'}, {"/",'/'},
        };
        
        for(int i=0;i<arr.size();i++){
            if(op.find(arr[i]) != op.end()){
                int x = sh.top();
                sh.pop();
                int y = sh.top();
                sh.pop();
                // cout<<x<<" "<<op[arr[i]]<<" "<<y<<"\n";
                if(op[arr[i]] == '+'){
                    sh.push(y + x);
                }
                if(op[arr[i]] == '-'){
                    sh.push(y - x);
                }
                if(op[arr[i]] == '*'){
                    sh.push(y * x);
                }
                if(op[arr[i]] == '/'){
                    sh.push(y / x);
                }
            }
            else{
                sh.push(stoi(arr[i]));
            }
        }
        
        return sh.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends