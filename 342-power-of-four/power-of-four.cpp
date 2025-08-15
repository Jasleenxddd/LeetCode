class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n<=0) return false;
        // while(n%4==0) n=n/4;
        // if(n==1) return true;
        // else return false;

        if(n<=0) return false;
        double t=log10(n)/log10(4);
        return t==floor(t);
    }
};