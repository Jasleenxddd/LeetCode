class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1, 0);
        const int MOD=1e9+7;
        dp[1]=1;
        for(int i=1; i<=n; i++){
            for(int d=i+delay; d<i+forget && d<=n; d++){
                dp[d]=(dp[d]+dp[i])%MOD;
            }
        }
        long long ans=0;
        for(int i=n-forget+1; i<=n; i++){
            if(i>0) ans=(ans+dp[i])%MOD;
        }
        return ans;
    }
};