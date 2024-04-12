//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
    vector<int> v(32,0);
    long long ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<32;j++) {
            if(arr[i] & (1 << j)){
                ans += v[j] * (1LL << j); // Using left shift operator to calculate power of 2
                v[j]++;
            }
        }
    }
    return ans;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends