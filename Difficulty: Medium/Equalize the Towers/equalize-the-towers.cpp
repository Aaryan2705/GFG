class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = cost.size();
    
        int l = *min_element(heights.begin(), heights.end());
        int r = *max_element(heights.begin(), heights.end());
    
        int ans = INT_MAX;  
    
        while(l <= r){
            int mid = l + (r - l) / 2;
    
            long long totalCost = 0;
            long long costLow = 0;
            long long costHigh = 0;
    
            for(int i = 0; i < n; i++) totalCost += 1LL * abs(heights[i] - mid) * cost[i];
            for(int i = 0; i < n; i++) costLow += 1LL * abs(heights[i] - (mid - 1)) * cost[i];
            for(int i = 0; i < n; i++) costHigh += 1LL * abs(heights[i] - (mid + 1)) * cost[i];
    
            ans = min(ans, (int)totalCost);
    
            if(costLow < totalCost) r = mid - 1;
            else if(costHigh < totalCost) l = mid + 1;
            else break;  
        }
    
        return ans;
    }
};
