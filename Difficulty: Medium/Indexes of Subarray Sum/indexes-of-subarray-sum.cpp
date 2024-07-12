//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        int start = 0;
        long long current_sum = 0;
        vector<int> result;

        for (int end = 0; end < n; end++) {
            current_sum += arr[end];

            while (current_sum > s && start < end) {
                current_sum -= arr[start];
                start++;
            }

            if (current_sum == s) {
                result.push_back(start + 1);
                result.push_back(end + 1);
                break;
            }
        }

        if (result.empty()) {
            return {-1};
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends