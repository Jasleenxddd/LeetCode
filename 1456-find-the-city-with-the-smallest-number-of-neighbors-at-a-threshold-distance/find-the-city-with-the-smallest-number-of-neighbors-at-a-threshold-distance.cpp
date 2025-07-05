class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int> (n,INT_MAX));
        for(auto edge: edges){
            dis[edge[0]][edge[1]]=edge[2];
            dis[edge[1]][edge[0]]=edge[2];
        }
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX){
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    }
                }
            }
        }
        int cntMax=n;
        int city=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dis[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<=cntMax){
                cntMax=cnt;
                city=i;
            }
        }
        return city;
    }
};