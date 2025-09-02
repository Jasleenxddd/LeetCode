class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n=g.size();
        int m=s.size();
        int i=0, j=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                j++;
                i++;
            }
            else j++;
        }
        return i;
    }






















    // // using memoization
    // // int cook(int i, int j, vector<int>& g, vector<int>& s, vector<vector<int>>& dp){
    // //     if(i==g.size() || j==s.size()) return 0;
    // //     if(dp[i][j]!=-1) return dp[i][j];
    // //     int assign=0;
    // //     if(s[j]>=g[i]) assign=1+cook(i+1, j+1, g, s, dp);
    // //     int skip=cook(i, j+1, g, s, dp);
    // //     return dp[i][j]= max(assign, skip);
    // // }
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     // sort(g.begin(),g.end());
    //     // sort(s.begin(),s.end());
    //     // int l=0,r=0;
    //     // while(l<g.size() && r<s.size()){
    //     //     if(s[r]>=g[l]){
    //     //         l++;
    //     //     }
    //     //     r++;
    //     // }
    //     // return l;

    //     // using memoization
    //     // int memo we go from bottom to up like we started from f(0,0)
    //     // using this space is very huge so it is showing memory limit exceeded
    //     sort(g.begin(), g.end());
    //     sort(s.begin(), s.end());
    //     int n=g.size();
    //     int m=s.size();
    //     // vector<vector<int>> dp(n, vector<int> (m,-1));
    //     // return cook(0, 0, g, s, dp);


    //     // using tabulation
    //     // in tabulation we go from top to down like we started from f(n-1, m-1)
    //     vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    //     for(int i=n-1; i>=0; i--){
    //         for(int j=m-1; j>=0; j--){
    //             int assign=0;
    //             if(s[j]>=g[i]) assign=1+dp[i+1][j+1];
    //             int skip=dp[i][j+1];
    //             dp[i][j]= max(assign, skip);
    //         }
    //     }
    //     return dp[0][0];

    //     // using space optimization
    // }
};