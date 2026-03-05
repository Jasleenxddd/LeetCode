class Solution {
public:
    int minOperations(string s) {
        // starting with either 0 or 1
        int n=s.length();
        int cnt0=0;
        int cnt1=0;
        for(int i=0; i<n; i++){
            char zero=(i%2==0)?'0':'1';
            char one=(i%2==0)?'1':'0';

            if(s[i]!=zero) cnt0++;
            if(s[i]!=one) cnt1++;
        }
        return min(cnt0, cnt1);
    }
};