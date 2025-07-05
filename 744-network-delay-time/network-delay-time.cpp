class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& time: times){
            int u=time[0];
            int v=time[1];
            int t=time[2];
            adj[u].push_back({v,t});
        }
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        // node and time
        pq.push({k,0});
        while(!pq.empty()){
            auto [node, time]= pq.top();
            pq.pop();
            for(auto& [adjNode, t] : adj[node]){
                if(time+t<dis[adjNode]){
                    dis[adjNode]=time+t;
                    pq.push({adjNode, dis[adjNode]});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            ans=max(ans, dis[i]);
        }
        return ans;
    }
};