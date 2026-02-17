class Solution {
public:
    int f(string& s, int ch1, int ch2){
        int n=s.length();
        int cnt1=0;
        int cnt2=0;
        int maxL=0;
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++){
            if(s[i]!=ch1 && s[i]!=ch2){
                mpp.clear();
                cnt1=0;
                cnt2=0;
                continue;
            }
            if(s[i]==ch1) cnt1++;
            if(s[i]==ch2) cnt2++;
            if(cnt1==cnt2) maxL=max(maxL, cnt1+cnt2);
            
            int diff=cnt1-cnt2;
            if(mpp.count(diff)) maxL=max(maxL, i-mpp[diff]);
            else mpp[diff]=i;
        }
        return maxL;
    }
    int longestBalanced(string s) {
        int n=s.length();
        int cnt=1;
        int maxL=0;

        // case 1: only one ch.
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]) cnt++;
            else{
                maxL=max(maxL, cnt);
                cnt=1;
            }
        }
        // for case "aaaa"
        maxL=max(maxL, cnt);

        // case 2: 2 ch. involved
        maxL=max(maxL, f(s, 'a', 'b'));
        maxL=max(maxL, f(s, 'a', 'c'));
        maxL=max(maxL, f(s, 'b', 'c'));

        // case 3: all 3 involved

        int cnta=0;
        int cntb=0;
        int cntc=0;
        unordered_map<string, int> mpp;
        for(int i=0; i<n; i++){
            if(s[i]=='a') cnta++;
            else if(s[i]=='b') cntb++;
            else cntc++;

            if(cnta==cntb && cnta==cntc) maxL=max(maxL, cnta+cntb+cntc);

            int difAB=cnta-cntb;
            int difAC=cnta-cntc;
            string key=to_string(difAB) + "_" + to_string(difAC);
            if(mpp.find(key)!=mpp.end()) maxL=max(maxL, i-mpp[key]);
            else mpp[key]=i;
        }
        return maxL;
    }
};