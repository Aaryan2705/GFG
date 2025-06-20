class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n%k!=0) return 0;
        int x=n/k;
        priority_queue<int, vector<int>, greater<int>>pq(arr.begin(), arr.end());
        unordered_map<int, int>mpp;
        
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }
        
        while(x--){
            int next=-1;
            while(!pq.empty()){
                int top=pq.top();
                pq.pop();
                if(mpp.find(top)!=mpp.end()){
                    next=top;
                    break;
                }
            }
            if(next==-1) return 0;
            for(int i=0; i<k; i++){
                if(mpp.find(next)==mpp.end()) return 0;
                else{
                    mpp[next]--;
                    if(mpp[next]==0) mpp.erase(next);
                    next++;
                }
            }
        }
        
        return 1;
        
    }
};