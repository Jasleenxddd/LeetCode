class Solution {
public:
    // int f(int i, vector<int>& nums, vector<int>& dp){
    //     int n=nums.size();
    //     int cnt=0;
    //     if(i>=n-2) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     // nums[i]->....
    //     for(int j=i+1; j<n; j++){
    //         for(int k=j+1; k<n; k++){
    //             if(nums[i]+nums[j]>nums[k] && nums[i]+nums[k]>nums[j] && nums[k]+nums[j]>nums[j]) cnt++;
    //         }
    //     }
    //     cnt+=f(i+1, nums, dp);
    //     return dp[i]=cnt;
    // }
    // int triangleNumber(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     vector<int> dp(nums.size(), -1);
    //     return f(0, nums, dp);
    // }

    // using two pointer
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt=0;
        int n=nums.size();
        for(int k=n-1; k>=2; k--){
            int i=0, j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    cnt+=(j-i);
                    j--;
                }
                else i++;
            }
        }
        return cnt;
    }
};