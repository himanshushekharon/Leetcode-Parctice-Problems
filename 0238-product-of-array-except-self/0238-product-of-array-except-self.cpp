class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n),suffix(n);
        prefix[0]=1;
        int p=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=p;
            p*=nums[i];
        }
        suffix[n-1]=1;
        int sp=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=sp;
            sp*=nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }
};