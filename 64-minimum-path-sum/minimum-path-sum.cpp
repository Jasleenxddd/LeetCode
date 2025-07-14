class Solution {
public:
    // using recursion
    // int sum(int i, int j, vector<vector<int>>& grid){
    //     if(i==0 && j==0) return grid[i][j];
    //     if(i<0 || j<0) return INT_MAX;
    //     int up=(i>0)? grid[i][j]+ sum(i-1, j, grid): INT_MAX;
    //     int left=(j>0)? grid[i][j]+ sum(i, j-1, grid):INT_MAX;
    //     return min(up, left);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     return sum(n-1, m-1, grid);
    // }

    // using memoization
    // int sum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(i==0 && j==0) return grid[i][j];
    //     if(i<0 || j<0) return INT_MAX;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up=(i>0)? grid[i][j]+ sum(i-1, j, grid, dp): INT_MAX;
    //     int left=(j>0)? grid[i][j]+ sum(i, j-1, grid, dp):INT_MAX;
    //     return dp[i][j]=min(up, left);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<int>> dp(n, vector<int> (m,-1));
    //     return sum(n-1, m-1, grid, dp);
    // }

    // using tabulation
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<int>> dp(n, vector<int> (m,0));
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(i==0 && j==0) dp[i][j]=grid[i][j];
    //             else{
    //                 int up=(i>0)? grid[i][j]+ dp[i-1][j]: INT_MAX;
    //                 int left=(j>0)? grid[i][j]+ dp[i][j-1]:INT_MAX;
    //                 dp[i][j]=min(up, left);
    //             }
    //         }
    //     }
    //     return dp[n-1][m-1];
    // }

    // using space optimization
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> tmp(m,0);
        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0) curr[j]=grid[i][j];
                else{
                    int up=(i>0)? grid[i][j]+ tmp[j]: INT_MAX;
                    int left=(j>0)? grid[i][j]+ curr[j-1]:INT_MAX;
                    curr[j]=min(up, left);
                }
            }
            tmp=curr;
        }
        return tmp[m-1];
    }
};