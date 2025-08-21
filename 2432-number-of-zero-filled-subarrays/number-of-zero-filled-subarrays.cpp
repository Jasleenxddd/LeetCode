class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                cnt++;
                sum+=cnt;
            }
            else cnt=0;
        }
        return sum;
    }
};