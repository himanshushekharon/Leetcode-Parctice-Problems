class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);
        
        // dp[r] stores the count of subarrays ending at the previous index with product modulo k == r
        vector<long long> dp(k, 0);

        for (int i = 0; i < n; i++) {
            vector<long long> next_dp(k, 0);
            long long rem = nums[i] % k;

            // A single element subarray starting and ending at index i
            next_dp[rem]++;

            // Extend all previous subarrays ending at i-1
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int new_rem = (r * rem) % k;
                    next_dp[new_rem] += dp[r];
                }
            }

            // Add counts to the global result and update dp for the next iteration
            dp = move(next_dp);
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};