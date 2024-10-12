//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int max1=-1;
        for(int i=0;i<n-1;i++){
           max1=max(max1,arr[i]+arr[i+1]);
        }
        return max1;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends