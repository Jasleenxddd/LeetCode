class Solution {
public:
    // int rob(int m, int n){
    //     if(m==0 && n==0) return 1;
    //     if(m<0 || n<0) return 0;
    //     int left=rob(m, n-1);
    //     int up=rob(m-1,n);
    //     return left+up;
    // }

    // using memoization
    // int rob(int m, int n, vector<vector<int>>& dp){
    //     if(m==0 && n==0) return 1;
    //     if(m<0 || n<0) return 0;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     int left=rob(m, n-1, dp);
    //     int up=rob(m-1,n, dp);
    //     return dp[m][n]=left+up;
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int> (n,-1));
    //     return rob(m-1,n-1, dp);
    // }

    // using tabulation
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int> (n,0));
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==0 && j==0) dp[i][j]=1;
    //             else{
    //                 int up=(i>0)? dp[i-1][j]: 0;
    //                 int left=(j>0)? dp[i][j-1]: 0;
    //                 dp[i][j]=up+left;
    //             } 
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    // using space optimization
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i=1;i<m;i++){
            vector<int> tmp(n, 1);
            for(int j=1;j<n;j++){
                tmp[j]=dp[j]+tmp[j-1];
            }
            dp=tmp;
        }
        return dp[n-1];
    }
};