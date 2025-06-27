class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else mat[i][j]=-1;
            }
        }
        vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto [r, c]=q.front();
            q.pop();
            for(auto [dr,dc]: dir){
                int nr=r+dr;
                int nc=c+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==-1){
                    mat[nr][nc]=mat[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return mat;
    }
};  