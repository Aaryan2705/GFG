//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {

        long long ans=0;
        long long temp=0;
            int cnt=0;


        for(int i=0;i<n;i++){


            if(arr[i]<=k){

              if(cnt==0)
                {//first stack
                    temp=arr[i];
                    cnt++;
                }
                else{//consecutive 
                    temp+=arr[i];
                    cnt++;
                }
            }
                else {//if not consecutive
                    ans=max(ans, temp);
                       cnt=0;
                    temp=0;
                }
           }


         ans=max(ans, temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends