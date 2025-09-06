class Solution {
public:
    long long f(int l, int r){
        // 1 to 3: 1 step
        // 4 to 15: 2 steps
        // 16 to 63: 3 steps
        // formula= 4^(s-1) to 4^(s)-1: s steps
        long long L=1;
        long long s=1;
        long long steps=0;
        while(L<=r){
            long long R=4*L-1;
            long long start=max(L, (long long)l);
            long long end=min(R, (long long)r);
            if(start<=end) steps+=(end-start+1)*s;
            s+=1;
            L=L*4;
        }
        return steps;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long res=0;
        for(auto& q: queries){
            int l=q[0];
            int r=q[1];
            long long steps=f(l, r);
            res+=(steps+1)/2;
        }
        return res;
    }
};