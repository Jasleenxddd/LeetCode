class Solution {
public:
    // using tabulation
    int lcs(string s, string t){
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        for(int i=0; i<=n; i++) dp[i][0]=0;
        for(int j=0; j<=n; j++) dp[0][j]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+ dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
    
    // using space optimization
    // int lcs(string s, string t){
    //     int n=s.size();
    //     vector<int> prev(n+1,0), curr(n+1, 0);
    //     for(int j=0; j<=n; j++) prev[j]=0;
    //     for(int i=1; i<=n; i++){
    //         for(int j=1; j<=n; j++){
    //             if(s[i-1]==t[j-1]) curr[j]=1+ prev[j-1];
    //             else curr[j]= max(prev[j], curr[j-1]);
    //         }
    //         prev=curr;
    //     }
    //     return prev[n];
    // }
    // int longestPalindromeSubseq(string s) {
    //     string t=s;
    //     reverse(t.begin(), t.end());
    //     return lcs(s, t);
    // }
    int minInsertions(string s) {
        return s.length()- longestPalindromeSubseq(s);
    }
};