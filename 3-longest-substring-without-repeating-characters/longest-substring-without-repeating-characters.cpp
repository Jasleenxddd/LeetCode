class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector<int> map(256,-1);
        // int l=0,r=0,len=0;
        // while(r<s.length()){
        //     if(map[s[r]]!=-1){
        //         l=max(map[s[r]]+1,l);
        //     }
        //     map[s[r]]=r;
        //     len=max(len,r-l+1);
        //     r++;
        // }
        // return len;

        unordered_map<char, int> mpp;
        int l=0, ans=0;
        for(int r=0; r<s.length(); r++){
            char ch=s[r];
            if(mpp.count(ch) && mpp[ch]>=l) l=mpp[ch]+1;
            mpp[ch]=r;
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};