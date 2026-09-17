class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int mx=sum;
        for(int i=0;i<n-k;i++){
            sum=sum-nums[i]+nums[i+k];
            mx=max(mx,sum);
        }
        return mx/(k*1.0);
    }
};