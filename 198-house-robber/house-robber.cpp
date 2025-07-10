class Solution {
public:
    // int f(int n, vector<int>& nums){
    //     if(n==0) return nums[0];
    //     if(n<0) return 0;
    //     int pick=nums[n]+f(n-2, nums);
    //     int notPick=0+f(n-1, nums);
    //     return max(pick, notPick);
    // }

    // using memoization
    // int f(int n, vector<int>& nums, vector<int>& dp){
    //     if(n==0) return nums[0];
    //     if(n<0) return 0;
    //     if(dp[n]!=-1) return dp[n];
    //     int pick=nums[n]+f(n-2, nums, dp);
    //     int notPick=0+f(n-1, nums, dp);
    //     return dp[n]=max(pick, notPick);
    // }

    int rob(vector<int>& nums) {
        int n=nums.size();

        // memoization
        // vector<int> dp(n,-1);
        // return f(n-1, nums, dp);

        // using tabulatiom
        vector<int> dp(n, 0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
            int notPick=0+dp[i-1];
            dp[i]=max(pick, notPick);
        }
        return dp[n-1];
    }
};