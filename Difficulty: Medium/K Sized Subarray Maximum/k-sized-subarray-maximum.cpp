//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        unordered_map<int,int> f; priority_queue<int> pq; vector<int> res;
        for ( int i = 0; i<k-1; i++ ) pq.push(arr[i]), f[ arr[i] ]++;
        for ( int i = k-1; i<arr.size(); i++ ){
            pq.push(arr[i]); f[ arr[i] ]++;
            while ( !pq.empty() && f[ pq.top() ] == 0 ) pq.pop();
            pq.push(arr[i-k+1]-1); f[ arr[i-k+1] ]--;
            res.push_back(pq.top());
        } return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends