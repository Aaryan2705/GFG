//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
       int n=arr.size();
       int m=arr[0].size();
       int index;
       int ans=0;
       int cnt;
       
       for(int i=0;i<n;i++)
       {   
           cnt=0;
           int k=m-1;
           while((arr[i][k])&&k>=0)
           {
               cnt++;
               k--;
               
           }
           
           if(cnt>ans)
           {
               ans=cnt;
               index=i;
           }
           
       }
       if(ans==0)return -1;
       return index;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends