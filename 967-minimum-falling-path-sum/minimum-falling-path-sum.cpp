class Solution {
public:
    // int sum(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    //     if(j<0 || j>=matrix[0].size()) return 1e9;
    //     if(i==0) return matrix[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int u= matrix[i][j] + sum(i-1, j, matrix, dp);
    //     int ld= matrix[i][j] + sum(i-1, j-1, matrix, dp);
    //     int rd= matrix[i][j] + sum(i-1, j+1, matrix, dp);
    //     return dp[i][j]=min({u, ld, rd});
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     if(matrix.empty()|| matrix[0].empty()) return 0;
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     vector<vector<int>> dp(n, vector<int> (m, -1));
    //     int mini=INT_MAX;
    //     for(int j=0;j<m;j++){
    //         mini= min(mini, sum(n-1, j, matrix, dp));
    //     }
    //     return mini;
    // }

    // using tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int u= dp[i-1][j];
                int ld= (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int rd= (j < m - 1) ? dp[i - 1][j + 1] : INT_MAX;
                dp[i][j]=matrix[i][j]+min(u, min(ld, rd));
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini, dp[n-1][i]);
        }
        return mini;
    }
};