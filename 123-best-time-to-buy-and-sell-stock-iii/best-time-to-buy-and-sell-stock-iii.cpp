class Solution {
public:
    // using memoization
    // int f(int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
    //     if(i==prices.size() || cap==0) return 0;
    //     if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
    //     if(buy) return dp[i][buy][cap]=max(-prices[i]+f(i+1, 0, cap, prices, dp), f(i+1, 1, cap, prices, dp));
    //     return dp[i][buy][cap]=max(prices[i]+ f(i+1, 1, cap-1, prices, dp), f(i+1, 0, cap, prices, dp));
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
    //     return f(0, 1, 2, prices, dp);
    // }

    // using tabulation 
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
    //     // no need for base case as it is already initialized to 0 

    //     // in case
    //     // for(int i=0; i<n; i ++){
    //     //     for(int buy=0; buy<=1; buy++){
    //     //         dp[i][buy][0]=0;
    //     //     }
    //     // }
    //     // for(int buy=0; buy<=1; buy++){
    //     //     for(int cap=0; cap<=2; cap++){
    //     //         dp[0][buy][cap]=0;
    //     //     }
    //     // }

    //     for(int i=n-1; i>=0; i--){
    //         for(int buy=0; buy<=1; buy++){
    //             for(int cap=1; cap<=2; cap++){
    //                 if(buy) dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap], dp[i+1][1][cap]);
    //                 else dp[i][buy][cap]=max(prices[i]+ dp[i+1][1][cap-1], dp[i+1][0][cap]);
    //             }
    //         }
    //     }
    //     return dp[0][1][2];
    // }

    // using space optimization
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> ahead(2, vector<int> (3, 0));
        vector<vector<int>> curr(2, vector<int> (3, 0));
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    if(buy) curr[buy][cap]=max(-prices[i]+ahead[0][cap], ahead[1][cap]);
                    else curr[buy][cap]=max(prices[i]+ ahead[1][cap-1], ahead[0][cap]);
                }
            }
            ahead=curr;
        }
        return ahead[1][2];
    }
};