class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& path, vector<int>& safe){
        vis[node]=1;
        path[node]=1;
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it, graph, vis, path, safe)==true) return true;
            }
            else if(path[it]) return true;
        }
        safe[node]=1;
        path[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n);
        vector<int> path(n);
        vector<int> safe(n);
        vector<int> safeStates;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i, graph, vis, path, safe);
        }
        for(int i=0;i<n;i++){
            if(safe[i]==1) safeStates.push_back(i);
        }
        return safeStates;
    }
};