class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, 1e9);
        int sum = 0, left = 0, ans = 1e9, best_so_far = 1e9;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left++];
            }
            if (sum == target) {
                int curr_len = right - left + 1;
                if (left > 0 && min_len[left - 1] != 1e9) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }
                best_so_far = min(best_so_far, curr_len);
            }
            min_len[right] = best_so_far;
        }

        return ans == 1e9 ? -1 : ans;
    }
};