class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    void makeSets(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(u== parent[u]) return parent[u];
        else return parent[u]=findParent(parent[u]);
    }
    void unionByRank(int u, int v){
        int p_u= findParent(u);
        int p_v=findParent(v);
        if(p_u!=p_v){
            if(rank[p_u]<rank[p_v]) parent[p_u]=p_v;
            else if(rank[p_u]>rank[p_v]) parent[p_v]=p_u;
            else{
                parent[p_v]=p_u;
                rank[p_u]++;
            }
        }
    }
    int cntParents(int n){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) cnt++;
        }
        return cnt;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        makeSets(n);
        int cnt=0;
        if(connections.size()<n-1) return -1;
        for(auto& it: connections){
            int u=it[0];
            int v=it[1];
            unionByRank(u,v);
        }
        int comp=cntParents(n);
        return comp-1;
    }
};