//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        int n = arr.size();
        if(x == y)
        {
            return (n*(n+1))/2;
        }
        
        map<int, int> mp;
        mp[0] = 1;
        
        for(int i = 0; i<arr.size(); i++)
        {
            if(arr[i] == x)
            {
                arr[i] = 1;
                continue;
            }
            if(arr[i] == y)
            {
                arr[i] = -1;
                continue;
            }
            
            arr[i] = 0;
        }
        int cnt = 0, sum = 0;
        
        for(int i = 0; i<n; i++)
        {
            sum += arr[i];
            
            if(mp.find(sum) != mp.end())
            {
                cnt += mp[sum];
            }
            mp[sum]+=1;
        }
        
        return cnt;
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
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends