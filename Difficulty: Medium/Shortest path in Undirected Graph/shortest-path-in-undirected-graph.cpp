//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int M, int src) {
        // Create adjacency list
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Initialize distance vector
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // Use a priority queue to implement Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0, src});  // {distance, node}

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            int currDist = top.first;

            for(auto neighbor : adj[node]){
                if(currDist + 1 < dist[neighbor]){
                    dist[neighbor] = currDist + 1;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        // Replace 1e9 with -1 for nodes that are unreachable
        for(int i = 0; i < dist.size(); i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends