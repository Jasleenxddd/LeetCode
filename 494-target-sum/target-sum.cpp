class Solution {
public:
    // int tar(int i, int sum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset){
    //     if(i==nums.size()){
    //         if(sum==target) return 1;
    //         else return 0;
    //     }
    //     if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];
    //     int add=tar(i+1, sum+nums[i], nums, target, dp, offset);
    //     int sub=tar(i+1, sum-nums[i], nums, target, dp, offset);
    //     return dp[i][sum+ offset]=add+sub;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     int offset=1000;
    //     vector<vector<int>> dp(n, vector<int> (2*offset+1, -1));
    //     return tar(0, 0, nums, target, dp, offset);
    // }

    // using memoization or recursion
    // int cntDiff(int i, int target, vector<int>& arr, vector<vector<int>>& dp){
    //     if(i==0){
    //         if(target==0 && arr[0]==0) return 2;
    //         if(target==0 || target==arr[0]) return 1;
    //         return 0;
    //     }
    //     if(dp[i][target]!=-1) return dp[i][target];
    //     int notPick=cntDiff(i-1, target, arr, dp);
    //     int pick=0;
    //     if(arr[i]<=target) pick=cntDiff(i-1, target-arr[i], arr, dp);
    //     return dp[i][target]=pick+notPick;
    // }
    // int findTargetSumWays(vector<int>& nums, int d) {
    //     int n=nums.size();
    //     int sum=accumulate(nums.begin(), nums.end(), 0);
    //     int target=(sum-d)/2;
    //     if(sum-d<0 || (sum-d)%2!=0) return 0;
    //     vector<vector<int>> dp(n, vector<int> (target+1, -1));
    //     return cntDiff(n-1, target, nums, dp);
    // }

    // using tabulation
    int findTargetSumWays(vector<int>& nums, int d) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int target=(sum-d)/2;
        if(sum-d<0 || (sum-d)%2!=0) return 0;
        vector<vector<int>> dp(n, vector<int> (target+1, 0));
        if(nums[0]==0) dp[0][0]=2;
        else{
            dp[0][0]=1;
            if( nums[0]<=target) dp[0][nums[0]]=1;
        }
        for(int i=1; i<n;i++){
            for(int sum=0; sum<=target;sum++){
                int notPick=dp[i-1][sum];
                int pick=0;
                if(nums[i]<=sum) pick=dp[i-1][sum-nums[i]];
                dp[i][sum]= pick+notPick;
            }
        }
        return dp[n-1][target];
    }
};