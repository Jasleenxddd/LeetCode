class DisjointSet {
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1); // Initially, each set has size 1
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // Each node is its own parent
        }
    }

    int findParent(int u) {
        if (parent[u] == u) {
            return parent[u];
        }
        return parent[u] = findParent(parent[u]); // Path compression
    }

    void unionBySize(int u, int v) {
        int upl_u = findParent(u);
        int ulp_v = findParent(v);

        if (upl_u != ulp_v) {
            if (size[upl_u] < size[ulp_v]) {
                parent[upl_u] = ulp_v;
                size[ulp_v] += size[upl_u]; // Increase size of new root
            } else {
                parent[ulp_v] = upl_u;
                size[upl_u] += size[ulp_v]; // Increase size of new root
            }
        }
    }
    int getSize(int u){
        return size[findParent(u)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n, vector<int> (n,0));
        int k=1;
        DisjointSet ds(n*n);
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                vector<int> dr={-1,0,1,0};
                vector<int> dc={0,1,0,-1};
                if(grid[r][c]==1){
                    for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int nodeNo= r*n + c;
                        int nrNo= nr*n + nc;
                        ds.unionBySize(nodeNo, nrNo);
                    }
                    }
                }
            }
        }
        int cnt=0;
        bool isZero=false;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){

                if(grid[r][c]==0){
                    isZero=true;
                    unordered_set<int> st;
                    vector<int> dr={-1,0,1,0};
                    vector<int> dc={0,1,0,-1};
                    for(int i=0;i<4;i++){
                        int nr=r+dr[i];
                        int nc=c+dc[i];
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            int nodeNo= r*n + c;
                            int nrNo= nr*n + nc;
                            st.insert(ds.findParent( nrNo));
                        }
                    }
                    int total=1;
                    for(auto it: st){
                        total+=ds.getSize(it);
                    }
                    cnt=max(cnt,total);
            }
        }
        }
        if(!isZero) return (n*n);
        return cnt;
    }
};