//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int cnt=0;
        int k=-1;
        for(int i=0;i<mat.size();i++)
        {
            bool flag=false;
            for(int j=0;j<mat.size();j++)
            {
            if(i==j && mat[i][j]==1)
            {
                cnt++;
            }
            else if(mat[i][j]==1)flag=true;
             else
             cnt++;
            }
            if(flag==false) k=i;

        }
        if(cnt==2 && mat[0][1]==0 && mat[1][0]==0)return -1;
        if(cnt==1)return k;
        int cnt1=0;
        for(int i=0;i<mat.size();i++)
        {
            if(k!=-1)
            if(mat[i][k]==1 && i!=k)cnt1++;
        }
        if(cnt==mat.size()*mat.size())return -1;
        else if(cnt1==mat.size()-1)return k;
         return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends