class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {
        
        int n = img1.size();

        vector<pair<int, int>> a, b;

        // Store positions of 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    a.push_back({i, j});

                if (img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }

        map<pair<int, int>, int> freq;

        int ans = 0;

        // Try every possible translation
        for (auto p1 : a) {
            for (auto p2 : b) {

                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;

                freq[{dx, dy}]++;

                ans = max(ans, freq[{dx, dy}]);
            }
        }

        return ans;
    }
};