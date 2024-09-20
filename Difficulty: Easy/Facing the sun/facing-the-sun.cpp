//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Returns count of buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        int count = 0;         // To store the count of buildings that can see the sunrise
        int max_height = -1;   // Variable to track the maximum height so far

        for (int h : height) {
            if (h > max_height) {
                count++;        // This building can see the sunrise
                max_height = h; // Update max height
            }
        }

        return count; // Return the total count of buildings that can see the sunrise
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends