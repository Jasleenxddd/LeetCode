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
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     int maxi=0;
    //     vector<int> dp(n, 1);
    //     for(int i=0; i<n; i++){
    //         for(int prev=0; prev<i; prev++){
    //             if( nums[i]> nums[prev]) dp[i]=max(dp[i], 1+dp[prev]);
    //         }
    //        maxi=max(maxi, dp[i]);
    //     }
    //     return maxi;
    // }

    // printing the array
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     int maxi=0;
    //     int lastI=0;
    //     vector<int> dp(n, 1), hash(n);
    //     for(int i=0; i<n; i++){
    //         hash[i]=i;
    //         for(int prev=0; prev<i; prev++){
    //             if( nums[i]> nums[prev] && 1+dp[prev]>dp[i]){
    //                 dp[i]=1+dp[prev];
    //                 hash[i]=prev;
    //             }
    //         }
    //         if(dp[i]>maxi){
    //             maxi=dp[i];
    //             lastI=i;
    //         }
    //     }
    //     vector<int> tmp;
    //     tmp.push_back(nums[lastI]);
    //     while(hash[lastI]!=lastI){
    //         lastI=hash[lastI];
    //         tmp.push_back(nums[lastI]);
    //     }
    //     reverse(tmp.begin(), tmp.end());
    //     for(auto it: tmp){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    //     return maxi;
    // }

    // using binary search
    int lengthOfLIS(vector<int>& nums){
        vector<int> tmp;
        if(nums.empty()) return 0;
        tmp.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i]> tmp.back()) tmp.push_back(nums[i]);
            else{
                auto it=lower_bound(tmp.begin(), tmp.end(), nums[i]);
                *it=nums[i];
            }
        }
        return tmp.size();
    }

};