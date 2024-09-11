//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        
        //declaring minheap
         priority_queue<long long, vector<long long>, greater<long long>>q;
        
      
        
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
        }
        long long sum=0;
            
        while(q.size()>1){
            
              long long fv=q.top();
              q.pop();
              long long sv=q.top();
              q.pop();
              sum+=fv+sv;
              q.push(fv+sv);
        }
        // long long fs=q.front();
        // q.pop();
        return sum;   // Your code here
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends