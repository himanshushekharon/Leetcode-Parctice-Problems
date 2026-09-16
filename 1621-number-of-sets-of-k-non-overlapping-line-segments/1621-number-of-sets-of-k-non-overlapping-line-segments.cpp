class Solution {
public:
    int numberOfSets(int n, int k) {
        long long mod = 1e9 + 7;
        int N = n + k - 1;
        int R = 2 * k;
        
        // We need to compute C(N, R) % mod using Pascal's Triangle or modular inverse.
        // Since N <= 2000, we can use Pascal's triangle to compute combinations safely.
        vector<vector<long long>> dp(N + 1, vector<long long>(R + 1, 0));
        
        for (int i = 0; i <= N; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= min(i, R); ++j) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }
        
        return dp[N][R];
    }
};