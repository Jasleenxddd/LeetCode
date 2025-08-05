class Solution {
public:
    int f(int num, vector<int>& baskets, vector<bool>& ifUsed){
        for(int i=0; i<baskets.size();i++){
            if(!ifUsed[i] && baskets[i]>=num){
                ifUsed[i]=true;
                return true;
            }
        }
        return false;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool> ifUsed(n, false);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!f(fruits[i], baskets, ifUsed)) cnt++;
        }
        return cnt;
    }
};