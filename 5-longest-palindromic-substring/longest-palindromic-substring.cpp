class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        if(n<=1) return s;
        for(int i=1; i<n; i++){
            int l=i;
            int r=i;
            while(s[l]==s[r]){
                l--;
                r++;
                if(l==-1 || r==n) break;
            }
            string pal=s.substr(l+1, r-l-1);
            if(pal.length()> ans.length()) ans=pal;

            l=i-1;
            r=i;
            while(s[l]==s[r]){
                l--;
                r++;
                if(l==-1 || r==n) break;
            }
            pal=s.substr(l+1, r-l-1);
            if(pal.length()> ans.length()) ans=pal;
        }
        return ans;
    }
};