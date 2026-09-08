class Solution {
public:
    int countCommas(int n) {
        int cnt=0;
        while(n>=1000){
            cnt++;
            n--;
        }
        return cnt;
    }
};