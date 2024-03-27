//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    if(i-1 >= 0)mat[i-1][j]=-1;
                    if(i+1< mat.size())mat[i+1][j]=-1;
                    if(j-1>=0)mat[i][j-1]=-1;
                    if(j+1<mat[0].size())mat[i][j+1]=-1;
                }
            }
        }
        int n=mat.size(),m=mat[0].size();
        // now we can move normally from left columns 1 to right columns
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            if(mat[i][0]==1)q.push({1,{i,0}});
        }
        //  to move in 3 direction ( no need to go backward )
        int dx[4] = {-1, 0, 1};
        int dy[4] = {0, 1, 0,};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int steps=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(col==m-1)return steps;
            // from current cell we can move to 4 dir (no need to move backward/right)
            for(int i=0;i<3;i++){
                int newR=row+dx[i];
                int newC=col+dy[i];
                if(newR>=0 && newR<n && newC>=0 && newC<m && mat[newR][newC]==1 && dist[newR][newC] > steps+1){
                    q.push({steps+1,{newR,newC}});
                    dist[newR][newC]=steps+1;
                }
            }
        }
        return -1;
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends