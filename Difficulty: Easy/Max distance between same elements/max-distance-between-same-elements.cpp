//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int>& arr) {
        unordered_map<int, int> firstIndex; // To store the first occurrence index of elements
        int maxDist = 0; // To keep track of the maximum distance
        
        for (int i = 0; i < arr.size(); ++i) {
            if (firstIndex.find(arr[i]) == firstIndex.end()) {
                // If it's the first occurrence, store the index
                firstIndex[arr[i]] = i;
            } else {
                // Calculate the distance and update maxDist
                int dist = i - firstIndex[arr[i]];
                maxDist = max(maxDist, dist);
            }
        }
        
        return maxDist;
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends