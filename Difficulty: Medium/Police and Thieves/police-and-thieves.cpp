class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size();
        int i=0, j=0, ans=0;
        while(i<n && j<n){
            if(arr[i] == 'T' && arr[j] == 'P'){
                if(abs(i-j) <= k){
                    ans++;
                    i++;
                    j++;
                }
                else{
                    i<j? i++ : j++;
                }
            }
            else{
                while(i<n && arr[i] == 'P'){
                    i++;
                }
                while(j<n && arr[j] == 'T'){
                    j++;
                }
            }
        }
        return ans;
    }
};