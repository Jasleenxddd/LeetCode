class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        while(target>1){
            if(maxDoubles==0) return ans+(target-1);
            else if(target%2==0){
                target=target/2;
                maxDoubles--;
                ans++;
            }
            else {
                target--;
                ans++;
            }
        }
        return ans;
    }
};