//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
 int count(int node,int par,vector<vector<int>>&adj,int &res){
       int cnt=0;
       for(auto child : adj[node]){
           if(child!=par){
               int temp=count(child,node,adj,res);
               cnt+=temp;
               if(temp%2==0)res++;
           }
       }
       return cnt+1;
   }
    int minimumEdgeRemove(int n, vector<vector<int>>edges){
        // Code here
        int even=0;
        vector<vector<int>> adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        count(1,-1,adj,even);
        return even;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends