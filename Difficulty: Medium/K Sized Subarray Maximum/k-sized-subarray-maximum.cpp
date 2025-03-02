//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
        // code here
       vector<int> ans;
        map<int,int>mp;//the last key of the sorted map is the largest element
        int i = 0;int j = 0;
        int n = nums.size();
       
        ///using sliding window to generate all subarrays
        while(i<n && j<n)
        {
            mp[nums[j]]++;
             
             
            if(j-i+1 ==k)
            {
                auto it = *mp.rbegin();
               
                ans.push_back(it.first);
                mp[nums[i]]--;
                if(mp[nums[i]] ==  0)
                mp.erase(nums[i]);
                i++;
                
            }
            j++;
            
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends