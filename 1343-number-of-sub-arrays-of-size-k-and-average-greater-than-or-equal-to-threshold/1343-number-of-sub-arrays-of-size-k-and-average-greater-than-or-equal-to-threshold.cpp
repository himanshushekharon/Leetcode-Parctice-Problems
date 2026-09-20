class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int cnt=0;
        if(sum/k>=th) cnt++;
        for(int i=k;i<n;i++){
            sum=sum-arr[i-k]+arr[i];
            if(sum/k>=th) cnt++;
        }
        return cnt;
    }
};