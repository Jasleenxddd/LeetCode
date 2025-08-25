class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;

        // using map
        // unordered_map<int, vector<int>> mpp;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m ;j++){
        //         mpp[i+j].push_back(mat[i][j]);
        //     }
        // }
        // for(int d=0;d<m+n-1;d++){
        //     if(d%2==0) reverse(mpp[d].begin(), mpp[d].end());
        //     for(int it: mpp[d]) ans.push_back(it);
        // }

        if(mat.empty()) return {};

        // for pre allocate memory
        ans.reserve(n*m);

        int i=0;
        int r=0;
        int c=0;
        bool up=true;
        while(ans.size()<n*m){
            ans.push_back(mat[r][c]);
            if(up){
                // right boundary while moving upwards
                if(c==m-1){
                    r++;
                    up=false;
                }
                // up boundary
                else if(r==0){
                    c++;
                    up=false;
                }
                else{
                    r--;
                    c++;
                }
            }
            else{
                // leftmost
                if(r==n-1){
                    c++;
                    up=true;
                }
                else if(c==0){
                    r++;
                    up=true;
                }
                else{
                    r++;
                    c--;
                }
            }
        }
        return ans;
    }
};