class Solution {
public:
    // using memoization
    // int f(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
    //     if(amount==0) return 1;
    //     if(i==0){
    //         if(amount%coins[0]==0) return 1;
    //         else return 0;
    //     }
    //     if(dp[i][amount]!=-1) return dp[i][amount];
    //     int notPick=f(i-1, amount, coins, dp);
    //     int pick=0;
    //     if(coins[i]<=amount) pick=f(i, amount-coins[i], coins, dp);
    //     return dp[i][amount]=pick+notPick;
    // }
    // int change(int amount, vector<int>& coins) {
    //     int n=coins.size();
    //     vector<vector<int>> dp(n, vector<int> (amount+1, -1));
    //     return f(n-1, amount, coins, dp);
    // }

    // using tabulation
    // not working properly
    // int change(int amount, vector<int>& coins) {
    //     const int MOD=1e9+7;
    //     int n=coins.size();
    //     vector<vector<long long>> dp(n, vector<long long> (amount+1, 0));
    //     for(int t=0; t<=amount; t++){
    //         if(t%coins[0]==0) dp[0][t]=1;
    //     }
    //     for(int i=1; i<n; i++){
    //         for(int t=0; t<=amount; t++){
    //             long long notPick=dp[i-1][t];
    //             long long pick=0;
    //             if(coins[i]<=t) pick=dp[i][t-coins[i]];
    //             dp[i][t]=(pick+notPick)%MOD;
    //         }
    //     }
    //     return (int)dp[n-1][amount];
    // }

    int change(int amount, vector<int>& coins) {
        const int MOD=1e9+7;
        int n=coins.size();
        vector<long long> prev(amount+1, 0);
        for(int t=0; t<=amount; t++){
            if(t%coins[0]==0) prev[t]=1;
        }
        for(int i=1; i<n; i++){
            vector<long long> curr(amount+1, 0);
            for(int t=0; t<=amount; t++){
                long long notPick=prev[t];
                long long pick=0;
                if(coins[i]<=t) pick=curr[t-coins[i]];
                curr[t]=pick+notPick;
                // to prevent overflow condition
                if(curr[t]> INT_MAX) curr[t]= INT_MAX; 
            }
            prev=curr;
        }
        return (int)prev[amount];
    }
};