class Solution {
public:
    int tar(int i, int sum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset){
        if(i==nums.size()){
            if(sum==target) return 1;
            else return 0;
        }
        if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];
        int add=tar(i+1, sum+nums[i], nums, target, dp, offset);
        int sub=tar(i+1, sum-nums[i], nums, target, dp, offset);
        return dp[i][sum+ offset]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int offset=1000;
        vector<vector<int>> dp(n, vector<int> (2*offset+1, -1));
        return tar(0, 0, nums, target, dp, offset);
    }
};