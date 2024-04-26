//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int i=0, j=0;
        int p_i=0, p_j=0;
        char ch = 'R';
        while(i>=0 and j>=0 and i<n and j<m){
            p_i = i;
            p_j = j;
            if(matrix[i][j]==0){
                if(ch=='R') j++;
                else if(ch=='D') i++;
                else if(ch=='L') j--;
                else i--;
            }
            else{
                matrix[i][j] = 0;
                if(ch=='R'){
                    ch='D';
                    i++;
                }
                else if(ch=='D'){
                    ch='L';
                    j--;
                }
                else if(ch=='L'){
                    ch='U';
                    i--;
                }
                else{
                    ch='R';
                    j++;
                }
            }
        }
        
        return {p_i, p_j};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends