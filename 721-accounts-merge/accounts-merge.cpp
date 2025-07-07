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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string, int> mpp;
        makeSets(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail= accounts[i][j];
                if(mpp.find(mail)== mpp.end()) mpp[mail]=i;
                else unionByRank(i, mpp[mail]);
            }
        }
        vector<vector<string>> merged(n);
        for(auto it: mpp){
            string mail=it.first;
            int node=findParent(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged[i].size()==0) continue;
            vector<string> temp;
            sort(merged[i].begin(), merged[i].end());
            temp.push_back(accounts[i][0]);
            for(auto& it: merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};