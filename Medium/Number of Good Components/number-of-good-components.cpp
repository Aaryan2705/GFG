//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        int ans = 0;
        vector<vector<int>> adj(v+1);
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> vis(v+1, 0); // Ignore 0 index
        for(int i=1;i<=v;i++){
            if(!vis[i]){
                vector<int> path;
                DFS(adj, i, path, vis);
                int flag = 0;
                for(int n:path){
                    if(adj[n].size() != path.size()-1){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) ans++;
            }
        }
        return ans;
    }
    
    void DFS(vector<vector<int>> &adj, int src, vector<int> &path, vector<int> &vis){
        vis[src] = 1;
        path.push_back(src);
        for(int nbr:adj[src]){
            if(!vis[nbr]) DFS(adj, nbr, path, vis);
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends