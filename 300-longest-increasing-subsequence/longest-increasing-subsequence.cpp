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
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    //     for(int prev=0; prev<=n; prev++){
    //         dp[n][prev]=0;
    //     }
    //     for(int i=n-1; i>=0; i--){
    //         for(int prev=i-1; prev>=-1; prev--){
    //             int notTake=dp[i+1][prev+1];
    //             int take=0;
    //             if(prev==-1 || nums[i]> nums[prev]){
    //                 take= 1+dp[i+1][i+1];
    //             }
    //             dp[i][prev+1]= max(take, notTake);
    //         }
    //     }
    //     return dp[0][0];
    // }

    // using space optimization
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> ahead(n+1, 0), curr(n+1, 0);
    //     for(int i=n-1; i>=0; i--){
    //         for(int prev=i-1; prev>=-1; prev--){
    //             int notTake=ahead[prev+1];
    //             int take=0;
    //             if(prev==-1 || nums[i]> nums[prev]){
    //                 take= 1+ahead[i+1];
    //             }
    //             curr[prev+1]= max(take, notTake);
    //         }
    //         ahead=curr;
    //     }
    //     return ahead[0];
    // }

    // for tracing back
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if( nums[i]> nums[prev]) dp[i]=max(dp[i], 1+dp[prev]);
            }
           maxi=max(maxi, dp[i]);
        }
        return maxi;
    }
};