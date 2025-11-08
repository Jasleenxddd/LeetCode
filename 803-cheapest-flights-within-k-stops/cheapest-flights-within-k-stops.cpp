class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto f: flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        // stops, {node, dis}
        queue<pair<int , pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dis(n, INT_MAX);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dist=it.second.second;
            if(stops>k) continue;
            for(auto i: adj[node]){
                int wt=i.second;
                int adjN=i.first;
                if(dist+wt< dis[adjN] ){
                    dis[adjN]=dist+wt;
                    q.push({stops+1, {adjN, dist+wt}});
                }
            }
        }
        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
    }
};