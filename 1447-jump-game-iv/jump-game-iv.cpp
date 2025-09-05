class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        unordered_map<int, vector<int>> g;
        for(int i=0; i<n; i++){
            g[arr[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        vector<bool> vis(n, false);
        q.push({0, 0});
        vis[0]=true;
        while(!q.empty()){
            auto [i, steps]= q.front();
            q.pop();
            if(i==n-1) return steps;

            // i-1;
            if(i-1>=0 && !vis[i-1]){
                vis[i-1]=true;
                q.push({i-1, steps+1});
            }
            // i+1
            if(i+1<n && !vis[i+1]){
                vis[i+1]=true;
                q.push({i+1, steps+1});
            }
            // equal
            for(auto it: g[arr[i]]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push({it, steps+1});
                }
            }
            g[arr[i]].clear();
        }
        return -1;
    }
};