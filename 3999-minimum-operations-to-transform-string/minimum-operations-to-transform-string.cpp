class Solution {
public:
    int minOperations(string s) {
        int cnt=0;
        for(int i=0; i<s.length(); i++){
            int num=(26-(s[i]-'a'))%26;
            cnt=max(num, cnt);
        }
        return cnt;
    }
};