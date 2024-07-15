//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int sum(int num)
     {
         int cnt=0;
         while(num!=0) {
             int t=num%10;
             num=num/10;
             cnt+=t;
         }
         return cnt;
     }
     int countdigit(int num) {
         int cnt=0;
         while(num!=0)
          {
              int t=num%10;
              num=num/10;
              cnt++;
          }
          return cnt;
     }
    string smallestNumber(int s, int d) {
        string ans="";
        int num=1;
        for(int i=1;i<d;i++)
        {
            num=num*10;
        }
        while(countdigit(num)==d)
        {
            if(sum(num)==s)
             {
               ans=to_string(num);
                return ans;
             }
            num+=1;
        }
         return to_string(-1);
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends