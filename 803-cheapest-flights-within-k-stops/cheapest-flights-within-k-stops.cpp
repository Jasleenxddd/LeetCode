class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(auto& flight:flights){
            int u=flight[0];
            int v=flight[1];
            int cost=flight[2];
            adj[u].push_back({v, cost});
        }
        pq.push({0,src,0});
        vector<vector<int>> dis(n, vector<int>(k+2,INT_MAX));
        dis[src][0]=0;
        while(!pq.empty()){
            auto [cost, city, stop]= pq.top();
            pq.pop();
            if(city==dst) return cost;
            if(stop>k) continue;
            for(auto& [adjNode, price]: adj[city]){
                if(cost+price< dis[adjNode][stop+1]){
                    dis[adjNode][stop+1]=cost+price;
                    pq.push({cost+price, adjNode, stop+1});
                }
            }
        }
        return -1;
    }
};