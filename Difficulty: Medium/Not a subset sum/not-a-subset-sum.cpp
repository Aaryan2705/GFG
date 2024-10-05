//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        long long ans = 1;  // Start with 1 as the smallest number
        
        // Sort the array to ensure we consider smaller elements first
        
        // Traverse the sorted array
        for(auto& e: arr) {
            // If the current element is greater than the running sum 'ans'
            if(e > ans) break;
            
            // Otherwise, include this element in the running sum
            ans += e;
        }
        
        // Return the smallest number that cannot be represented
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        auto ans = ob.findSmallest(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends