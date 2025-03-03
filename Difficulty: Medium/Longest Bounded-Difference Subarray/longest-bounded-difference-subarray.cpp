//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        
     multiset<int>ms;
     int sz=0;
     int n=arr.size();
        
        int st=0;
        int ind=-1;
        int ans=0;
      
        for(int i=0;i<n;i++)
        {
          
          
          ms.insert(arr[i]);
          sz++;
          
          
          
          if(*ms.rbegin() - *ms.begin() > x)
          {
              ms.erase(ms.find(arr[st++]));
              
              sz--;
          }
          
          
          if(sz>ans)
          {
              ans=sz;
              ind=i;
          }
          
          
          
          
          
          
          
       
        
        }
        
        return vector<int>(arr.begin() + ind-sz + 1, arr.begin() + ind + 1);
        
        
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends