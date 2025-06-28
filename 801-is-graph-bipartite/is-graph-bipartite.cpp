class Solution {
public:
    // bool bfs(int node, vector<vector<int>>& graph, vector<int>& col){
    //     queue<int> q;
    //     q.push(node);
    //     col[node]=0;
    //     while(!q.empty()){
    //         int i=q.front();
    //         q.pop();
    //         for(auto it: graph[i]){
    //             if(col[it]==-1){
    //                 col[it]=!col[i];
    //                 q.push(it);
    //             }
    //             else if(col[it]==col[i]) return false;
    //         }
    //     }
    //     return true;
    // }
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& col){
        for( auto it: graph[node]){
            if(col[it]==-1){
                col[it]=!col[node];
                if(!dfs(it, graph, col)) return false;
            }
            else if(col[it]==col[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                col[i] = 0;
                // if(bfs(i, graph, col)==false){
                if(dfs(i,graph, col)==false){
                    return false;
                }
            }
        }
        return true;
    }
};