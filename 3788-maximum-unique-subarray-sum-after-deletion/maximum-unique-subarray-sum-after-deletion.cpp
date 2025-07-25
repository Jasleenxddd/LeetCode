class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0;
        unordered_set<int> st;
        bool allNeg=true;
        int mini=INT_MIN;
        for(auto it: nums) st.insert(it);
        for(auto it: st){
            mini=max(mini, it);
            if(it>0){
                sum+=it;
                allNeg=false;
            }
        }
        if(allNeg==true) return mini;
        else return sum;
    }
};