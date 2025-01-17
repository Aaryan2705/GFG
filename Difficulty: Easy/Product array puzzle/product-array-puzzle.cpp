//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int zeroes=0;
        int total=1;
        for(int& num:arr)
        {
            if(num)total*=num;
            if(num==0)
            {
                zeroes++;
            }
        }
        vector<int>result;
        for(int& num:arr)
        {
            if(num==0)
            {
                if(zeroes-1>0)
                {
                   result.push_back(0); 
                }
                else
                {
                    result.push_back(total);
                }
            }
            else
            {
                if(zeroes>0)
                {
                   result.push_back(0); 
                }
                else
                {
                    result.push_back(total/num);
                }
            }
            
        }
        return result;
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
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends