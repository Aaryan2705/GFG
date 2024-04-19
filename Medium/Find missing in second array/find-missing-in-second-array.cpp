//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
    vector<int> findMissing(int a[], int b[], int n, int m) 
    { 
        // Your code goes here
        vector<int> ans;
        unordered_map<int,int> mpp;
        
        for(int i=0;i<m;i++){
            mpp[b[i]]++;
        }
        
        for(int i=0;i<n;i++){
            int num = a[i];
            if(mpp.find(num) == mpp.end()){
                ans.push_back(num);
            }
        }
        
        return ans;
    } 
};
	

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        int m;
        cin>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<int> ans;
        

        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends