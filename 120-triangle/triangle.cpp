class Solution {
public:
    // using recursion
    // int tri(int i, int j, vector<vector<int>>& triangle, int n){
    //     if(i==n-1) return triangle[n-1][j];
    //     int down= triangle[i][j] + tri(i+1, j, triangle, n);
    //     int diag= triangle[i][j] + tri(i+1, j+1, triangle, n);
    //     return min(down, diag);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //     return tri(0,0, triangle, n);
    // }

    // using memoization
    // int tri(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
    //     if(i==n-1) return triangle[n-1][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int down= triangle[i][j] + tri(i+1, j, triangle, n, dp);
    //     int diag= triangle[i][j] + tri(i+1, j+1, triangle, n, dp);
    //     return dp[i][j]= min(down, diag);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //     vector<vector<int>> dp(n, vector<int> (n, -1));
    //     return tri(0,0, triangle, n, dp);
    // }

    // using tabulation
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //     vector<vector<int>> dp(n, vector<int> (n, -1));
    //     for(int j=0;j<n;j++){
    //         dp[n-1][j]=triangle[n-1][j];
    //     }
    //     for(int i=n-2;i>=0;i--){
    //         for(int j=0;j<=i;j++){
    //             int down= triangle[i][j] + dp[i+1][j];
    //             int diag= triangle[i][j] + dp[i+1][j+1];
    //             dp[i][j]=min(down, diag);
    //         }
    //     }
    //     return dp[0][0];
    // }

    // using space optimization
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> last(n, 0);
        vector<int> curr(n, 0);
        for(int j=0;j<n;j++){
            last[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down= triangle[i][j] + last[j];
                int diag= triangle[i][j] + last[j+1];
                curr[j]=min(down, diag);
            }
            last=curr;
        }
        return last[0];
    }
};