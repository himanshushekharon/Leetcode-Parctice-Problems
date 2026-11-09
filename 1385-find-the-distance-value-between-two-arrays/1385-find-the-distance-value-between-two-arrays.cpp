class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            bool ch=false;
            for(int j=0;j<m;j++){
                if(abs(arr2[j]-arr1[i])<=d){
                    ch=true;
                    break;
                }
            }
            if(!ch)
                cnt++;
        }
        return cnt;
    }
};