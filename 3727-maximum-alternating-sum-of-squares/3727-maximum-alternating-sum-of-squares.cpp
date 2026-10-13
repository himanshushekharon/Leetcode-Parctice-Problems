class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            nums[i]=abs(x);
        }
        long long a=0,b=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++){
            a+=(nums[i]*nums[i]);
        }
        for(int i=n/2;i<n;i++){
            b+=(nums[i]*nums[i]);
        }
        ans=b-a;
        return ans;
    }
};