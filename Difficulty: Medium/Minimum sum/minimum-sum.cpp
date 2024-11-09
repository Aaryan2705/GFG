//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        int n = arr.size();
        if(n == 1) 
           return to_string(arr[0]);
          
        // Sort the array : as we have to find the min sum
        sort(arr.begin(), arr.end());
        
        // First num starting digit will be arr[0] and second num starting digit will be arr[1]
        string a = to_string(arr[0]),
        b = to_string(arr[1]);
        
        // Add digits in both
        for(int i=2; i<n; i+=2){
            a += to_string(arr[i]);
        }
        for(int i=3; i<n; i+=2){
            b += to_string(arr[i]);
        }
        
        // Reverse : as we have to add them
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        // Add both numbers
        int m = min(a.size(), b.size());
        string res = "";
        int i = 0, carry = 0;
        for(; i<m; i++){
            int cur = (a[i] - '0') + (b[i] - '0') + carry;
            carry = cur / 10;
            int num = cur % 10;
            res += to_string(num);
        }
        
        // Add remaining digits of num a
        int j = i;
        while(i < a.size()){
            int cur = (a[i] - '0') + carry;
            carry = cur / 10;
            int num = cur % 10;
            res += to_string(num);
            i++;
        }
        
        // Add remaining digits of num b
        while(j < b.size()){
            int cur = (b[i] - '0') + carry;
            carry = cur / 10;
            int num = cur % 10;
            res += to_string(num);
            j++;
        }
        
        // Add one digit for carry if it is not zero
        if(carry)
            res += to_string(carry);
        
        // Reverse the result to find the original sum
        reverse(res.begin(), res.end());
        
        // Skip the leading zeros
        i = 0;
        while(i < res.size() && res[i] == '0') i++;
        string ans = res.substr(i);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends