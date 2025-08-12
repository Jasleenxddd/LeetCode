class Solution {
public:
    // usig memoization
    // int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
    //     if(i==prices.size()) return 0;
    //     int profit=0;
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     if(buy) profit=max(-prices[i]+f(i+1, 0, prices, dp), 0+f(i+1, 1, prices, dp));
    //     else profit=max(prices[i]+ f(i+1, 1, prices, dp), f(i+1, 0, prices, dp));
    //     return dp[i][buy]= profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>> dp(n, vector<int> (2, -1));
    //     return f(0, 1, prices, dp);
    // }

    // using tabulation
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>> dp(n+1, vector<int> (2, 0));
    //     dp[n][0]=dp[n][1]=0;
    //     for(int i=n-1; i>=0; i--){
    //         for(int buy=0; buy<=1; buy++){
    //             if(buy) dp[i][buy]=max(-prices[i]+ dp[i+1][0], 0+ dp[i+1][1]);
    //             else dp[i][buy]=max(prices[i]+ dp[i+1][1], dp[i+1][0]);
    //         }
    //     }
    //     return dp[0][1];
    // }  

    // using space optimization
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<int> ahead(2, 0), curr(2, 0);
    //     ahead[0]=ahead[1]=0;
    //     for(int i=n-1; i>=0; i--){
    //         for(int buy=0; buy<=1; buy++){
    //             if(buy) curr[buy]=max(-prices[i]+ ahead[0], 0+ ahead[1]);
    //             else curr[buy]=max(prices[i]+ ahead[1], ahead[0]);
    //         }
    //         ahead=curr;
    //     }
    //     return ahead[1];
    // }  

    // using 4 variables
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int aheadNotBuy, aheadBuy, currNotBuy, currBuy;
        aheadNotBuy=aheadBuy=0;
        for(int i=n-1; i>=0; i--){
            currBuy=max(-prices[i]+ aheadNotBuy, 0+ aheadBuy);
            currNotBuy=max(prices[i]+ aheadBuy, aheadNotBuy);
            aheadNotBuy=currNotBuy;
            aheadBuy=currBuy;
        }
        return aheadBuy;
    }  
};