class Solution {
public:
    // recursive
    // 
    
    // using memoization
    int func(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        if(obstacleGrid[m][n]==1) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=func(m-1, n, obstacleGrid, dp);
        int left=func(m, n-1, obstacleGrid, dp);
        return dp[m][n]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        return func(m-1,n-1,obstacleGrid, dp);

    // using tabulation
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m=obstacleGrid.size();
    //     int n=obstacleGrid[0].size();
    //     vector<vector<int>> dp(m, vector<int> (n,0));
    //     if(obstacleGrid[0][0]==1) return 0;
    //     dp[0][0]=1;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(obstacleGrid[i][j]==1) dp[i][j]=0;
    //             else{
    //                 if(i==0 && j==0) continue;
    //                 int up=(i>0)? dp[i-1][j]: 0; 
    //                 int left=(j>0)? dp[i][j-1]:0;
    //                 dp[i][j]=up+left;
    //             }

    //         }
    //     }
    //     return dp[m-1][n-1];
    }
};