class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // int n=image.size();
        // int m=image[0].size();
        // queue<pair<int,int>> q;
        // int prev=image[sr][sc];
        // if(prev==color) return image;
        // q.push({sr,sc});
        // image[sr][sc]=color;
        // vector<pair<int,int>> dir={{-1,0},{0,1},{0,-1},{1,0}};

        // while(!q.empty()){
        //     auto [r,c]= q.front();
        //     q.pop();
        //     for(auto [dr,dc]:dir){
        //         int nr=r+dr;
        //         int nc=c+dc;
        //         if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==prev){
        //             image[nr][nc]=color;
        //             q.push({nr,nc});
        //         }
        //     }
            
        // }
        // return image;

        int n=image.size();
        int m=image[0].size();
        queue<pair<int, int>> q;
        int prev=image[sr][sc];
        if(prev==color) return image;
        q.push({sr, sc});
        image[sr][sc]=color;
        vector<pair<int, int>> dir={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while(!q.empty()){
            auto [r, c]=q.front();
            q.pop();
            for(auto [dr, dc]: dir){
                int nr=r+dr;
                int nc=c+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==prev){
                    image[nr][nc]=color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};