class Solution {
  public:
    void palMatrixCreation(string &s,vector<vector<bool>>&isPal){
        int n=s.size();
        // make all single digit as true
        for(int i=0;i<n;i++){
            isPal[i][i]=true;
        }
        // for remaining string
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;
                if(len==2) isPal[i][j] = s[i]==s[j];
                else{
                    isPal[i][j] = (isPal[i+1][j-1] && s[i]==s[j]);
                }
            }
        }
        return;
    }
    void solve(string &s,int i,int n,vector<string>&curr,
    vector<vector<string>>&ans,vector<vector<bool>>&isPal){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        for(int k=i;k<n;k++){
            if(isPal[i][k]){  // left is pal
                curr.push_back(s.substr(i,k-i+1));
                solve(s,k+1,n,curr,ans,isPal);
                curr.pop_back(); // backtrack
            }
        }
        return;
    }
    vector<vector<string>> palinParts(string &s) {
        int n = s.size();
        // create a is palindrome matrix  
        vector<vector<bool>>isPal(n,vector<bool>(n,false));
        palMatrixCreation(s,isPal);
        
        // solving the problem using MCM pattern
        vector<vector<string>>ans;
        vector<string> curr;
        solve(s,0,n,curr,ans,isPal);
        return ans;
    }
};

