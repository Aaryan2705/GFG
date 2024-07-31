//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        int N = arr.size();
        int i,j;
        sort(arr.begin(),arr.end());
        string s1=arr[0];
        string s2=arr[N-1];
        string ans="";
       for(int i=0; i<min(s1.size(),s2.size()); i++)
        {
            if(s1[i]==s2[i])
            {
                ans+=s1[i];
            
            }
            else
            {
                break;
            }
        }
         if(ans=="")
        return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends