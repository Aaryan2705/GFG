//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int c1=0,c2=0,m1=-1,m2=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==m1){
                c1++;
            }else if(nums[i]==m2){
                c2++;
            }else if(c1==0){
                m1=nums[i];
                c1=1;
            }else if(c2==0){
                m2=nums[i];
                c2=1;
            }else{
                c1--,c2--;
            }
        }
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            c1+=(nums[i]==m1);
            c2+=(nums[i]==m2);
        }
        if(c1>n/3) ans.push_back(m1);
        if(c2>n/3) ans.push_back(m2);
        return (ans.size()==0) ? vector<int>{-1} : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends