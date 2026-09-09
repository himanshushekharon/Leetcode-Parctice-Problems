class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans=0;
        int p=0;
        for(int i:nums){
            p+=i;
            ans=min(p,ans);
        }
        return 1-ans;

    }
};