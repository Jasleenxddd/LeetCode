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
    int sum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=(i>0)? grid[i][j]+ sum(i-1, j, grid, dp): INT_MAX;
        int left=(j>0)? grid[i][j]+ sum(i, j-1, grid, dp):INT_MAX;
        return dp[i][j]=min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return sum(n-1, m-1, grid, dp);
    }
};