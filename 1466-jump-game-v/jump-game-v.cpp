class Solution {
public:
    int n, jump;
    vector<int> nums;
    vector<int> dp;
    int dfs(int i){
        if(dp[i]!=-1) return dp[i];
        int res=1;

        // left i-x
        for(int x=1; x<=jump && i-x>=0; x++){
            if(nums[i-x]>= nums[i]) break;
            res=max(res, 1+ dfs(i-x));
        }

        // right i+x
        for(int x=1; x<=jump && i+x<n; x++){
            if(nums[i+x]>= nums[i]) break;
            res=max(res, 1+ dfs(i+x));
        }
        return dp[i]=res;

    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        jump=d;
        nums=arr;
        dp=vector<int>(n, -1);
        // or dp.assign(n, -1);

        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans, dfs(i));
        }
        return ans;
    }
};