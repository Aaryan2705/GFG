//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int Maximize(vector<int> arr) {
        int n = arr.size();
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Step 2: Initialize sum to 0
        long long sum = 0;
        
        // Step 3: Calculate the sum of arr[i] * i
        for (int i = 0; i < n; i++) {
            sum += (arr[i] * 1LL * i); // Multiply each element by its index
        }
        
        // Step 4: Return the result modulo 10^9 + 7
        return sum % 1000000007;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends