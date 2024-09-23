//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int xo =0, n = arr.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            xo^=abs(arr[i])^(i+1); 
            if(arr[abs(arr[i])-1]<0)ans.push_back(abs(arr[i])); 
            else arr[abs(arr[i])-1]*=-1;
        }
        ans.push_back(ans[0]^xo);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends