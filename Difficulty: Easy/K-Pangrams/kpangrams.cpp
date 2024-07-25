//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        vector<int> ok(26,0);
        for(int i =0;i< str.size();i++){
            if(str[i] >='a' && str[i] <='z'){
                ok[str[i] -'a']++;
            }
        }
        int cnt =0;
        int extra =0;
        for(int i=0;i< 26;i++){
            if(ok[i] >0){
                cnt++;
                extra+=ok[i] -1;
            }
        }
       if(cnt == 26){
           return true;
       }
       int want =26- cnt;
       return extra >= want && want <=k;
    }    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends