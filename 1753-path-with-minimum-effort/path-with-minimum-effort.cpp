class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dis(n, vector<int>(m,INT_MAX));
        pq.push({0,0,0});
        dis[0][0]=0;
        while(!pq.empty()){
            auto [effort, row, col]= pq.top();
            pq.pop();
            if(row==n-1 && col==m-1) return effort;
            for(auto [dr, dc]: dir){
                int newR=row+dr;
                int newC=col+dc;
                if(newR>=0 && newR<n && newC>=0 && newC<m ){
                    int nextEffort=max(effort,abs(heights[newR][newC]-heights[row][col]));
                    if(nextEffort< dis[newR][newC]){
                        dis[newR][newC]=nextEffort;
                        pq.push({ dis[newR][newC], newR, newC});
                    }
                }
            }
        }
        return 0;
    }
};