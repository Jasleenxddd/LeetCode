class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=0;
        int curr=1;
        int prev=0;
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[i-1]) curr++;
            else{
                cnt+=min(prev, curr);
                prev=curr;
                curr=1;
            }
        }
        cnt+=min(prev, curr);
        return cnt;
    }
};