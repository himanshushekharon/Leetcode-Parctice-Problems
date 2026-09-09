class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        int l=0;
        for(int i=0;i<nums.size();i++){
            int r=sum-l-nums[i];
            if(l==r) return i;
            l+=nums[i];
        }
        return -1;
    }
};