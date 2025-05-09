//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            int num = s[i] - '0';
            int id = -1;
            int mx = num + 1;
            for(int j = i+1; j < n; j++){
                int curr = s[j] - '0';
                if(curr >= mx){
                    id = j;
                    mx = curr;
                }
            }
            
            if(id != -1 && k > 0){
                swap(s[i], s[id]);
                k--;
            }
        }
        
        return s;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends