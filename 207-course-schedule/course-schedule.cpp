class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int> indegree(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int fro=q.front();
            q.pop();
            topo.push_back(fro);
            for(auto i: adj[fro]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(topo.size()==numCourses) return true;
        return false;
    }
};