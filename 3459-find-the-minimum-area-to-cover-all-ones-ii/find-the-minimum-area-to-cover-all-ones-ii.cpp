class Solution {
public:
    int f(int sr, int er, int sc, int ec, vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sl=INT_MAX;
        int sb=INT_MAX;
        int el=INT_MIN;
        int eb=INT_MIN;
        for(int i=sr; i<er; i++){
            for(int j=sc; j<ec; j++){
                if(grid[i][j]==1){
                    sl=min(sl, j+1);
                    sb=min(sb, i+1);
                    el=max(el, j+1);
                    eb=max(eb, i+1);
                }
            }
        }
        if(sl==INT_MAX) return INT_MAX;
        return (el-sl+1)*(eb-sb+1);
    }
    int minAr(vector<vector<int>>& grid){
        // use 2 lines to splot rect into 3 rects

        // we have 3 cases 
        // in case 1 we have top, bottomLeft, and bottomRight
        // in case 2 we have topLeft, topRight, and bottom
        // in case 3 we have rowsplits only

        // in total we have 6 case and if we rotate the 3 case we get the other 3 cases also

        // case 1 and case 2-> for loop
        // case 3-> for loop
        // rotation of grid(clockwise)
        // repeat step 1 and step 2
        int n=grid.size();
        int m=grid[0].size();
        int res=INT_MAX;
        // case 1
        // rowsplit and colsplit
        for(int i=1; i<n; i++){  
            for(int j=1; j<m; j++){
                int top=f(0, i, 0, m, grid);
                int bottomLeft=f(i, n, 0, j, grid);
                int bottomRight=f(i, n, j, m, grid);

                if (top != INT_MAX && bottomLeft != INT_MAX && bottomRight != INT_MAX) res = min(res, top + bottomLeft + bottomRight);
                
                // case 2
                // rowsplit and colsplit
                int topLeft=f(0, i, 0, j, grid);
                int topRight=f(0, i, j, m, grid);
                int bottom=f(i, n, 0, m, grid);
                if (topLeft != INT_MAX && topRight != INT_MAX && bottom != INT_MAX) res = min(res, topLeft + topRight + bottom);

            }
        }

        // case 3
        // horizontal
        // rowsplit1 and rowsplit2
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                int top=f(0, i, 0, m, grid);
                int middle=f(i, j, 0, m, grid);
                int bottom=f(j, n, 0, m, grid);
                if(top== INT_MAX || middle== INT_MAX || bottom== INT_MAX) continue;
                res=min(res, top+middle+bottom);
            }
        }
        return res;
    }
    vector<vector<int>> rotation(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> rota(m, vector<int> (n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rota[j][n-i-1]=grid[i][j];
            }
        }
        return rota;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int res=minAr(grid);
        vector<vector<int>> rot=rotation(grid);
        res=min(res, minAr(rot));
        return res;
    }
};