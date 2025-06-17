class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());

        // Prefix sum: prefix[i] = sum of arr[0 to i-1]
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        long long res = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            int minVal = arr[i];
            int maxAllowed = minVal + k;

            // Binary search to find first index j such that arr[j] > maxAllowed
            int left = i, right = n - 1, cut = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (arr[mid] > maxAllowed) {
                    cut = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            long long leftRemoved = prefix[i];

           
            int count = n - cut;
            long long rightRemoved = 0;
            if (cut < n) {
                rightRemoved = prefix[n] - prefix[cut] - 1LL * count * maxAllowed;
            }
            res = min(res, leftRemoved + rightRemoved);
        }

        return (int)res;
    }
};