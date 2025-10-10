class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        string ans="";
        for(int i=1; i<n; i++){
            int l=i;
            int h=i;
            while(s[l]==s[h]){
                l--;
                h++;
                if(l==-1 || h==n) break;
            }
            string pal=s.substr(l+1, h-l-1);
            if(pal.length()>ans.length()) ans=pal;

            l=i-1;
            h=i;
            while(s[l]==s[h]){
                l--;
                h++;
                if(l==-1 || h==n) break;
            }
            pal=s.substr(l+1, h-l-1);
            if(pal.length()>ans.length()) ans=pal;
        }
        return ans;
    }
};