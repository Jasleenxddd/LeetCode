class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int time=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2) q.push({{i, j}, 0});
            }
        }
        int dr[4]={0, -1, 0, 1};
        int dc[4]={-1, 0, 1, 0};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time, t);
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m &&  grid[nr][nc]==1){
                    q.push({{nr, nc}, t+1});
                    grid[nr][nc]=2;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 ) return -1;
            }
        }
        return time;





















        // int n=grid.size();
        // int m=grid[0].size();
        // queue<pair<pair<int,int>, int>> q;
        // int vis[n][m];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==2){
        //             q.push({{i,j},0});
        //             vis[i][j]=1;
        //         }
        //         else{
        //             vis[i][j]=0;
        //         }
        //     }
        // }
        // int time=0;
        // int dr[4]={-1,0,1,0};
        // int dc[4]={0,1,0,-1};
        // while(!q.empty()){
        //     int r=q.front().first.first;
        //     int c=q.front().first.second;
        //     int t=q.front().second;
        //     time=max(time,t);
        //     q.pop();
        //     for(int i=0;i<4;i++){
        //         int nr=r+dr[i];
        //         int nc=c+dc[i];
        //         if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
        //             q.push({{nr,nc},t+1});
        //             vis[nr][nc]=2;
        //         }
        //     }
            
        // }
        // for(int i=0;i<n;i++){
        //         for(int j=0;j<m;j++){
        //             if(vis[i][j]!=2 && grid[i][j]==1){
        //                 return -1;
        //             }
        //         }
        // }
        // return time;
    }
};