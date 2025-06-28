class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<int>& dr, vector<int>& dc){
        grid[row][col]=0;
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1){
                dfs(nr, nc, grid, dr, dc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid, dr, dc);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid, dr, dc);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid, dr, dc);
            }
            if(grid[n-1][i]==1){
                dfs(n-1,i,grid, dr, dc);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};