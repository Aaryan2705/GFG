//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  vector<int> leftNS(vector<int> &arr,int n){
        vector<int> v(n,-1);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){s.pop();}
            if(!s.empty()){
                v[i]=s.top();
            }
            s.push(i);
        }
        return v;
    }
    
    vector<int> rightNS(vector<int> &arr,int n){
        vector<int> v(n,-1);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){s.pop();}
            if(!s.empty()){
                v[i]=s.top();
            }
            s.push(i);
        }
        return v;
    }
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n=arr.size();
        vector<int> l=leftNS(arr,n);
        vector<int> r=rightNS(arr,n);
        int diff=0;
        for(int i=0;i<n;i++){
            int a=l[i] != -1 ? arr[l[i]] : 0;
            int b=r[i] != -1 ? arr[r[i]] : 0;
            diff=max(diff,abs(a-b));
        }
        return diff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends