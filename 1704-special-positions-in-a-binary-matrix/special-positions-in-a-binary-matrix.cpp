class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        // queue<pair<int,int>> q;
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(mat[i][j]==1) q.push({i, j});
        //     }
        // }
        // int ans=0;
        // while(!q.empty()){
        //     int r=q.front().first;
        //     int c=q.front().second;
        //     q.pop();
        //     bool special=true;

        //     for(int i=0; i<m; i++){
        //         if(i!=r && mat[i][c]==1) special=false;
        //     }

        //     for(int j=0; j<n; j++){
        //         if(j!=c && mat[r][j]==1) special=false;
        //     }
        //     if(special) ans++;
        // }
        // return ans;

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1 && rows[i]==1 && cols[j]==1) ans++;
            }
        }
        return ans;
    }
};