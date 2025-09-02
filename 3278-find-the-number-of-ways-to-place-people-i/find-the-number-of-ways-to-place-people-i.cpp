class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
        }
    };
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int cnt=0;
        sort(points.begin(), points.end(), cmp());
        for(int a=0; a<n; a++){
            int prev=INT_MIN;
            for(int b=a+1; b<n; b++){
                if(points[a][1]>=points[b][1]){
                    if( points[b][1]>prev){
                        cnt++;
                        prev=points[b][1];
                    }
                }
                
            }
        }
        return cnt;
    }
};
