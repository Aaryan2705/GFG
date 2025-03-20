//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
         vector<int>next(5),curr(5);
         int n=prices.size();
         for(int i=n-1;i>=0;i--){
             for(int j=3;j>=0;j--){
                 int profit=0;
                 if(j%2==0){
                     profit=max(-prices[i]+next[j+1],next[j]);
                 }
                 else{
                     profit=max(prices[i]+next[j+1],next[j]);
                 }
                 curr[j]=profit;
             }
             next=curr;
         }
         return next[0];
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends