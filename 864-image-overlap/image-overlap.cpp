class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        for(int row=-(n-1); row<n; row++){
            for(int col=-(n-1); col<n; col++){
                int cnt=0;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        int nr=i+row;
                        int nc=j+col;
                        if(nr>=0 && nr<n && nc>=0 && nc<n && img1[i][j]==1 && img2[nr][nc]==1){
                            cnt++;
                        }
                    }
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};