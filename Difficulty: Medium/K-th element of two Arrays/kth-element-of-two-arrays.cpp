//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the k-th element in the merged sorted array
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        vector<int> merged; // To store the merged array
        int i = 0, j = 0; // Indices for arr1 and arr2

        // Merge the two arrays until one of them is exhausted
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                merged.push_back(arr1[i]);
                i++;
            } else {
                merged.push_back(arr2[j]);
                j++;
            }
        }

        // Add remaining elements of arr1 if any
        while (i < arr1.size()) {
            merged.push_back(arr1[i]);
            i++;
        }

        // Add remaining elements of arr2 if any
        while (j < arr2.size()) {
            merged.push_back(arr2[j]);
            j++;
        }

        // Return the k-th element (1-indexed, so access k-1)
        return merged[k - 1];
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends