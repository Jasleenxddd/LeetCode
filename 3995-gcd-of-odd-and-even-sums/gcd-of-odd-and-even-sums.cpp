class Solution {
public:
    int f(int a, int b){
        if(b==0) return a;
        return f(b, a%b);
    }
    int gcdOfOddEvenSums(int n) {
        return f(n*n, n*(n+1));
        // return n;
    }
};