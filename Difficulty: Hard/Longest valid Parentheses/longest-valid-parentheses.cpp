//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& s) {
        int n = s.size();
        // code here
        stack<int>st; 
        int i = 0;
        vector<int>arr(n, 0);
        while(i < n){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(st.empty()){
                    arr[i] = -1;
                }
                else{
                    st.pop();
                }
                
            }
            i++;
        }
        
        while(!st.empty()){
            arr[st.top()] = -1;
            st.pop();
        }
                
        int ans = 0;
        i = 0;
        int l = -1;
        while(i < n){
            if(arr[i] == -1){
                l = i;
            }
            else{
                ans = max(ans, i - l);
            }
            i++;
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
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends