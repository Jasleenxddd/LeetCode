class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // optimal: Boyer Moore Voting Algo
        int el=0;
        int cnt=0;
        for(int it: nums){
            if(cnt==0) el=it;
            if(el==it) cnt++;
            else cnt--; 
        }
        return el;

        // better optimal code
        // int can=0, cnt=0;
        // for(int num: nums){
        //     if(cnt==0) can=num;
        //     if(num==can) cnt++;
        //     else cnt--;
        // }
        // return can;
    }
};