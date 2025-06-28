class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<int>& dr, vector<int>& dc, int& cnt){
        grid[row][col]='0';
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1'){
                dfs(nr, nc, grid, dr, dc, cnt);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i, j, grid, dr, dc, cnt);
                }
            }
        }
        return cnt;
    }
};