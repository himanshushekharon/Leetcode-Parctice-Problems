class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        char c='a';
        unordered_map<char,int>mp;
        for(int i=26;i>=1;i--){
            mp[c++]=i;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=mp[s[i]]*(i+1);
        }
        return sum;
        
    }
};