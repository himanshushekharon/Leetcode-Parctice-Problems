#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // Add original indices to intervals to track them after sorting
        vector<vector<long long>> ext_intervals(n);
        for (int i = 0; i < n; ++i) {
            ext_intervals[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        
        // Sort intervals by right endpoint
        sort(ext_intervals.begin(), ext_intervals.end(), [](const vector<long long>& a, const vector<long long>& b) {
            return a[1] < b[1];
        });
        
        vector<long long> rights(n);
        for (int i = 0; i < n; ++i) {
            rights[i] = ext_intervals[i][1];
        }
        
        // DP state: pair of (score, vector of indices)
        // Using a custom structure or pair for values
        using State = pair<long long, vector<int>>;
        
        vector<State> prev(n + 1, {0, {}});
        
        for (int k = 0; k < 4; ++k) {
            vector<State> cur(n + 1, {0, {}});
            for (int p = 1; p <= n; ++p) {
                long long l = ext_intervals[p - 1][0];
                long long r = ext_intervals[p - 1][1];
                long long w = ext_intervals[p - 1][2];
                int idx = ext_intervals[p - 1][3];
                
                // Binary search for the largest index whose right endpoint < l
                auto it = lower_bound(rights.begin(), rights.end(), l);
                int j = distance(rights.begin(), it);
                
                // Option 1: Take the current interval
                long long score = prev[j].first + w;
                vector<int> ids = prev[j].second;
                ids.push_back(idx);
                sort(ids.begin(), ids.end());
                State take = {score, ids};
                
                // Option 2: Do not take the current interval (inherit from cur[p - 1])
                State skip = cur[p - 1];
                
                // Compare to maximize score, with tie-break on lexicographically smallest indices
                if (take.first > skip.first) {
                    cur[p] = take;
                } else if (take.first < skip.first) {
                    cur[p] = skip;
                } else {
                    cur[p] = (take.second < skip.second) ? take : skip;
                }
            }
            prev = cur;
        }
        
        return prev[n].second;
    }
};