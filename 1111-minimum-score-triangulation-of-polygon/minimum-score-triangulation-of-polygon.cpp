class Solution {
public:
    int f(int i, int j, vector<int>& values, vector<vector<int>>& dp){
        if(j-i<2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i+1; k<j; k++){
            mini=min(mini, f(i, k, values, dp)+ f(k, j, values, dp) +values[i]*values[j]*values[k]);
        }
        return dp[i][j]=mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return f(0, n-1, values, dp);
    }
    // int minScoreTriangulation(vector<int>& values) {
    //     int n=values.size();
    //     vector<vector<int>> dp(n, vector<int> (n, 0));
    //     for(int len=3; len<=n; len++){
    //         for(int i=0; i+len-1<n; i++){
    //             int j=i+len-1;
    //             int mini=INT_MAX;
    //             for(int k=i+1; k<j; k++){
    //                 mini=min(mini, dp[i][k]+dp[k][j]+values[i]*values[j]*values[k]);
    //             }
    //             dp[i][j]=mini;
    //         }
    //     }
    //     return dp[0][n-1];
    // }
};