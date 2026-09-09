class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        for(int i:nums){
            sum+=i;
        }
        int cnt=0;
        long long l=0;
        for(int i=0;i<nums.size()-1;i++){
            l+=nums[i];
            sum-=nums[i];
            if(l>=sum)cnt++;
        }
        return cnt;
    }
};