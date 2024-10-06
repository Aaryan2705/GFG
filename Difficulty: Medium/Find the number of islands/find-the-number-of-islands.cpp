//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void fun(vector<vector<char>>& grid, vector<vector<bool>>&vis, vector<pair<int, int>>&v, int i, int j){
        vis[i][j]=1;
        for(auto &b: v){
            int newi=i+b.first, newj=j+b.second;
            if(newi>=0 and newj>=0 and newi<grid.size() and newj<grid[0].size() and !vis[newi][newj] and grid[newi][newj]=='1'){
                fun(grid, vis, v, newi, newj);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>vis(grid.size(), vector<bool>(grid[0].size(), 0));
        vector<pair<int, int>>v={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    ans++;
                    fun(grid, vis, v, i, j);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends