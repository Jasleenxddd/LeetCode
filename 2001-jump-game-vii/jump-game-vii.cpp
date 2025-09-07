class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        int far=0;
        vector<bool> dp(n, false);
        dp[0]=true;
        for(int i=0; i<n; i++){
            if(!dp[i]) continue;
            int st=max(i+minJump, far+1);
            int e=min(i+maxJump, n-1);
            for(int j=st; j<=e; j++){
                if(s[j]=='0'){
                    if(j==n-1) return true;
                    dp[j]=true;
                }
            }
            far=e;
        }
        return false;
    }
};