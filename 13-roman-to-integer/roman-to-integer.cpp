class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp={
            {'I', 1},
            {'V', 5}, 
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int n=s.size();
        int prev=0;
        int ans=0;
        for(int i=n-1; i>=0; i--){
            int val=mpp[s[i]];
            if(val<prev) ans-=val;
            else ans+=val;
            prev=val;
        }
        return ans;
    }
};