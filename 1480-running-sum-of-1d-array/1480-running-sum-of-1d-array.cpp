class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // vector<int>v;
        // int x=0;
        // for(int i=0;i<nums.size();i++){
        //     x+=nums[i];
        //     v.push_back(x);
        // }
        // return v;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};