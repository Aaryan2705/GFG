//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<int> post_max(n), post_min(n);
        post_max[n - 1] = post_min[n - 1] = arr[n - 1];
        
        for(int i = n - 2; i >= 0; i--) {
            post_max[i] = max(arr[i], post_max[i + 1]);
            post_min[i] = min(arr[i], post_min[i + 1]);
        }
        
        int mini = arr[0], maxi = arr[0], res = post_max[k] - post_min[k];
        
        for(int i = 1; i < n - k; i++) {
            res = min(res, max(maxi, post_max[i + k]) - min(mini, post_min[i + k]));
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        
        res = min(res, maxi - mini);
        
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends