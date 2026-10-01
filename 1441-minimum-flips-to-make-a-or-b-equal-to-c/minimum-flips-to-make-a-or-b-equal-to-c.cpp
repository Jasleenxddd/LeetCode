class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=0; i<32; i++){
            int a_bit=a&(1<<i);
            int b_bit=b&(1<<i);
            int c_bit=c&(1<<i);
            if(c_bit==0){
                if(a_bit!=0) cnt++;
                if(b_bit!=0) cnt++;
            }
            else{
                if(a_bit==0 && b_bit==0) cnt++;
            }
        }
        return cnt;
    }
};