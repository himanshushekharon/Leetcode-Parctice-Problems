class Solution {
public:
    bool isvowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int maxVowels(string s, int k) {
        int cnt=0;
        for(int i=0;i<k;i++){
            if(isvowel(s[i])) cnt++;
        }
        int mx=cnt;
        int n=s.size();
        for(int i=k;i<n;i++){
            if(isvowel(s[i])) cnt++;
            if(isvowel(s[i-k])) cnt--;
            mx=max(mx,cnt);
        }
        return mx;
    }
};