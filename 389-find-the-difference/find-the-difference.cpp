class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans=0;
        for(char it: s) ans^=it;
        for(char it: t) ans^=it;
        return ans;
    }
};