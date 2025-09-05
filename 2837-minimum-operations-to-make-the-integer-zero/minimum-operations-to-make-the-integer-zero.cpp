class Solution {
public:
    int cntSet(long long i){
        int cnt=0;
        while(i>0){
            if(i&1) cnt++;
            i>>=1;
        }
        return cnt;
    }
    int makeTheIntegerZero(int num1, int num2) {
        for(long long i=0; i<=60; i++){
            long long s=(long long)(num1)-i*(long long)(num2);
            if(s<i) continue;
            if(cntSet(s)<=i) return (int)i;
        }
        return -1;
    }
};