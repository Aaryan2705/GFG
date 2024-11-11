//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,int>m;
        int ans=0;
        int curr=0;
        for(auto &i:arr){
            
            if(m[i]==0){
                m[i]++;
            }
            else{
                if(curr>i){
                    ans+=curr-i;
                    i=curr;}
                while(m[i]){i++;ans++;}
                m[i]++;
                curr=i;
            }
        }
        return ans;
    }
};;

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends