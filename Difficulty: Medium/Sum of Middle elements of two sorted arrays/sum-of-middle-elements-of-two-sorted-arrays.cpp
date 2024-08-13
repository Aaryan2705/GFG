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
        for(auto it: arr1) {
            merged.push_back(it);
        }
        for(auto it: arr2) {
            merged.push_back(it);
        }
        // Sort the merged vector in non-decreasing order
        sort(merged.begin(), merged.end());

        // Access the first middle element (n-1)th element in the merged vector
        int middle1 = merged[n - 1];  // (n-1)th index
        
        // Access the second middle element (n)th element in the merged vector
        int middle2 = merged[n];    // nth index
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