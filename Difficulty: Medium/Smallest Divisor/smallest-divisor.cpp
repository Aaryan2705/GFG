class Solution {
  public:
    bool func(vector<int>& arr, int mid, int k)
    {
        int sum = 0;
        for(int &x: arr)
        {
            sum += ceil(double(x)/double(mid));
            if(sum > k) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int s = 1, e = *max_element(arr.begin(), arr.end()), ans = e;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(func(arr, mid, k))
            {
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};