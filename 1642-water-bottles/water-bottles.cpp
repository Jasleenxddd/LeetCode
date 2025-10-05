class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int i=numBottles;
        int j=numBottles;
        while(j>=numExchange){
            int n=j/numExchange;
            i+=n;
            j=j%numExchange+n;
        }
        return i;
    }
};