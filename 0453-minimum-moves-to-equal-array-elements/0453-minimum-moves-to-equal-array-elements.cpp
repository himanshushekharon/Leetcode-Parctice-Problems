class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=nums[0];
        int sum=0;
        for(int x:nums){
            mx=min(mx,x);
            sum+=x;
        }
        return sum-mx*nums.size();
    }
};