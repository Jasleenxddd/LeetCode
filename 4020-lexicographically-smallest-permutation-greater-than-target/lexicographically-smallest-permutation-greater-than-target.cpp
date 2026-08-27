class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.length();
        vector<int> arr(26,0);
        for(auto ch:s) arr[ch-'a']++;
        for(int i=n-1; i>=0; i--){
            vector<int> rem=arr;
            bool pos=true;
            for(int p=0; p<i; p++){
                int c=target[p]-'a';
                if(rem[c]==0){
                    pos=false;
                    break;
                }
                rem[c]--;
            }
            if(!pos) continue;
            int curr=target[i]-'a';
            for(int j=curr+1; j<26; j++){
                if(rem[j]==0) continue;
                string ans=target.substr(0, i);
                ans+=char('a'+j);
                rem[j]--;
                for(int x=0; x<26; x++){
                    while(rem[x]>0){
                        ans+=char('a'+x);
                        rem[x]--;
                    }
                }
                return ans;
            }
        }
        return "";
    }
};