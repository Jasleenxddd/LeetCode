class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(auto &it: guards) grid[it[0]][it[1]]=1;
        for(auto &i: walls) grid[i[0]][i[1]]=2;
        vector<pair<int, int>> dir={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for(auto &x: guards){
            int r=x[0], c=x[1];
            for(auto &d: dir){
                int nr=r+d.first;
                int nc=c+d.second;
                while(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]!=1 && grid[nr][nc]!=2){
                    if(grid[nr][nc]==0) grid[nr][nc]=3;
                    nr+=d.first;
                    nc+=d.second;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};