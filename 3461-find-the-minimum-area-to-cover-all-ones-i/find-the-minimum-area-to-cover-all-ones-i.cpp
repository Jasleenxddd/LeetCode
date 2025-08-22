class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sl=INT_MAX;
        int sb=INT_MAX;
        int el=INT_MIN;
        int eb=INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    sl=min(sl, j+1);
                    sb=min(sb, i+1);
                    el=max(el, j+1);
                    eb=max(eb, i+1);
                }
            }
        }
        return (el-sl+1)*(eb-sb+1);
    }
};