class Solution {
public:
    // using memoization
    // int f(int i, vector<int>& arr, int k, vector<int>& dp){
    //     if(i== arr.size()) return 0;
    //     int len=0;
    //     int maxi=INT_MIN;
    //     int ans=INT_MIN;
    //     if(dp[i]!=-1) return dp[i];
    //     for(int j=i; j<min(i+k, (int)arr.size()); j++){
    //         len++;
    //         maxi=max(maxi, arr[j]);
    //         int sum= len*maxi + f(j+1, arr, k, dp);
    //         ans=max(ans, sum);
    //     }
    //     return dp[i]=ans;
    // }
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     int n=arr.size();
    //     vector<int> dp(n, -1);
    //     return f(0, arr, k, dp);
    // }

    // using tabulation
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int len=0;
            int maxi=INT_MIN;
            int ans=0;
            for(int j=i; j<min(i+k, (int)arr.size()); j++){
                len++;
                maxi=max(maxi, arr[j]);
                int sum= len*maxi + dp[j+1];
                ans=max(ans, sum);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};