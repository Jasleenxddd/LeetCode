class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD=1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        priority_queue<pair<long long,int>, vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        for(auto& road: roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});

        }
        vector<long long> dis(n, LLONG_MAX);
        vector<int> ways(n,0);
        pq.push({0,0});
        dis[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto [time,  node]= pq.top();
            pq.pop();
            for(auto& [adjNode, t]: adj[node]){
                long long newTime=time+t;
                if(newTime<dis[adjNode]){
                    dis[adjNode]=newTime;
                    ways[adjNode]=ways[node];
                    pq.push({newTime, adjNode});
                }
                else if(newTime==dis[adjNode]) ways[adjNode]=(ways[adjNode]+ways[node])% MOD;
            }
        }
        return ways[n-1];
    }
};