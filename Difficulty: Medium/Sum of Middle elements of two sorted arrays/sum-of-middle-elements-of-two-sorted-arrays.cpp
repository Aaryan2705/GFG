//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        vector<int> merged;

        // Merge the two arrays
        merged.reserve(2 * n);
        merged.insert(merged.end(), arr1.begin(), arr1.end());
        merged.insert(merged.end(), arr2.begin(), arr2.end());
        
        // Sort the merged array
        sort(merged.begin(), merged.end());

        // Find the middle elements and sum them
        int middle1 = merged[n - 1];  // (n-1)th index
        int middle2 = merged[n];      // nth index
        return middle1 + middle2;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends