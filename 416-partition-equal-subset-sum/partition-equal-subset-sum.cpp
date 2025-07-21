class Solution {
public:
    // using memoization
    bool target(int i, int tar, vector<int>& arr, vector<vector<int>>& dp){
        if(tar==0) return true;
        if(i==0) return arr[i]==tar;
        if(dp[i][tar]!=-1) return dp[i][tar];
        bool notTake= target(i-1, tar, arr, dp);
        bool take=false;
        if(tar>= arr[i]) take=target(i-1, tar- arr[i], arr, dp);
        return dp[i][tar]= take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int tar=sum/2;
        vector<vector<int>> dp(n, vector<int> (tar+1, -1));
        return target(n-1, tar, nums, dp);
    }
};