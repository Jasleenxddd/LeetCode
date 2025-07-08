class DisjointSet {
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // Initially, each element is its own parent
        }
    }

    int findParent(int u) {
        if (parent[u] == u) {
            return parent[u];
        }
        return parent[u] = findParent(parent[u]); // Path compression
    }
    

    void unionByRank(int u, int v) {
        int upl_u = findParent(u);
        int ulp_v = findParent(v);

        if (upl_u != ulp_v) {
            if (rank[upl_u] < rank[ulp_v]) {
                parent[upl_u] = ulp_v;
            } else if (rank[upl_u] > rank[ulp_v]) {
                parent[ulp_v] = upl_u;
            } else {
                parent[ulp_v] = upl_u;
                rank[upl_u]++;
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxR=0;
        int maxC=0;
        for(auto it: stones){
            maxR=max(maxR, it[0]);
            maxC=max(maxC, it[1]);
        }
        DisjointSet ds(maxR+maxC+1);
        unordered_map<int,int> mpp;
        for(auto it: stones){
            int r=it[0];
            int c=it[1] + maxR+1;
            ds.unionByRank(r,c);
            mpp[r]=1;
            mpp[c]=1;
        }
        int cnt=0;
        for(auto it: mpp){
            if(ds.findParent(it.first)==it.first) cnt++;
        }
        return stones.size()-cnt;
    }
};