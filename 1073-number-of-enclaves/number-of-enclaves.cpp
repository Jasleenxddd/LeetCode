class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<int>& dr, vector<int>& dc){
        grid[i][j]=0;
        for(int d=0; d<4; d++){
            int nr=i+dr[d];
            int nc=j+dc[d];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1) dfs(nr, nc, grid, dr, dc);
        }
    }    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dr={-1, 0, 1, 0};
        vector<int> dc={0, 1, 0, -1};
        for(int i=0; i<n; i++){
            if(grid[i][0]==1) dfs(i, 0, grid, dr, dc);
            if(grid[i][m-1]==1) dfs(i, m-1, grid, dr, dc);
        }
        for(int j=0; j<m; j++){
            if(grid[0][j]==1) dfs(0, j, grid, dr, dc);
            if(grid[n-1][j]==1) dfs(n-1, j, grid, dr, dc);
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};