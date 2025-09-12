class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.length();
        unordered_map<int, char> mpp;
        for(int i=0; i<n; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') mpp[i]=s[i];
        }
        int m=mpp.size();
        if(m==0) return false;
        else if(m==1) return true;
        else if(m%2==0) return true;
        return true;
    }
};