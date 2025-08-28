class Solution {
public:
    // using connected components
    // void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& vis){
    //     vis[i]=true;
    //     for(int j=0;j<isConnected.size();j++){
    //         if(isConnected[i][j]==1 && !vis[j]){
    //             dfs(j, isConnected, vis);
    //         }
    //     }
    // }

    // vector<bool> vis(n, false);
        // int prov=0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         dfs(i, isConnected, vis);
        //         prov++;
        //     }
        // }

    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[i]=1;
        for(int j=0; j<isConnected.size(); j++){
            if(vis[j]!=1 && isConnected[i][j]==1){
                dfs(j, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int prov=0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(vis[i]!=1){
                prov++;
                dfs(i, isConnected, vis);
            }
        }
        return prov;
    }


    // using dsu
    // vector<int> parent;
    // vector<int> rank;
    // void makeSet(int n){
    //     parent.resize(n+1);
    //     rank.resize(n+1,0);
    //     for(int i=0;i<n;i++){
    //         parent[i]=i;
    //     }
    // }
    // int findParent(int u){
    //     if(u== parent[u]) return parent[u];
    //     else return parent[u]=findParent(parent[u]);
    // }
    // void unionByRank(int u, int v){
    //     int p_u= findParent(u);
    //     int p_v=findParent(v);
    //     if(p_u!=p_v){
    //         if(rank[p_u]<rank[p_v]) parent[p_u]=p_v;
    //         else if(rank[p_u]>rank[p_v]) parent[p_v]=p_u;
    //         else{
    //             parent[p_v]=p_u;
    //             rank[p_u]++;
    //         }
    //     }
    // }
    // int cntP(int n){
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         if(parent[i]==i) cnt++;
    //     }
    //     return cnt;
    // }
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n=isConnected.size();
    //     int prov=0;
    //     makeSet(n);
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(isConnected[i][j]==1) unionByRank(i,j);
    //         }
    //     }
    //     return cntP(n);

        
        // return prov;
    
};