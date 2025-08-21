class Solution {
public:
    int f(vector<int>& v){
        int cnt=0;
        int sum=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]==0) cnt=0;
            else{
                cnt++;
                sum+=cnt;
            }
        }
        return sum;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            vector<int> v(m, 1);
            for(int j=i; j<n;  j++){
                for(int k=0; k<m; k++){
                    v[k]=v[k]& mat[j][k];
                }
                ans+=f(v);
            }
        }
        return ans;
    }
};