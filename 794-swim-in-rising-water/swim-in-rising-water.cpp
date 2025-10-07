class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n, vector<int> (n,0));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0]=1;
        while(!pq.empty()){
            auto [el, r, c]= pq.top();
            pq.pop();
            if(r==n-1 && c==n-1) return el;
            vector<int> dr={-1,0,1,0};
            vector<int> dc={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    pq.push({max(el, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};