class Solution {
public:
    // using memoization
    // bool target(int i, int tar, vector<int>& arr, vector<vector<int>>& dp){
    //     if(tar==0) return true;
    //     if(i==0) return arr[i]==tar;
    //     if(dp[i][tar]!=-1) return dp[i][tar];
    //     bool notTake= target(i-1, tar, arr, dp);
    //     bool take=false;
    //     if(tar>= arr[i]) take=target(i-1, tar- arr[i], arr, dp);
    //     return dp[i][tar]= take || notTake;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int n=nums.size();
    //     int sum=0;
    //     for(int i=0;i<n;i++){
    //         sum+=nums[i];
    //     }
    //     if(sum%2!=0) return false;
    //     int tar=sum/2;
    //     vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    //     return target(n-1, tar, nums, dp);
    // }

    // using tabulation
    // bool canPartition(vector<int>& nums) {
    //     int n=nums.size();
    //     int sum=0;
    //     for(int i=0;i<n;i++){
    //         sum+=nums[i];
    //     }
    //     if(sum%2!=0) return false;
    //     int tar=sum/2;
    //     vector<vector<int>> dp(n, vector<int> (tar+1, 0));
    //     for(int i=0;i<n;i++){
    //         dp[i][0]=true;
    //     }
    //     if(nums[0]<=tar) dp[0][nums[0]]=true;
    //     for(int i=1;i<n;i++){
    //         for(int j=1;j<=tar;j++){
    //             bool notTake= dp[i-1][j];
    //             bool take=false;
    //             if(j>= nums[i]) take=dp[i-1][j-nums[i]];
    //             dp[i][j]= take || notTake;
    //         }
    //     }
    //     return dp[n-1][tar];
    // }

    // using space optimization
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int tar=sum/2;
        vector<int> prev(tar+1, 0);
        vector<int> curr(tar+1, 0);
        prev[0]=true;
        curr[0]=true;
        if(nums[0]<=tar) prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=tar;j++){
                bool notTake= prev[j];
                bool take=false;
                if(j>= nums[i]) take=prev[j-nums[i]];
                curr[j]= take || notTake;
            }
            prev=curr;
        }
        return prev[tar];
    }
};