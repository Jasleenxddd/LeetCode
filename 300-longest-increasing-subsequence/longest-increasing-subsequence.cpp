class Solution {
public:
    // using memoization
    // int f(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
    //     if(i==nums.size()) return 0;
    //     if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    //     int len=f(i+1, prev, nums, dp);
    //     if(prev==-1 || nums[i]> nums[prev]){
    //         len=max(len, 1+f(i+1, i, nums, dp));
    //     }
    //     return dp[i][prev+1]= len;
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n, vector<int> (n+1, -1));
    //     return f(0, -1, nums, dp);
    // }

    // using tabulation
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int prev=0; prev<=n; prev++){
            dp[n][prev]=0;
        }
        for(int i=n-1; i>=0; i--){
            for(int prev=i-1; prev>=-1; prev--){
                int notTake=dp[i+1][prev+1];
                int take=0;
                if(prev==-1 || nums[i]> nums[prev]){
                    take= 1+dp[i+1][i+1];
                }
                dp[i][prev+1]= max(take, notTake);
            }
        }
        return dp[0][0];
    }
};