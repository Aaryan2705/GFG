class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();
        vector <int> ans;
        
        int id = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        
        int i = id-1;
        int j = id;
        
        
        while(k){
            while(i >= 0 && arr[i] == x) i--;
            
            int diff1 = INT_MAX;
            int diff2 = INT_MAX;
            if(i >= 0) diff1 = abs(x - arr[i]);
            if(j < n) diff2 = abs(x - arr[j]);
            
            if(diff2 <= diff1){
                ans.push_back(arr[j]);
                k--, j++;
            }
            else{
                ans.push_back(arr[i]);
                k--, i--;
            }
        }
        
        return ans;
    }
};