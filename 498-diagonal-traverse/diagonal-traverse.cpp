class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;
        unordered_map<int, vector<int>> mpp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m ;j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }
        for(int d=0;d<m+n-1;d++){
            if(d%2==0) reverse(mpp[d].begin(), mpp[d].end());
            for(int it: mpp[d]) ans.push_back(it);
        }
        return ans;
    }
};