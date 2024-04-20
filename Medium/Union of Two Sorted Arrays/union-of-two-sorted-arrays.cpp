//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public: 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int>ans;
        int i=0, j=0; 
        int last = INT_MAX;
        
        while(i<n and j<m){
            if(arr1[i] == arr2[j] and last != arr1[i]){
                ans.push_back(arr1[i]);
                last = arr1[i];
                i++, j++;
            }else if(arr1[i] < arr2[j]){
                if(last != arr1[i]){
                    ans.push_back(arr1[i]);
                    last = arr1[i];
                }
                i++;
            }else{
                if(last != arr2[j]){
                    ans.push_back(arr2[j]);
                    last = arr2[j];
                }
                j++;
            }
        }
        
        while(i<n){
            if(last != arr1[i]){
                ans.push_back(arr1[i]);
                last = arr1[i];
            }
            i++;
        }
        while(j<m){
            if(last != arr2[j]){
                ans.push_back(arr2[j]);
                last = arr2[j];
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends