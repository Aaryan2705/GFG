//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        if(arr.size() <= 2)
        {
            if(arr.size() == 2) return arr[0] == arr[1]  ? 1 : 2;
            return arr.size();
        }
        
        int c1{1};
        int c2{1};

        bool flip_flop{true};
        // x1 < x2 > x3 < x4 > x5. . . . . and so on
        for(int i{1}; i < arr.size(); i++)
        {
           if(flip_flop && arr[i-1] < arr[i])  {
               c1++;
               flip_flop = !flip_flop;
           }
           if(!flip_flop && arr[i-1] > arr[i])
           {
               c1++;
               flip_flop = !flip_flop;
           }
        }
        
        // x1 >x2 < x3 > x4 < x5. . . . . and so on
        flip_flop = false;
        for(int i{1}; i < arr.size(); i++)
        {
           if(flip_flop && arr[i-1] < arr[i])  {
               c2++;
               flip_flop = !flip_flop;
           }
           if(!flip_flop && arr[i-1] > arr[i])
           {
               c2++;
               flip_flop = !flip_flop;
           }
        }
        
        return std::max(c1, c2);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends