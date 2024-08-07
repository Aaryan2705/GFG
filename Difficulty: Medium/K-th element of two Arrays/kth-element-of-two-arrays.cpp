//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int i = 0, j = 0, count = 0;
        int result = 0;

        // Traverse both arrays
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                result = arr1[i];
                i++;
            } else {
                result = arr2[j];
                j++;
            }
            count++;

            // If we have reached the k-th element
            if (count == k) {
                return result;
            }
        }

        // If arr1 still has elements left
        while (i < n) {
            result = arr1[i];
            i++;
            count++;
            if (count == k) {
                return result;
            }
        }

        // If arr2 still has elements left
        while (j < m) {
            result = arr2[j];
            j++;
            count++;
            if (count == k) {
                return result;
            }
        }

        // This should never be reached if k is valid
        return -1;
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